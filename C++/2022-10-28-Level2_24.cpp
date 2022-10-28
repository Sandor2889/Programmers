#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Init(vector<vector<int>>& answer, int rowSize, int columnSize)
{
    for (int row = 0; row < rowSize; ++row)
    {
        vector<int> temp(columnSize);
        answer.push_back(temp);
    }
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;

    int rowSize = arr1.size();        // 만들어질 행렬의 행 = 앞 행렬의 행
    int columnSize = arr2[0].size();  // 만들어질 행렬의 열 = 뒤 행렬의 열
    
    Init(answer, rowSize, columnSize);  // 만들어질 행렬 사이즈 만큼 공간 확보

    for (int row = 0; row < rowSize; ++row)
    {
        for (int column = 0; column < columnSize; ++column)
        {       
            // 두 행렬의 곱 (x * k) * (k * y) 공통된 k 만큼 반복
            for (int k = 0; k < arr2.size(); ++k)
            {
                answer[row][column] += arr1[row][k] * arr2[k][column];
            }
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> arr1
    {
        { 2, 3, 2 },
        { 4, 2, 4 }, 
        { 3, 1, 4} 
    };
    vector<vector<int>> arr2
    {
        { 5, 4, 3 },
        { 2, 4, 1 },
        { 3, 1, 1}
    };
    
    vector<vector<int>> answer = solution(arr1, arr2);

    for (int i = 0; i < answer.size(); ++i)
    {
        for (int j = 0; j < answer[0].size(); ++j)
        {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
}