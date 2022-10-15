#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int answer = 0;
    int maxW = 0;
    int maxH = 0;

    // ū ���ڴ� ����, ���� ���ڴ� ���η� �����ϱ�
    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] < sizes[i][1])
        {
            int temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
    }

    // ������ ���� ū ���ο� ���� ���� �̱�
    for (int i = 0; i < sizes.size(); i++)
    {
        if (maxW < sizes[i][0]) { maxW = sizes[i][0]; }
        if (maxH < sizes[i][1]) { maxH = sizes[i][1]; }
    }

    // ���� ������ ũ��
    answer = maxW * maxH;

    return answer;
}

int main()
{
    vector<vector<int>> sizes = 
    { 
        {60, 50},
        {30, 70},
        {60, 30},
        {80, 40},
    };

    int answer = solution(sizes);
    cout << answer;

    return 0;
}