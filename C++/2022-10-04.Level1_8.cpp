#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> solution(vector<int> numbers)
{
    vector<int> answer;
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            int a = numbers[i];
            int b = numbers[j];
            int sum = a + b;
            answer.push_back(sum);
        }
    }

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}

int main()
{
    // �Է�
    vector<int> temp;
    int size = 5; // �Է� ��
    for (int i = 0; i < size; i++)
    {
        int num;
        cin >> num;
        temp.push_back(num);
    }

    temp = solution(temp);

    // ��� ���
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i];
    }


    return 0;
}