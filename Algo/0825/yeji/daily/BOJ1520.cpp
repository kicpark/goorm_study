#include <iostream>

using namespace std;
int arr[501][501] = {
    0,
};
int dp[501][501] = {
    0,
};
bool visited[501][501] = {0};
int m, n;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int dfs(int cy, int cx)
{

  if (cy == m && cx == n)
  {
    return 1; // 종점이라면 1을 반환한다.
  };

  if (visited[cy][cx])
  { // 이미 방문한 곳이라면 해당 dp 값을 전달해준다.
    return dp[cy][cx];
  }

  visited[cy][cx] = 1;
  for (int i = 0; i < 4; i++)
  {
    int ny = cy + dy[i];
    int nx = cx + dx[i];
    if (ny > 0 && nx > 0 && ny <= m && nx <= n)
    {
      if (arr[cy][cx] > arr[ny][nx])
      {
        dp[cy][cx] = dp[cy][cx] + dfs(ny, nx);
        
      }
    }
  }
  return dp[cy][cx];
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> m >> n;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      cin >> arr[i][j];

  cout << dfs(1, 1) << '\n';

  return 0;
}