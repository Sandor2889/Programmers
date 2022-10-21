#include <iostream>
#include <vector>

using namespace std;


int solution(int k, vector<vector<int>> dungeons)
{
    int answer = 0;

    for (int i = 0; i < dungeons.size(); i++)
    {
        int result = 0;
        

        if (result > answer) { answer = result; }
    }

    return answer;
}

/*
{ 80, 20 } 선택
{ 50, 40 }, { 30, 10 } 가능한지 확인

{ 50, 40 } 선택
{ 30, 10 } 불가

{ 30, 10 } 선택
{ 50, 40 } 불가
*/

int main()
{
    int k = 80;
    vector<vector<int>> dungeons =
    {
        { 80, 20 },
        { 50, 40 },
        { 30, 10 }
    };

    int answer = solution(k, dungeons);
    cout << answer;

    return 0;
}