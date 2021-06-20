#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(vector<int> &cards, vector<vector<int>> &limits, vector<int> &range) {
    int n=(int)cards.size(); 
    map<int, int> lowlimits, highlimits;
    lowlimits[1e9+1]=n;
    highlimits[1]=n;
    for(int i=n-1; i>=0; i--) {
        while(limits[i][0]>=lowlimits.begin()->first) {
            lowlimits.erase(lowlimits.begin());
        }
        lowlimits[limits[i][0]]=i;
        while(limits[i][1]<=-highlimits.begin()->first) {
            highlimits.erase(highlimits.begin());
        }
        highlimits[-limits[i][1]]=i;
        range[i]=min(lowlimits.upper_bound(cards[i])->second, highlimits.upper_bound(-cards[i])->second);
    }
    return;
}

void solve() {
    int n;
    ll m;
    cin>>n>>m;
    vector<int> cards(n+1);
    vector<vector<int>> left(n+1, vector<int> (2)), right;
    right=left;
    for(int i=1; i<=n; i++) {
        cin>>cards[i]>>left[i][0]>>left[i][1]>>right[i][0]>>right[i][1];
    }
    left[0]=right[0]={0, (int)1e9};
    vector<int> leftRange(n+1), rightRange(n+1);
    go(cards, left, leftRange);
    go(cards, right, rightRange);
    vector<vector<int>> dp(n+1, vector<int> (2));
    dp[0][0]=rightRange[0];
    dp[0][1]=leftRange[0];
    for(int i=1; i<=n; i++) {
        if(leftRange[i-1]>=i && dp[i-1][0]>=i) {
            dp[i][0]=max(dp[i][0], dp[i-1][0]);
            dp[i][1]=max(dp[i][1], leftRange[i-1]);
        }
        if(rightRange[i-1]>=i && dp[i-1][1]>=i) {
            dp[i][0]=max(dp[i][0], rightRange[i-1]);
            dp[i][1]=max(dp[i][1], dp[i-1][1]);
        }
    }
    string ans="No";
    if((dp[n][0]>n && leftRange[n]>n) || (dp[n][1]>n && rightRange[n]>n)) {
        ans="Yes";
    }
    cout<<ans<<endl;
    if(ans=="No") {
        return;
    }
    int winning=0;
    if(dp[n][1]>n && rightRange[n]>n) {
        winning++;
    }
    vector<int> moves;
    for(int i=n; i; i--) {
        moves.push_back(winning); 
        if(winning==1) {
            if(leftRange[i-1]>=i && dp[i-1][0]>=i && (rightRange[i-1]<i || dp[i-1][1]<i || leftRange[i-1]>dp[i-1][1])) {
                winning=0;
            }
        } else {
            if(rightRange[i-1]>=i && dp[i-1][1]>=i && (leftRange[i-1]<i || dp[i-1][0]<i || rightRange[i-1]>dp[i-1][0])) {
                winning=1;
            }
        }
    }
    for(int i=n-1; i>=0; i--) {
        cout<<moves[i]<<" ";
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

