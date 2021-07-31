#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0; i<4; i++) {
        a.push_back(n%10);
        n/=10;
    }
    reverse(a.begin(), a.end());
    string ans="Weak";
    for(int i=0; i<4; i++) {
        if(a[i]!=a[0]) {
            ans="Strong";
            break;
        }
    }
    if(ans=="Strong") {
        int last=a[0];
        ans="Weak";
        for(int i=1; i<4; i++) {
            last=(last+1)%10;
            if(a[i]!=last) {
                ans="Strong";
                break;
            }
            last=a[i];
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

