#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<int> map[101];
bool visited[101]={false,};
stack<int> s;
int cnt = 0;

int dfs(){
    int cur = s.top();
    visited[cur]=true;

    for(int i=0;i<map[cur].size();i++){
        int next = map[cur][i];
        if(!visited[next]){
            s.push(next);
            cnt++;
            dfs();
        }
    }
    return cnt;
    
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    int m;
    

    cin >> n;
    cin >> m;


    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        map[a].emplace_back(b);
        map[b].emplace_back(a);
    }

    int answer=0;
    s.push(1);
    answer = dfs();
    cout << answer << '\n';

}