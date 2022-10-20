#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;
    int people[11] = { 0 };
    unordered_set<string> data;

    // 1 2 3

    for (int i = 0; i < words.size(); i++)
    {
        int order = i % n + 1;
        people[order]++;

        int lastSize = 0;
        char lastAlpha = '0';
        char startAlpha = words[i][0];
        if (i > 0)
        {
            lastSize = words[i - 1].size() - 1;
            lastAlpha = words[i - 1][lastSize];
        }

        // 1. �ߺ��� Ű�� �ִ��� �˻� (������ data�� �ش� �ܾ� ����)
        // 2. ���� ���ĺ��� ���� �ܾ��� ������ ���ĺ��� ������ �˻� 
        if (data.find(words[i]) == data.end() && (lastAlpha == startAlpha) || i == 0)
        {
            data.insert(words[i]);
        }
        else
        {
            answer.push_back(order);
            answer.push_back(people[order]);
            return answer;
        }
    }

    // �ƹ��� Ʋ���� �ʾ�����
    answer.clear();
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}

int main()
{ 
    int n = 3;
    vector<string> words = 
    { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };

    vector<int> answer = solution(n, words);
    cout << answer[0] << answer[1];

    return 0;
}