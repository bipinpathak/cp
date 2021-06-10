#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> primes;

void pre() {
    int n=1;
    while(n*n<=1e9) {
        n++;
    }
    vector<int> lp(n+1, 0);
    for(int i=2; i<=n; i++) {
        if(lp[i]==0) {
            primes.push_back(i);
        }
        for(auto p : primes) {
            if(p>lp[i] || p*i>n) {
                break;
            }
            lp[p*i]=p;
        }
    }
    return;
}

int count(int n) {
    int ans=0;
    for(auto p : primes) {
        while(n%p==0) {
            n/=p;
            ans++;
        }
        if(n==1) {
            break;
        }
    }
    ans+=n>1;
    return ans;
}

void solve() {
    int a, b, k;
    cin>>a>>b>>k;
    if(k==1 && a==b) {
        cout<<"No"<<endl;
        return;
    }
    int f=__gcd(a, b);
    int low=0, high=0;
    low=(a>f)+(b>f);
    high=count(a)+count(b);
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
    pre();
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}
