#include <iostream>
#include <string>
#include <vector>

using namespace std;


double solution(vector<int> arr) 
{
    double answer = 0;
    
    // 모든 수의 합
    for(int i : arr)
    {
        answer += i;
    }
    
    // 평균 값
    answer /= arr.size();  
    return answer;
}

int main()
{
    // 입력
    vector<int> temp;
    int size = 4; // 입력 수
    for (int i = 0; i < size; i++)
    {
        int num;
        cin >> num;
        temp.push_back(num);
    }

    // 결과 출력
    cout << solution(temp);

    return 0;
}