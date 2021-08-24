#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void calc(int my, int other, int won, int lost, vector<int> &possible) {
    for(int x=0; won-x<=other && x<=won && x<=my; x++) {
        possible[won-x+my-x]++;
    }
    return;
}

void solve() {
    int a, b;
    cin>>a>>b;
    int n=a+b;
    vector<int> possible(n+3);
    calc(n/2, n-n/2, a, b, possible);
    calc(n-n/2, n/2, a, b, possible);
    calc(n/2, n-n/2, b, a, possible);
    calc(n-n/2, n/2, b, a, possible);
    vector<int> ans;
    for(int i=0; i<n+3; i++) {
        if(possible[i]) {
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(auto i : ans) {
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

