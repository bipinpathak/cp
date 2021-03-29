#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool good(ll n) {
    ll sum=0, temp=n;
    while(temp) {
        sum+=temp%10;
        temp/=10;
    }
    return __gcd(sum, n)>1;
}

void solve() {
    ll n;
    cin>>n;
    while(!good(n)) {
        n++;
    }
    cout<<n<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

