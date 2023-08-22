#include <iostream>
#include <queue>

using namespace std;

int main(){
    priority_queue<int,vector<int>,greater<int> > q;

    int n;
    cin >> n;
    
    vector<int> answer;

    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        if(num==0 && q.empty()){
            answer.emplace_back(0);
        }else if(num==0){
            answer.emplace_back(q.top());
            //cout << q.top()<< endl;
            q.pop();
        }else if(num!=0){
            q.push(num);
        }
    }

    for(int i=0;i<answer.size();i++){
        cout << answer[i] << '\n';
    }
}

