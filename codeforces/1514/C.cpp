#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> have(n);
    ll p=1;
    for(int i=1; i<n; i++) {
        if(__gcd(i, n)==1) {
            have[i]=1;
            p=(p*i)%n;
        }
    }
    if(p!=1) {
        have[p]=0;
    }
    vector<int> ans;
    for(int i=1; i<n; i++) {
        if(have[i]) {
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

