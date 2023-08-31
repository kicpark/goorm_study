#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;


char map[601][601]={0,};
int visited[601][601]={false,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
int n,m;
int y, x;
stack<pair<int, int> > s;

int p = 0;
void dfs(){
    int cy = s.top().first;
    int cx = s.top().second;
    s.pop();
    visited[cy][cx]=true;

    if(map[cy][cx]=='P'){
        p++;
    }

    for(int i=0;i<4;i++){
        int ny = cy+dy[i];
        int nx = cx+dx[i];
        if(ny>=0 && nx>=0 && ny<n && nx<m){
            if(map[ny][nx]!='X' && !visited[ny][nx]){
                s.push(make_pair(ny,nx));
                dfs();
            }
        }
    }
        
}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<str.length();j++){
            if(str[j]=='I'){
                y= i;
                x= j;
            }
            map[i][j]=str[j];
            
        }
    }

    s.push(make_pair(y,x));
    dfs();


    if(p==0){
        cout << "TT" << '\n';
    }else{
        cout << p << '\n';
    }
    

}