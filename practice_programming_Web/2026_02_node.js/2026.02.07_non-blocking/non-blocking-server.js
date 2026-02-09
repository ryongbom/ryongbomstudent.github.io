const http = require('http');

console.log('non-blocking-server started!');

const server = http.createServer((req, res) => {
    const startTime = new Date();
    console.log(`[${startTime.toISOString()}] receive request: ${req.url}`);

    if (req.url === '/fast') {
        res.writeHead(200, { 'Content-Type': 'text/plain' });
        res.end(`fast response (${new Date() - startTime}ms)\n`);
        console.log(`[${new Date().toISOString()}] end FAST response`);
    }
    else if (req.url === '/slow') {
        console.log(`[${new Date().toISOString()}] start slow response (non-blocking)`);

        setTimeout(() => {
            res.writeHead(200, { 'Content-Type': 'text/plain' });
            res.end(`slow response (${new Date() - startTime}ms)\n`);
            console.log(`[${new Date().toISOString()}] end SLOW response`);
        }, 10000);
    }
    else if (req.url === '/io-slow') {
        console.log(`[${new Date().toISOString()}] start file I/O simulation`);

        const simulateFileRead = (callback) => {
            setTimeout(() => {
                callback(null, 'File content: Hello from non-blocking I/O');
            }, 5000);
        };

        simulateFileRead((err, data) => {
            if (err) {
                res.writeHead(500, { 'Content-Type': 'text/plain' });
                res.end('Error read File\n');
            } else {
                res.writeHead(200, { 'Content-Type': 'text/plain' });
                res.end(`${data} (total time: ${new Date() - startTime}ms)\n`);
                console.log(`[${new Date().toISOString()}] end file I/O response`);
            }
        });
    }
    else if (req.url === '/parallel') {
        console.log(`[${new Date().toISOString()}] start parallel requests`);

        const results = [];
        const tasks = [1000, 2000, 3000];

        let completed = 0;

        const checkAllCompleted = () => {
            if (completed === tasks.length) {
                res.writeHead(200, { 'Content-Type': 'application/json' });
                res.end(JSON.stringify({
                    message: 'All parallel tasks completed!',
                    result: results,
                    totalTime: `${new Date() - startTime}ms`
                }, null, 2));
                console.log(`[${new Date().toISOString()}] all parallel tasks done`);
            }
        };

        tasks.forEach((delay, index) => {
            setTimeout(() => {
                results[index] = `Task ${index + 1} done in ${delay}ms`;
                completed++;
                console.log(`[${new Date().toISOString()}] Task ${index + 1} completed`);

                checkAllCompleted();
            }, delay);
        });
    }
    else {
        res.writeHead(200, { 'Content-Type': 'text/html' });
        res.end(`
            <!DOCTYPE html>
            <html lang="ko">
            <head>
                <title>Non-Blocking Server Demo</title>
                <meta charset="UTF-8">
                <style>
                    body { font-family: Arial, sans-serif; margin: 40px; }
                    .demo { background: #f0f0f0; padding: 20px; margin: 20px 0; border-radius: 5px; }
                    .blocking { background: #ffe6e6; }
                    .non-blocking { background: #e6ffe6; }
                    a { display: inline-block; margin: 5px; padding: 10px 15px; background: #007bff; color: white; text-decoration: none; border-radius: 3px; }
                    a:hover { background: #0056b3; }
                </style>
            </head>
            <body>
                <h1>NON-BLOCKING Server Demo</h1>
                
                <div class="demo">
                    <h2>📊 차이점 비교</h2>
                    <div class="blocking">
                        <h3>블로킹 서버 (3001번 포트)</h3>
                        <p>동시 요청이 불가능합니다. /slow 요청 중에는 /fast도 대기해야 합니다.</p>
                        <a href="http://localhost:3001" target="_blank">블로킹 서버 테스트</a>
                    </div>
                    <div class="non-blocking">
                        <h3>논블로킹 서버 (3002번 포트 - 지금 이 서버)</h3>
                        <p>동시 요청이 가능합니다! /slow 요청 중에도 /fast는 즉시 응답합니다.</p>
                        <p>이유: setTimeout은 콜백 큐에 작업을 등록하고 바로 반환되기 때문입니다.</p>
                    </div>
                </div>
                
                <div class="demo">
                    <h2>🔄 테스트용 엔드포인트</h2>
                    <p><strong>아래 링크들을 각각 새 탭에서 동시에 열어보세요!</strong></p>
                    
                    <h3>1. 기본 테스트</h3>
                    <a href="/fast" target="_blank">/fast - 즉시 응답</a>
                    <a href="/slow" target="_blank">/slow - 10초 후 응답 (논블로킹)</a>
                    
                    <h3>2. I/O 작업 모사</h3>
                    <a href="/io-slow" target="_blank">/io-slow - 파일 읽기 작업 모사 (5초)</a>
                    
                    <h3>3. 병렬 작업</h3>
                    <a href="/parallel" target="_blank">/parallel - 병렬 작업 실행</a>
                </div>
                
                <div class="demo">
                    <h2>🎯 테스트 방법</h2>
                    <ol>
                        <li>두 개의 터미널 창을 열기</li>
                        <li>첫 번째 터미널: <code>curl http://localhost:3002/slow</code></li>
                        <li>2초 후 두 번째 터미널: <code>curl http://localhost:3002/fast</code></li>
                        <li>결과: /fast는 기다리지 않고 즉시 응답!</li>
                    </ol>
                </div>
                
                <div class="demo">
                    <h2>🔍 Node.js 이벤트 루프 동작 방식</h2>
                    <pre>
1. /slow 요청 들어옴
2. setTimeout() 호출 → 타이머 큐에 등록
3. 함수는 바로 종료 (메인 스레드 차단 없음)
4. 이벤트 루프는 다른 요청(/fast) 처리 가능
5. 10초 후 타이머 큐의 콜백 실행
                    </pre>
                </div>
            </body>
            </html>
        `);
    }
});

const PORT = 3002;
server.listen(PORT, () => {
    console.log(`NON-BLOCKING Server is open: http://localhost:${PORT}`);
    console.log('테스트 방법:');
    console.log('1. Terminal1: curl http://localhost:3002/slow');
    console.log('2. 2초 후 Terminal2: curl http://localhost:3002/fast');
    console.log('3. 결과: /fast는 /slow를 기다리지 않고 즉시 응답!');
    console.log('\n웹 브라우저에서도 테스트 가능:');
    console.log('- http://localhost:3002/slow 열기');
    console.log('- 새 탭에서 http://localhost:3002/fast 열기');
    console.log('==============================================\n');
});