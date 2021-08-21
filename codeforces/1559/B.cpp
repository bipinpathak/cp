#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    int index=-1;
    for(int i=0; i<n; i++) {
        if(s[i]!='?') {
            index=i;
            break;
        }
    }
    if(index==-1) {
        if(s.front()=='?') {
            for(int i=0; i<n; i++) {
                s[i]=(i&1)?'R':'B';
            }
        }
    } else {
        for(int i=index-1; i>=0; i--) {
            if(s[i]!='?') {
                continue;
            }
            s[i]=(s[i+1]=='R')?'B':'R';
        }
        for(int i=index+1; i<n; i++) {
            if(s[i]!='?') {
                continue;
            }
            s[i]=(s[i-1]=='R')?'B':'R';
        }
    }
    cout<<s<<endl;
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

