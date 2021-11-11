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
    auto ans=a;
    for(int i=0; i+1<n; i+=2) {
        swap(ans[i], ans[i+1]);
        ans[i]*=-1;
    }
    if(n&1) {
        reverse(ans.begin(), ans.end());
        reverse(a.begin(), a.end());
        ll sum=a[0]+a[1]+a[2];
        for(int i=0; i<3; i++) {
            if(sum==a[i]) {
                continue;
            }
            ans[i]=-a[(i+1)%3]-a[(i+2)%3];
            ans[(i+1)%3]=a[i];
            ans[(i+2)%3]=a[i];
            break;
        }
        reverse(ans.begin(), ans.end());
    }
    for(auto i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

