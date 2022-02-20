#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    stack<vector<int>> a;
    int ans=0;
    int last=-1, count=0;
    while(n--) {
        int x;
        cin>>x;
        if(x!=last) {
            count=0;
        }
        last=x;
        count++;
        a.push({x, count});
        ans++;
        if(count==x) {
            ans-=count;
            while(count--) {
                a.pop();
            }
            last=-1;
            count=0;
            if(!a.empty()) {
                last=a.top().front();
                count=a.top().back();
            }
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
    int t = 1;
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

