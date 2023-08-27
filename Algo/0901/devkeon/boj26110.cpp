#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string seq;
int ans;

void backtracking(int k, int left, int right){
  if (k > 3)  return;
  if (left >= right){
    ans = min(ans, k);
    return;
  }
  if (seq[left] != seq[right]){
    backtracking(k + 1, left + 1, right);
    backtracking(k + 1, left, right - 1);
  }
  else  backtracking(k, left + 1, right - 1);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> seq;
  ans = 4;
  backtracking(0, 0, seq.length() - 1);
  if (ans == 4){
    cout << -1;
  }
  else{
    cout << ans;
  }
}
