#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double dp[302][302][302];
int know[302][302][302]={0};
int n;

double p(int x) {
    return (double)x/(double)n;
}

double fetch(int i, int j, int k) {
    if(!know[i][j][k]) {
        know[i][j][k]=1;
        dp[i][j][k]=0;
        if(i || j || k) {
            double add=1;
            dp[i][j][k]=add/(add-p(n-i-j-k));
            if(k) {
                add+=p(k)*fetch(i, j+1, k-1);
            }
            if(j) {
                add+=p(j)*fetch(i+1, j-1, k);
            }
            if(i) {
                add+=p(i)*fetch(i-1, j, k); 
            }
            dp[i][j][k]*=add;
        }
    }
    return dp[i][j][k];
}

void solve() {
    cout<<fixed<<setprecision(10);
    cin>>n;
    vector<int> a(3);
    for(int i=0; i<n; i++) {
        int x;
        cin>>x, x--;
        a[x]++;
    }
    cout<<fetch(a[0], a[1], a[2])<<endl;
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

