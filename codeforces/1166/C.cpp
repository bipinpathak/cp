#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
        i=abs(i);
    }      
    sort(a.begin(), a.end());
    ll ans=0;
    queue<int> limit;
    int curr=0;
    for(auto i : a) {
        while(!limit.empty() && i>limit.front()) {
            curr--;
            limit.pop();
        }       
        ans+=curr;
        limit.push(2*i);
        curr++;
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

