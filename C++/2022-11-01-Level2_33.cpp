#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[60001];

// Á¡È­½Ä : n > 2, f(n) = f(n-1) + f(n-2) 
int tiles(int n)
{
    if (n == 1) { return 1; }
    else if (n == 2) { return 2; }

    if (dp[n] != 0) { return dp[n]; }

    return dp[n] = (tiles(n - 1) + tiles(n - 2)) % 1000000007;
}

int solution(int n)
{
    int answer = 0;
    answer = tiles(n);
    return answer;
}

int main()
{
    int n = 4;
    cout << solution(n);

    return 0;
}