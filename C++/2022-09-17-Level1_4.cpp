#include <iostream>
#include <string>

using namespace std;

string solution(int num) 
{
    string answer = "";
    int temp = num % 2;

    if (temp == 0)
    {
        answer = "Even";
    }
    else
    {
        answer = "Odd";
    }

    return answer;
}

int main()
{
    // �Է�
    int input;
    cin >> input;

    // ��� ���
    cout << solution(input);

    return 0;
}