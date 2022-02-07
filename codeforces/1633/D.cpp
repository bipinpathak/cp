#include "bits/stdc++.h"
using namespace std;
using ll = long long;

vector<int> moves;

void pre() {
    int n=1e3;
    moves.resize(n+1, n);
    moves[1]=0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i && i+j<=n; j=i/(i/(j+1))) {
            moves[i+j]=min(moves[i+j], moves[i]+1); 
            if(j==i) {
                break;
            }
        }
    }
    return;
}

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> b(n), c(n);
    for(auto &i : b) {
        cin>>i;
        i=moves[i];
    }
    for(auto &i : c) {
        cin>>i;
    }
    vector<int> coins(k+1);
    for(int i=0; i<n; i++) {
        for(int curr=k-b[i]; curr>=0; curr--) {
            coins[curr+b[i]]=max(coins[curr+b[i]], coins[curr]+c[i]);
        }
    }
    int ans=0;
    for(auto &i : coins) {
        ans=max(i, ans);
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
    int t = 1;
    cin>>t;
    pre();
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

