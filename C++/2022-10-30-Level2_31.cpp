#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board)
{
    int answer = 0;

    while (true)
    {
        vector<pair<int, int>> clearIdx; // ������ ����� idx

        // 2x2 ��� ã��
        for (int row = 0; row < m - 1; ++row)
        {
            for (int column = 0; column < n - 1; ++column)
            {
                if (board[row][column] != '0' &&
                    board[row][column] == board[row][column + 1] &&
                    board[row][column] == board[row + 1][column] &&
                    board[row][column] == board[row + 1][column + 1])
                { clearIdx.push_back({ row, column }); }
            }
        }

        if (clearIdx.empty()) { break; }    // ������ ����� ������ ����������

        // ��� ����
        for (int i = 0; i < clearIdx.size(); ++i)
        {
            pair<int, int> temp = clearIdx[i];

            if (board[temp.first][temp.second] != '0') 
            { 
                board[temp.first][temp.second] = '0';
                ++answer; 
            }
            if (board[temp.first][temp.second + 1] != '0')
            {
                board[temp.first][temp.second + 1] = '0';
                ++answer;
            }
            if (board[temp.first + 1][temp.second] != '0')
            {
                board[temp.first + 1][temp.second] = '0';
                ++answer;
            }
            if (board[temp.first + 1][temp.second + 1] != '0')
            {
                board[temp.first + 1][temp.second + 1] = '0';
                ++answer;
            }
        }

        // �� ���� ä���
        for (int row = m - 1; row > 0; --row)
        {
            for (int column = n - 1; column >= 0; --column)
            {
                if (board[row][column] == '0')
                {
                    for (int height = row-1; height >= 0; --height)
                    {
                        if (board[height][column] != '0')
                        {
                            board[row][column] = board[height][column];
                            board[height][column] = '0';
                            break;
                        }
                    }
                }
            }
        }
    }

    return answer;
}

int main()
{
    vector<string> board = { "CCBDE", "AAADE", "AAABF", "CCBBF" };
    int answer = solution(4, 5, board);
    
    cout << answer;

    return 0;
}