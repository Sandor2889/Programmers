#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<int> q;

    // q에 progresses.size 만큼 인덱스 순서대로 넣기
    for (int i = 0; i < progresses.size(); i++) { q.push(i); }

    while (!q.empty())
    {
        int idx = q.front();
        int cnt = 0; // 완료 수

        // 진도가 100이 될때까지 걸리는 시간
        int spentTime = (100 - progresses[idx]) / speeds[idx];
        if ((100 - progresses[idx]) % speeds[idx] != 0) { ++spentTime; }

        for (int i = idx; i < progresses.size(); ++i)
        {
            // 진도가 100이 아니면 걸린 시간 만큼 더하기 
            if (progresses[i] < 100) { progresses[i] += spentTime * speeds[i]; }

            // 가장 앞에있는 작엎의 진도가 100이라면 q에서 빼내기
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