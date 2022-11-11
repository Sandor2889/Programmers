#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements)
{
    int answer = 0;
    int size = elements.size();
    unordered_set<int> res;

    // i 부터 길이가 각각 1 ~ size 일때의 합 구하기
    for (int i = 0; i < size; ++i)
    {
        int sum = 0;
        for (int j = i; j < size + i; ++j)
        {
            // (idx % size) 하면 끝이 이어진 것 처럼 다음 인접한 다음 수를 알 수 있다.
            sum += elements[j % size];
            res.insert(sum);
        }
    }

    return answer = res.size();
}

int main()
{
    vector<int> elements = { 7,9,1,1,4 };
    int answer = solution(elements);
    cout << answer;

    return 0;
}
