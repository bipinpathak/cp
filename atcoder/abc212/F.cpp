#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(ll u, vector<ll> &adjacency, vector<vector<ll>> &down) {
    if(adjacency[u]!=-1) {
        go(adjacency[u], adjacency, down);
        down[u][0]=adjacency[u];
        for(ll i=1; i<17 && down[u][i-1]!=-1; i++) {
            down[u][i]=down[down[u][i-1]][i-1];
        }
    }
    return;
}

ll calc(ll u, vector<vector<ll>> &down, ll &z, vector<vector<ll>> &busses) {
    ll jump=0;
    while(jump<17 && down[u][jump]!=-1 && busses[down[u][jump]][0]<z) {
        jump++;
    }
    jump--;
    if(jump<0) {
        return u;
    } 
    return calc(down[u][jump], down, z, busses);
}


void solve() {
    ll n, m, q;
    cin>>n>>m>>q;
    vector<vector<ll>> busses(m, vector<ll> (4));
    for(auto &i : busses) {
        cin>>i[2]>>i[3]>>i[0]>>i[1];
        i[2]--, i[3]--;
    }
    sort(busses.begin(), busses.end());
    vector<vector<vector<ll>>> city(n);
    for(ll i=0; i<m; i++) {
        city[busses[i][2]].push_back({busses[i][0], busses[i][1], busses[i][3], i});
    }
    vector<ll> adjacency(m, -1);
    for(ll i=0; i<m; i++) {
        ll b=busses[i][3], t=busses[i][1]; 
        if(city[b].empty() || city[b].back().front()<t) {
            continue;
        }
        vector<ll> temp={t, 0, 0, 0};
        auto next=*lower_bound(city[b].begin(), city[b].end(), temp);
        adjacency[i]=next.back();;
    }
    vector<vector<ll>> down(m, vector<ll> (17, -1));
    for(int i=0; i<m; i++) {
        if(down[i][0]==-1) {
            go(i, adjacency, down);
        }
    }
    while(q--) {
        ll x, y, z;
        cin>>x>>y>>z;
        y--;
        if(city[y].empty() || x>city[y].back().front()) {
            cout<<y+1<<endl;
            continue;
        }
        vector<ll> temp={x, 0, 0, 0};
        auto start=*lower_bound(city[y].begin(), city[y].end(), temp);
        if(start[0]>=z) {
            cout<<busses[start[3]][2]+1<<endl;
            continue;
        }
        auto last=calc(start[3], down, z, busses);
        if(busses[last][1]>=z) {
            cout<<busses[last][2]+1<<" "<<busses[last][3]+1<<endl; 
        } else {
            cout<<busses[last][3]+1<<endl;
        }
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
    auto start=clock();
    int t = 1;
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

