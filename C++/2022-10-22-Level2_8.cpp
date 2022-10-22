#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int runtime[10001];     // �ٸ��� Ʈ���� ��� �ð�

// �ٸ� �� Ʈ���� ���� ��
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

// �ٸ� �� Ʈ���� ��� �ð� ����
void runningTime(queue<int>& q, int bridge_length)
{
    queue<int> copyQ = q;

    // Ʈ�� ������ ��� �ð� ����
    while (!copyQ.empty())
    {
        int idx = copyQ.front();
        copyQ.pop();
        runtime[idx] += 1;
    }

    // ���� ���� ����� Ʈ���� �ٸ��� �ǳԴ��� Ȯ��
    if (!q.empty() && runtime[q.front()] >= bridge_length) { q.pop(); }
}

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 1;
    int nextIdx = 0;
    queue<int> q; // ����� �ٸ��� Ʈ��
    q.push(nextIdx);   // ���� ó���� Ʈ�� Idx
    nextIdx++;

    while (!q.empty())
    {
        answer++;   // �ð��� ���
        runningTime(q, bridge_length);  // �ٸ� �� Ʈ���� �ð� ���
        int diff = weight - sumWeightOnBridge(q, truck_weights); // �ٸ� ���Կ� �ٸ� �� Ʈ���� ���� ���� ��
        
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

