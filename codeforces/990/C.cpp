#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> open(n), close(n);
    map<int, int> prefix;
    ll ans=0;
    for(int i=0; i<n; i++) {
        string s;
        cin>>s;
        stack<char> red;
        for(auto j : s) {
            if(!red.empty() && red.top()=='(' && j==')') {
                red.pop();
            } else {
                red.push(j);
            }
        }
        while(!red.empty() && red.top()=='(') {
            open[i]++;
            red.pop();
        }
        close[i]=(int)red.size();
        if(close[i]==0) {
            prefix[open[i]]++;
        }
    }
    for(int i=0; i<n; i++) {
        if(open[i]==0) {
            ans+=prefix[close[i]];
        }
    }
    cout<<ans<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}

