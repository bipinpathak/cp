#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<double>> multiply(vector<vector<double>> &a, vector<vector<double>> &b) {
    int r1=(int)a.size(), c1=(int)a.front().size(), c2=(int)b.front().size();
    vector<vector<double>> ans(r1, vector<double> (c2));
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            for(int k=0; k<c1; k++) {
                ans[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    return ans;
}

vector<vector<double>> power(vector<vector<double>> a, int x) {
    int n=(int)a.size();
    vector<vector<double>> ans(n, vector<double> (n));
    for(int i=0; i<n; i++) {
        ans[i][i]=1;
    }
    while(x) {
        if(x&1) {
            ans=multiply(ans, a);
        }
        a=multiply(a, a);
        x=x>>1;
    }
    return ans;
}


void solve() {
    int n, x;
    cin>>n>>x;
    vector<double> p(x+1);
    for(auto &i : p) {
        cin>>i;
    }
    x=128;
    while((int)p.size()<128) {
        p.push_back(0);
    }
    vector<vector<double>> a(1, vector<double> (x)), b(x, vector<double> (x));
    a[0][0]=1;
    for(int i=0; i<x; i++) {
        for(int j=0; j<x; j++) {
            b[i][i^j]+=p[j];
        }
    }
    b = power(b, n);
    a=multiply(a, b);
    double ans=(double)1 - a[0][0];
    cout<<fixed<<setprecision(9);
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

