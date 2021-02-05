#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<string> edges(n);
    for(auto &i : edges) {
        cin>>i;
    }
    if(m%2) {
        cout<<"YES"<<endl;
        for(int i=0; i<m+1; i++) {
            cout<<i%2+1<<" ";
        }
        cout<<endl;
        return;
    }
    vector<int> golden;
    for(int i=0; i<n && golden.empty(); i++) {
        for(int j=i+1; j<n && golden.empty(); j++) {
            if(edges[i][j]==edges[j][i]) {
                golden={i, j};
            }
        }
    }
    if(!golden.empty()) {
        cout<<"YES"<<endl;
        for(int i=0; i<m+1; i++) {
            cout<<golden[i%2]+1<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=0; i<n; i++) {
        int one=-1, two=-1;
        for(int j=0; j<n; j++) {
            if(j==i) {
                continue;
            }
            if(one==-1) {
                one=j;
            } else if(edges[i][one]!=edges[i][j]) {
                two=j;
                break;
            }
        }
        if(two==-1) {
            continue;
        }
        cout<<"YES"<<endl;
        for(int k=0; k<m+1; k++) {
            if((m/2)%2) {
                if(k%2) {
                    cout<<i+1<<" ";
                } else if(k<=m/2) {
                    cout<<one+1<<" ";
                } else {
                    cout<<two+1<<" ";
                }
            } else {
                if(k%2==0) {
                    cout<<i+1<<" ";
                } else if(k<=m/2) {
                    cout<<one+1<<" ";
                } else {
                    cout<<two+1<<" ";
                }
            }
        }
        cout<<endl;
        return;
    }
    cout<<"NO"<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

