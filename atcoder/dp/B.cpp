#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> h(n);
    for(auto &i : h) {
        cin>>i;
    }   
    vector<int> cost(n, 1e9+1);
    cost[0]=0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n && j<=i+k; j++) {
            cost[j]=min(cost[j], cost[i]+abs(h[i]-h[j]));
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

