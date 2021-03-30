#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<pair<int, ll>, int> store;

int go(int val, ll mask) {
    if(val==0) {
        return 0;
    }
    ll curr=(ll)1<<val;
    for(int i=val+1; i<=60; i++) {
        if(curr&mask) {
            mask-=curr;
        }
        curr=curr<<1;
    }
    if(store.find({val, mask})==store.end()) {
        int ans=0;
        set<int> have;
        curr=1;
        for(int i=0; i<val; i++) {
            if(mask&curr) {
                mask-=curr;
                have.insert(go(val-i-1, mask));
                mask+=curr;
            }
            curr=curr<<1;
        }
        while(have.find(ans)!=have.end()) {
            ans++;
        }
        store[{val, mask}]=ans;
    }
    return store[{val, mask}];
}

void solve() {
    vector<int> grundy(61);
    ll mask=0;
    for(int i=1; i<=60; i++) {
        mask=mask<<1;
        mask++;
        grundy[i]=go(i, mask);
    }
    string ans="YES";
    int n, curr=0;
    cin>>n;
    while(n--) {
        int x;
        cin>>x;
        curr^=grundy[x];
    }
    if(curr) {
        ans="NO";
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

