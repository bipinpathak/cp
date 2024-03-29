#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    string s;
    cin>>n>>k>>s;
    vector<int> count(26);
    int curr=0;
    for(int i=0; i<n; i++) {
        curr++;
        if(i==n-1 || s[i]!=s[i+1]) {
            count[s[i]-'a']+=curr/k;
            curr=0;
        }
    }
    int x=0;
    for(auto i : count) {
        x=max(x, i);
    }
    cout<<x<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    auto start=clock();
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

