#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    n=min(n, (int)1e4);
    vector<vector<int>> sum(5e6+1);
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int curr=a[i]+a[j];
            if(sum[curr].empty() || !(sum[curr].back()==i || sum[curr].back()==j || sum[curr].front()==i || sum[curr].front()==j)) {
                sum[curr].push_back(j);
                sum[curr].push_back(i);
            }
            if((int)sum[curr].size()==4) {
                cout<<"YES"<<endl;
                for(auto k : sum[curr]) {
                    cout<<k+1<<" ";
                }
                cout<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
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
    while(t--) {
        solve();
    }
    return 0;
}

