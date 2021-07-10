#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> lp(n+1), primes;
    for(int i=2; i<=n; i++) {
        if(lp[i]==0) {
            lp[i]=i;
            primes.push_back(i);
        }
        for(auto j : primes) {
            if(j>lp[i] || j*i>n) {
                break;
            }
            lp[j*i]=j;
        }
    }
    map<int, int> index;
    for(auto i : lp) {
        index[i]=0;
    }
    index.erase(index.begin());
    int key=1;
    for(auto &i : index) {
        i.second=key;
        key++;
    }
    for(int i=2; i<=n; i++) {
        cout<<index[lp[i]]<<" ";
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

