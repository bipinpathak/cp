#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int p;
    cin>>p;
    vector<int> coins(10, 1);
    for(int i=1; i<10; i++) {
        coins[i]=coins[i-1]*(i+1);
    }
    int ans=0;
    while(p) {
        int curr=0;
        while(p>=coins.back() && curr<100) {
            p-=coins.back();
            curr++;
        }
        ans+=curr;
        coins.pop_back();
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
    auto start=clock();
    int t = 1;
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

