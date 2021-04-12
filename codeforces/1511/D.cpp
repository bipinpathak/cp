#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<char> s;
    for(int i=0; i<k; i++) {
        for(int j=i; j<k; j++) {
            s.push_back('a'+j);
            s.push_back('a'+i);
        }
        s.pop_back();
    }
    int curr=0, base=(int)s.size();
    while(n--) {
        cout<<s[curr];
        curr=(curr+1)%base;
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
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}
