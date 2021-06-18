#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<int, int> grundy;

vector<int> go(int n) {
    vector<int> ans;
    for(int i=2; i*i<=n; i++) {
        if(n%i==0) {
            ans.push_back(i);
            if(i*i!=n) {
                ans.push_back(n/i);
            }
        }
    }
    return ans;
}

int fetch(int curr) {
    if(!grundy.count(curr)) {
        set<int> have;
        auto moves=go(curr);
        for(auto v : moves) {
            have.insert(fetch(curr-v));  
        }
        int ans=0;
        while(have.count(ans)) {
            ans++;
        }
        grundy[curr]=ans;
    }
    return grundy[curr];
}

void solve() {
    int n;
    cin>>n;
    string ans="Bob";
    int count=0;
    while(n%2==0) {
        n/=2;
        count++;
    }
    if(count && (n>1 || count%2==0)) {
        ans="Alice";
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

