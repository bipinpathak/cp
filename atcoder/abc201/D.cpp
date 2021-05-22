#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int h, w;
    cin>>h>>w;
    vector<string> grid(h);
    for(auto &i : grid) {
        cin>>i;
    }
    vector<vector<int>> dp(h, vector<int> (w, -1e9));
    for(int i=h-1; i>=0; i--) {
        for(int j=w-1; j>=0; j--) {
            if(i+1<h) {
                int option=-dp[i+1][j];
                if(grid[i+1][j]=='+') {
                    option++;
                } else {
                    option--;
                }
                dp[i][j]=max(dp[i][j], option);
            }
            if(j+1<w) {
                int option=-dp[i][j+1];
                if(grid[i][j+1]=='+') {
                    option++;
                } else {
                    option--;
                }
                dp[i][j]=max(dp[i][j], option);
            }
            if(i==h-1 && j==w-1) {
                dp[i][j]=0;
            }
        }
    }
    string ans="Takahashi";
    if(dp[0][0]<0) {
        ans="Aoki";
    } else if(dp[0][0]==0) {
        ans="Draw";
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

