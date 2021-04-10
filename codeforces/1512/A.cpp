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
    int val=a.back();
    if(val!=a.front()) {
        if(a[1]==val) {
            cout<<1<<endl;
            return;
        } 
        cout<<n<<endl;
        return;
    }
    for(int i=0; i<n; i++) {
        if(a[i]!=val) {
            cout<<i+1<<endl;
            return;
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
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

