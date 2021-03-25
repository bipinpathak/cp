#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    string s;
    cin>>n>>k>>s;
    int ans=0, last=-1, option=-1;
    for(int i=0; i<n; i++) {
        if(s[i]=='.') {
            continue;
        }
        if(last==-1 || i-last>k) {
            if(last==-1) {
                option=i;
            }
            s[option]='y';
            last=option;
            ans++;
        }
        if(s[i]=='*') {
            option=i;
        }
    }
    for(int i=n-1; i>=0; i--) {
        if(s[i]=='y') {
            break;
        }
        if(s[i]=='*') {
            ans++;
            break;
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
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

