#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int q;
    cin>>q;
    map<ll, int> count;
    ll diff=0;
    while(q--) {
        int t;
        cin>>t;
        if(t==3) {
            ll smallest=count.begin()->first; 
            count[smallest]--;
            if(count[smallest]==0) {
                count.erase(smallest);
            }
            smallest+=diff;
            cout<<smallest<<endl;
            continue;
        }
        ll x;
        cin>>x;
        if(t==1) {
            x-=diff;
            count[x]++;
        } else {
            diff+=x; 
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

