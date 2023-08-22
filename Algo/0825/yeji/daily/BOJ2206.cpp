#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[1001][1001][2] = {
    0,
};
int map[1001][1001] = {
    0,
};
int n, m;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int bfs()
{
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));

    visited[0][0][0]=true;
    visited[0][0][1]=true;

    while (!q.empty())
    {
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int visit = q.front().second.first;
        int cost = q.front().second.second;

        q.pop();

        if (cy == n - 1 && cx == m - 1)
        {
            return cost;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny >= 0 && nx >= 0 && ny < n && nx < m && !visited[ny][nx][visit])
            {
                if (map[ny][nx] == 0 && visit == 0)
                {
                    visited[ny][nx][visit] = true;
                    q.push(make_pair(make_pair(ny, nx), make_pair(visit, cost + 1)));
                }
                else if (map[ny][nx] == 0 && visit == 1)
                {
                    visited[ny][nx][visit] = true;
                    q.push(make_pair(make_pair(ny, nx), make_pair(visit, cost + 1)));
                }
                else if (map[ny][nx] == 1 && visit == 0)
                {
                    visited[ny][nx][visit] = true;
                    q.push(make_pair(make_pair(ny, nx), make_pair(1, cost + 1)));
                }
                else if (map[ny][nx] == 1 && visit == 1)
                {
                    //visited[ny][nx][visit] = true;
                }
            }
        }
    }
    return -1;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
        {
            map[i][j] = str[j] - '0';
        }
    }

    int answer = bfs();
    cout << answer << '\n';
}