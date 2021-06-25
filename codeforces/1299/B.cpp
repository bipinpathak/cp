#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct point{
    ll x, y;
};

bool dist(point a, point b, point c, point d) {
    return (pow(a.x-b.x, 2)+pow(a.y-b.y, 2))==(pow(c.x-d.x, 2)+pow(c.y-d.y, 2));
}

bool parallel(point a, point b, point c, point d) {
    return (a.x-b.x)*(c.y-d.y)==(c.x-d.x)*(a.y-b.y);
}

bool check(point a, point b, point c, point d) {
    return parallel(a, b, c, d) && dist(a, b, c, d);
}   

void solve() {
    int n;
    cin>>n;
    vector<point> a(n);
    for(auto &i : a) {
        cin>>i.x>>i.y;
    }
    string ans="Yes";
    for(int i=0; i<n; i++) {
        if(!check(a[i], a[(i+1)%n], a[(i+n/2)%n], a[(i+1+n/2)%n])) {
            ans="No";
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

