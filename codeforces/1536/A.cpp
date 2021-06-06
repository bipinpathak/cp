#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int g=0, low=100, high=-100;
    for(auto i : a) {
        cin>>i;
        g=__gcd(g, i);
        low=min(low, i);
        high=max(high, i);
    }
    if(low<0) {
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    vector<int> b;
    low=min(low, g);
    while(low<=high) {
        b.push_back(low);
        low+=g;
    }
    cout<<b.size()<<endl;
    for(auto i :b) {
        cout<<i<<" ";
    }
    cout<<endl;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

