#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int ask(int n) {
    cout<<"? "<<n<<endl;
    int ans;
    cin>>ans;
    return ans;
}

void tell(int n) {
    cout<<"! "<<n<<endl;
    return;
}

void solve() {
    int n;
    cin>>n;
    int l=1, r=n;
    while(l<r) {
        int mid=l+(r-l)/2;
        int a=ask(mid), b=ask(mid+1);
        if(a>b) {
            l=mid+1;
        } else {
            r=mid;
        }
    }
    tell(l);
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

