#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    ll leftLen, rightLen;
    ll ans;
    node() {
        leftLen=1;
        rightLen=1;
        ans=1;
    };
};

void update(ll l, ll r, ll index, vector<node> &seg, ll start, ll end, vector<ll> &a) {
    if(!(end<l || start>r)) {
        if(start<=l && r<=end) {
        } else {
            ll mid=l+(r-l)/2;
            update(l, mid, index+1, seg, start, end, a);
            update(mid+1, r, index+2*(mid-l+1), seg, start, end, a);
            seg[index].ans=seg[index+1].ans+seg[index+2*(mid-l+1)].ans;
            seg[index].leftLen=seg[index+1].leftLen;
            seg[index].rightLen=seg[index+2*(mid-l+1)].rightLen;
            if(a[mid]<=a[mid+1]) {
                seg[index].ans+=seg[index+1].rightLen*seg[index+2*(mid-l+1)].leftLen;
                if(seg[index].leftLen==mid-l+1) {
                    seg[index].leftLen+=seg[index+2*(mid-l+1)].leftLen;
                }
                if(seg[index].rightLen==r-mid) {
                    seg[index].rightLen+=seg[index+1].rightLen;
                }
            }
        }
    }
    return;
}
 
ll query(ll l, ll r, ll index, vector<node> &seg, ll start, ll end, vector<ll> &a) {
    ll ans=0;
    if(!(end<l || start>r)) {
        if(start<=l && end>=r) {
            ans=seg[index].ans;
        } else {
            ll mid=l+(r-l)/2;
            ans=query(l, mid, index+1, seg, start, end, a)+query(mid+1, r, index+2*(mid-l+1), seg, start, end, a);
            if(start<=mid && end>=mid+1 && a[mid]<=a[mid+1]) {
                ll leftLen=min(seg[index+1].rightLen, mid-start+1); 
                ll rightLen=min(seg[index+2*(mid-l+1)].leftLen, end-mid);
                ans+=rightLen*leftLen;
            }
        }
    }
    return ans;
}

void solve() {
    ll n, q;
    cin>>n>>q;
    vector<ll> a(n+1);
    for(ll i=1; i<=n; i++) {
        cin>>a[i];
    }
    vector<node> seg(2*n+1);
    for(int i=1; i<=n; i++) {
        update(1, n, 1, seg, i, i, a);
    }
    while(q--) {
        ll t;
        cin>>t;
        if(t==1) {
            ll x, y;
            cin>>x>>y;
            a[x]=y;
            update(1, n, 1, seg, x, x, a);
        } else {
            ll l, r;
            cin>>l>>r;
            cout<<query(1, n, 1, seg, l, r, a)<<endl;
        }
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

