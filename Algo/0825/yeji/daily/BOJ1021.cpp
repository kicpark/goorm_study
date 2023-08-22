#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    deque<int> dq;

    for(int i=1;i<=n;i++){
        dq.push_back(i);
    };


    int count = 0;
    while(m--){
        int idx = 0;
        int num;
        cin >> num;
        for(int i=0;i<dq.size();i++){
            if(dq[i]==num){
                idx=i;
                break;
            }
        }

        if(idx<=dq.size()-idx){
            while(1){
                if(dq.front()==num){
                    dq.pop_front();
                    break;
                }
                count++;
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }else if(idx>dq.size()-idx){
            while(1){
                if(dq.front()==num){
                    dq.pop_front();
                    break;
                }
                count++;
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    cout << count << endl;

}