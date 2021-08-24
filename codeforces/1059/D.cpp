#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

bool possible(ld r, vector<vector<ld>> &a) {
    r*=(ld)2;
    ld low=-1e18, high=1e18; 
    int n=(int)a.size();
    for(int i=0; i<n && low<=high; i++) {
        ld x=a[i][0], y=a[i][1];
        if(y>r) {
            return false;
        }
        ld d=y*(r-y);
        d=sqrtl(d);
        low=max(low, x-d);
        high=min(high, x+d);
    }
    return low<=high;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<ll>> a(n, vector<ll> (2));
    bool up=false, down=false;
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
        up=up|(i[1]>0);
        down=down|(i[1]<0);
    }
    if(up && down) {
        cout<<-1<<endl;
        return;
    }
    ll lowest=1e7;
    for(auto &i : a) {
        if(down) {
            i[1]*=-1;
        }
        lowest=min(lowest, i[0]);
    }
    lowest*=-1;
    for(auto &i : a) {
        i[0]+=lowest;
    }
    vector<vector<ld>> use(n, vector<ld> (2));
    for(int i=0; i<n; i++) {
        for(int j=0; j<2; j++) {
            use[i][j]=(ld)a[i][j];
        }
    }
    ld low=0, high=1e18, e=1e-6, two=2;
    while(high-low>e*max((ld)1, low)) {
        ld mid=low+(high-low)/two;
        if(possible(mid, use)) {
            high=mid;
        }  else {
            low=mid;
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
    cout<<fixed<<setprecision(9);
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

