#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool visited[8];
vector<int> weight;

// dfs + ��Ʈ��ŷ
void dfs(vector<vector<int>>& dungeons, int& k, int cnt)
{
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (!visited[i] && k >= dungeons[i][0])
        {
            visited[i] = true;
            k -= dungeons[i][1];
            dfs(dungeons, k, cnt + 1);
            k += dungeons[i][1];
            visited[i] = false;
        }
    }

    // ������ Ž���ϸ� ���� weight ����
    weight.push_back(cnt);
}

int solution(int k, vector<vector<int>> dungeons)
{
    dfs(dungeons, k, 0);
    int answer = *max_element(weight.begin(), weight.end());    // �ִ밪 ���
    return answer;
}
int main()
{
    int k = 80;
    vector<vector<int>> dungeons =
    {
        { 80, 20 },
        { 50, 40 },
        { 30, 10 }
    };

    int answer = solution(k, dungeons);
    cout << answer;

    return 0;
}