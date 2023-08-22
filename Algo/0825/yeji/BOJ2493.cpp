#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int answer[500001] = {
    0,
};
int main()
{
    int n;
    cin >> n;

    stack<pair<int, int>> s;   // main stack
    stack<pair<int, int>> sub; // sub stack
    vector<pair<int, int>> v;

    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        v.emplace_back(num, i);
    }

    for (int i = n; i >= 0; i--)
    {
        s.push(make_pair(v[i].first, v[i].second));
    }

    while (!s.empty())
    {
        if (sub.empty())
        {
            sub.push(s.top());
            answer[s.top().second] = 0;
            s.pop();
        };
        // 앞 숫자가 더 클 경우
        if (s.top().first < sub.top().first)
        {
            answer[s.top().second] = sub.top().second;
            sub.push(s.top());
            s.pop();
            // 앞 숫자가 더 작을 경우
        }
        else if (s.top().first > sub.top().first)
        {
            bool flag = false;
            while (!sub.empty())
            {
                if (s.top().first < sub.top().first)
                {
                    answer[s.top().second] = sub.top().second;
                    flag = true;
                    break;
                }
                else if (s.top().first > sub.top().first)
                {
                    sub.pop();
                    flag = false;
                }
            }
            if (!flag)
            {
                answer[s.top().second] = 0;
            }
            sub.push(s.top());
            s.pop();
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << answer[i] << " ";
    }
    cout << '\n';
}