#include <bits/stdc++.h>
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
    for(int i=0; i<n; i++) {
        a[i]=b[i]-a[i];
    }
    string ans="YES";
    bool done=false;
    for(int i=0; i<n && ans=="YES"; i++) {
        if(a[i]<0 || (a[i] && done)) {
            ans="NO";
        }
        if(a[i]) {
            int diff=a[i];
            for(int j=i; j<n && a[j]==diff; j++) {
                a[j]=0;
            }
            done=true;
        }
    }
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
    auto start=clock();
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

