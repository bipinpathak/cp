#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool win(vector<int> &a, vector<int> &b) {
    int ans=0;
    for(int i=0; i<5; i++) {
        ans+=a[i]<b[i];
    }
    return ans>=3;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int> (5));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    int ans=0;
    for(int i=1; i<n; i++) {
        if(win(a[i], a[ans])) {
            ans=i;
        }
    }
    for(int i=0; i<n; i++) {
        if(i==ans) {
            continue;
        }
        if(win(a[i], a[ans])) {
            ans=-2;
            break;
        }
    }
    cout<<ans+1<<endl;
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

