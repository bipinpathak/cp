#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<ll> b(n+2);
    ll total=0;
    map<ll, int> have;
    for(auto &i : b) {
        cin>>i;
        total+=i;
        have[i]++;
    }
    bool found=false;
    ll x;
    for(int i=0; i<n+2 && !found; i++) {
        x=total-2*b[i];
        if((x==b[i] && have[x]>=2) || (x!=b[i] && have[x])) {
            have[x]--;
            have[b[i]]--;
            found=true;
        }
    }
    vector<ll> ans;
    if(found) {
        for(auto i : have) {
            while(i.second--) {
                ans.push_back(i.first);
            }
        }
    } else {
        ans={-1};
    }
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
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

