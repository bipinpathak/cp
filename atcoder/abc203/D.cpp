#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool possible(int val, vector<vector<int>> &a, int n, int k) {
    vector<vector<int>> row(n, vector<int> (n)), dp(n, vector<int> (n));
    for(int i=0; i<n; i++) {
        int curr=0;
        for(int j=0; j<n; j++) {
            if(a[i][j]<=val) {
                curr++;
            }
            if(j-k>=0 && a[i][j-k]<=val) {
                curr--;
            }
            row[i][j]=curr;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            dp[i][j]=row[i][j]+(i?dp[i-1][j]:0);
            if(i-k>=0) {
                dp[i][j]-=row[i-k][j];
            }
        }
    }
    for(int i=k-1; i<n; i++) {
        for(int j=k-1; j<n; j++) {
            if(dp[i][j]>=(k*k-1)/2+1) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    int n, k;
    cin>>n>>k;
    vector<vector<int>> a(n, vector<int> (n));
    vector<int> range;
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
            range.push_back(j);
        }
    }
    sort(range.begin(), range.end());
    range.erase(unique(range.begin(), range.end()), range.end());
    int low=0, high=(int)range.size()-1;
    while(low<high) {
        int mid=low+(high-low)/2;
        if(possible(range[mid], a, n, k)) {
            high=mid;
        } else {
            low=mid+1;
        }
    }
    cout<<range[low]<<endl;
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

