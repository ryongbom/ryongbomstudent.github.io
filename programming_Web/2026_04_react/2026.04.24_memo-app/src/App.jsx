import { useState, useMemo } from "react";

function App() {
  const [count, setCount] = useState(0)
  const [input, setInput] = useState('')

  const heavyCalculation = (num) => {
    console.log('🔥 무거운 계산 실행 중...')
    let sum = 0
    for (let i = 0; i < 100000000; i++) {
      sum += i
    }
    return sum + num
  }

  const result = useMemo(() => heavyCalculation(count), [count])

  console.log('컴포넌트 렌더링!')

  return (
    <div style={{ padding: '20px', textAlign: 'center' }}>
      <h1>useMemo Practice</h1>

      <div>
        <h2>Heavy calculation Result: {result}</h2>
        <button onClick={() => setCount(count + 1)} style={buttonStyle}>
          count 증가 (무거운 계산 실행) - {count}
        </button>
      </div>

      <div style={{ marginTop: '30px' }}>
        <h2>가벼운 input (리렌더링만 발생)</h2>
        <input
          value={input}
          onChange={(e) => setInput(e.target.value)}
          placeholder="아무거나 입력..."
          style={inputStyle}
        />
        <p>입력값: {input}</p>
      </div>

      <p style={{ color: '#666', marginTop: '30px' }}>
        💡 콘솔을 확인해보십시오!<br />
        count 버튼 클릭: 무거운 계산 실행됨<br />
        input 입력: 무거운 계산 실행 안 됨!
      </p>
    </div>
  )
}

const buttonStyle = {
  padding: '10px 20px',
  fontSize: '16px',
  cursor: 'pointer',
  backgroundColor: '#007bff',
  color: 'white',
  border: 'none',
  borderRadius: '5px',
  margin: '10px'
}

const inputStyle = {
  padding: '10px',
  fontSize: '16px',
  width: '200px',
  margin: '10px'
}

export default App