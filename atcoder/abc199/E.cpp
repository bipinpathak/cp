#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct condition{
    int high, count;
    condition(int highi, int counti) : high(highi), count(counti) {}
};

int n;
vector<vector<condition>> c;
map<vector<int>, ll> dp;

bool valid(int index, vector<int> &seen) {
    while(index<n) {
        for(auto j: c[index]) {
            if(seen[j.high]>j.count) {
                return false;
            }   
        }
        index++;
    }
    return true;
}

ll fetch(vector<int> &state, vector<int> &seen) {
    if(state[0]==n) {
        return 1;
    }
    if(dp.find(state)==dp.end()) {
        ll ans=0;
        for(int i=0; i<n; i++) {
            int curr=1<<i;
            if(state[1]&curr) {
                continue;
            }
            state[1]+=curr;
            for(int j=i; j<n; j++) {
                seen[j]++;
            }
            if(valid(state[0], seen)) {
                state[0]++;
                ans+=fetch(state, seen);
                state[0]--;
            }
            state[1]-=curr;
            for(int j=i; j<n; j++) {
                seen[j]--;
            }
        }
        dp[state]=ans;
    }
    return dp[state];
}

void solve() {
    int m;
    cin>>n>>m;
    c.resize(n);
    while(m--) {
        int x, y, z;
        cin>>x>>y>>z;
        x--, y--;
        condition ci(y, z);
        c[x].push_back(ci);
    }
    vector<int> start={0, 0}, seen(n);
    cout<<fetch(start, seen)<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

