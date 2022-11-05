#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool sum(int limit, int a, int& total)
{
    total += a;

    if (total > limit) { return false; }
    else if (total == limit) { return true; }

    return sum(limit, a + 1, total);
}

int solution(int n)
{
    int answer = 0;

    // 1~n 범위에서 가능한 것 찾아 카운팅 
    for (int i = 1; i <= n; i++)
    {
        int total = 0;
        if (sum(n, i, total)) { answer++; }
    }

    return answer;
}

int main()
{
    int n = 15;
    int answer = solution(n);
    cout << answer;

    return 0;
}
