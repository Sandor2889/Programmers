#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n)
{
    int answer = 0;
    int origin = n;

    // n의 이진변환 했을 때 1의 수
    int oneCnt = 1;
    while (origin > 0)
    {
        int temp = origin % 2;
        if (temp == 1) { oneCnt++; }   // 나머지가 1이면 카운팅
        origin /= 2;
    }

    int loop = 0;   // 반복 수
    while (true)
    {
        // 1씩 증가하며 이진화 과정에서 1의 수 찾기
        loop++;
        origin = n;
        origin += loop;
        int target = origin;
        int tempOneCnt = 1;

        while (origin > 0)
        {
            int temp = origin % 2;
            if (temp == 1) { tempOneCnt++; }
            origin /= 2;
        }

        // 1의 수가 같은 것을 찾으면 중단
        if (tempOneCnt == oneCnt) { answer = target; break; }
    }

    return answer;
}

int main()
{
    int n = 15;
    int answer = solution(n);
    cout << answer;

    return 0;
}
