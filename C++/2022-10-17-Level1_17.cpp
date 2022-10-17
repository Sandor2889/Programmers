#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 30

using namespace std;

// ���ӵ� ���� ����
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

// ������ �ִٸ� '0�̻��� ��'�� ����, ���ٸ� '0'����
int tryGetDoll(vector<vector<int>>& board, int line)
{
    int temp = 0;
    for (int i = 0; i < board[line].size(); i++)
    {
        // ������ �ִٸ� �̾Ƴ��� �ش� �ڸ��� �湮ó�� ���ֱ�
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
        // ������ 0�� �ƴϸ� (������ �ش� ���ο� ��� 1�� �̻� ����)
        int doll = tryGetDoll(board, moves[i] - 1);

        if (doll) { storage.push_back(doll); }
    }

    // ���ӵ� ���� ����
    while (true)
    {
        // ���̻� ���Ű� �̷������ ������ while���� ���� ���´�.
        if (!continuousDoll(storage)) { break; }
        answer += 2;    // loop�� ��ӵǸ� ���Ű� �̷���� �Ͱ� ����. 
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