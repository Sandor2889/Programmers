#include <iostream>
#include <vector>

using namespace std;

vector<int> answer;

vector<int> solution(vector<int> arr)
{
    int prev = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (prev != arr[i])
        {
            answer.push_back(arr[i]);
        }
        prev = arr[i];
    }

    return answer;
}
int main()
{
    // �Է�
    vector<int> input;
    input.push_back(1);
    input.push_back(1);
    input.push_back(3);
    input.push_back(3);
    input.push_back(0);
    input.push_back(1);
    input.push_back(1);

    answer = solution(input);

    // ��� ���
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}