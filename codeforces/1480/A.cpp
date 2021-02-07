#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    vector<int> used(n);
    for(int move=0; move<n; move++) {
        if(move%2==0) {
            for(int i=0; i<n; i++) {
                if(!used[i]) {
                    used[i]=1;
                    if(s[i]=='a') {
                        s[i]='b';
                    } else {
                        s[i]='a';
                    }
                    break;
                }
            }
        } else {
            for(int i=0; i<n; i++) {
                if(!used[i]) {
                    used[i]=1;
                    if(s[i]=='z') {
                        s[i]='y';
                    } else {
                        s[i]='z';
                    }
                    break;
                }
            }
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
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

