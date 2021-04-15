#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct point{
    ll x, y;
};

void solve() {
    ll n;
    cin>>n;
    set<vector<ll>> count;
    vector<point> a(n);
    for(auto &i : a) {
        cin>>i.x>>i.y;
    }
    for(ll i=0; i<n; i++) {
        for(ll j=i+1; j<n; j++) {
            vector<ll> build={a[j].x-a[i].x, a[j].y-a[i].y, a[i].y*a[j].x-a[i].x*a[j].y};
            if(build.front()<0 || (build.front()==0 && build[1]<0)) {
                for(auto &k : build) {
                    k*=-1;
                }
            }
            ll c=abs(build.front());
            for(auto &k : build) {
                c=__gcd(c, abs(k));
            }
            if(c) {
                for(auto &k : build) {
                    k/=c;
                }
            }
            count.insert(build);
        }
    }
    ll ans=0;
    n=(ll) count.size();
    ans=(n*(n-1))/2;
    map<vector<ll>, ll> slope;
    for(auto i : count) {
        i.pop_back();
        ll c=abs(i.front());
        for(auto &k : i) {
            c=__gcd(c, abs(k));
        }
        if(c) {
            for(auto &k : i) {
                k/=c;
            }
        }
        if(i[0]==0 && i[1]<0) {
            i[1]*=-1;
        }
        slope[i]++;
    }
    for(auto &i : slope) {
        n=i.second;
        ans-=(n*(n-1))/2;
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

