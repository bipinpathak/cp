#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void in(vector<ll> &a) {
    for(auto &i : a) {
        cin>>i;
    }
    return;
}

void in2(int n, vector<set<int>> &a) {
    while(n--) {
        int x, y;
        cin>>x>>y;
        x--, y--;
        a[y].insert(x);
    }
    return;
}

void go(vector<set<int>> &ban, vector<ll> &curr, vector<ll> &prev) {
    int n=(int)curr.size();
    multiset<ll> active;
    for(auto i : prev) {
        active.insert(i);
    }
    for(int i=0; i<n; i++) {
        ll base=curr[i];
        curr[i]=(ll)5e8;
        for(auto  j : ban[i]) {
            active.erase(active.lower_bound(prev[j]));
        }
        if(!active.empty()) {
            curr[i]=min(curr[i], base+*active.begin());
        }
        for(auto  j : ban[i]) {
            active.insert(prev[j]);
        }
    }
    return;
}

void solve() {
    int n1, n2, n3, n4, m1, m2, m3;
    cin>>n1>>n2>>n3>>n4;
    vector<ll> one(n1), two(n2), three(n3), four(n4);
    vector<set<int>> x(n2), y(n3), z(n4);
    in(one), in(two), in(three), in(four);
    cin>>m1, in2(m1, x);
    cin>>m2, in2(m2, y);
    cin>>m3, in2(m3, z);
    go(x, two, one);
    go(y, three, two);
    go(z, four, three);
    ll ans=5e8;
    for(auto &i : four) {
        ans=min(ans, i);
    }
    if(ans==(ll)5e8) {
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
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}

