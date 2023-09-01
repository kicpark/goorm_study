#include <iostream>
#include <vector>
using namespace std;

int map[129][129] = {
    0,
};
int n = 0;
int blue = 0;
int white = 0;

void input(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> map[i][j];
    }
  }
};

void recur(int y, int x, int size)
{
  int start = map[y][x];
  bool flag = true;
  for (int i = y; i < y + size; i++)
  {
    for (int j = x; j < x + size; j++)
    {
      if (start != map[i][j])
      {
        flag = false;
        break;
      }
    }
  };

  if (!flag)
  {
    recur(y, x, size / 2);
    recur(y + size / 2, x, size / 2);
    recur(y + size / 2, x + size / 2, size / 2);
    recur(y, x + size / 2, size / 2);
  }
  else if (start == 1)
  {
    blue++;
  }
  else if (start == 0)
  {
    white++;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;

  input(n);
  recur(0, 0, n);

  cout << white << '\n'
       << blue << '\n';
}