#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(ll index, ll n, vector<ll> &a, vector<ll> &curr, vector<ll> &other) {
    if(n==0) {
        return;
    }
    ll half=(1<<(n-1));
    go(index, n-1, a, curr, other);
    go(index+half, n-1, a, curr, other);
    ll right=index+half+half-1;
    for(ll left=index+half-1; left>=index; left--) {
        while(right>=index+half && a[right]>=a[left]) {
            right--;
        }
        curr[n]+=right+1-index-half;
    }
    right=index+half;
    for(ll left=index; left<index+half; left++) {
        while(right<index+half+half && a[right]<=a[left]) {
            right++;
        }
        other[n]+=index+half+half-right;
    }
    sort(a.begin()+index, a.begin()+index+half+half);
    return;
}

void solve() {
    ll N;
    cin>>N;
    ll n=(1<<N);
    vector<ll> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<ll> curr(N+1), other(N+1);
    go(0, N, a, curr, other);
    ll m;
    cin>>m;
    while(m--) {
        ll q;
        cin>>q;
        ll ans=0;
        for(ll i=0; i<=N; i++) {
            if(i<=q) {
                swap(curr[i], other[i]);
            }
            ans+=curr[i];
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

