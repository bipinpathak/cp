#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(auto &i : a) {
        cin>>i;
    }
    for(auto &i : b) {
        cin>>i;
    }
    int total=0;
    for(int i=0; i<n; i++) {
        total+=a[i]-b[i];
    }
    if(total) {
        cout<<-1<<endl;
        return;
    }
    vector<vector<int>> ans;
    int i=0, j=0;
    while(1) {
        while(i<n && a[i]<=b[i]) {
            i++;
        }
        while(j<n && a[j]>=b[j]) {
            j++;
        }
        if(i==n || j==n) {
            break;
        }
        a[i]--, a[j]++;
        ans.push_back({i+1, j+1});
    }
    cout<<ans.size()<<endl;
    for(auto i : ans) {
        for(auto j : i) {
            cout<<j<<" ";
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

