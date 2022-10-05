#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


bool primeNumSeive(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) { return false; }
    }

    return true;
}

int solution(int n)
{
    int answer = 0;

    for (int i = 2; i <= n; i++)
    {
        if (primeNumSeive(i)) { answer++; }
    }

    return answer;
}

int main()
{
    // ют╥б
    int size;
    cin >> size;

    cout << solution(size);

    return 0;
}