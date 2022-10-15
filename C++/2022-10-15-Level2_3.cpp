#include <iostream>

using namespace std;

// 2의 거듭제곱 판별
bool isTwoPower(int n)
{
    int temp = 1;
    while (true)
    {
        temp *= 2;

        if (temp == n) { return true; }
        else if (temp > n) { return false; }
    }
}

// n이 2의 거듭 제곱일때 가장 적은 횟수로 이동 가능하다
int solution(int n)
{
    int ans = 1;

    if (!isTwoPower(n))
    {
        while (n > 1)
        {
            if (n % 2 == 1) { ans++; }   // 나누어 떨어지지 않으면 점프해야 됨
            n /= 2;
        }
    }

    return ans;
}

int main()
{
    int n = 5000;
    cout << solution(n);

    return 0;
}