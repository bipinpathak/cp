#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, a, b;
    string s;
    cin>>n>>a>>b>>s;
    int seg=1, last=s[0]-'0';
    for(auto i : s) {
        int curr=i-'0';
        if(curr!=last) {
            seg++;
        }
        last=curr;
    }
    int ans=n*a;
    if(b>=0) {
        ans+=n*b;
    } else {
        seg/=2;
        seg++;
        ans+=seg*b;
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

