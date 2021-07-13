#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool possible(string a, string b, vector<vector<int>> &index, int &m) {
    reverse(b.begin(), b.end()); 
    int an=(int)a.size(), bn=(int)b.size(); 
    vector<vector<int>> dp(an+1, vector<int> (bn+1, m+1));
    for(int i=0; i<=an; i++) {
        for(int j=0; j<=bn; j++) {
            if(i==0 && j==0) {
                dp[i][j]=0;
                continue;
            }
            int up,left, curr, offer;
            up=left=m+1;
            if(i-1>=0) {
                up=dp[i-1][j];
            }
            if(j-1>=0) {
                left=dp[i][j-1];
            }
            if(up<=m) {
                curr=a[i-1]-'a'; 
                offer=*upper_bound(index[curr].begin(), index[curr].end(), up);
                dp[i][j]=min(dp[i][j], offer);
            }
            if(left<=m) {
                curr=b[j-1]-'a'; 
                offer=*upper_bound(index[curr].begin(), index[curr].end(), left);
                dp[i][j]=min(dp[i][j], offer);
            }
        }
    }
    return dp[an][bn]<=m;
}

void solve() {
    string s, t;
    cin>>s>>t;
    int n=(int)t.size(), m=(int)s.size();
    vector<vector<int>> index(26);
    for(int i=0; i<m; i++) {
        index[s[i]-'a'].push_back(i+1);
    }
    for(auto &i : index) {
        i.push_back(m+1);
    }
    string ans="No";
    if((int)t.size()==1 && (int)index[t[0]-'a'].size()>1) {
        ans="Yes";
    }
    string front="", back=t;
    reverse(back.begin(), back.end());
    for(int i=0; i<n-1 && ans=="No"; i++) { 
        front.push_back(back.back());
        back.pop_back();
        if(possible(front, back, index, m)) {
            ans="Yes";
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

