#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin>>s;
    vector<vector<int>> indedxes(26);
    int n=(int)s.length();
    for(int i=0; i<n; i++) {
        indedxes[s[i]-'a'].push_back(i);
    }
    for(auto &i : indedxes) {
        reverse(i.begin(), i.end());
    }
    string out="";
    for(int move=0; move<26; move++) {
        int chosen=-1; 
        for(int i=25; i>=0 && chosen==-1; i--) {
            if(indedxes[i].empty()) {
                continue;
            }
            int j;
            for(j=25; j>=0; j--) {
                if(!indedxes[j].empty() && indedxes[j].front()<indedxes[i].back()) {
                    break;                
                }
            }
            if(j==-1) {
                chosen=i;
            }
        }
        if(chosen==-1) {
            break;
        }
        out+=('a'+chosen);
        int index=indedxes[chosen].back();
        indedxes[chosen].clear();
        for(auto &i :indedxes) {
            while(!i.empty() && i.back()<=index) {
                i.pop_back();
            }
        }
    }
    cout<<out<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

