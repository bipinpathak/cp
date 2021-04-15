#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll a, b, m;
    cin>>a>>b>>m;
    if(a==b) {
        cout<<1<<" "<<a<<endl;
        return;
    }
    vector<ll> ans;
    int len=2;
    ll low=a+1, high=a+m;
    while(high<b) {
        len++;
        low=2*low;
        high=2*high;
    }
    if(low<=b) {
        ll base=pow((ll)2,  len-2);
        vector<ll> r;
        ll curr=a*base;
        base/=2;
        low-=curr+base;
        while(curr<b && base) {
            ll left=b-curr;
            ll build=min(m, (left-low)/base);
            r.push_back(build);
            curr+=base*build;
            base/=2;
            low-=base;
        }
        r.push_back(b-curr);
        ans={a};
        ll prefix=a;
        for(auto i : r) {
            ans.push_back(prefix+i);
            prefix+=ans.back();
        }       
    }
    if(ans.empty()) {
        cout<<-1;
    } else {
        cout<<ans.size();
        for(auto i : ans) {
            cout<<" "<<i;
        }
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
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

