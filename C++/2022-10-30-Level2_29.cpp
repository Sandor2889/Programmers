#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> q;

    // q�� progresses.size ��ŭ �ε��� ������� �ֱ�
    for (int i = 0; i < progresses.size(); i++) { q.push(i); }

    while (!q.empty())
    {
        int idx = q.front();
        int cnt = 0; // �Ϸ� ��

        // ������ 100�� �ɶ����� �ɸ��� �ð�
        int spentTime = (100 - progresses[idx]) / speeds[idx];
        if ((100 - progresses[idx]) % speeds[idx] != 0) { ++spentTime; }

        for (int i = idx; i < progresses.size(); ++i)
        {
            // ������ 100�� �ƴϸ� �ɸ� �ð� ��ŭ ���ϱ� 
            if (progresses[i] < 100) { progresses[i] += spentTime * speeds[i]; }

            // ���� �տ��ִ� �۾��� ������ 100�̶�� q���� ������
            if (progresses[i] >= 100 && idx == i)
            {
                q.pop();
                ++idx;
                ++cnt;
            }
        }

        answer.push_back(cnt);
    }

    return answer;
}

int main()
{
    vector<int> progresses = { 95, 90, 99, 99, 80, 99 };
    vector<int> speeds = { 1, 1, 1, 1, 1, 1 };

    vector<int> answer = solution(progresses, speeds);

    for (int i : answer)
    {
        cout << i << ' ';
    }
    

    return 0;
}