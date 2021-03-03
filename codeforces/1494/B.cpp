#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool good(int n, vector<int> curr, vector<int> &a) {
    vector<int> b=a;
    for(int i=0; i<4; i++) {
        if(curr[i]) {
            b[i]--;
            b[(i+3)%4]--;
        }
    }
    for(int i=1; i<n-1; i++) {
        if(b[0]>0) {
            b[0]--;
        }
        if(b[1]>0) {
            b[1]--;
        }
        if(b[2]>0) {
            b[2]--;
        }
        if(b[3]>0) {
            b[3]--;
        }
    }
    for(auto i : b) {
        if(i!=0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    vector<int> a(4);
    cin>>n;
    for(auto &i : a) {
        cin>>i;
    }   
    for(int u=0; u<2; u++) {
        for(int r=0; r<2; r++) {
            for(int d=0; d<2; d++) {
                for(int l=0; l<2; l++) {
                    if(good(n, {u, r, d, l}, a)) {
                        cout<<"Yes"<<endl;
                        return;
                    }
                }
            }
        }
    }
    cout<<"No"<<endl;
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

