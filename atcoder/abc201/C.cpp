#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin>>s;
    vector<vector<int>> options;
    vector<int> build;
    for(int i=0; i<=9; i++) {
        if(s[i]=='x') {
            continue;
        }
        build.push_back(i);
        for(int j=0; j<=9; j++) {
            if(s[j]=='x') {
                continue;
            }
            build.push_back(j);
            for(int k=0; k<=9; k++) {
                if(s[k]=='x') {
                    continue;
                }
                build.push_back(k);
                for(int l=0; l<=9; l++) {
                    if(s[l]=='x') {
                        continue;
                    }
                    build.push_back(l);
                    options.push_back(build);
                    build.pop_back();
                }
                build.pop_back();
            }
            build.pop_back();
        }
        build.pop_back();
    }
    vector<int> need(10);
    int ans=0, total=0;
    for(int i=0; i<10; i++) {
        if(s[i]=='o') {
            need[i]++;
            total++;
        }
    }
    for(auto i : options) {
        vector<int> c=need;
        int curr=0;
        for(auto k : i) {
            if(c[k]) {
                c[k]--;
                curr++;
            }
        }
        if(curr==total) {
            ans++;
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

