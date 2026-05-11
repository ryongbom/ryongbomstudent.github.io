검증을 위한 테스트 코드 추가 버전
c
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

long long gcd(long long a, long long b)
{
    long long r;
    do {
        r = a % b;
        a = b;
        b = r;
    } while (r != 0);
    return a;
}

// 점진적 계산법 (가장 안전한 방법)
void calculateSeries(int n, long long* num, long long* den)
{
    *num = 1;  // 첫 항: 1/2
    *den = 2;
    
    for (int i = 3; i <= n; i++) {
        long long term_num = i - 1;
        long long term_den = i;
        
        // 부호 결정
        if (i % 2 == 1) {
            term_num = -term_num;
        }
        
        // 분수 덧셈
        long long new_num = (*num) * term_den + term_num * (*den);
        long long new_den = (*den) * term_den;
        
        // 약분
        long long common = gcd(llabs(new_num), new_den);
        *num = new_num / common;
        *den = new_den / common;
    }
}

int main()
{
    int n;
    printf("n 값을 입력하세요 (2 ≤ n ≤ 20): ");
    scanf_s("%d", &n);
    
    if (n < 2 || n > 20) {
        printf("2에서 20 사이의 값을 입력해주세요.\n");
        return 1;
    }
    
    // 두 방법 모두로 계산하여 검증
    long long num1, den1, num2, den2;
    
    // 통분 방법
    den2 = 1;
    for (int i = 2; i <= n; i++) den2 *= i;
    num2 = getNum(n);
    long long common_divisor = gcd(llabs(num2), den2);
    
    // 점진적 방법
    calculateSeries(n, &num1, &den1);
    
    printf("통분 방법: %lld/%lld\n", num2 / common_divisor, den2 / common_divisor);
    printf("점진적 방법: %lld/%lld\n", num1, den1);
    
    // 두 결과 비교
    if (num1 * den2 == num2 * den1) {
        printf("✓ 두 방법의 결과가 일치합니다.\n");
    } else {
        printf("✗ 결과가 일치하지 않습니다!\n");
    }
    
    return 0;
}
