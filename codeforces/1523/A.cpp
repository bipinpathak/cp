#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    string s;
    cin>>n>>m>>s;
    vector<int> nearest(n, n+1), left(n, -1), right(n, -1);
    int last=-1;
    for(int i=0; i<n; i++) {
        if(s[i]=='1') {
            last=i;
            continue;
        }
        if(last!=-1) {
            nearest[i]=i-last;
            left[i]=nearest[i];
        }
    }
    last=n;
    for(int i=n-1; i>=0; i--) {
        if(s[i]=='1') {
            last=i;
            continue;
        }
        if(last!=n) {
            nearest[i]=min(nearest[i], last-i);
            right[i]=last-i;
        }
    }
    string ans="";
    for(int i=0; i<n; i++) {
        if(s[i]=='0' && (nearest[i]>m || left[i]==right[i])) {
            ans.push_back('0');
        } else {
            ans.push_back('1');
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

