#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin>>s;
    int l=0, r=(int)s.size()-1;
    string ans="Yes";
    int last=max(s.front()-'a', s.back()-'a')+1;
    while(l<=r) {
       int curr=max(s[l]-'a', s[r]-'a'); 
       if(curr!=last-1 || (l==r && curr)) {
            ans="No";
            break;
       }
       last=curr;
       if(s[l]>s[r]) {
            l++;
       } else {
            r--;
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

