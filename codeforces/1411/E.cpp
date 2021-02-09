#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll a, ll x) {
	ll ans=1;
	while(x) {
		if(x&1) {
			ans*=a;
		}
		x=x>>1;
		a*=a;
	}
	return ans;
}
bool solve() {
    ll n, target;
    string s;
    cin>>n>>target>>s; 
    vector<int> have(26, 0);
    ll total=0;
    target-=power(2, s.back()-'a');
    s.pop_back();
    target+=power(2, s.back()-'a');
    s.pop_back();
    for(auto i : s) {
        int curr=i-'a';
        have[curr]++;
        ll val=power(2, curr);
        total+=val;
    }
    ll need=total-target;
    if(need%2) {
        return false;
    } else {
        need/=2;
    }
    for(int i=25; i>=0 && need>0; i--) {
        ll val=power(2, i);
         while(have[i] && need>=val) {
            have[i]--;
            need-=val;
         }
    }
    return need==0;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--) {
        if(solve()) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
