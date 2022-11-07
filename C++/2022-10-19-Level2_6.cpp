#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long dp[5001];

long long tiling(int n)
{
    // Ȧ���� ���簢�� �Ұ�
    // n > 2 ���� ����
    if (n == 0) { return 1; }   // ¦���� f(0)�� ���� ����
    else if (n == 2) { return 3; }
    else if (n % 2 != 0) { return 0; }

    if (dp[n] != 0) { return dp[n]; }

    long long sum = 3 * tiling(n - 2); // 3f(n-2)
    // ¦���� ��� Ư���� �� ������ ���� ó��
    for (int i = 4; i <= n; i += 2)
    {
        sum += 2 * tiling(n - i);
    }

    return dp[n] = sum % 1000000007;
}

int solution(int n)
{
    long long answer = tiling(n);
    return answer;
}

int main()
{
    int n = 1;
    int answer = solution(n); 
    cout << answer;

    return 0;
}