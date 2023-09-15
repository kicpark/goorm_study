#include <bits/stdc++.h>
using namespace std;
int n, m, k; // m : 상어,k : 냄새
int arr[21][21];
vector<vector<pair<int, int>>> map1;
const int INF = 1001;
struct shark
{
    /* data */
    int y;
    int x;
    int dir;
    bool alive = true;
    vector<vector<int>> n_dir;
};
int yarr[4] = {-1, 1, 0, 0};
int xarr[4] = {0, 0, -1, 1};
vector<shark> sharks;
vector<tuple<int,int,int>> next_S;
void think_difference(int y, int x, int dir, int i)
{
    for (auto nextdir : sharks[i].n_dir[dir])
    {
        int y1 = y + yarr[nextdir];
        int x1 = x + xarr[nextdir];
        if (y1 < 0 || y1 >= n || x1 < 0 || x1 >= n)
            continue;
        if (map1[y1][x1].first != 0)
            continue;

        sharks[i].y = y1;
        sharks[i].x = x1;
        sharks[i].dir = nextdir;
        if (arr[y1][x1] != -1)
        {
            int die = arr[y1][x1];
            sharks[die].alive = false;
            sharks[die].y = 500;
            sharks[die].x = 500;
        }
        arr[y1][x1] = i;
        next_S.push_back({i,y1,x1});
        return;
    }
    for (auto nextdir : sharks[i].n_dir[dir])
    {
        int y1 = y + yarr[nextdir];
        int x1 = x + xarr[nextdir];
        if (y1 < 0 || y1 >= n || x1 < 0 || x1 >= n)
            continue;
        if (map1[y1][x1].first != 0 && map1[y1][x1].second != i)
            continue;

        sharks[i].y = y1;
        sharks[i].x = x1;
        sharks[i].dir = nextdir;
        if (arr[y1][x1] != -1)
        {
            int die = arr[y1][x1];
            sharks[die].alive = false;
            sharks[die].y = 500;
            sharks[die].x = 500;
        }
        arr[y1][x1] = i;
        next_S.push_back({i,y1,x1});
        return;
    }
}

void move()
{
    int n1 = sharks.size();
    int y, x, dir;
    for (int i = n1 - 1; i >= 0; i--)
    {
        if (!sharks[i].alive)
            continue;
        y = sharks[i].y;
        x = sharks[i].x;
        dir = sharks[i].dir;
        arr[y][x] = -1;
        think_difference(y, x, dir, i);
    }
}
void del()
{
    int now, y,x;
    for(auto next : next_S)
    {
        tie(now,y,x) = next;
        map1[y][x] = {k+1,now};
    }
    next_S.clear();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(map1[i][j].first == 0)
                continue;
            map1[i][j].first--;
            if(map1[i][j].first <= 0)
            {
                map1[i][j].first = 0;
                map1[i][j].second = -1;
            }
        }
    }
}
int go(int cnt)
{
    if (cnt == INF)
        return -1;
    int s_cnt = 0;
    for (int i = 0; i < sharks.size(); i++)
    {
        if (sharks[i].alive)
            s_cnt++;
    }
    if (s_cnt == 1)
        return cnt;
    move();
    del();
    return go(cnt + 1);
}
int main()
{
    cin >> n >> m >> k;
    vector<pair<int,int>> v1(n,make_pair(0,-1));
    map1.resize(n,v1);
    sharks.resize(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            arr[i][j]--;
            if (arr[i][j] == -1)
                continue;
            int now = arr[i][j];
            sharks[now].y = i;
            sharks[now].x = j;
            map1[i][j] = {k, now};
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> sharks[i].dir;
        sharks[i].dir -= 1;
    }
    for (int i = 0; i < m; i++)
    {
        vector<vector<int>> dirs;
        for (int j = 0; j < 4; j++)
        {
            vector<int> v1;
            for (int k = 0; k < 4; k++)
            {
                int u;
                cin >> u;
                v1.push_back(u - 1);
            }
            dirs.push_back(v1);
        }
        sharks[i].n_dir = dirs;
    }
    int ans = go(0);
    cout << ans;
}
