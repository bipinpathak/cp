#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> odd, even;
    while(n--) {
        int a;
        cin>>a;
        if(a&1) {
            odd.push_back(a);
        } else {
            even.push_back(a);
        }
    }
    int m=odd.size();
    n=even.size();
    int ans=n*m+(n*(n-1))/2;
    for(int i=0; i<m; i++) {
        for(int j=i+1; j<m; j++) {
            if(__gcd(odd[i], odd[j])>1) {
                ans++;
            }
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

