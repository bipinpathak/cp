#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
string s;
vector<vector<vector<int>>> dp;

bool possible(int index, int diff) {
    if(index!=n-1 && (diff==0 || diff==2*k)) {
        return false;
    }
    if(index==-1) {
        return diff==k;
    }
    if(diff<2*k+1 && diff>=0) {
        for(auto &i : dp[index][diff]) {
            if(i) {
                return true;
            }
        }
    }
    return false;
}

void build(int index, int diff, string &ans) {
    if(index<0) {
        return;
    }
    for(int curr=0; curr<3; curr++) {
        if(dp[index][diff][curr]) {
            if(curr==0) {
                build(index-1, diff-1, ans);
                ans.push_back('W');
            } else if(curr==1) {
                build(index-1, diff, ans);
                ans.push_back('D');
            }   else {
                build(index-1, diff+1, ans);
                ans.push_back('L');
            }
            return;
        }
    }
    return;
}

void solve() {
    cin>>n>>k>>s; 
    vector<vector<int>> temp;
    for(int i=0; i<2*k+1; i++) {
        temp.push_back({0, 0, 0});
    }
    for(int i=0; i<n; i++) {
        dp.push_back(temp);
    }
    map<char, int> outcome;
    outcome['W']=0;
    outcome['D']=1;
    outcome['L']=2;
    for(int index=0; index<n; index++) {
        vector<int> option;
        for(auto i : outcome) {
            if(s[index]=='?' || s[index]==i.first) {
                option.push_back(i.second);
            }
        }
        for(int diff=0; diff<2*k+1; diff++) {
            for(auto curr : option) {
                if(possible(index-1, diff+curr-1)) {
                    dp[index][diff][curr]=1;
                }
            }
        }
    }
    string ans="NO";
    if(possible(n-1, 0)) {
        ans.clear();
        build(n-1, 0, ans);
    } else if(possible(n-1, 2*k)) {
        ans.clear();
        build(n-1, 2*k, ans);
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
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}

