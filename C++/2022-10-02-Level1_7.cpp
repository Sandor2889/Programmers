#include <iostream>
#include <string>
#include <vector>

using namespace std;


double solution(vector<int> arr) 
{
    double answer = 0;
    
    // ��� ���� ��
    for(int i : arr)
    {
        answer += i;
    }
    
    // ��� ��
    answer /= arr.size();  
    return answer;
}

int main()
{
    // �Է�
    vector<int> temp;
    int size = 4; // �Է� ��
    for (int i = 0; i < size; i++)
    {
        int num;
        cin >> num;
        temp.push_back(num);
    }

    // ��� ���
    cout << solution(temp);

    return 0;
}