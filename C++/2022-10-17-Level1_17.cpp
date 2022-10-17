#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 30

using namespace std;

// 연속된 인형 제거
bool continuousDoll(vector<int>& storage)
{
    int prev = -1;
    for (int i = 0; i < storage.size(); i++)
    {
        if (prev == storage[i])
        {
            storage.erase(storage.begin() + i - 1, storage.begin() + i + 1);
            return true;
        }
        prev = storage[i];
    }
    return false;
}

// 인형이 있다면 '0이상의 값'을 리턴, 없다면 '0'리턴
int tryGetDoll(vector<vector<int>>& board, int line)
{
    int temp = 0;
    for (int i = 0; i < board[line].size(); i++)
    {
        // 인형이 있다면 뽑아내고 해당 자리를 방문처리 해주기
        if (board[i][line] > 0)
        {
            temp = board[i][line];
            board[i][line] = 0;
            return temp;
        }
    }

    return 0;
}

int solution(vector<vector<int>> board, vector<int> moves)
{
    vector<int> storage;
    int answer = 0;

    for (int i = 0; i < moves.size(); i++)
    {
        // 인형이 0이 아니면 (인형이 해당 라인에 적어도 1개 이상 존재)
        int doll = tryGetDoll(board, moves[i] - 1);

        if (doll) { storage.push_back(doll); }
    }

    // 연속된 인형 제거
    while (true)
    {
        // 더이상 제거가 이루어지지 않으면 while문을 빠져 나온다.
        if (!continuousDoll(storage)) { break; }
        answer += 2;    // loop가 계속되면 제거가 이루어진 것과 같다. 
    }

    return answer;
}

int main()
{ 
    vector<vector<int>> board =
    {
        {0, 0, 0, 0, 0 },
        {0, 0, 1, 0, 3 },
        {0, 2, 5, 0, 1 },
        {4, 2, 4, 4, 2 },
        {3, 5, 1, 3, 1 }
    };

    vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };
    int answer = solution(board, moves);
    cout << answer;

    return 0;
}