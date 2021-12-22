#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    sort(a.begin(), a.end());
    vector<int> ans(k);
    int index=-1, curr=0;
    for(int i=0; i<k; i++) {
        index++;
        while(index<n && a[index]==curr) {
            index++;
        }
        if(index==n) {
            break;
        }
        ans[i]=a[index]-curr;
        curr=a[index];
    }
    for(auto i : ans) {
        cout<<i<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

