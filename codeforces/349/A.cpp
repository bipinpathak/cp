#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    string ans="YES";
    int b, c, d;
    b=c=d=0;
    for(auto &i : a) {
        if(i==25) {
            b++;
            continue;
        } else if(i==50) {
            if(b) {
                b--;
                c++;
            } else {
                ans="NO";
            }
        } else {
            if(c && b) {
                c--;
                b--;
                d++;
            } else if(b>=3) {
                b-=3;
                d++;
            } else {
                ans="NO";
            }
        }
        if(ans=="NO") {
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

