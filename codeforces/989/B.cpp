#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, p;
    string s;
    cin>>n>>p>>s;
    vector<vector<char>> period(p);
    for(int i=0; i<n; i++) {
        period[i%p].push_back(s[i]);
    }
    bool done=false; 
    for(auto &i : period) {
        n=(int)i.size();
        int zero=0, one=0;
        for(auto j : i) {
            zero+=j=='0';
            one+=j=='1';
        }
        if(one==0) {
            for(auto &j : i) {
                if(j=='.') {
                    j='1';
                    one++;
                    break;
                }
            }
        }
        if(zero==0) {
            for(auto &j : i) {
                if(j=='.') {
                    j='0';
                    zero++;
                    break;
                }
            }
        }
        for(auto &j : i) {
            if(j=='.') {
                j='0';
                zero++;
            }
        }
        if(n>1 && max(one, zero)!=n) {
            done=true;
        }
    }
    if(done) {
        for(int i=0; i<p; i++) {
            int curr=i;
            for(auto j : period[i]) {
                s[curr]=j;
                curr+=p;
            }
        }
    } else {
        s="No";
    }
    cout<<s<<endl;
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

