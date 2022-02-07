#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, k, a, b;
    cin>>n>>k>>a>>b;
    char last='A';
    int count=0;
    string ans="";
    while(n--) {
        if(a>=b) {
            ans.push_back('G');
            a--;
        } else {
            ans.push_back('B');
            b--;
        }
        if(ans.back()!=last) {
            count=0;
        }
        count++;
        if(count>k) {
            if(ans.back()=='G') {
                a++;
                b--;
                ans.back()='B';
            } else {
                a--;
                b++;
                ans.back()='G';
            }
            count=1;
        }
        if(a<0 || b<0) {
            ans="NO";
            break;
        }
        last=ans.back();
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

