#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    string s;
    cin>>n>>k>>s;
    string temp="";
    string ans(k, 'z');
    for(auto j: s) {
        temp.push_back(j);
        string offer="";
        n=(int)temp.length();
        for(int i=0; i<k; i++) {
            offer.push_back(temp[i%n]);
        }
        ans=min(ans, offer);
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

