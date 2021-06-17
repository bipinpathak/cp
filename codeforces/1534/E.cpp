#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    int x=(n+k-1)/k, y=(x*k-n)/2;
    while(n+2*y != x*k || x<1+2*((y+n-1)/n)) {
        if(x==500) {
            cout<<-1<<endl;
            return;
        }
        x++;
        y=(x*k-n)/2;
    }
    vector<int> use(n, 1);
    int left=k*x-n;
    for(int i=0; i<n && left; i++) {
        int add=min(x-1, left);
        add-=add&1;
        use[i]+=add;
        left-=add;
    }
    int curr=0;
    vector<vector<int>> queries(x);
    ll ans=0;
    for(int i=0; i<n; i++) {
        while(use[i]--) {
            queries[curr].push_back(i);
            curr=(curr+1)%x;
        }
    }
    for(auto q : queries) {
        cout<<"?";
        for(auto i : q) {
            cout<<" "<<i+1;
        }
        cout<<endl;
        ll res;
        cin>>res;
        ans^=res;
    }
    cout<<"! "<<ans<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    //(void)!freopen("input.txt", "r", stdin);
    //(void)!freopen("output.txt", "w", stdout);
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

