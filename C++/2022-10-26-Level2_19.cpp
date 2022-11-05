#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
    // ������ �ִ� ���Կ� �ּ� ���Ը� ��� �¿��.
    int answer = 0;

    // �������� ����
    sort(people.begin(), people.end());

    // ū ���� ���� ����
    int minIdx = 0;
    for (int i = people.size() - 1; i != minIdx - 1; i--)
    {
        ++answer; // ��Ʈ �� ����

        if (i == minIdx) { break; }  // ���� ���� ����Ű�� �Ǹ� ����

        int max = people[i];
        int min = people[minIdx];

        // �ּ� ���԰� (limit - max) ���� �۰ų� ���� �� ���� Ȯ��
        if (limit - max >= min) { minIdx++; }
    }

    return answer;
}

int main()
{
    vector<int> people = { 70, 70, 60, 40, 40 };
    int limit = 110;

    int answer = solution(people, limit);
    cout << answer;

    return 0;
}
