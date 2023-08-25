#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int N;
    cin>>N;
    stack<pair<long long, int>> st1;
    st1.push({100000005, 0});
    int h;
    for(int i=0;i<N;i++)
    {
        cin>>h;
        while(st1.top().first<h)
            st1.pop();
        cout<<st1.top().second<<' ';
        st1.push({h,i+1});
    }
}
