#include <bits/stdc++.h>
using namespace std;
void solve() {
    long long n, k, l, i, m;
    cin>>n>>k>>l;
    m=n*k;
    vector<long long> staves(m);
    for(i=0; i<m; i++) {
        cin>>staves[i];
    }
    sort(staves.begin(), staves.end());
    i=0; 
    while(i<m && staves[i]-staves[0]<=l) i++;
    if(i<n) {
        cout<<"0"<<endl;
    } else {
        int start=0, end=i+1-n;
        m=0;
        while(start<end && start<i) {
            m+=staves[start];
            start+=k;
            end++;
        }
        end--;
        while(end<i) {
            m+=staves[end];
            end++;
        }
        cout<<m<<endl;
    }
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

