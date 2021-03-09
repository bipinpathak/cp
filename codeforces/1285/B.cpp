#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll go(vector<ll> &a) {
    ll curr=0, high=0;
    for(auto &i : a) {
        curr=max((ll)0, curr+i);
        high=max(high, curr);
    }
    return high;
}

bool solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    ll total=0, low=-1e9;
    for(auto &i : a) {
        cin>>i;
        total+=i;
        low=max(low, i);
    }
    ll high=low, temp=a.back();
    a.pop_back();
    high=max(high, go(a));
    a.push_back(temp);
    reverse(a.begin(), a.end());
    a.pop_back();
    high=max(high, go(a));
    if(low<0) {
        high=low;
    }
    return total>high;
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
        if(solve()) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

