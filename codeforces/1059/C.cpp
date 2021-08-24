#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void build(int base, int n, vector<int> &order) {
    if(n) {
        if(n==3) {
            for(int i=1; i<=n; i++) {
                order.push_back(base*i);
            }
        } else {
            for(int i=1; i<=n; i+=2) {
                order.push_back(i*base);
            }
            build(base*2, n/2, order);
        }
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<int> order;
    build(1, n, order);
    vector<int> ans(n);
    int prev=0;
    for(int i=n-1; i>=0; i--) {
        prev=__gcd(prev, order[i]);
        ans[i]=prev;
    }
    for(auto i : ans) {
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

