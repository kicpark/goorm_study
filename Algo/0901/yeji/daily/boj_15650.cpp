#include <iostream>
#include <vector>

using namespace std;
int n,m;
bool visited[9]={false,};


void bt(int idx,int cnt){

  if(cnt==m){
    cout << cnt << endl;
    for(int i=1;i<=n;i++){
      if(visited[i]){
        cout << i << " ";
      }
    }
    cout << '\n';
    return; // 끝내고
  }else{
    for(int i=idx;i<=n;i++){
      if(!visited[i]){
        visited[i]=true;
        bt(idx+1,cnt+1);
        visited[i]=false;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin >> n >> m;

  bt(1,1);



}