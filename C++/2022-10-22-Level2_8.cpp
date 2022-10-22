#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int runtime[10001];     // 다리위 트럭의 경과 시간

// 다리 위 트럭의 무게 합
int sumWeightOnBridge(queue<int> q, vector<int>& truck_weights)
{
    int sum = 0;
    while (!q.empty())
    {
        int idx = q.front();
        q.pop();
        sum += truck_weights[idx];
    }

    return sum;
}

// 다리 위 트럭의 경과 시간 증가
void runningTime(queue<int>& q, int bridge_length)
{
    queue<int> copyQ = q;

    // 트럭 각각의 경과 시간 증가
    while (!copyQ.empty())
    {
        int idx = copyQ.front();
        copyQ.pop();
        runtime[idx] += 1;
    }

    // 가장 먼저 출발한 트럭이 다리를 건넜는지 확인
    if (!q.empty() && runtime[q.front()] >= bridge_length) { q.pop(); }
}

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 1;
    int nextIdx = 0;
    queue<int> q; // 출발한 다리위 트럭
    q.push(nextIdx);   // 가장 처음의 트럭 Idx
    nextIdx++;

    while (!q.empty())
    {
        answer++;   // 시간의 경과
        runningTime(q, bridge_length);  // 다리 위 트럭의 시간 경과
        int diff = weight - sumWeightOnBridge(q, truck_weights); // 다리 무게와 다리 위 트럭의 무게 합의 차
        
        if (nextIdx < truck_weights.size() && 0 < diff && truck_weights[nextIdx] <= diff)
        {
            q.push(nextIdx);
            nextIdx++;
        }
    }

    return answer;
}

int main()
{
    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights = { 7, 4, 5, 6 };

    int answer = solution(bridge_length, weight, truck_weights);
    cout << answer;

    return 0;
}

