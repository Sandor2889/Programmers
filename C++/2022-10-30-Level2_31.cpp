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

    // q�� ������� (�߿䵵, idx) �ֱ�
    for (int i = 0; i < size; ++i) { q.push({ priorities[i], i }); }

    // �ִ�
    int max = *max_element(priorities.begin(), priorities.end());

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        int importance = temp.first;

        // �ִ� ���� ������ q���� �ǵڷ� ������
        if (importance < max) { q.pop(); q.push(temp); }

        // �ִ񰪰� ���ų� ������ stack�� �ְ� q���� ������, �ִ� ����
        else
        {
            result.push_back(temp.second);
            priorities.erase(max_element(priorities.begin(), priorities.end()));
            if (!priorities.empty()) max = *max_element(priorities.begin(), priorities.end());
            q.pop();
        }
    }

    // location�� ���� ���
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