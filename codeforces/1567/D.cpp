#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll s, n;
    cin>>s>>n;
    vector<ll> a;
    ll have=0;
    while(s) {
        a.push_back(s%10);
        s/=10;
        have+=a.back();
    }
    ll need=n-have, m=(ll)a.size(), d=0;
    for(ll i=1; i<m && need>0; i++) {
        d=d*10+9;
        ll available=a[i]*d;
        if(available<need) {
            a[0]+=available+a[i];
            a[i]=0;
            need-=available;
        } else {
            for(ll j=i; j && need>0; j--) {
                ll count=(need+d-1)/d;
                a[j]-=count;
                a[j-1]+=10*count;
                need-=count*9;
                d/=10;
            }
            break;
        }
    }
    vector<ll> ans;
    d=1;
    for(ll i=0; i<m && (ll)ans.size()<n-1; i++) {
        while(a[i] && (ll)ans.size()<n-1) {
            ans.push_back(d);
            a[i]--;
        }
        d*=10;
    }
    d=0;
    reverse(a.begin(), a.end());
    for(auto i : a) {
        d=d*10+i;
    }
    ans.push_back(d);
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

