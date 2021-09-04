#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    vector<string> have(3);
    for(auto &i : have) {
        cin>>i;
    }
    set<string> all={"ABC", "ARC", "AGC", "AHC"};
    for(auto i : have) {
        all.erase(i);
    }
    cout<<*all.begin()<<endl;
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

