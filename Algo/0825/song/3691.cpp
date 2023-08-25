#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
void solve()
{
    cin >> n >> m;
    map<string, int> map1;
    vector<priority_queue<pair<int,int>>> v1;
    priority_queue<pair<int,int>> pq1;
    priority_queue<tuple<int,int,int>> p1;
    for(int i=0;i<n;i++)
    {
        string u,v;
        int a1,a2;
        cin>>u>>v>>a1>>a2;
        if(map1.find(u) == map1.end())
        {
            map1[u] = map1.size();
            v1.push_back(pq1);
            v1[map1[u]].push({-a1,a2});
        }
        else
            v1[map1[u]].push({-a1,a2});
    }
    int sum = 0;
    int p=0;
    int ans = 0;
    for(int i=0;i<map1.size();i++)
    {
        auto now = v1[i].top();
        sum += -now.first; 
        p += now.second; 
        v1[i].pop();
        p1.push({-now.second, -now.first, i});
    }
    int minp,v, now;
    while(sum<=m && !p1.empty())
    {
        tie(minp,v,now) = p1.top();
        p1.pop();
        ans = max(ans, minp);

        while(!v1[now].empty() && v1[now].top().second <= -minp)
            v1[now].pop();

        if(v1[now].empty())
            break;

        int nowp = v1[now].top().second;
        int nowv = -v1[now].top().first;

        sum -= v;
        sum += nowv;

        p1.push({-nowp,nowv ,now});
    }
    cout<<-minp<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
}
/*
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
void solve()
{
    cin >> n >> m;
    map<string, map<string, pair<int, int>>> computa;
    for (int i = 0; i < n; i++)
    {
        string u, v;
        int a1, a2;
        cin >> u >> v >> a1 >> a2;
        computa[u][v] = {a2, a1};
    }
    map<string, priority_queue<pair<int, int>>> ans;
    priority_queue<tuple<int, int, string>> now1;
    map<string, int> check;
    for (auto now : computa)
    {
        for (auto next : computa[now.first])
        {
            ans[now.first].push({-next.second.second, next.second.first});
        }
        check[now.first] = 0;
    }
    int sum = 0;
    int max1 = INT_MAX;
    for (auto now : ans)
    {
        sum += -now.second.top().first;
        max1 = min(max1, now.second.top().second);
        now1.push({-now.second.top().second, -now.second.top().first, now.first});
    }

    string nowstr;
    int p, v;
    while (sum<=m && !now1.empty())
    {
        tie(v, p, nowstr) = now1.top();
        now1.pop();
        max1 = max(-1 * v, max1);                                          
        int now2 = p;
        while(!ans[nowstr].empty() && -v>=ans[nowstr].top().second)
            ans[nowstr].pop();
        if (ans[nowstr].empty())
            break;
        sum -= now2;
        sum += -ans[nowstr].top().first;
        now1.push({-ans[nowstr].top().second, -ans[nowstr].top().first, nowstr});
    }
    cout << max1<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
}
*/
