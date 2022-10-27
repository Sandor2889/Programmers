#include <iostream>

using namespace std;

// 숫자 a의 대진표 위치와, b의 위치가 같아 지는 round를 찾는 것이 핵심이다.
// (x / 2) + (x % 2) => x를 2로나눈 몫과 나머지를 더하면 다음 대진표의 위치를 알 수 있다. 
int solution(int n, int a, int b)
{
    int answer = 0;

    // a와 b의 대진표 위치가 같을 때 찾기
    while (a != b)
    {
        ++answer;
        a = (a / 2) + (a % 2);
        b = (b / 2) + (b % 2);
    }

    return answer;
}

int main()
{
    int n = 8;
    int answer = solution(n, 4, 7);

    cout << answer;
}