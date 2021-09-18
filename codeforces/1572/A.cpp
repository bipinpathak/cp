#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> left(n);
    vector<vector<int>> adjacency(n);
    set<int> active;
    for(int i=0; i<n; i++) {
        cin>>left[i];
        for(int j=0; j<left[i]; j++) {
            int prev;
            cin>>prev;
            prev--;
            adjacency[prev].push_back(i);
        }
        if(left[i]==0) {
            active.insert(i);
        }
    }
    int ans=0;
    while(!active.empty()) {
        ans++;
        int curr=-1;
        while(1) {
            auto next=active.upper_bound(curr);
            if(next==active.end()) {
                break;
            }
            curr=*next;
            for(auto v : adjacency[curr]) {
                left[v]--;
                if(left[v]==0) {
                    active.insert(v);
                }
            }
            active.erase(curr);
        }
    }
    for(auto &i : left) {
        if(i) {
            ans=-1;
            break;
        }
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

