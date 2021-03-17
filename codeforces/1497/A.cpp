#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> f(101), ans(n);
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        f[x]++;
    }
    int index=0, curr=0;
    while(index<101 && curr<n) {
        while(index<101 && f[index]==0) {
            index++;
        }
        if(index<101) {
            ans[curr]=index;
            f[index]--;
            index++;
            curr++;
        }
    }
    index=0;
    while(curr<n) {
        while(f[index]==0) {
            index++;
        }
        ans[curr]=index;
        f[index]--;
        curr++;
    }
    for(auto i : ans) {
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
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

