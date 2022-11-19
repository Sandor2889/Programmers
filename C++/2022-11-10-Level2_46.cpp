#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer, cnt;

// ����Ž�� (��� ���ڿ� ���� ������ �ű�)
void dfs(string curr, string target, char alpha[])
{
    if (curr == target) { answer = cnt; }   // Ÿ�ٰ� �������� answer�� ����
    if (curr.length() > 5) { return; }
    
    ++cnt;
    for (int i = 0; i < 5; ++i)
    {
        dfs(curr + alpha[i], target, alpha);
    }
}

int solution(string word)
{
    char alpha[5] = { 'A', 'E', 'I', 'O', 'U' };
    dfs("", word, alpha);
    return answer;
}

int main()
{
    string word = "EIO";
    answer = solution(word);
    cout << answer;

    return 0;
}