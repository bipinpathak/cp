#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int h, w;
    cin>>h>>w;
    vector<string> a(h);
    for(auto &i : a) {
        cin>>i;
    }
    int ans=1, p=998244353;
    for(int d=0; d<h+w-1; d++) {
        map<char, int> count;
        for(int i=0; i<h; i++) {
            int j=d-i;
            if(j>=0 && j<w) {
                count[a[i][j]]++;
            }
        }
        if(count['R'] && count['B']) {
            ans=0;
        } else if(!(count['R'] || count['B'])) {
            ans=(ans*2)%p;
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

