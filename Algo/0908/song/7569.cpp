#include <bits/stdc++.h>
using namespace std;
int arr[101][101][101];
bool vis[101][101][101] = {0,};
int m, n, h;
int harr[6] = {0, 0, 0, 0, 1, -1};
int yarr[6] = {1, -1, 0, 0, 0, 0};
int xarr[6] = {0, 0, 1, -1, 0, 0};
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n >> h;
    queue<tuple<int, int, int>> q1;
    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[k][i][j];
                if (arr[k][i][j] == 1)
                {
                    arr[k][i][j] = 0;
                    q1.push({k, i, j});
                    vis[k][i][j] = 1;
                }
            }
        }
    }
    int h1, y1, x1;
    while (!q1.empty())
    {
        tie(h1, y1, x1) = q1.front();
        q1.pop();
        for (int i = 0; i < 6; i++)
        {
            int h2 = h1 + harr[i];
            int y2 = y1 + yarr[i];
            int x2 = x1 + xarr[i];
            if (h2 < 0 || h2 >= h || y2 < 0 || y2 >= n || x2 < 0 || x2 >= m)
                continue;
            if (arr[h2][y2][x2] == -1)
                continue;
            if (vis[h2][y2][x2])
                continue;
            vis[h2][y2][x2] = 1;
            arr[h2][y2][x2] = arr[h1][y1][x1] + 1;
            q1.push({h2, y2, x2});
        }
    }
    int ans = 0;
    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(arr[k][i][j] == -1)
                    continue;
                if(vis[k][i][j] == 0)
                    ans = 0x3f3f3f3f;
                ans = max(ans, arr[k][i][j]);
            }
        }
    }
    if(ans == 0x3f3f3f3f)
        ans = -1;
    cout<<ans;
}
