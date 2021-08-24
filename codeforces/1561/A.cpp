#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(int i, vector<int> &a, int &ans, set<int> &left) {
    int n=(int)a.size();
    ans++;
    while(i+1<n && !left.empty()) {
        if(a[i]>a[i+1]) {
            swap(a[i], a[i+1]);
            if(a[i]==i) {
                left.erase(i);
            }   
            if(a[i+1]==i+1) {
                left.erase(i+1);
            }
        }
        i+=2;
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
        i--;
    }
    set<int> left;
    for(int i=0; i<n; i++) {
        if(a[i]!=i) {
            left.insert(i);
        }
    }
    int ans=0;
    for(int i=0; i<=n && !left.empty(); i++) {
        go(i%2, a, ans, left);
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

