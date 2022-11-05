#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2)
{
    int answer = 0;
    vector<string> v1;
    vector<string> v2;
    vector<string> intersection;    // ������
    vector<string> sumSet;          // ������

    string temp = "";
    // set1 ���� ���� ���� ����� - ���ڸ��� �˻�
    for (int i = 0; i < str1.size() - 1; ++i)
    {
        if (!isalpha(str1[i]) || !isalpha(str1[i + 1])) { continue; }

        temp += toupper(str1[i]);
        temp += toupper(str1[i + 1]);
        v1.push_back(temp);
        temp = "";
    }

    // set2 ���� ���� ���� ����� - ���ڸ��� �˻�
    for (int i = 0; i < str2.size() - 1; ++i)
    {
        if (!isalpha(str2[i]) || !isalpha(str2[i + 1])) { continue; }

        temp += toupper(str2[i]);
        temp += toupper(str2[i + 1]);
        v2.push_back(temp);
        temp = "";
    }

    // ������ - v2���� �������� ã���� �������� �����
    for (int i = 0; i < v1.size(); ++i)
    {
        for (int j = 0; j < v2.size(); ++j)
        {
            if (v1[i] == v2[j])
            {
                intersection.push_back(v1[i]);
                v2[j] = "";
                break;
            }
        }
    }

    // ������ - v1 + v2(��������)
    for (int i = 0; i < v1.size(); ++i)
    {
        sumSet.push_back(v1[i]);
    }
    for (int i = 0; i < v2.size(); ++i)
    {
        if (v2[i] == "") { continue; }
        sumSet.push_back(v2[i]);
    }

    // �������� ���� ���
    if (sumSet.size() == 0) { return 65536; }

    float round = (float)intersection.size() / sumSet.size();
    answer = round * 65536;

    return answer;
}

int main()
{
    string str1 = { "aa1+aa2" };
    string str2 = { "AAAA12" };

    cout << solution(str1, str2);

    return 0;
}