#include <iostream>
#include <string>
#include <vector>

using namespace std;

// �� ���� �ִ� ����� ���ϱ� (��Ŭ���� ȣ����)
int gcd(int a, int b)
{
    int temp = 0;
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// �� ���� �ּ� ����� ���ϱ�
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

// `�ּ� ������� (a * b) / �ִ� �����` ��� ����� ���� �ִ�.
int solution(vector<int> arr)
{
    int answer = 0;

    // �� ���� ���� �ּ� ������� ���������� ������ �����Ѵ�.
    for (int i = 1; i < arr.size(); ++i)
    {
        arr[i] = lcm(arr[i - 1], arr[i]); // arr[i]�� �ּ� ����� ������ ���� �����
        answer = arr[i];
    }

    return answer;
}

int main()
{
    vector<int> arr = { 2, 6, 8, 14 };
    int answer = solution(arr);
    cout << answer;

    return 0;
}