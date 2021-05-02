#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, l, r;
    cin>>n>>l>>r;
    vector<vector<int>> count(n, vector<int> (2));
    int curr=0;
    for(int i=0; i<n; i++) {
        int c;
        cin>>c;
        c--;
        if(i==l) {
            curr++;
        }
        count[c][curr]++;
    }
    vector<vector<int>> leftover(2);
    vector<int> sum(2);
    for(auto &i : count) {
        int good=min(i[0], i[1]);
        i[0]-=good;
        i[1]-=good;
        if(i[0]) {
            leftover[0].push_back(i[0]);
            sum[0]+=i[0];
        }
        if(i[1]) {
            leftover[1].push_back(i[1]);
            sum[1]+=i[1];
        }
    }
    int ans=0;
    if(sum[0]!=sum[1]) {
        if(sum[0]<sum[1]) {
            reverse(sum.begin(), sum.end());
            reverse(leftover.begin(), leftover.end());
        }
        for(auto i : leftover[0]) {
            int use=min(sum[0]-sum[1], i);
            use-=use&1;
            sum[0]-=use;
            ans+=use/2;
        }
    }
    if(sum[0]!=sum[1]) {
        int use=sum[0]-sum[1];
        ans+=use;
        sum[0]-=use;
    }
    ans+=sum[0];
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

