#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    int x = n - 1;

    for (int i = 2; i <= x; i++)
    {
        if (n % i == 1)
        {
            answer = i;
            break;
        }
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