#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[100001];

int fibonacci(int n)
{
    if (n == 0) { return 0; }
    else if (n == 1) { return 1; }

    // dp[n]�� ��ϵ� �����Ͱ� ������ ������
    if (dp[n] != 0) { return dp[n]; }

    // ��� ���� dp[]�� ����
    return dp[n] = (fibonacci(n - 1) + fibonacci(n - 2)) % 1234567;
}

int solution(int n)
{
    int answer = fibonacci(n);
    return answer;
}

int main()
{
    int n = 3;
    int answer = solution(n);
    cout << answer;

    return 0;
}
