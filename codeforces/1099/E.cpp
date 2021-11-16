#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int calc(string s, string p) {
    int n=(int)s.size(), ans=0;
    for(int i=0; i<n; i++) {
        ans+=s[i]==p[i&1];
    }
    return ans;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<string> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    string s="AGCT";
    vector<string> options;
    map<string, int> index;
    string curr="";
    for(int i=0; i<4; i++) {
        curr.push_back(s[i]);
        for(int j=0; j<4; j++) {
            if(i==j) {
                continue;
            }
            curr.push_back(s[j]);
            index[curr]=(int)options.size();
            options.push_back(curr);
            curr.pop_back();
        }
        curr.pop_back();
    }
    int k=(int)options.size();
    vector<vector<int>> adjacency(k);
    for(int i=0; i<k; i++) {
        for(int j=i+1; j<k; j++) {
            if(options[i].front()==options[j].front() || options[i].back()==options[j].back()) {
                continue;
            }
            if(options[i].front()==options[j].back() || options[i].back()==options[j].front()) {
                continue;
            }
            adjacency[i].push_back(j);
            adjacency[j].push_back(i);
        }
    }
    vector<vector<int>> dp(n, vector<int> (k));
    for(int i=0; i<n; i++) {
        for(int j=0; j<k; j++) {
            dp[i][j]+=calc(a[i], options[j]);
            if(i+1<n) {
                for(auto v : adjacency[j]) {
                    dp[i+1][v]=max(dp[i+1][v], dp[i][j]);
                }
            }
        }
    }
    vector<string> ans(n);
    set<int> valid;
    for(int i=0; i<k; i++) {
        valid.insert(i);
    }
    int same=0;
    for(int i=n-1; i>=0; i--) {
        int best=*valid.begin();
        for(auto j : valid) {
            if(dp[i][j]>dp[i][best]) {
                best=j;
            }
        }
        for(int j=0; j<m; j++) {
            ans[i].push_back(options[best][j&1]);
            same+=ans[i][j]==a[i][j];
        }
        valid.clear();
        for(auto j : adjacency[best]) {
            valid.insert(j);
        }
    }
    vector<string> rotated(m);
    for(int j=m-1; j>=0; j--) {
        for(int i=0; i<n; i++) {
            rotated[m-1-j].push_back(a[i][j]); 
        }
    }
    swap(n, m);
    vector<vector<int>> dpr(n, vector<int> (k));
    for(int i=0; i<n; i++) {
        for(int j=0; j<k; j++) {
            dpr[i][j]+=calc(rotated[i], options[j]);
            if(i+1<n) {
                for(auto v : adjacency[j]) {
                    dpr[i+1][v]=max(dpr[i+1][v], dpr[i][j]);
                }
            }
        }
    }
    vector<string> ansr(n);
    valid.clear();
    for(int i=0; i<k; i++) {
        valid.insert(i);
    }
    int offer=0;
    for(int i=n-1; i>=0; i--) {
        int best=*valid.begin();
        for(auto j : valid) {
            if(dpr[i][j]>dpr[i][best]) {
                best=j;
            }
        }
        for(int j=0; j<m; j++) {
            ansr[i].push_back(options[best][j&1]);
            offer+=ansr[i][j]==rotated[i][j];
        }
        valid.clear();
        for(auto j : adjacency[best]) {
            valid.insert(j);
        }
    }
    if(offer>same) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans[j][n-1-i]=ansr[i][j];
            }
        }
    }
    for(auto i : ans) {
        cout<<i<<endl;
    }
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

