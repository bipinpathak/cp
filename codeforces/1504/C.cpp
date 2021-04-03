#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>> ans(2, vector<int> (n, -1));
    int curr=1;
    bool have=false;
    for(int i=0; i<n; i++) {
        if(s[i]=='0') {
            have=true;
            ans[curr][i]=1;
            curr=!curr;
            ans[curr][i]=0;
        }
    }
    bool possible=true;
    if(have && (s.front()!='1' || s.back()!='1')) {
        possible=false;
    }
    if(possible) {
        if(have) {
            ans[0][0]=ans[1][0]=1;
            ans[0][n-1]=ans[1][n-1]=0;
        }
        int open=1;
        for(int i=0; i<n; i++) {
            if(ans[0][i]!=-1) {
                continue;
            }
            ans[0][i]=ans[1][i]=open;
            open=!open;
        }
        int up=0, down=0;
        for(int i=0; i<n && possible; i++) {
            if(ans[0][i]) {
                up++;
            } else {
                up--;
            }
            if(ans[1][i]) {
                down++;
            } else {
                down--;
            }       
            if(open<0 || down<0) {
                possible=false;
            }
        }
        if(up || down) {
            possible=false;
        }
    }
    if(possible) {
        cout<<"YES"<<endl;
        for(int i=0; i<n; i++) {
            if(ans[0][i]) {
                cout<<'(';
            } else {
                cout<<')';
            }
        }
        cout<<endl;
        for(int i=0; i<n; i++) {
            if(ans[1][i]) {
                cout<<'(';
            } else {
                cout<<')';
            }
        }
        cout<<endl;
    } else {
        cout<<"NO"<<endl;
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
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

