#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll x;
    cin>>x;
    vector<int> a;
    while(x) {
        a.push_back(x%10);
        x/=10;
    }   
    reverse(a.begin(), a.end());
    int n=(int)a.size();
    bool change=true;
    while(change) {
        change=false;
        int curr=(a[0]+2)/3;
        for(int i=1; i<n; i++) {
            if(a[i]<curr) {
                a[i-1]--;
                a[i]+=10;
                change=true;
                break;
            }
            curr=max(curr, (a[i]+2)/3);
        }
    }
    int ans=0;
    for(auto i: a) {
        int curr=(i+2)/3;
        ans=max(ans, curr);
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

