#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string s;
long long int cnt = 0;
int check = 4;
int ans = 1e9;

int palindrome(int cnt, int startIdx, int endIdx)
{
  if (check <= cnt)
  {
    return 1e9;
  }
  if (startIdx >= endIdx)
  {
    check = cnt;
    return cnt;
  }

  if (s[startIdx] == s[endIdx])
  {
    ans = min(palindrome(cnt, startIdx + 1, endIdx - 1), ans);
  }
  else
  {
    ans = min(palindrome(cnt + 1, startIdx, endIdx - 1), ans);
    ans = min(palindrome(cnt + 1, startIdx + 1, endIdx), ans);
  }

  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;
  int ans = 0;
  ans = palindrome(0, 0, s.length() - 1); // count, startpos, endpos
  if (ans == 1e9)
  {
    ans = -1;
  }
  cout << ans << '\n';
}