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
    for(int i=0; i<n; i++) {
        int sum=0;
        for(int j=i; j<n; j++) {
            sum+=a[j];
            if(sum%2==0) {
                cout<<j-i+1<<endl;
                for(int k=i; k<=j; k++) {
                    cout<<k+1<<" ";
                }
                cout<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
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

