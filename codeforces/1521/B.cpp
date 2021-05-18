#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int index=0;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        if(a[i]<a[index]) {
            index=i;
        }
    }
    cout<<n-1<<endl;
    int p=1e9+7;
    for(int i=0; i<n; i+=2) {
        if(i==index) {
            continue;
        }
        cout<<i+1<<" "<<index+1<<" "<<p<<" "<<a[index]<<endl;
    }
    p=1e9+9;
    for(int i=1; i<n; i+=2) {
        if(i==index) {
            continue;
        }
        cout<<i+1<<" "<<index+1<<" "<<p<<" "<<a[index]<<endl;
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

