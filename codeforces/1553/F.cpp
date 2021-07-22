#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void add(ll index, ll val, vector<ll> &a) {
    ll n=(ll)a.size();
    while(index<n) {
        a[index]+=val;
        index+=index&-index;
    }
    return;
}
 
ll get(ll index, vector<ll> &a) {
    ll ans=0;
    while(index) {
        ans+=a[index];
        index-=index&-index;
    }
    return ans;
}
 
 
void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll m=0;
    for(auto &i :a) {
        cin>>i;
        m=max(m, i);
    }
    vector<ll> ans(n), singleModRange(m+1), f(m+1);
    ll sum=0;
    for(ll i=0; i<n; i++) {
        if(i) {
            ans[i]=ans[i-1];
        }
        ans[i]+=i*a[i];
        ans[i]-=get(a[i], singleModRange);
        ans[i]+=sum;
        for(ll j=1; j*a[i]<=m; j++) {
            add(j*a[i], a[i], singleModRange);
            ans[i]-=(i-get(j*a[i]-1, f))*a[i];
        }
        add(a[i], 1, f);
        sum+=a[i];
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
