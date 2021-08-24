#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, total, smoke;
    cin>>n>>total>>smoke;
    vector<vector<int>> people(n, vector<int> (2));
    for(auto &i : people) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    sort(people.begin(), people.end());
    int ans=0, prev=0;
    for(auto i : people) {
        ans+=(i[0]-prev)/smoke;
        prev=i[0]+i[1];
    }
    if(prev<total) {
        ans+=(total-prev)/smoke;
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

