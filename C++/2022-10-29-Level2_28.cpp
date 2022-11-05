#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 2������ 1�������� ��ȯ
// 1���� idx = row * n + column
// 1������ �� = row�� column �� ���� ū ���� + 1
// row = i/n, column = i%n
vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;

    // left�� right ������ ���� answer�� push
    for (long long i = left; i <= right; ++i)
    {
        int row = i / n;
        int column = i % n;
        int bigger = 0;

        if (row >= column)
        {
            bigger = i / n + 1;
        }
        else
        {
            bigger = i % n + 1;
        }

        answer.push_back(bigger);
    }

    return answer;
}

/*
1����   2����     ��    [i/n][i%n]
0 1 2  00 01 02  1 2 3  00 01 02
3 4 5  10 11 12  2 2 3  10 11 12
6 7 8  20 21 22  3 3 3  20 21 22
*/

int main() 
{
    vector<int> answer = solution(3, 2, 5);
    
    for (int i : answer) { cout << i << ' '; }

    return 0;
}


