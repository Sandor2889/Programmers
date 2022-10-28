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

    int rowSize = arr1.size();        // ������� ����� �� = �� ����� ��
    int columnSize = arr2[0].size();  // ������� ����� �� = �� ����� ��
    
    Init(answer, rowSize, columnSize);  // ������� ��� ������ ��ŭ ���� Ȯ��

    for (int row = 0; row < rowSize; ++row)
    {
        for (int column = 0; column < columnSize; ++column)
        {       
            // �� ����� �� (x * k) * (k * y) ����� k ��ŭ �ݺ�
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