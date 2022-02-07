#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    string t;
    cin>>t;
    string order="";
    set<char> seen;
    int n=(int)t.size();
    vector<int> f(26);
    for(int i=n-1; i>=0; i--)  {
        if(!seen.count(t[i])) {
            order.push_back(t[i]);
            seen.insert(t[i]);
        }
        f[t[i]-'a']++;
    }
    reverse(order.begin(), order.end());
    n=0;
    for(int i=0; i<(int)order.size(); i++) {
        f[order[i]-'a']/=(i+1);
        n+=f[order[i]-'a'];
    }
    string s=t;
    s.erase(s.begin()+n, s.end());
    string check="";
    seen.clear();
    for(int i=0; i<(int)order.length(); i++) {
        for(auto &j : s) {
            if(!seen.count(j)) {
                check.push_back(j);
            }
        }
        seen.insert(order[i]);
    }
    if(check!=t) {
        cout<< -1<<endl;
        return;
    }
    cout<<s<<" "<<order<<endl;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

