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
{ 80, 20 } ����
{ 50, 40 }, { 30, 10 } �������� Ȯ��

{ 50, 40 } ����
{ 30, 10 } �Ұ�

{ 30, 10 } ����
{ 50, 40 } �Ұ�
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