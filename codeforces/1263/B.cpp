#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<string> a(n);
    vector<int> count(10);
    for(auto &i : a) {
        cin>>i;
        count[i[0]-'0']++;
    }
    set<string> seen;
    int ans=0;
    for(auto &i : a) {
        if(seen.count(i)) {
            count[i[0]-'0']--;
            for(int j=0; j<10; j++) {
                if(count[j]==0) {
                    i[0]='0'+j;
                    count[j]=1;
                    break;
                }
            }
            ans++;
        }
        seen.insert(i);
    }
    cout<<ans<<endl;
    for(auto &i : a) {
        cout<<i<<endl;
    }
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

