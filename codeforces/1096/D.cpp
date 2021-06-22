#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<ll> prev(4);
    for(int i=0; i<n; i++) {
        vector<ll> curr(4);
        curr[0]=prev[0]+((s[i]=='h')?a[i]:0);
        curr[1]=prev[1]+((s[i]=='a')?a[i]:0);
        if(s[i]=='h') {
            curr[1]=min(curr[1], prev[0]);
        }
        curr[2]=prev[2]+((s[i]=='r')?a[i]:0);
        if(s[i]=='a') {
            curr[2]=min(curr[2], prev[1]);
        }
        curr[3]=prev[3]+((s[i]=='d')?a[i]:0);
        if(s[i]=='r') {
            curr[3]=min(curr[3], prev[2]);
        }
        prev=curr;
    }
    sort(prev.begin(), prev.end());
    cout<<prev.front()<<endl;
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

