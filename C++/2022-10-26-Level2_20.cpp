#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 두 수의 최대 공약수 구하기 (유클리드 호제법)
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

// 두 수의 최소 공배수 구하기
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

// `최소 공배수는 (a * b) / 최대 공약수` 라는 증명된 식이 있다.
int solution(vector<int> arr)
{
    int answer = 0;

    // 두 수에 대한 최소 공배수를 순차적으로 여러번 시행한다.
    for (int i = 1; i < arr.size(); ++i)
    {
        arr[i] = lcm(arr[i - 1], arr[i]); // arr[i]에 최소 공배수 값으로 덮어 씌우기
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