#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int a, b, k;
    cin>>a>>b>>k;
    if(k==1 && a==b) {
        cout<<"No"<<endl;
        return;
    }
    int f=__gcd(a, b);
    int low=0, high=0;
    if(a>f) {
        low++;
    }
    if(b>f) {
        low++;
    }
    for(int i=2; i*i<=a; i++) {
        while(a%i==0) {
            a/=i;
            high++;
        }
    }
    high+=a>1;
    for(int i=2; i*i<=b; i++) {
        while(b%i==0) {
            b/=i;
            high++;
        }
    }
    high+=b>1;
    string ans="No";
    if(low<=k && k<=high) {
        ans="Yes";
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

