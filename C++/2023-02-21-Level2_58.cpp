#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> uniqeNums;
vector<bool> visited(7);

// dfs + 백 트래킹
// 1 -> 12 -> 123 -> 1234 -> 123 -> 12 -> 124 -> 1243 -> 124 -> 12 -> 1 -> 13 ...
void dfs(string num, string numbers)
{
    if (!num.empty()) { uniqeNums.insert(stoi(num)); }

    for (int i = 0; i < numbers.size(); ++i)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            dfs(num + numbers[i], numbers);
            visited[i] = false;
        }
    }
}

// 소수 판별
bool isPrimeNum(int num)
{
    if (num < 2) { return false; }

    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0) { return false; }
    }

    return true;
}

int solution(string numbers)
{
    int answer = 0;
    
    dfs("", numbers);

    for (auto iter = uniqeNums.begin(); iter != uniqeNums.end(); ++iter)
    {
        answer += isPrimeNum(*iter);
    }

    return answer;
}

int main()
{
    string numbers = { "1234" };
    int answer = solution(numbers);
    cout << answer;
    return 0;
}