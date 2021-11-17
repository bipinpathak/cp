#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    ll kx, ky;
    cin>>kx>>ky;
    map<char, int> index;
    index['R']=0;
    index['B']=1;
    index['Q']=2;
    vector<vector<vector<ll>>> peices(3);
    while(n--) {
        char c;
        ll x, y;
        cin>>c>>x>>y;
        peices[index[c]].push_back({x, y});
    }
    ll low=-1e9-1, high=1e9+1;
    for(auto i : peices[1]) {
        if(i[0]!=kx) {
            continue;
        }
        if(i[1]<ky) {
            low=max(low, i[1]);
        } else {
            high=min(high, i[1]);
        }
    }
    for(auto i : peices[0]) {
        if(i[0]!=kx) {
            continue;
        }
        if((i[1]>ky && i[1]<high) || (i[1]<ky && i[1]>low)) {
            cout<<"YES"<<endl;
            return;
        }
    }
    for(auto i : peices[2]) {
        if(i[0]!=kx) {
            continue;
        }
        if((i[1]>ky && i[1]<high) || (i[1]<ky && i[1]>low)) {
            cout<<"YES"<<endl;
            return;
        }
    }
    low=-1e9-1, high=1e9+1;
    for(auto i : peices[1]) {
        if(i[1]!=ky) {
            continue;
        }
        if(i[0]<kx) {
            low=max(low, i[0]);
        } else {
            high=min(high, i[0]);
        }
    }
    for(auto i : peices[0]) {
        if(i[1]!=ky) {
            continue;
        }
        if((i[0]>kx && i[0]<high) || (i[0]<kx && i[0]>low)) {
            cout<<"YES"<<endl;
            return;
        }
    }
    for(auto i : peices[2]) {
        if(i[1]!=ky) {
            continue;
        }
        if((i[0]>kx && i[0]<high) || (i[0]<kx && i[0]>low)) {
            cout<<"YES"<<endl;
            return;
        }
    }
    ll d=kx+ky;
    low=-1e9-1, high=1e9+1;
    for(auto i : peices[0]) {
        if(i[0]+i[1]!=d) {
            continue;
        }
        if(i[0]<kx) {
            low=max(low, i[0]);
        } else {
            high=min(high, i[0]);
        }
    }
    for(auto i : peices[1]) {
        if(i[0]+i[1]!=d) {
            continue;
        }
        if((i[0]>kx && i[0]<high) || (i[0]<kx && i[0]>low)) {
            cout<<"YES"<<endl;
            return;
        }
    }
    for(auto i : peices[2]) {
        if(i[0]+i[1]!=d) {
            continue;
        }
        if((i[0]>kx && i[0]<high) || (i[0]<kx && i[0]>low)) {
            cout<<"YES"<<endl;
            return;
        }
    }
    d=kx-ky;
    low=-1e9-1, high=1e9+1;
    for(auto i : peices[0]) {
        if(i[0]-i[1]!=d) {
            continue;
        }
        if(i[0]<kx) {
            low=max(low, i[0]);
        } else {
            high=min(high, i[0]);
        }
    }
    for(auto i : peices[1]) {
        if(i[0]-i[1]!=d) {
            continue;
        }
        if((i[0]>kx && i[0]<high) || (i[0]<kx && i[0]>low)) {
            cout<<"YES"<<endl;
            return;
        }
    }
    for(auto i : peices[2]) {
        if(i[0]-i[1]!=d) {
            continue;
        }
        if((i[0]>kx && i[0]<high) || (i[0]<kx && i[0]>low)) {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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

