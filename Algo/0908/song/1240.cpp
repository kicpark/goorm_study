#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<pair<int,int>>> &tree, vector<tuple<int,int,int>> &p, vector<bool> &vis,int now, int depth)
{
    for(auto next : tree[now])
    {
        if(vis[next.first])
            continue;
        vis[next.first] = 1;
        p[next.first] = {now, next.second, depth+1};
        dfs(tree,p,vis,next.first,depth+1);
    }
}
int solve(vector<tuple<int,int,int>> &p, int u, int v)
{
    int sum = 0;
    auto u1 = p[u];
    auto v1 = p[v];
    int pu, du, udepth;
    int pv, dv, vdepth;
    tie(pu,du,udepth) = u1;
    tie(pv, dv, vdepth) = v1;
    if(udepth < vdepth)
        swap(u,v);
    tie(pu,du,udepth) = p[u];
    tie(pv, dv, vdepth) = p[v];
    while(udepth != vdepth)
    {
        sum += du;
        u = pu;
        auto u1 = p[u];
        tie(pu,du,udepth) = u1;
    }
    while(u != v)
    {
        u = pu;
        v = pv;
        sum += du;
        sum += dv;
        tie(pu,du,udepth) = p[u];
        tie(pv,dv,vdepth) = p[v];
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> tree(n+1);
    vector<tuple<int,int,int>> p(n+1);
    vector<bool> vis(n+1,0);
    for(int i=0;i<n-1;i++)
    {
        int u,v,d;
        cin>>u>>v>>d;
        tree[u].push_back({v,d});
        tree[v].push_back({u,d});
    }
    vis[1] = 1;
    p[1] = {0,0,0};
    dfs(tree, p,vis, 1,0);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        cout<<solve(p,u,v)<<'\n';
    }
}
