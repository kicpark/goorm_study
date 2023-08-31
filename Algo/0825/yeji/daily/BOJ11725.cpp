#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> arr[100002];
int visited[100002] = {
    false,
};

int answer[100001]={0,};

void bfs(int start){
    visited[start]=true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int cur = q.front();
        visited[cur]=true;
        q.pop();
        for(int i=0;i<arr[cur].size();i++){
            int next = arr[cur][i];
            if(!visited[next]){
                visited[next]=true;
                answer[next]=cur;
                q.push(next);
            }
        }
    }
}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false); 
    
    int n;
    cin >> n;

    

    int end = n-1;
    for(int i=0;i<end;i++){
        int a,b;
        cin >> a >>b;
        arr[a].emplace_back(b);
        arr[b].emplace_back(a);
    }

    bfs(1);

    for(int i=2;i<=n;i++){
        cout << answer[i] << '\n';
    }

}