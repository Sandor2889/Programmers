#include <iostream>
#include <string>
#include <unordered_map>

#define MAX 11
#define ZERO 5

using namespace std;

bool visited[10101010];  // ���� ���� �湮 (���x,y + ����x,y)

int solution(string dirs)
{
    int answer = 0;

    pair<int, int> coord = { ZERO, ZERO };    // x,y ��ǥ (500,500 ����)
    // �������κ��� �̵�
    // ���� ���� �湮 ó�� ��߰� ���������� ����� �湮 ó��
    for (int i = 0; i < dirs.size(); ++i)
    {
        // ��� ���� (sum ������, reverse ������)
        int sum = coord.first * 1000000 + coord.second * 10000;
        int reverse = coord.first * 100 + coord.second;

        if (dirs[i] == 'U' && coord.second < ZERO * 2) { coord.second += 1; }
        else if (dirs[i] == 'D' && coord.second > 0) { coord.second -= 1; }
        else if (dirs[i] == 'R' && coord.first < ZERO * 2) { coord.first += 1; }
        else if (dirs[i] == 'L' && coord.first > 0) { coord.first -= 1; }
        else { continue; }

        // ���� ����
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