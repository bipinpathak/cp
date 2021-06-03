#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void add(int index, int val, vector<ll> &a) {
    while(index<(int)a.size()) {
        a[index]+=val;
        index+=index&-index;
    }
    return;
}

ll get(int index, vector<ll> &a) {
    ll ans=0;
    while(index) {
        ans+=a[index];
        index-=index&-index;
    }
    return ans;
}

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
    map<int, queue<int>> indexes;
    for(int i=0; i<n; i++) {
        a[i]-=n-i-1;
        b[i]-=n-i-1;
        indexes[a[i]].push(i+1);
    }
    ll ans=0;
    vector<ll> seen(n+1);
    for(int i=0; i<n; i++) {
        if(indexes[b[i]].empty()) {
            ans=-1;
            break;
        }   
        int index=indexes[b[i]].front();
        indexes[b[i]].pop();
        b[i]=index;
        ans+=i-get(b[i], seen);
        add(b[i], 1, seen);
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

