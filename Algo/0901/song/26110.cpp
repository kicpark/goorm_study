#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
string a;
int count1 = 4;
int go(int count, int stpos, int enpos)
{
    if (count >= count1)
        return INF;

    if (stpos >= enpos)
    {
        count1 = count;
        return count;
    }

    int ans = INF;

    if (a[stpos] == a[enpos])
        ans = min(go(count, stpos + 1, enpos - 1), ans);
    else
    {
        ans = min(go(count + 1, stpos + 1, enpos), ans);
        ans = min(go(count + 1, stpos, enpos - 1), ans);
    }
    return ans;
}
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a;
    int ans = go(0, 0, a.size() - 1);
    if (ans == INF)
        ans = -1;
    cout << ans;
}
