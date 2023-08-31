#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;


char map[51][51];
int visited[51][51]={false,};
int n,m;
int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};


int tree=0;
stack<pair<int,int> > s;
int dfs(){
    int cy = s.top().first;
    int cx = s.top().second;

    visited[cy][cx]=true; // 현재 위치 방문찍고

    s.pop();

    char now = map[cy][cx]; // 현재 값

    for(int i=0;i<4;i++){
        int ny = cy+dy[i];
        int nx = cx+dx[i];
        if(ny>=0 && nx>=0 && ny<n && nx<m && !visited[ny][nx]){
            if(now=='-' && map[ny][nx]=='-' && cy==ny){
                s.push(make_pair(ny,nx));
                visited[ny][nx]=true;
                dfs();
            }else if(now=='|' && map[ny][nx]=='|' && cx==nx){
                s.push(make_pair(ny,nx));
                visited[ny][nx]=true;
                dfs();
            }
        }
    }


    return 1;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;

    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<str.length();j++){
            map[i][j]=str[j];
        }
    }

    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                s.push(make_pair(i,j));
                cnt+=dfs();
            }
        }
    }

    cout << cnt << '\n';


}