#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> res;

    // set에 주어진 초기 값 담기 
    for (int i : scoville) { res.push(i); }

    while (res.size() > 1)
    {
        if (res.top() >= K) { break; }

        // 섞을 두개의 음식 빼내기
        int min = res.top();
        res.pop();

        int second = res.top();
        res.pop();

        // 합쳐진 새로운 음식 넣기
        res.push(min + second * 2);
        ++answer;
    }

    // 가장 작은 스코빌 지수가 k보다 작을 때
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