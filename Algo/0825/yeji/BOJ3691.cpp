#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
using namespace std;


// 왜틀렸다고 나오지 노이해..다시풀기


int main(){
    int Test, line, budget;
    cin >> Test;

    for(int i=0;i<Test;i++){
        cin >> line >> budget;

        map<string,int> type_count;
        map<string,int>::iterator tp;
        map<string,stack<pair<int,int> > > m;
        
        for(int j=0;j<line;j++){
            string type, name;
            int price, quality;
            cin >>  type >> name >> price >> quality;

            m[type].push(make_pair(price,quality));
            // 예산이 낮은거부터 몽땅 맵으로 받음
            type_count[type]++;
        }
        
        int sum = 0;
        pair<int,int> pq;
        map<string,pair<int,int> > bag;
        map<string,pair<int,int> > ::iterator mp;
        vector<string> upgrade;


        // 모든 종류의 맨 앞 부분의 있는 부품을 가방에 넣어줌
        for (tp = type_count.begin(); tp != type_count.end(); tp++)
        {
            bag[tp->first]=m[tp->first].top();
            m[tp->first].pop();
        }

        while(1){
            pair<string,int> low;
            low.second = 1e9;
            

            for(mp=bag.begin();mp!=bag.end();mp++){
                low = low.second < mp->second.second ? low : make_pair(mp->first,mp->second.second);
            }

            // 업데이트 해주고
            if(!m[low.first].empty()){
                bag[low.first] = m[low.first].top();
                m[low.first].pop();
            }else{
                cout << low.second << endl;
                break;
            }
            

            // 다시 모든 부품의 예산을 더해주고
            for(mp=bag.begin();mp!=bag.end();mp++){
                sum+=mp->second.first;
            }
            // 모든 부품의 합이 예산을 초과하면 업데이트 전에 가장 작았던 부품의 성능을 출력
            if(sum>budget){
                cout << low.second << endl;
                break;
            }
            
        }

    }


}