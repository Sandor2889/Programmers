#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) 
{
    string answer = "";
    string temp;
    temp = new_id;
    char prev = '0';

    // 7�ܰ� ����
    int phase = 1;
    int size = temp.size();
    while (phase < 8)
    {
        switch (phase)
        {
        case 1: // �빮�ڸ� �ҹ��ڷ� ġȯ
            for (int i = 0; i < size; i++)
            {
                if (isupper(temp[i]))
                {
                    temp[i] += 32;
                }
            }
            break;
        case 2: // ����, �ҹ���, �빮�� '-', '_', '.'�� ������ ������ ����
            for (int i = 0; i < size; i++)
            {
                if ((temp[i] >= '0' && temp[i] <= '9') || isalpha(temp[i]) ||
                    temp[i] == '-' || temp[i] == '_' || temp[i] == '.')
                {
                    continue;
                }
                else
                {
                    // ���� �� �ε��� �� ĭ�� ����
                    for (int k = i; k < size; k++)
                    {
                        temp[k] = temp[k + 1];
                    }
                    size--;
                    i--;
                }
            }
            break;
        case 3: // ���ӵ� ��ħǥ'.'�� �ϳ��� ġȯ
            for (int i = 0; i < size; i++)
            {
                if (prev == '.' && temp[i] == '.')
                {
                    // ���� �� �ε��� �� ĭ�� ����
                    for (int k = i; k < size; k++)
                    {
                        temp[k] = temp[k + 1];
                    }
                    size--;
                    i--;
                }

                prev = temp[i];
            }
            break;
        case 4: // ó���� ���� '.'�̶�� ����
            // ó���� ������
            if (temp[0] == '.')
            {
                // ���� �� �ε��� �� ĭ�� ����
                for (int k = 0; k < size; k++)
                {
                    temp[k] = temp[k + 1];
                }
                size--;
            }
            // �������� ������
            if (temp[size - 1] == '.') { size--; }
            break;
        case 5: // �� ���ڿ��̸� 'a' ����
            if (size == 0) { temp[0] = 'a'; size++; }
            break;
        case 6: // ���� 16�� �̻� ����
            if (size > 15) { size = 15; }
            // ������ ���� �� �������� '.' �̶�� ����
            if (temp[size - 1] == '.') { size--; }
            break;
        case 7:
            if (size <= 2)
            {
                for (int i = size; i < 3; i++)
                {
                    temp[i] = temp[size - 1];
                    size++;
                }
            }
            break;
        }

        phase++;
    }

    // �����Ⱚ�� ������ �������� answer�� �ű��
    for (int i = 0; i < size; i++)
    {
        answer += temp[i];
    }
    return answer;
}

int main()
{
    string st = "...!@BaT#*..y.abcdefghijklm";

    st = solution(st);

    for (int i = 0; i < st.size(); i++)
    {
        cout << st[i];
    }

    return 0;
}