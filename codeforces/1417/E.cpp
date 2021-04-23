#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> store(n, vector<int> (30));
    vector<int> a;
    int x;
    for(int i=0; i<n; i++) {
        a.push_back(i);
        cin>>x;
        for(int j=0; j<30 && x; j++) {
            store[i][j]=x&1;
            x>>=1;
        }           
    }
    queue<vector<int>> active;
    active.push(a);
    x=0;
    ll ans=0, inversions=0;
    for(int j=29; j>=0; j--) {
        vector<ll> cost(2);
        n=(int)active.size();
        while(n--) {
            auto curr=active.front();
            active.pop();
            vector<int> zero, one;
            for(auto i : curr) {
                vector<int> seen={(int)zero.size(), (int)one.size()};
                cost[store[i][j]]+=seen[!store[i][j]];
                if(store[i][j]) {
                    one.push_back(i);
                } else {
                    zero.push_back(i);
                }
            }
            if((int)one.size()>1) {
                active.push(one);
            }
            if((int)zero.size()>1) {
                active.push(zero);
            }
        }
        int chosen=(cost[1]<cost[0]);
        ans<<=1;
        ans+=chosen;
        inversions+=cost[chosen];
    }
    cout<<inversions<<" "<<ans<<endl;
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

