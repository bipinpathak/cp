#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool good(int x) {
    set<int> seen;
    while(x) {
        int curr=x%10;
        if(seen.find(curr)!=seen.end()) {
            return false;
        }
        seen.insert(curr);
        x/=10;
    }
    return true;
}

void solve() {
    int l, r;
    cin>>l>>r;
    while(l<=r) {
        if(good(l)) {
            cout<<l<<endl;
            return;
        }
        l++;
    }
    cout<<-1<<endl;
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

