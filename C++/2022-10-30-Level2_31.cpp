#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board)
{
    int answer = 0;

    while (true)
    {
        vector<pair<int, int>> clearIdx; // 제거할 블록의 idx

        // 2x2 블록 찾기
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

        if (clearIdx.empty()) { break; }    // 제거할 블록이 없으니 빠져나오기

        // 블록 제거
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

        // 빈 공간 채우기
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