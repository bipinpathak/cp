#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> ans(1e7+1, 1e7+1);

void solve() {
    int c;
    cin>>c;
    int n=ans[c];
    if(n==1e7+1) {
        n=-1;
    }
    cout<<n<<endl;
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
    int n=1e7;
    vector<int> sum(n+1);
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j+=i) {
            if(sum[j]<=n) {
                sum[j]+=i;
            }
        }
        if(sum[i]<=n) {
            ans[sum[i]]=min(ans[sum[i]], i);
        }
    }
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}
