#include <iostream>
#include <string>
#include <vector>

using namespace std;


string solution(vector<string> seoul) 
{
    string answer = "";
    string who = "Kim";

    for (int i = 0; i < seoul.size(); i++)
    {
        if (seoul[i] == who)
        {
            answer = "�輭���� " + to_string(i) + "�� �ִ�";
            break;
        }
    }
    return answer;
}
int main()
{
    
    vector<string> temp;
    int people = 2; // �Է� ��

    // �Է�
    for (int i = 0; i < people; i++)
    {
        string name;
        cin >> name;
        temp.push_back(name);
    }

    // ��� ���
    cout << solution(temp);

    return 0;
}