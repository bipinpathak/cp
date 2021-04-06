#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s, t;
    cin>>s>>t;
    int n=s.length(), m=t.length();
    vector<vector<int>> store(n, vector<int> (m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(s[i]==t[j]) {
                store[i][j]=1;
                if(i && j) {
                    store[i][j]+=store[i-1][j-1];
                }
            }
            if(i) {
                store[i][j]=max(store[i][j], store[i-1][j]);
            }
            if(j) {
                store[i][j]=max(store[i][j], store[i][j-1]);
            }       
            if(i && j) {
                store[i][j]=max(store[i][j], store[i-1][j-1]);
            }
        }
    }   
    vector<char> ans;
    int i=n-1, j=m-1;
    while(1) {
        if(i<0 || j<0 || store[i][j]==0) {
            break;
        }
        if(s[i]==t[j]) {
            ans.push_back(s[i]);
            i--;
            j--;
        } else if(i && (j==0 || store[i-1][j]>=store[i][j-1])) {
            i--;
        } else {
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto i : ans) {
        cout<<i;
    }
    cout<<endl;
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
    //cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

