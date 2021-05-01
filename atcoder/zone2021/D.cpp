#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin>>s;
    deque<char> x;
    bool reversed=false;
    for(auto i : s) {
        if(i=='R') {
            reversed=!reversed;
        } else if(reversed) {
            x.push_front(i);
        } else {
            x.push_back(i);
        }
    }
    stack<char> active;
    while(!x.empty()) {
        char curr;
        if(reversed) {
            curr=x.back();
            x.pop_back();
        } else {
            curr=x.front();
            x.pop_front();
        }
        if(active.empty() || active.top()!=curr) {
            active.push(curr);
        } else {
            active.pop();
        }
    }
    string ans="";
    while(!active.empty()) {
        ans.push_back(active.top());
        active.pop();
    }
    reverse(ans.begin(), ans.end());
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

