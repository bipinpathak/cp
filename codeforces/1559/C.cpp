#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<int> ans;
    if(a.front()) {
        ans.push_back(n+1);
        for(int i=0; i<n; i++) {
            ans.push_back(i+1);
        }
    } else if(a.back()==0) {
        for(int i=0; i<n; i++) {
            ans.push_back(i+1);
        }
        ans.push_back(n+1);
        
    }
    for(int i=0; i+1<n && ans.empty(); i++) {
        if(a[i]==0 && a[i+1]==1) {
            for(int j=0; j<=i; j++) {
                ans.push_back(j+1);
            }
            ans.push_back(n+1);
            for(int j=i+1; j<n; j++) {
                ans.push_back(j+1);
            }
        }
    }
    if(ans.empty()) {
        ans={-1};
    }
    for(auto &i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
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

