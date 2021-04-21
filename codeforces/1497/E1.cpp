#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int high=1e7;
vector<int> prime, lprime(high+1);

void pre() {
    for(int i=2; i<=high; i++) {
        if(lprime[i]==0) {
            lprime[i]=i;
            prime.push_back(i);
        }
        for(auto p : prime) {
            if(p>lprime[i] || (ll)i*p>high) {
                break;
            }
            lprime[i*p]=p;
        }
    }
    return;
}

void solve() {
    int n, k;
    cin>>n>>k;
    int ans=1;
    set<set<int>> seen;
    while(n--) {
        int a;
        cin>>a;
        set<int> oddPowers;
        while(a>1) {
            if(oddPowers.count(lprime[a])) {
                oddPowers.erase(lprime[a]);
            } else {
                oddPowers.insert(lprime[a]);
            }
            a/=lprime[a];
        }
        if(seen.count(oddPowers)) {
            ans++;
            seen.clear();
        }
        seen.insert(oddPowers);
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
    int t = 1;
    cin >> t;
    pre();
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

