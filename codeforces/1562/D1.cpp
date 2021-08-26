#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, q;
    string s;
    cin>>n>>q>>s;
    vector<int> suffix(n);
    for(int i=n-1; i>=0; i--) {
        if(i+1<n) {
            suffix[i]=-suffix[i+1];
        }
        if(s[i]=='-') {
            suffix[i]--;
        } else {
            suffix[i]++;
        }
    }
    while(q--) {
        int l, r;
        cin>>l>>r;
        l--, r--;
        int curr=suffix[l];
        if(r+1<n) {
            curr-=suffix[r+1];
        }
        curr=abs(curr);
        int ans=0;
        if(curr) {
            ans=1+((curr&1)==0);
        }   
        cout<<ans<<endl;
    }
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

