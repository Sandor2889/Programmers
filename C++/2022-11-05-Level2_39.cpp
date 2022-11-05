#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> res;

    // set�� �־��� �ʱ� �� ��� 
    for (int i : scoville) { res.push(i); }

    while (res.size() > 1)
    {
        if (res.top() >= K) { break; }

        // ���� �ΰ��� ���� ������
        int min = res.top();
        res.pop();

        int second = res.top();
        res.pop();

        // ������ ���ο� ���� �ֱ�
        res.push(min + second * 2);
        ++answer;
    }

    // ���� ���� ���ں� ������ k���� ���� ��
    if (res.top() < K) { answer = -1; }

    return answer;
}

int main()
{
    vector<int> scoville = { 1, 1, 1 };
    int answer = solution(scoville, 7);
    cout << answer;

    return 0;
}