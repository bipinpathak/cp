#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, k, m;
    cin>>n>>k>>m;
    vector<ll> a(n);
    ll total=0;
    for(auto &i : a) {
        cin>>i;
        total+=i;
    }
    sort(a.begin(), a.end());
    ll sum=total, people=n;
    for(int i=0; i<min(n, m+1); i++) {
        ll currPeople=n-i, offer=total+min(m-i, k*currPeople); 
        if(offer*people>sum*currPeople) {
            people=currPeople;
            sum=offer;
        }
        total-=a[i];
    }   
    cout<<fixed<<setprecision(6);
    cout<<(double)sum/(double) people<<endl;
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
    while(t--) {
        solve();
    }
    return 0;
}

