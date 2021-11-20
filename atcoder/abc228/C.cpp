#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> total(n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            int p;
            cin>>p;
            total[i]+=p;
        }
    }
    auto temp=total;
    sort(temp.rbegin(), temp.rend());
    int target=temp[k-1];
    for(auto i : total) {
        if(i+300>=target) {
            cout<<"Yes";
        } else {
            cout<<"No";
        }
        cout<<endl;
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
    int t = 1;
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

