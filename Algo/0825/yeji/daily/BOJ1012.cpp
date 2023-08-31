#include <iostream>
#include <vector>
#include <stack>
#include <memory.h>

using namespace std;

int map[51][51]={0,};
bool visited[51][51]={false,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
int n,m;

stack<pair<int,int> > s;
int dfs(){
    int cy = s.top().first;
    int cx = s.top().second;
    s.pop();

    visited[cy][cx]=true; // 방문체크

    for(int i =0;i<4;i++){
        int ny = cy+dy[i];
        int nx = cx+dx[i];

        if(ny>=0 && nx>=0 && ny<m && nx<n){
            if(!visited[ny][nx] && map[ny][nx]==1){
                s.push(make_pair(ny,nx));
                dfs();

            }
        }
    }
    return 1;


}



void reset(){
    for(int i=0;i<51;i++){
        memset(visited[i],false,sizeof(visited[i])*51);
    }
    for(int i=0;i<51;i++){
        for(int j=0;j<51;j++){
            map[i][j]=0;
        }
    }
}


int main(){
    int T;
    cin >> T;
    vector<int> answer;

    for(int i=0;i<T;i++){
        int line;
        cin >> n >> m >> line;
        

        for(int j=0;j<line;j++){
            int x,y;
            cin >> x >> y;
            map[y][x]=1;
        }

        int connect=0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(!visited[r][c] && map[r][c]==1){
                    s.push(make_pair(r,c));
                    connect += dfs();
                }
            }
        }

        answer.emplace_back(connect);

        reset();
    }

    
    for(int i=0;i<answer.size();i++){
        cout << answer[i] << '\n';
    }



}