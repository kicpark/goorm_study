#include <iostream>
#include <vector>
#include <string> 

using namespace std;

string str;
string b;

void input()
{
    cin >> str;
    cin >> b;
}

int main()
{

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    input();

    string ans = "";

    int it = 0;
    for (int i = 0; i < str.length(); i++)
    {
        ans += str[i];
        int b_len = 0;
        if (ans.size() >= b.size())
        {
            int idx = ans.size() - b.size();
            for (int j = 0; j < b.size(); j++)
            {
                if (ans[idx++] == b[j])
                {
                    b_len++;
                }
            }
            if (b_len == b.size())
            {
                ans.erase(ans.end() - b.size(), ans.end());
            }
        }
    }

    if (ans.empty())
    {
        cout << "FRULA" << '\n';
    }
    else
    {
        cout << ans << '\n';
    }
}