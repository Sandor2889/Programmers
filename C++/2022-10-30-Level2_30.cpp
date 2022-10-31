#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 1;
    int size = priorities.size();
    vector<int> result;
    queue<pair<int, int>> q;

    // q에 순서대로 (중요도, idx) 넣기
    for (int i = 0; i < size; ++i) { q.push({ priorities[i], i }); }

    // 최댓값
    int max = *max_element(priorities.begin(), priorities.end());

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        int importance = temp.first;

        // 최댓값 보다 작으면 q에서 맨뒤로 보내기
        if (importance < max) { q.pop(); q.push(temp); }

        // 최댓값과 같거나 같으면 stack에 넣고 q에서 빼내기, 최댓값 갱신
        else
        {
            result.push_back(temp.second);
            priorities.erase(max_element(priorities.begin(), priorities.end()));
            if (!priorities.empty()) max = *max_element(priorities.begin(), priorities.end());
            q.pop();
        }
    }

    // location의 순서 출력
    for (int i = 0; i < result.size(); ++i)
    {
        if (result[i] == location) { answer = i + 1; }
    }

    return answer;
}

int main()
{
    vector<int> priorities = { 2, 1, 3, 2 };
    int answer = solution(priorities, 2);
    
    cout << answer;

    return 0;
}