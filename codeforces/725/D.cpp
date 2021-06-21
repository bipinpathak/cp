#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<ll>> teams(n, vector<ll> (2));
    for(auto &i : teams) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    map<vector<ll>, int> low;
    map<ll, int> high;
    int highsum=0;
    for(int i=1; i<n; i++) {
        if(teams[i][0]<=teams[0][0]) {
            teams[i][0]*=-1;
            low[teams[i]]++;
        } else {
            high[teams[i][1]+1-teams[i][0]]++;
            highsum++;
        }
    }
    int ans=highsum+1;
    while(teams[0][0] && !high.empty()) {
        ll need=high.begin()->first;
        if(need>teams[0][0]) {
            break;
        }
        teams[0][0]-=need;
        highsum--;
        if(high.begin()->second==1) {
            high.erase(high.begin());
        } else {
            high.begin()->second--;
        }
        while(!low.empty() && -low.begin()->first[0]>teams[0][0]) {
            auto curr=low.begin()->first;
            curr[0]*=-1;
            highsum++;
            high[curr[1]+1-curr[0]]++;
            if(low.begin()->second==1) {
                low.erase(low.begin());
            } else {
                low.begin()->second--;
            }
        }
        ans=min(ans, highsum+1);
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

