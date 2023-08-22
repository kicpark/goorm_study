#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> v1(n);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq1;
    for(int i=0;i<n;i++)
    {
        cin>>v1[i];
        while(!pq1.empty() && pq1.top().second <= i-m)
            pq1.pop();
        pq1.push({v1[i],i});
        cout<<pq1.top().first<<' ';
    }
}
