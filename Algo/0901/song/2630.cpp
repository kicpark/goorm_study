#include <bits/stdc++.h>
using namespace std;
int N;
bool arr[129][129];
int count1[2] = {0,};
int yarr[4] = {0,0,1,1};
int xarr[4] = {0,1,0,1};
bool checkarr(int size, int y, int x)
{
    for(int i=y;i<y+size;i++)
    {
        for(int j=x;j<x+size;j++)
        {
            if(arr[i][j] != arr[y][x])
                return false;
        }
    }
    return true;
}
void solve(int size, int y, int x)
{
    bool check = checkarr(size,y,x);
    if(check)
    {
        count1[arr[y][x]]++;
        return ;
    }
    for(int i=0;i<4;i++)
        solve(size/2, y + size*yarr[i]/2, x+size*xarr[i]/2);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>arr[i][j];
        }
    }
    solve(N,1,1);
    cout<<count1[0]<<'\n'<<count1[1];
}
