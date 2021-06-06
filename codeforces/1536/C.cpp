#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> reduce(int d, int k) {
    int g=__gcd(d, k);
    if(g) {
        d/=g;
        k/=g;
    }
    return {d, k};
}

void solve() {
    int n;
    string s;
    cin>>n>>s;
    map<vector<int>, int> count;
    int d=0, k=0;
    for(auto i : s) {
       if(i=='D') {
           d++;
       } else {
           k++;
       }
       auto curr=reduce(d, k);
       count[curr]++;
       cout<<count[curr]<<" ";
    }       
    cout<<endl;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

