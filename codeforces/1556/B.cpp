#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(int need, vector<int> a) {
    ll ans=0;
    int n=(int)a.size();
    vector<int> index(2, n);
    for(int i=n-1; i>=0; i--) {
        index[a[i]]=i;
    }
    for(int i=0; i<n; i++) {
        if(a[i]!=need) {
            index[need]=max(index[need], i+1);
            while(index[need]<n && a[index[need]]!=need) {
                index[need]++;
            }
            if(index[need]==n) {
                ans=1e18;
                break;
            }
            swap(a[index[need]], a[i]);
            ans+=index[need]-i;
        }
        need=!need;
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
        i&=1;
    }
    ll ans=1e18;
    ans=min(ans, calc(0, a));
    ans=min(ans, calc(1, a));
    if(ans==1e18) {
        ans=-1;
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

