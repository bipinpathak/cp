#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<string> s(3);
    for(auto &i : s) {
        cin>>i;
    }
    vector<int> p(3);
    string ans="";
    while(1) {
        if(max(p[0], max(p[1], p[2]))==2*n) {
            break;
        } else {
            bool moved=false;
            for(int i=0; i<3 && !moved; i++) {
                for(int j=i+1; j<3 && !moved; j++) {
                    if(s[i][p[i]]==s[j][p[j]]) {
                        ans.push_back(s[i][p[i]]);
                        moved=true;
                        for(int k=0; k<3; k++) {
                            if(s[k][p[k]]==ans.back()) {
                                p[k]++;
                            }
                        }
                    }       
                }
            }   
        }
    }
    if(p[0]==2*n) {
        swap(s[0], s[1]);
        swap(p[0], p[1]);
    }
    if(p[1]==2*n) {
        swap(s[1], s[2]);
        swap(p[1], p[2]);
    }       
    int choose=p[0]<p[1];
    while(p[choose]<2*n) {
        ans.push_back(s[choose][p[choose]]);
        p[choose]++;
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
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

