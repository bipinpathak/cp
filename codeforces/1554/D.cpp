#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(string &s, int n, char c) {
    n=max(n, 0);
    while(n--) {
        s.push_back(c);
    }       
    return;
}   

void solve() {
    int n;
    cin>>n;
    string ans="";
    if(n==1) {
        ans="z";
    } else if(n&1) {
        go(ans, (n-2)/2, 'z');
        go(ans, 1, 'a');
        go(ans, 1, 'b');
        go(ans, (n-1)/2, 'z');
    } else {
        go(ans, (n-1)/2, 'z');
        go(ans, 1, 'a');
        go(ans, n/2, 'z');
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

