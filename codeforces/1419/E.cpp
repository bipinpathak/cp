#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin>>n;
    vector<int> factors;
    for(ll i=2; i*i<=n; i++) {
        if(n%i==0) {
            factors.push_back(i);
            factors.push_back(n/i);
        }
    }
    sort(factors.begin(), factors.end());
    factors.erase(unique(factors.begin(), factors.end()), factors.end());
    vector<int> ans;
    ans.push_back(n);
    n=factors.size();
    int curr, left=0;
    vector<int> used(n);
    while(1) {
        curr=0;
        for(int i=left; i<n; i++) {
            if(!used[i]) {
                curr=factors[i];
                ans.push_back(factors[i]);
                used[i]=1;
                left=i+1;
                break;
            }
        }
        if(!curr) {
            break;
        }
        for(int i=n-1; i>=left; i--) {
            if(!used[i] && factors[i]%curr==0) {
                ans.push_back(factors[i]);
                used[i]=1;
            }
        }
    }
    curr=1;
    for(int i=2; i<n+1; i++) {
        if(ans[i]%ans[curr]!=0) {
            for(int j=i-1; j>curr; j--) {
                if(ans[j]==ans[i]*ans[curr]) {
                    swap(ans[j], ans[i-1]);
                    curr=i;
                    break;
                }
            }
        }
    }
    int count=0;
    for(int i=0; i<n+1; i++) {
        cout<<ans[i]<<" ";
        if(i && __gcd(ans[i], ans[i-1])==1) {
            count++;
        }
    }
    cout<<endl<<count<<endl;
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
    while(t--) {
        solve();
    }
    return 0;
}

