#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool good(string s, string t) {
    int open=0, close=0;
    for(auto &i : s) {
        i=t[i-'A'];
        if(i=='(') {
            open++;
        } else {
            close++;
        }
        if(close>open) {
            return false;
        }   
    }
    return open==close;
}

void solve() {
    string s;
    cin>>s;
    string option="()";
    for(int a=0; a<2; a++) {
        for(int b=0; b<2; b++) {
            for(int c=0; c<2; c++) {
                string curr;
                curr.push_back(option[a]);
                curr.push_back(option[b]);
                curr.push_back(option[c]);
                if(good(s, curr)) {
                    cout<<"Yes"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"No"<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

