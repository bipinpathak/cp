#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    int one=0, two=0;
    while(n--) {
        int x;
        cin>>x;
        one+=x==1;
        two+=x==2;
    }
    n=one+(two*2);
    vector<int> sieve(n+1, 1), primes;
    for(ll i=2; i<=n; i++) {
        if(sieve[i]==0) {
            continue;
        }
        primes.push_back(i);
        for(ll j=i*i; j<=n; j+=i) {
            sieve[j]=0;
        }
    }
    n=primes.size();
    vector<int> ans;
    int sum=0;
    for(auto i : primes) {
        while(sum<i && (one || two)) {
            if(two) {
                ans.push_back(2);
                two--;
            } else {
                ans.push_back(1);
                one--;
            }
            sum+=ans.back();
        }
        if(!(one || two)) {
            break;
        }
        if(sum==i) {
            continue;
        }
        if(sum>i && one) {
            sum--;
            ans.back()=1;
            one--;
            two++;
        }
    }
    while(one--) {
        ans.push_back(1);
    }   
    while(two--) {
        ans.push_back(2);
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
    while(t--) {
        solve();
    }
    return 0;
}

