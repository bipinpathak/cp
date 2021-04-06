#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    cout<<fixed<<setprecision(10);
    int n;
    cin>>n;
    vector<double> p(n);
    for(auto &i : p) {
        cin>>i;
    }
    vector<vector<double>> ans(n, vector<double> (n+1));
    double one=1;
    ans[0][0]=one-p[0];
    ans[0][1]=p[0];
    for(int i=1; i<n; i++) {
        for(int j=0; j<=n; j++) {
            ans[i][j]=ans[i-1][j]*(one-p[i]); 
            if(j) {
                ans[i][j]+=ans[i-1][j-1]*p[i];
            }
        }
    }
    double sum=0;
    for(int i=(n+1)/2; i<=n; i++) {
        sum+=ans[n-1][i];
    }
    cout<<sum<<endl;
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
    //cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

