#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    vector<int> next(n);
    int curr=n;
    for(int i=n-1; i>=0; i--) {
        next[i]=curr;
        if(s[i]=='(') {
            curr=i;
        }
    }
    int till=-1, ans=0, open=0, closed=0;
    for(int i=0; i<n; i++) {
        if(s[i]=='(') {
            open++;
        } else {
            closed++;
        }
        if(closed>open) {
            int prev=till;
            till=max(till, next[i]);
            while(till<n && till<=prev) {
                till=next[till];
            }
            if(till==n)  {
                cout<<-1<<endl;
                return;
            }
            ans+=till+1-max(i, prev+1);
            prev=till;
            swap(s[i], s[till]);
            open++;
            closed--;
        }
    }
    if(open!=closed) {
        ans=-1;
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

