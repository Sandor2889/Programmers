#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    // 가능한 최대 무게와 최소 무게를 묶어서 태운다.
    int answer = 0;

    // 오름차순 정렬
    sort(people.begin(), people.end());

    // 큰 무게 부터 시작
    int minIdx = 0;
    for (int i = people.size() - 1; i != minIdx - 1; i--)
    {
        ++answer; // 보트 수 증가

        if (i == minIdx) { break; }  // 같은 곳을 가리키게 되면 종료

        int max = people[i];
        int min = people[minIdx];

        // 최소 무게가 (limit - max) 보다 작거나 같은 값 인지 확인
        if (limit - max >= min) { minIdx++; }
    }

    return answer;
}

int main()
{
    vector<int> people = { 70, 70, 60, 40, 40 };
    int limit = 110;

    int answer = solution(people, limit);
    cout << answer;

    return 0;
}
