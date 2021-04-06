#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> h(n);
    for(auto &i : h) {
        cin>>i;
    }   
    vector<int> cost(n, 1e9+1);
    cost[0]=0;
    for(int i=0; i<n; i++) {
        if(i+1<n) {
            cost[i+1]=min(cost[i+1], cost[i]+abs(h[i]-h[i+1]));
        }       
        if(i+2<n) {
            cost[i+2]=min(cost[i+2], cost[i]+abs(h[i]-h[i+2]));
        }
    }
    cout<<cost[n-1]<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

