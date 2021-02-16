#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> rem(3);
    for(int i=0; i<n; i++) {
        int x;
        cin>>x;
        x%=3;
        if(x==0) {
            rem[0]++;
        } else if(x==1) {
            rem[1]++;
        } else{
            rem[2]++;
        }
    }
    int ans=0;
    for(int i=0; i<6; i++) {
        int curr=i%3, next=(i+1)%3;
        if(rem[curr]>n/3) {
            int excess=rem[curr]-n/3;
            rem[curr]-=excess;
            rem[next]+=excess;
            ans+=excess;
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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

