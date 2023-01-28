#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 시간초과
int solution_TimeOver(int number, int limit, int power) 
{
    int answer = 0;

    // number까지 순서대로 탐색
    for (int i = 1; i <= number; ++i)
    {
        int count = 0; // i에 대한 약수의 수
        for (int j = 1; j * j <= i; ++j)
        {
            if (i % j == 0) { ++count; }
        }

        // count가 limit 보다 크면 power로 제한
        if (count > limit) { count = power; }
        answer += count;
    }

    return answer;
}

// 정답
int solution(int number, int limit, int power)
{
    int answer = 1; // 1의 약수는 항상 한 개

    // 2부터 number까지 순서대로 탐색
    for (int i = 2; i <= number; ++i)
    {
        int count = 0; // i에 대한 약수의 수

        // 자신 i의 제곱근까지 구하면 됨
        // 6 = 1 * 6, 2 * 3 -> 1, 2, 3, 6
        for (int j = 1; j * j <= i; ++j)
        {
            if (j * j == i) { ++count; } // 제곱수 중복 예외처리
            else if (i % j == 0) { count += 2; }
        }

        // count가 limit 보다 크면 power로 제한
        if (count > limit) { count = power; }
        answer += count;
    }

    return answer;
}

int main()
{
    int number = 5;
    int limit = 3;
    int power = 2;

    int answer = solution(number, limit, power);
    cout << answer;

    return 0;
}