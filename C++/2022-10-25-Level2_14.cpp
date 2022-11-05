#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool myCompare(int a, int b)
{
    return a > b;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    // 한 쪽은 오름차순, 한 쪽은 내림차순 
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), myCompare);

    for (int i = 0; i < A.size(); i++)
    {
        answer += A[i] * B[i];
    }

    return answer;
}

int main()
{
    vector<int> A = { 1, 4, 2 };
    vector<int> B = { 5, 4, 4 };

    int answer = solution(A, B);
    cout << answer;

    return 0;
}
