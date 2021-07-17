#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(auto &i : a) {
        cin>>i;
    }
    for(auto &i : b) {
        cin>>i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int last=0;
    for(auto &i : a) {
        i+=last;
        last=i;
    }
    last=0;
    for(auto &i : b) {
        i+=last;
        last=i;
    }
    int atotal=a.back(), btotal=b.back(), ans=0;
    if(n>3) {
        atotal-=a[n/4-1];
        btotal-=b[n/4-1];
    }
    while(atotal<btotal) {
        ans++;
        n++;
        atotal=a.back()+ans*100, btotal=b.back();
        if(n>3) {
            atotal-=a[n/4-1];
        }
        int rem=n/4, temp=min(rem, ans);
        rem-=temp;
        if(rem) {
            btotal-=b[rem-1];
        }
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

