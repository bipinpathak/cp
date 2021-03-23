#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin>>s;
    int n=(int)s.length();
    vector<int> next(n), prev(n);
    stack<pair<int, int>> a;
    for(int i=0; i<n; i++) {
        next[i]=i+1;
        prev[i]=i-1;
        int left=i-1, right=i;
        if(left>=0 && right<n && s[left]!=s[right]) {
            int start=left;
            if(!a.empty() && a.top().second>=prev[left]) {
                start=a.top().first;
                a.pop();
            }
            a.push({start, right});
        }
    }
    int ans=0;
    while(!a.empty()) {
        ans++;
        stack<pair<int, int>> b;
        while(!a.empty()) {
            b.push(a.top());
            a.pop();
        }
        while(!b.empty()) {
            int left=prev[b.top().first], right=next[b.top().second];
            b.pop();
            if(left>=0) {
                next[left]=right;
            }
            if(right<n) {
                prev[right]=left;
            }
            if(left>=0 && right<n && s[left]!=s[right]) {
                int start=left;
                if(!a.empty() && a.top().second>=prev[left]) {
                    start=a.top().first;
                    a.pop();
                }
                a.push({start, right});
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
