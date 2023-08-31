#include <iostream>
#include <vector>
#include <stack>
#include <memory.h>

using namespace std;

int n;
char map[101][101];
int imap[101][101]={0,};
int visited[101][101]={false,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};

stack<pair<int,int> > s;
int dfs(){
    int cy = s.top().first;
    int cx = s.top().second;

    s.pop();
    visited[cy][cx]=true;

    char now = map[cy][cx];
    if(now=='R' || now=='G')
        map[cy][cx]='A';
    else if(now=='B'){
        map[cy][cx]='C';
    }

    for(int i=0;i<4;i++){
        int ny = cy+dy[i];
        int nx = cx+dx[i];
        if(ny>=0 && nx>=0 && ny<n && nx<n){
            if(now == map[ny][nx] && !visited[ny][nx]){
                s.push(make_pair(ny,nx));
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

    int basic = 0;
    int special = 0;


    cin >> n;

    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<str.length();j++){
            map[i][j]=str[j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                s.push(make_pair(i,j));
                basic+=dfs();
            }
        }
    }

    for(int i=0;i<51;i++){
        memset(visited[i],false,sizeof(visited[i])*51);
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                s.push(make_pair(i,j));
                special+=dfs();
            }
        }
    }


    cout << basic << " " << special << '\n';



}