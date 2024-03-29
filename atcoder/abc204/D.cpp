#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int total=0;
    for(auto &i : a) {
        cin>>i;
        total+=i;
    }   
    vector<int> possible(total+1);
    possible[0]=1;
    for(auto i : a) {
        for(int curr=total; curr>=i; curr--) {
            if(possible[curr-i]) {
                possible[curr]=1;
            }
        }
    }
    int ans=total;
    for(int i=0; i<=total; i++) {
        if(!possible[i]) {
            continue;
        }
        ans=min(ans, max(i, total-i));
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

