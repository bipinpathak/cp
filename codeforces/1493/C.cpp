#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<vector<int>> a(n+1, vector<int> (26));
    vector<int> b(n+1);
    for(int i=1; i<=n; i++) {
        b[i]=s[i-1]-'a';
        a[i]=a[i-1];
        a[i][b[i]]=(a[i][b[i]]+1)%k;
    }
    bool found=true;
    for(auto i : a[n]) {
        if(i) {
            found=false;
            break;
        }
    }
    for(int i=n; i && !found; i--) {
        if(b[i]==25) {
            continue;
        }
        for(int j=b[i]+1; j<26 && !found; j++) {
            a[i]=a[i-1];
            a[i][j]=(a[i][j]+1)%k;
            int have=n-i;
            for(int t=0; t<26; t++) {
                have-=(k-a[i][t])%k;
            }
            if(have>=0 && have%k==0) {
                b[i]=j;
                found=true;
            }
        }
        if(found) {
            int curr=n;
            for(int j=25; j>0; j--) {
                while(a[i][j] && a[i][j]<k) {
                    b[curr]=j;
                    a[i][j]++;
                    curr--;
                }
            }
            while(curr>i) {
                b[curr]=0;
                curr--;
            }
        }
    }
    if(!found) {
        cout<<-1<<endl;
        return;
    }
    string ans;
    for(int i=1; i<=n; i++) {
        ans+='a'+b[i];
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
    while(t--) {
        solve();
    }
    return 0;
}

