#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, i, one=0;
    cin>>n;
    vector<int> a(n);
    for(int &i : a) {
        cin>>i;
        if(i) one++;
    }
    if(one<=n/2) {
        n-=one;
        cout<<n<<endl;
        while(n--) cout<<"0 ";
    } else {
        if(one%2) one--;
        cout<<one<<endl;
        while(one--) cout<<"1 ";
    }
    cout<<endl;
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

