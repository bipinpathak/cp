#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, x;
    cin>>n>>x;
    vector<int> w(n);
    for(auto &i : w) {
        cin>>i;
    }
    sort(w.begin(), w.end());
    int sum=0;
    for(int i=0; i<n; i++) {
        sum+=w[i];
        if(sum==x) {
            swap(w[i], w[n-1]);
            break;
        }
    }
    sum=0;
    for(auto i : w) {
        sum+=i;
        if(sum==x) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    for(auto i : w) {
        cout<<i<<" ";
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

