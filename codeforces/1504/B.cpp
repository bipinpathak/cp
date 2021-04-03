#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    string a, b;
    cin>>a>>b;
    vector<int> aCount(n);
    for(int i=0; i<n; i++) {
        if(i) {
            aCount[i]=aCount[i-1];
        }
        if(a[i]=='1') {
            aCount[i]++;
        } else {
            aCount[i]--;
        }
    }
    bool same=true;
    for(int i=n-1; i>=0; i--) {
        if((a[i]==b[i]) ^ same) {
            if(aCount[i]) {
                cout<<"NO"<<endl;
                return;
            }
            same=!same;
        }
    }
    cout<<"YES"<<endl;
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

