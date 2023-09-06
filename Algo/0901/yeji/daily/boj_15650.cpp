#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m;
bool visited[9];
int arr[9];

stack<int> s;

void BT(int index, int cnt)
{

  // 종료조건
  if (cnt == m)
  {
    for (int i = 0; i < m; i++)
    {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }
  else
  {
    for (int i = index; i <= n; i++)
    {
      if (!visited[i])
      {
        visited[i] = true;
        arr[cnt] = i;
        
        BT(i + 1, cnt + 1);
        //cout << "cnt:" << cnt << "i:" << i << endl;
        visited[i] = false;
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  BT(1, 0);
}