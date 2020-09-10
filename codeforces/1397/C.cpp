#include <bits/stdc++.h>
using namespace std;
void solve() {
    long long n;
    cin>>n;
    vector<long long> a(n);
    for(long long &i : a) cin>>i;
    if(n==1) {
        cout<<"1 1"<<endl;
        cout<<-a[0]<<endl;
        cout<<"1 1"<<endl;
        cout<<"1"<<endl;
        cout<<"1 1"<<endl;
        cout<<"-1"<<endl;
    } else {
        cout<<"1 1"<<endl;
        cout<<n-a[0]<<endl;
        a[0]=n;
        cout<<"2"<<" "<<n<<endl;
        for(int i=1; i<n; i++) {
            cout<<(n-1)*a[i]<<" ";
            a[i]*=n;
        }
        cout<<endl;
        cout<<"1"<<" "<<n<<endl;
        for(long long & i : a ) cout<<-i<<" ";
        cout<<endl;
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

