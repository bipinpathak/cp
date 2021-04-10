#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b;
    string s;
    cin>>a>>b>>s;
    int n=a+b;
    vector<char> val(n, '?');
    for(int i=0; i<n; i++) {
        if(s[i]=='?') {
            continue;
        }
        int curr=min(i, n-1-i);
        if(val[curr]=='?' || val[curr]==s[i]) {
            val[curr]=s[i];
            continue;
        }
        cout<<-1<<endl;
        return;
    }
    for(int i=0; i<n; i++) {
        int curr=min(i, n-1-i);
        s[i]=val[curr];
    }
    for(auto i : s) {
        if(i=='0') {
            a--;
        } else if(i=='1') {
            b--;
        }
    }
    if(a<0 || b<0) {
        cout<<-1<<endl;
        return;
    }
    for(int i=0; i<=n-1-i; i++) {
        if(val[i]=='?') {
            if(i==n-1-i) {
                if(a) {
                    val[i]='0';
                    a--;
                } else if(b) {
                    val[i]='1';
                    b--;
                } else {
                    cout<<-1<<endl;
                    return;
                }
            } else {
                if(a>=2) {
                    val[i]='0';
                    a-=2;
                } else if(b>=2) {
                    val[i]='1';
                    b-=2;
                } else {
                    cout<<-1<<endl;
                    return;
                }
            }
        }
    }
    for(int i=0; i<n; i++) {
        cout<<val[min(i, n-1-i)];
    }
    cout<<endl;
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

