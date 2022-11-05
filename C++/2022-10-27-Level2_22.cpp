#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[2001];

int cases(int n)
{
    if (n == 1) { return 1; }
    else if (n == 2) { return 2; }

    if (dp[n] != 0) { return dp[n]; }

    return dp[n] = (cases(n - 1) + cases(n - 2)) % 1234567;
}

long long solution(int n)
{
    long long answer = 0;
    answer = cases(n);

    return answer;
}

int main()
{
    int n = 4;
    long long answer = solution(n);

    cout << answer;
}

/*

1, 1, 1
2, 2, 11 2
3, 3, 111 12 21
4, 5, 1111 112 121 211 22
5, 8, 11111 1112 1121 1211 2111 122 212 221
6, 13, 111111 11112 11121 11211 12111 21111 1122 1212 2112 1221 2121 2211 222
7, 21, 1111111 111112 111121 111211 112111 121111 211111 11122 11212 12112 21112 11221 12121 21121 12211 21211 22111 1222
2122 2212 2221

f(1) = 1
f(2) = 2

n > 2
f(n) = f(n-1) + f(n-2)

*/