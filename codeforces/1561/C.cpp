#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool possible(ll curr, vector<vector<ll>> &a) {
    for(auto i : a) {
        if(curr<i[0]) {
            return false;
        }
        curr+=i[1];
    }
    return true;
}

void solve() {
    ll n;
    cin>>n;
    vector<vector<ll>> cave(n);
    for(auto &i : cave) {
        ll k;
        cin>>k;
        while(k--) {
            ll p;
            cin>>p;
            i.push_back(p);
        }
    }
    vector<vector<ll>> a(n, vector<ll> (2));
    for(ll i=0; i<n; i++) {
        ll curr=0, k=(ll)cave[i].size();
        for(ll j=0; j<k; j++) {
            curr=max(curr, cave[i][j]-j+1);
        }
        a[i][0]=curr;
        a[i][1]=k;
    }
    sort(a.begin(), a.end());
    ll low=0, high=1e9+1;
    while(low<high) {
        ll mid=low+(high-low)/2;
        if(possible(mid, a)) {
            high=mid;
        } else {
            low=mid+1;
        }
    }   
    cout<<low<<endl;
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

