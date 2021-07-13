#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, x;
    string s;
    cin>>n>>x>>s;
    map<int, int> count;
    int curr=0;
    for(auto i : s) {
        if(i=='0') {
            curr++;
        } else {
            curr--;
        }
        count[curr]++;
    }
    int ans=x==0;
    for(auto i : count) {
        if(curr==0) {
            if(i.first==x) {
                ans=-1;
                break;
            }
            continue;
        }
        if((x-i.first)%curr==0) {
            int times=(x-i.first)/curr;
            if(times>=0) {
                ans+=i.second;
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
    auto start=clock();
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

