#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int box[101][101][101]={0,};
int visited[101][101][101]={false,};
int dy[6] = {0,0,-1,1,0,0};
int dx[6] = {-1,1,0,0,0,0};
int dl[6] = {0,0,0,0,1,-1}; // up,down
int n, m, h;
bool flag = true; // loop stop
int days = -1e9;
queue<pair<int, pair<int, int> > > q;

void bfs(){
  
  while(!q.empty()){
    int cl = q.front().first;
    int cy = q.front().second.first;
    int cx = q.front().second.second;

    
    //visited[cl][cy][cx]=true; //delete


    q.pop();
    //qq.pop();

    int nl,ny,nx;
    for(int i=0;i<6;i++){
      nl = cl+dl[i];
      ny = cy+dy[i];
      nx = cx+dx[i];
      if(nl>=0 && nl<h && ny>=0 && nx>=0 && ny<m && nx<=n && !visited[nl][ny][nx]){
        if(box[nl][ny][nx]==0){
          visited[nl][ny][nx] = true;
          box[nl][ny][nx]=box[cl][cy][cx]+1;
          q.push(make_pair(nl,make_pair(ny,nx)));
        }
      }
    }
  };
};





int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> h;

  for(int a=0;a<h;a++){
    for(int b=0;b<m;b++){
      for(int c=0;c<n;c++){
        cin >> box[a][b][c];
        if(box[a][b][c]==1){
          q.push(make_pair(a,make_pair(b,c)));
          visited[a][b][c]=true;
        }
      }
    }
  }


  bfs();

  

  for(int a=0;a<h;a++){
    for(int b=0;b<m;b++){
      for(int c=0;c<n;c++){
        if(box[a][b][c]==0){
          cout << -1 << '\n';
        }else{
          days = days < box[a][b][c] ? box[a][b][c] : days;
        }
      }
    }
  }

  cout << days-1 << '\n';

  return 0;
};