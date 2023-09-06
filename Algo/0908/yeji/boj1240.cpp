#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n,m;

vector<pair<int,int> > arr[1001];
bool visited[1001]={false,};
vector<int> answer;


void reset(){
  for(int i=0;i<1001;i++){
    visited[i]=false;
  }
}

void bfs(int start,int end){
  queue<pair<int,int> > q;
  int cost = 0;
  q.push(make_pair(start,cost));
  while(!q.empty()){
    int cur = q.front().first;
    int cost = q.front().second;
    visited[cur]=true;//방문    

    q.pop();

    for(int i=0;i<arr[cur].size();i++){
      int next = arr[cur][i].first;
      int n_cost = arr[cur][i].second;

      if(next==end){
        answer.emplace_back(cost+n_cost);
        return;
      }

      if(!visited[next]){
        visited[next]=true;
        q.push(make_pair(next,cost + n_cost));
      }
    }
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i=0;i<n-1;i++){
    int x,y,cost;
    cin >> x >> y >> cost;
    arr[x].emplace_back(y,cost);
    arr[y].emplace_back(x,cost);
  };

  for(int i=0;i<m;i++){
    int start,end;
    cin >> start >> end;
    bfs(start,end);
    reset();
  }

  for(int i=0;i<answer.size();i++){
    cout << answer[i] << '\n';
  }

}