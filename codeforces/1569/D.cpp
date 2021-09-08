#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll calc(vector<int> &a) {
    ll n=a.size(), ans=(n*(n-1))/2;
    map<int, ll> count;
    while(!a.empty()) {
        count[a.back()]++;
        a.pop_back();
    }
    for(auto i : count) {
        n=i.second;
        ans-=(n*(n-1))/2;
    }
    return ans;
}

ll go(vector<vector<int>> people, set<int> &roads) {
    ll ans=0;
    vector<int> points;
    sort(people.begin(), people.end());
    while(!people.empty()) {
        int high=*roads.rbegin();
        while(!people.empty() && people.back().front()==high) {
            people.pop_back();
        }
        roads.erase(high);
        if(roads.empty() || people.empty()) {
            break;
        }
        int low=*roads.rbegin();
        while(!people.empty() && people.back().front()>low) {
            points.push_back(people.back().back());
            people.pop_back();
        }
        ans+=calc(points);
    }
    return ans;
}

void solve() {
    int n, m, k;
    cin>>n>>m>>k;
    set<int> x, y;
    while(n--) {
        int z;
        cin>>z;
        x.insert(z);
    }
    while(m--) {
        int z;
        cin>>z;
        y.insert(z);
    }
    vector<vector<int>> people;
    while(k--) {
        int xi, yi;
        cin>>xi>>yi;
        if(x.count(xi) && y.count(yi)) {
            continue;
        }
        people.push_back({xi, yi});
    }
    ll ans=go(people, x);
    for(auto &i : people) {
        swap(i[0], i[1]);
    }
    ans+=go(people, y);
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

