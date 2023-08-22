#include <bits/stdc++.h>
using namespace std;
bool vis[1000001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(vis, 0, sizeof(vis));
    string a, b;
    cin >> a >> b;
    int s = a.size();
    int sb = b.size();
    if (sb == 1)
    {
        for (int i = 0; i < s; i++)
        {
            if (a[i] == b[0])
                vis[i] = 1;
        }
    }
    else
    {
        stack<pair<int, int>> st1;
        for (int i = 0; i < s; i++)
        {
            if (a[i] == b[0])
                st1.push({i, 0});
            else if (!st1.empty())
            {
                auto now = st1.top();
                if (b[now.second + 1] == a[i])
                {
                    st1.push({i, now.second + 1});
                    if (now.second + 1 == sb - 1)
                    {
                        for (int k = 0; k < sb; k++)
                        {
                            auto next = st1.top();
                            vis[next.first] = 1;
                            st1.pop();
                        }
                    }
                }
                else
                {
                    while (!st1.empty())
                        st1.pop();
                }
            }
        }
    }
    string ans = "";
    for (int i = 0; i < s; i++)
    {
        if (vis[i])
            continue;
        ans.push_back(a[i]);
    }
    if (ans.empty())
        cout << "FRULA";
    else
        cout << ans;
}
