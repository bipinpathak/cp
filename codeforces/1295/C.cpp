#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s, t;
    cin>>s>>t;
    int n=(int)s.size();
    vector<vector<int>> index(26);
    for(int i=0; i<n; i++) {
        index[s[i]-'a'].push_back(i);
    }
    for(auto i : t) {
        if(index[i-'a'].empty()) {
            cout<<-1<<endl;
            return;
        }
    }   
    for(auto &i : index) {
        i.push_back(n);
    }
    int ans=1, last=-1;
    for(auto i : t) {
        int next=*upper_bound(index[i-'a'].begin(), index[i-'a'].end(), last); 
        if(next==n) {
            ans++;
            next=index[i-'a'].front();
        }
        last=next;
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

