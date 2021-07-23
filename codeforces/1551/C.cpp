#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set<char> use={'a', 'b', 'c', 'd', 'e'};

int go(char target, vector<string> &a) {
    int ans=0;
    vector<int> options;
    for(auto i : a) {
        int curr=0;
        for(auto j : i) {
            if(j==target) {
                curr++;
            } else if(use.count(j)) {
                curr--;
            }
        }
        options.push_back(curr);
    }
    sort(options.rbegin(), options.rend());
    int score=0;
    for(auto i : options) {
        score+=i;
        if(score<=0) {
            break;
        }
        ans++;
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<string> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    int ans=0;
    for(auto i : use) {
        ans=max(ans, go(i, a));
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

