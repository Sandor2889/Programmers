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

        // 현재 지점에서 갈수 있는 사방위 확인
        for (int i = 0; i < 4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            // 맵의 범위를 벗어나는지 체크
            if (0 <= nextX && nextX < maps.size() && 0 <= nextY && nextY < maps[0].size())
            {
                // 방문하지 않았고 0이 아니라면 방문하기
                if (!visited[nextX][nextY] && maps[nextX][nextY])
                {
                    q.push({ nextX, nextY });
                    visited[nextX][nextY] = true;
                    maps[nextX][nextY] = maps[x][y] + 1; // 현재 길의 가중치 증가

                    // 목적지 도달시
                    if (nextX == maps.size() - 1 && nextY == maps[0].size() - 1)
                    {
                        return maps[nextX][nextY];
                    }
                }
            }
        }
    }
    // 도달 하지 못할 시
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