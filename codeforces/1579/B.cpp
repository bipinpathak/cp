#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void shift(int l, int r, int d, vector<int> &a) {
    vector<int> temp;
    for(int i=l; i<=r; i++) {
        temp.push_back(a[i]);
    }
    int n=r-l+1;
    for(int i=0; i<=r-l; i++) {
        a[l+i]=temp[(i+d)%n];
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<vector<int>> ans;
    for(int i=0; i<n; i++) {
        int low=i;
        for(int j=i+1; j<n; j++) {
            if(a[j]<a[low]) {
                low=j;
            }
        }
        if(low>i) {
            ans.push_back({i+1, low+1, low-i});
            shift(i, low, low-i, a);
        }
    }
    cout<<ans.size()<<endl;
    for(auto i: ans) {
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
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

