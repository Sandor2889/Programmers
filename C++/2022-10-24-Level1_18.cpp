#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n)
{
    int answer = 0;

    // 병의 전체 수가 a 보다 작을 때까지 반복
    while (n >= a)
    {
        int cola = b * (n / a);   // 교환 수 
        n %= a;                   // 남은 빈 병
        n += cola;                // 교환 한 콜라를 마셨을때
        answer += cola;
    }

    return answer;
}

int main()
{
    int a = 3;
    int b = 2;
    int n = 10;

    int answer = solution(a, b, n);
    cout << answer;

    return 0;
}

