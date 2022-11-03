#include <iostream>
#include <string>
#include <unordered_map>

#define MAX 11
#define ZERO 5

using namespace std;

bool visited[10101010];  // 선에 대한 방문 (출발x,y + 도착x,y)

int solution(string dirs)
{
    int answer = 0;

    pair<int, int> coord = { ZERO, ZERO };    // x,y 좌표 (500,500 원점)
    // 원점으로부터 이동
    // 선에 대한 방문 처리 출발과 도착지간의 양방향 방문 처리
    for (int i = 0; i < dirs.size(); ++i)
    {
        // 출발 지점 (sum 정방향, reverse 역방향)
        int sum = coord.first * 1000000 + coord.second * 10000;
        int reverse = coord.first * 100 + coord.second;

        if (dirs[i] == 'U' && coord.second < ZERO * 2) { coord.second += 1; }
        else if (dirs[i] == 'D' && coord.second > 0) { coord.second -= 1; }
        else if (dirs[i] == 'R' && coord.first < ZERO * 2) { coord.first += 1; }
        else if (dirs[i] == 'L' && coord.first > 0) { coord.first -= 1; }
        else { continue; }

        // 도착 지점
        sum += coord.first * 100 + coord.second;
        reverse += coord.first * 1000000 + coord.second * 10000;

        if (visited[sum] && visited[reverse]) { continue; }

        visited[sum] = true;
        visited[reverse] = true;
        ++answer;
    }

    return answer;
}

int main()
{
    string dirs = "ULURRDLLU";
    int answer = solution(dirs);

    cout << answer;

    return 0;
}