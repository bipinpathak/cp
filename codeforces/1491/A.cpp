#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin>>n>>q;
    vector<int> a(n);
    int one=0;
    for(auto &i : a) {
        cin>>i;
        one+=i;
    }
    while(q--) {
        int t;
        cin>>t;
        if(t==1) {
            int x;
            cin>>x;
            x--;
            if(a[x]) {
                one--;
                a[x]=0;
            } else {
                one++;
                a[x]=1;
            }
        } else {
            int k;
            cin>>k;
            if(one>=k) {
                cout<<1<<endl;
            } else {
                cout<<0<<endl;
            }
        }
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
    while(t--) {
        solve();
    }
    return 0;
}

