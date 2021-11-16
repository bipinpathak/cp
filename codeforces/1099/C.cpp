#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    string s;
    int k;
    cin>>s>>k;
    vector<int> stick, star;
    int n=(int)s.size();
    for(int i=0; i<n; i++) {
        if(s[i]=='?') {
            stick.push_back(i);
        } else if(s[i]=='*') {
            star.push_back(i);
        }
    }
    int low=n-2*(int)(stick.size()+star.size()), high=n-(int)(stick.size()+star.size());
    if(!star.empty()) {
        high=k;
    }
    string ans="Impossible";
    if(low<=k && k<=high) {
        ans="";
        int curr=n-(int)(stick.size()+star.size());
        if(curr>=k) {
            curr-=k;
            for(auto i : s) {
                if(i=='?' || i=='*') {
                    if(curr) {
                        ans.pop_back();
                        curr--;
                    }
                } else {
                    ans.push_back(i);
                }
            }
        } else {
            k-=curr;
            for(auto i : s) {
                if(i=='?') {
                    continue;
                } else if(i=='*') {
                    while(k) {
                        ans.push_back(ans.back());
                        k--;
                    }
                } else {
                    ans.push_back(i);
                }
            }
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
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

