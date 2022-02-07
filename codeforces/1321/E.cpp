#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void push(int l, int r, int index, vector<ll> &seg, vector<ll> &lazy) {
    int mid=l+(r-l)/2;
    lazy[index+1]+=lazy[index];
    seg[index+1]+=lazy[index];
    lazy[index+2*(mid-l+1)]+=lazy[index];
    seg[index+2*(mid-l+1)]+=lazy[index];
    lazy[index]=0;
    return;
}

void update(int l, int r, int index, vector<ll> &seg, int start, int end, ll val, vector<ll> &lazy) {
    if(!(end<l || start>r)) {
        if(start<=l && r<=end) {
            seg[index]+=val;
            lazy[index]+=val;
        } else {
            push(l, r, index, seg, lazy);
            int mid=l+(r-l)/2;
            update(l, mid, index+1, seg, start, end, val, lazy);
            update(mid+1, r, index+2*(mid-l+1), seg, start, end, val, lazy);
            seg[index]=max(seg[index+1], seg[index+2*(mid-l+1)]);
        }
    }
    return;
}
 
ll query(int l, int r, int index, vector<ll> &seg, int start, int end, vector<ll> &lazy) {
    ll ans=-1e18;
    if(!(end<l || start>r)) {
        if(start<=l && end>=r) {
            ans=seg[index];
        } else {
            push(l, r, index, seg, lazy); 
            int mid=l+(r-l)/2;
            ans=max(query(l, mid, index+1, seg, start, end, lazy), query(mid+1, r, index+2*(mid-l+1), seg, start, end, lazy));
        }
    }
    return ans;
}

void solve() {
    int n, m, p, k=1e6;
    cin>>n>>m>>p;
    vector<ll> weaponCost(k+1, 1e15), armorCost;
    armorCost=weaponCost;
    while(n--) {
        ll a, ca;
        cin>>a>>ca;
        weaponCost[a]=min(weaponCost[a], ca);
    }
    while(m--) {
        ll b, cb;
        cin>>b>>cb;
        armorCost[b]=min(armorCost[b], cb);
    }
    ll aLow=1e15, bLow=1e15;
    for(int i=k; i; i--) {
        bLow=min(bLow, armorCost[i]);
        aLow=min(aLow, weaponCost[i]);
        weaponCost[i]=aLow;
        armorCost[i]=bLow;
    }   
    vector<vector<int>> monsters(p, vector<int> (3));
    for(auto &i : monsters) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    sort(monsters.begin(), monsters.end());
    vector<ll> seg(2*k+1), lazy(2*k+1);
    for(int i=1; i<=k; i++) {
        update(1, k, 1, seg, i, i, -armorCost[i], lazy);
    }
    int left=0;
    ll ans=-1e15;
    for(int i=1; i<=k && left<p; i++) {
        while(left<p && monsters[left][0]<i) {
            update(1, k, 1, seg, monsters[left][1]+1, k, monsters[left][2], lazy); 
            left++;
        }
        ll offer=query(1, k, 1, seg, 1, k, lazy)-weaponCost[i];
        ans=max(ans, offer);
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

