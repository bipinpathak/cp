#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool possible(int target, vector<vector<int>> &lengths , int &k) {
    if(target==0) {
        return true;
    }
    int n=(int)lengths.size(), m=(1<<k);
    vector<vector<int>> a(k);
    for(int i=0; i<k; i++) {
        for(int j=0; j<n; j++) {
            if(lengths[j][i]>=target) {
                a[i].push_back(j);
            }
        }
        a[i].push_back(n);
    }
    vector<int> dp(m, n);
    dp[0]=-1;
    for(int i=1; i<m; i++) {
        for(int j=0; j<k; j++) {
            if((i&(1<<j))==0) {
                continue;
            }
            int prev=i-(1<<j), index=dp[prev];
            if(index==n) {
                continue;
            }
            index=*upper_bound(a[j].begin(), a[j].end(), index);
            index+=target-1;
            dp[i]=min(dp[i], index);
        }
    }
    return dp[m-1]<n;
}

void solve() {
    int n, k;
    string s;
    cin>>n>>k>>s;
    vector<int> a(n, -1);
    for(int i=0; i<n; i++) {
        if(s[i]=='?') {
            continue;
        }
        a[i]=s[i]-'a';
    }
    vector<vector<int>> lengths(n, vector<int> (k));
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<k; j++) {
            if(a[i]==j || a[i]==-1) {
                lengths[i][j]=1+((i+1<n)?lengths[i+1][j]:0);
            }
        }
    }
    int low=0, high=n/k;
    while(low<high) {
        int mid=(high+low+1)/2;
        if(possible(mid, lengths, k)) {
            low=mid;
        } else {
            high=mid-1;
        }   
    }
    cout<<low<<endl;
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

