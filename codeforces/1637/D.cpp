#include "bits/stdc++.h"
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
    int m=1e4, ans=0, total=0;
    vector<int> possible(m+1);
    possible[0]=1;
    for(int i=0; i<n; i++) {
        ans+=a[i]*a[i];
        ans+=b[i]*b[i];
        total+=a[i]+b[i];
        vector<int> update(m+1);
        for(int j=m; j>=0; j--) {
            if(!possible[j]) {
                continue;
            }
            update[j+a[i]]=1;
            update[j+b[i]]=1;
        }
        possible=update;
    }
    ans*=n-2;
    int add=1e9;
    for(int i=0; i<=m; i++) {
        if(possible[i]) {
            add=min(add, i*i + (total-i)*(total-i)); 
        }
    }
    ans+=add;
    cout<<ans<<endl;
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

