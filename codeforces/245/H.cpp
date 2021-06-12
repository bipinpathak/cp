#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin>>s;
    int n=(int)s.length();
    vector<vector<int>> pal(n, vector<int> (n)), dp(n, vector<int> (n));
    for(int i=n-1; i>=0; i--) {
        for(int j=i; j<n; j++) {
            int len=j-i+1;
            if(len==1) {
                pal[i][j]=1;
            } else if(len==2) {
                pal[i][j]=s[i]==s[j];
            } else {
                pal[i][j]=pal[i+1][j-1]&(s[i]==s[j]);
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            dp[i][j]=pal[i][j]+(j>i?dp[i][j-1]:0);
        }
    }
    for(int j=n-1; j>=0; j--) {
        for(int i=j-1; i>=0; i--) {
            dp[i][j]+=dp[i+1][j];
        }
    }
    int q;
    cin>>q;
    while(q--) {
        int l, r;
        cin>>l>>r;
        l--, r--;
        cout<<dp[l][r]<<'\n';
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}
