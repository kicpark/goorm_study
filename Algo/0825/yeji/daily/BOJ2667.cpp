#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int map[26][26]={0,};
int visited[26][26]={false,};
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
int n;

stack<pair<int,int> > s;

int dfs(){
    
    int cnt=0;

    while(!s.empty()){
        int cy = s.top().first;
        int cx = s.top().second;

        if(!visited[cy][cx]){
            visited[cy][cx] = true;
            cnt++;
        }

        s.pop();

        for(int i=0;i<4;i++){
            int ny = cy+dy[i];
            int nx = cx+dx[i];

            if(ny>=0 && nx>=0 && ny<n && nx<n){
                if(!visited[ny][nx] && map[ny][nx]==1){
                    s.push(make_pair(ny,nx));
                }
            }
        }
    }

    return cnt;
}


int main(){
    cin >> n;
    
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        for(int j=0;j<str.length();j++){
            map[i][j]=str[j]-'0';
        }
    }

    vector<int> answer;
    
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && map[i][j]==1){
                s.push(make_pair(i,j));
                ans = dfs();
                answer.emplace_back(ans);
            }
        }
    }

    sort(answer.begin(),answer.end());


    cout << answer.size() << '\n';
    for(int i=0;i<answer.size();i++){
        cout << answer[i] << endl;
    }




}