#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++)
    {
        vector<int> temp;
        int from = commands[i][0] - 1;
        int to = commands[i][1];
        int k = commands[i][2] - 1;

        for (int j = 0; j < array.size(); j++)
        {
            if (j >= from && j < to)
            {
                temp.push_back(array[j]);
            }
            else if (j >= to) { break; }
        }

        sort(temp.begin(), temp.end());
        answer.push_back(temp[k]);
    }

    return answer;
}

int main()
{
    // 입력
    vector<int> temp;
    int size = 7; // 입력 수
    for (int i = 0; i < size; i++)
    {
        int num;
        cin >> num;
        temp.push_back(num);
    }

    // 입력 2
    vector<vector<int>> temp2;
    for (int i = 0; i < 3; i++)
    {
        vector<int> temp3;
        for (int j = 0; j < 3; j++)
        {
            int num;
            cin >> num;
            temp3.push_back(num);
        }
        
        temp2.push_back(temp3);
    }

    temp = solution(temp, temp2);

    // 결과 출력
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i];
    }


    return 0;
}