#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements)
{
    int answer = 0;
    int size = elements.size();
    unordered_set<int> res;

    // i ���� ���̰� ���� 1 ~ size �϶��� �� ���ϱ�
    for (int i = 0; i < size; ++i)
    {
        int sum = 0;
        for (int j = i; j < size + i; ++j)
        {
            // (idx % size) �ϸ� ���� �̾��� �� ó�� ���� ������ ���� ���� �� �� �ִ�.
            sum += elements[j % size];
            res.insert(sum);
        }
    }

    return answer = res.size();
}

int main()
{
    vector<int> elements = { 7,9,1,1,4 };
    int answer = solution(elements);
    cout << answer;

    return 0;
}
