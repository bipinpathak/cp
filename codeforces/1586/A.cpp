#include "bits/stdc++.h"
using namespace std;
using ll = long long;

bool isPrime(int n) {
    for(int i=2; i*i<=n; i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    int  m=n*200;
    vector<vector<int>> possible(m+1, {0, -1});
    possible[0][0]=1;
    for(int i=0; i<n; i++) {
        for(int curr=m-a[i]; curr>=0; curr--) {
            if(!possible[curr][0] || possible[curr+a[i]][0]) {
                continue;     
            }
            possible[curr+a[i]][0]=1;
            possible[curr+a[i]][1]=i;
        }
    }
    vector<int> ans;
    while(m) {
        if(possible[m][0] & !isPrime(m)) {
            while(m) {
                ans.push_back(possible[m][1]);
                m-=a[possible[m][1]];
            }
            break;
        }
        m--;
    }
    cout<<ans.size()<<endl;
    for(auto i : ans) {
        cout<<i+1<<" ";
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
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

