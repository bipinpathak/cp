#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void add(ll index, ll val, vector<ll> &a) {
    int n=(int)a.size();
    while(index<n && val) {
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

void divide(int i, set<vector<ll>> &segments) {
    auto it=segments.lower_bound({i, 0, -(ll)1e15});
    if(it->front()!=i) {
        it--;
        auto curr=*it;
        curr[0]=i;
        segments.insert(curr);
    }
    return;
}

void update(int l, int r, int c, set<vector<ll>> &segments, vector<ll> &a, vector<ll> &val) {
    divide(l, segments);
    divide(r+1, segments);
    vector<vector<ll>> op;
    ll sum=0;
    while(1) {
        auto it=segments.lower_bound({l, 0, -(ll)1e15});
        if(it->front()>r) {
            break;
        }
        ll diff=val[it->at(1)]-it->at(2);    
        diff-=sum;
        op.push_back({it->front(), diff});
        sum+=diff;
        segments.erase(it);
    }
    op.push_back({r+1, -sum});
    for(auto &i : op) {
        add(i[0], i[1], a); 
    }
    segments.insert({l, c, val[c]});
    return;
}

ll calc(int i, set<vector<ll>> &segments, vector<ll> &a, vector<ll> &val) {
    ll ans=get(i, a);
    auto it=segments.lower_bound({i, 0, -(ll)1e15});
    if(it->front()>i) {
        it--;   
    }
    ans+=val[it->at(1)]-it->at(2);
    return ans; 
}

void solve() {
    int n, q;
    cin>>n>>q;
    vector<ll> a(n+1), val(n+1);
    set<vector<ll>> segments;
    //{index, color, current value of color 
    segments.insert({1, 1, 0});
    segments.insert({n+1, 0, 0});
    while(q--) {
        string type;
        cin>>type;
        if(type=="Color") {
            int l, r, c;
            cin>>l>>r>>c;
            update(l, r, c, segments, a, val);
        } else if(type=="Add") {
            ll c, x;
            cin>>c>>x;
            val[c]+=x;
        } else {
            int i;
            cin>>i;
            cout<<calc(i, segments, a, val)<<endl;
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
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

