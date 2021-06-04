#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int k, n;
vector<int> a;
string s;

void update(int index) {
    if(index) {
        if(s[index]=='?') {
            if(2*index+1<=n) {
                a[index]=a[2*index]+a[2*index+1];
            } else {
                a[index]=2;
            }
        } else if(s[index]=='1') {
            if(2*index<=n) {
                a[index]=a[2*index];
            } else {
                a[index]=1;
            }
        } else {
            if(2*index+1<=n) {
                a[index]=a[2*index+1];
            } else {
                a[index]=1;
            }
        }
        update(index/2);
    }
    return;
}

void solve() {
    int index;
    char c;
    cin>>index>>c;
    index=n+1-index;
    s[index]=c;
    update(index);
    cout<<a[1]<<endl;
    return;
}

void pre() {
    cin>>k;
    n=(1<<k)-1;
    a.resize(n+1, 0);
    cin>>s;
    s.push_back('x');
    reverse(s.begin(), s.end());
    for(int i=1; i<=n; i++) {
        update(i);
    }
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    auto start=clock();
    pre();
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

