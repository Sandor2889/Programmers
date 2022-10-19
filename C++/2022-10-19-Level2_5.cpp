#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    unordered_map<string, int> kinds;
    int answer = 1;

    // �ǻ��� �������� ����� �ֱ�
    for (int i = 0; i < clothes.size(); i++)
    {
        // key�� ���ٸ� �߰�
        if (kinds.find(clothes[i][1]) == kinds.end())
        {
            kinds.insert({ clothes[i][1], 1 });
        }
        // key�� �̹� �ִٸ� ���� ���� 
        else
        {
            kinds[clothes[i][1]]++;
        }
    }

    // �� ������ ���� ���� (x + a)(x + b)(x + n)... - 1
    // -1 �� (�ǻ� ������ x�� �¼��� ���� ���� ���ǹ� �ϱ� ����)
    for (auto it = kinds.begin(); it != kinds.end(); it++)
    {
        answer *= (1 + it->second);
    }

    return answer - 1;
}

int main()
{ 
    vector<vector<string>> clothes
    {
        { "yellow_hat", "headgear"},
        { "blue_sunglasses", "eyewear"},
        { "green_turban", "headgear"}
    };

    int answer = solution(clothes);
    cout << answer;

    return 0;
}