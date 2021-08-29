#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll askand(int i, int j) {
    cout<<"and "<<i+1<<" "<<j+1<<endl;
    ll res;
    cin>>res;
    return res;
}

ll askor(int i, int j) {
    cout<<"or "<<i+1<<" "<<j+1<<endl;
    ll res;
    cin>>res;
    return res;
}
void solve() {
    int n, k;
    cin>>n>>k;
    vector<ll> a(n);
    ll a1=askand(0, 1), a2=askand(1, 2), a3=askand(0, 2), o1=askor(0, 1), o2=askor(1, 2), curr=1;
    while(a1 || a2 || o1 || o2) {
        if((a1&1)==1) {
            a[0]+=curr;
            a[1]+=curr;
            if((a2&1)==1) {
                a[2]+=curr;
            }
        } else if((a2&1)==1) {
            a[1]+=curr;
            a[2]+=curr;
        } else {
            if((o1&1)==0) {
                if((o2&1)) {
                    a[2]+=curr;
                }
            } else if((o2&1)==0) {
                if((o1&1)) {
                    a[0]+=curr;
                }
            } else {
                if((a3&1)) {
                    a[0]+=curr;
                    a[2]+=curr;
                } else {
                    a[1]+=curr;
                }
            }
        }
        a1>>=1;
        a2>>=1;
        a3>>=1;
        o1>>=1;
        o2>>=1;
        curr<<=1;
    }
    for(int i=3; i<n; i++) {
        ll ai=askand(i, i-1), oi=askor(i, i-1);
        a[i]=oi+ai-a[i-1];
    }
    sort(a.begin(), a.end());
    cout<<"finish "<<a[k-1]<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    //(void)!freopen("input.txt", "r", stdin);
    //(void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    auto start=clock();
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

