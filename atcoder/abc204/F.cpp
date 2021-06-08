#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll p=998244353;

vector<vector<ll>> multiply(vector<vector<ll>> &a, vector<vector<ll>> &b) {
    int r1=(int)a.size(), c1=(int)a.front().size(), c2=(int)b.front().size();
    vector<vector<ll>> ans(r1, vector<ll> (c2));
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            for(int k=0; k<c1; k++) {
                ans[i][j]=(ans[i][j]+(a[i][k]*b[k][j])%p)%p;
            }
        }
    }
    return ans;
}

vector<vector<ll>> power(vector<vector<ll>> a, ll x) {
    int n=(int)a.size();
    vector<vector<ll>> ans(n, vector<ll> (n));
    for(int i=0; i<n; i++) {
        ans[i][i]=1;
    }
    while(x) {
        if(x&1) {
            ans=multiply(ans, a);
        }
        a=multiply(a, a);
        x>>=1;
    }
    return ans;
}

int valid(int prev, int curr, int h, vector<int> &ways) {
    int ans=1, len=0;
    while(h--) {
        if((prev&1)==0) {
            if((curr&1)==0) {
                ans=0;
                break;
            }
            ans*=ways[len];
            len=0;
        } else {
            if(curr&1) {
                len++;
            } else {
                ans*=ways[len];
                len=0;
            }
        }
        prev>>=1;
        curr>>=1;
    }
    ans*=ways[len];
    return ans;
}

void solve() {
    int h;
    ll w;
    cin>>h>>w;
    int n=(1<<h);
    vector<vector<ll>> a(1, vector<ll> (n)), x(n, vector<ll> (n));
    vector<int> ways(h+1);
    ways[0]=1;
    for(int i=1; i<=h; i++) {
        ways[i]=ways[i-1]+((i-2>=0)?ways[i-2]:0);
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            x[i][j]=valid(i, j, h, ways);
        }
    }
    a[0][n-1]=1;
    x=power(x, w);
    a=multiply(a, x);
    cout<<a[0][n-1]<<endl;
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

