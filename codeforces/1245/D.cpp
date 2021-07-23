#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calc(int a, int b, vector<vector<int>> &city, vector<int> &wire) {
    ll ans=abs(city[a][0]-city[b][0]);
    ans+=abs(city[a][1]-city[b][1]);
    ans*=wire[a]+wire[b];
    return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> city(n, vector<int> (2));
    vector<int> wire(n);
    vector<ll> cost(n);
    for(auto &i : city) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    for(auto &i : cost) {
        cin>>i;
    }
    for(auto &i : wire) {
        cin>>i;
    }
    vector<int> done(n), sources, parent(n, -1);
    vector<vector<int>> connections;
    ll total=0;
    for(int k=0; k<n; k++) {
        int best=-1;
        for(int i=0; i<n; i++) {
            if(done[i]) {
                continue;
            }
            if(best==-1 || cost[i]<cost[best]) {
                best=i;
            }
        }
        if(best==-1) {
            break;
        }
        total+=cost[best];
        if(parent[best]==-1) {
            sources.push_back(best);
        } else {
            connections.push_back({parent[best], best});
        }
        done[best]=1;
        for(int i=0; i<n; i++) {
            if(done[i]) {
                continue;
            }
            if(calc(best, i, city, wire)<cost[i]) {
                cost[i]=calc(best, i, city, wire);
                parent[i]=best;
            }
        }   
    }   
    cout<<total<<endl;
    cout<<sources.size()<<endl;
    for(auto i : sources) {
        cout<<i+1<<" ";
    }
    cout<<endl;
    cout<<connections.size()<<endl;
    for(auto i : connections) {
        for(auto j : i) {
            cout<<j+1<<" ";
        }
        cout<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

