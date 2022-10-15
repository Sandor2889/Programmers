#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int answer = 0;
    int maxW = 0;
    int maxH = 0;

    // 큰 숫자는 가로, 작은 숫자는 세로로 정렬하기
    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] < sizes[i][1])
        {
            int temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
    }

    // 각각의 가장 큰 가로와 세로 길이 뽑기
    for (int i = 0; i < sizes.size(); i++)
    {
        if (maxW < sizes[i][0]) { maxW = sizes[i][0]; }
        if (maxH < sizes[i][1]) { maxH = sizes[i][1]; }
    }

    // 최종 지갑의 크기
    answer = maxW * maxH;

    return answer;
}

int main()
{
    vector<vector<int>> sizes = 
    { 
        {60, 50},
        {30, 70},
        {60, 30},
        {80, 40},
    };

    int answer = solution(sizes);
    cout << answer;

    return 0;
}