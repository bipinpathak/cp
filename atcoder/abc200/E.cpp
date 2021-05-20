#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, k;
    cin>>n>>k;
    vector<ll> two(2*n+1), three(3*n+1);
    for(ll total=2; total<=2*n; total++) {
        ll low=max((ll)1, total-n), high=min(n, total-1);
        two[total]=high-low+1;
        two[total]+=two[total-1];
    }
    for(ll total=3; total<=3*n; total++) {
        ll low=max((ll)1, total-2*n), high=min(n, total-2);
        ll slow=max((ll)2, total-high), shigh=min(2*n, total-low);
        three[total]=two[shigh]-two[slow-1];
    }
    for(ll total=3; total<=3*n; total++) {
        if(k>three[total]) {
            k-=three[total];
            continue;
        }
        ll low=max((ll)1, total-2*n), high=min(n, total-2);
        while(low<=high) {
            ll curr=two[total-low]-two[total-low-1];
            if(k>curr) {
                k-=curr;
                low++;
                continue;
            }
            vector<ll> ans(3);
            ans[0]=low;
            curr=total-low;
            ll slow=max((ll)1, curr-n);
            ans[1]=slow+k-1;
            ans[2]=total-ans[0]-ans[1];
            for(auto i : ans) {
                cout<<i<<" ";
            }
            cout<<endl;
            return;
        }
    }
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

