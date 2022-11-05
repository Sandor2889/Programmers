#include <iostream>
#include<string>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int open = 0;

    // '(' �� open�� �����ϰ� ')' �� open�� ���ҽ�Ų��.
    // open�� 0�� �Ǿ�� �ùٸ��� ¦������ ���̴�.
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')    // ')' �̰� '(' ���� ��� false ��ȯ�ϰ� ����
        {
            if (open == 0) { return false; }
            else { open -= 1; }
        }
        else  // '(' �̸� ���� ���� 
        {
            open++;
        }
    }

    // open ��ȣ�� ���� ¦(close)�� �������� ������ false
    if (open != 0) { answer = false; }

    return answer;
}

int main()
{
    string s = { "(())()" };

    bool answer = solution(s);
    cout << answer;

    return 0;
}

