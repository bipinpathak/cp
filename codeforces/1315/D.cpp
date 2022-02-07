#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int> (2));
    for(auto &i : a) {
        cin>>i[0];
    }
    for(auto &i : a) {
        cin>>i[1];
    }
    sort(a.rbegin(), a.rend());
    priority_queue<int> active;
    int curr=0;
    ll total=0, ans=0;
    while(!a.empty() || !active.empty()) {
        if(active.empty() && !a.empty()) {
            curr=a.back().front();
        }
        while(!a.empty() && a.back().front()==curr) {
            total+=a.back().back();
            active.push(a.back().back());
            a.pop_back();
        }
        total-=active.top();
        active.pop();
        ans+=total;
        curr++;
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

