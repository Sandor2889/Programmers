#include <iostream>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

int visited[MAX][MAX];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int bfs(vector<vector<int>> maps)
{
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    visited[0][0] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // ���� �������� ���� �ִ� ����� Ȯ��
        for (int i = 0; i < 4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            // ���� ������ ������� üũ
            if (0 <= nextX && nextX < maps.size() && 0 <= nextY && nextY < maps[0].size())
            {
                // �湮���� �ʾҰ� 0�� �ƴ϶�� �湮�ϱ�
                if (!visited[nextX][nextY] && maps[nextX][nextY])
                {
                    q.push({ nextX, nextY });
                    visited[nextX][nextY] = true;
                    maps[nextX][nextY] = maps[x][y] + 1; // ���� ���� ����ġ ����

                    // ������ ���޽�
                    if (nextX == maps.size() - 1 && nextY == maps[0].size() - 1)
                    {
                        return maps[nextX][nextY];
                    }
                }
            }
        }
    }
    // ���� ���� ���� ��
    return -1;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    return bfs(maps);
}

int main()
{ 
    vector<vector<int>> maps =
    {
        {1, 0, 1, 1, 1 },
        {1, 0, 1, 0, 1 },
        {1, 0, 1, 1, 1 },
        {1, 1, 1, 0, 1 }
        //{0, 0, 0, 0, 1 }
    };

    int answer = solution(maps);
    cout << answer;

    return 0;
}