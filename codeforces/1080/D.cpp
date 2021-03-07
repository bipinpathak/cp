#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cuts(ll i) {
    ll ans=((ll)1<<(i+1))-2-i;
    return ans;
}

void go(vector<ll> &a) {
    bool change=true;
    while(change) {
        sort(a.begin(), a.end());
        vector<ll> curr;
        change=false;
        for(auto i: a) {
            if(!curr.empty() && i==curr.back()) {
                curr.pop_back();
                change=true;
                i++;
            }
            curr.push_back(i);
        }
        a=curr;
    }
    return;
}

bool possible(ll n, ll i, ll k) {
    vector<ll> a, b;
    a={2*n, 2*n-2*i, i+1};
    b={2*n-i+1, 1};
    k*=3;
    ll curr=0;
    while(k) {
        if(k&1) {
            b.push_back(curr);
        }
        curr++;
        k=k>>1;
    }
    go(a);
    go(b);
    stack<ll> c, d;
    for(auto j : a) {
        if(!c.empty() && c.top()==j) {
            c.pop();
            j++;
        }
        c.push(j);
    }
    for(auto j : b) {
        if(!d.empty() && d.top()==j) {
            d.pop();
            j++;
        }
        d.push(j);
    }
    while(1) {
        if(!(c.empty() || d.empty())) {
            if(c.top()!=d.top()) {
                return c.top()>d.top();
            }
            c.pop();
            d.pop();
        } else if(c.empty() && !d.empty()) {
            return false;
        } else {
            break;
        }
    }
    return true;
}

void solve() {
    ll n, k;
    cin>>n>>k;
    ll i=0;
    while(cuts(i)<=k) {
        i++;
    }
    i--;
    i=min(i, n);
    if(possible(n, i, k)) {
        cout<<"YES "<<n-i<<endl;
    } else {
        cout<<"NO"<<endl;
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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

