#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool myCompare(int a, int b)
{
    return a > b;
}

int solution(vector<int> order)
{
    int answer = 0;

    stack<int> sub;
    vector<int> main = order;
    sort(main.begin(), main.end(), myCompare);


    // target     //  main         // sub     // result
    // 4          (5 4 3 2 1)      ()
    //            (5 4 3 2)        (1)        1 -> sub
    //            (5 4 3)          (1 2)      2 -> sub
    //            (5 4)            (1 2 3)    3 -> sub
    //            (5)              (1 2 3)    4 -> truck  
    // 3          (5)              (1 2)      3 -> truck


    for (int target = 0; target < order.size(); ++target)
    {
        while(true)
        {
            // ���� ��Ʈ�� ù ��° �ù� (�׻� ������Ʈ���� Ȯ���ϱ�)
            if (!sub.empty())
            {
                if (order[target] == sub.top())
                {
                    ++answer;
                    sub.pop();
                    break;
                }
            }

            // ���� ��Ʈ�� ù ��° �ù�
            if (!main.empty())
            {
                if (order[target] == main.back())
                {
                    ++answer;
                    main.pop_back();
                    break;
                }
                else
                {
                    sub.push(main.back());
                    main.pop_back();
                    continue;
                }
            }

            // �ƹ� ���ǿ� ���� ���ϸ� ����
            return answer;
        }
    }

    return answer;
}

int main()
{
    vector<int> order = { 4, 3, 1, 2, 5 };
    int answer = solution(order);
    cout << answer;

    return 0;
}