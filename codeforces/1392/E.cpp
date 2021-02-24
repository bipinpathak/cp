#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<ll>> a(n, vector<ll> (n));
    for(int i=0; i<n; i++) {
        for(int j=1; j<n; j+=2) {
            a[i][j]=(ll)1<<(49-i-j);
        }
    }
    for(auto i : a) {
        for(auto j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    int q;
    cin>>q;
    while(q--) {
        ll k;
        cin>>k;
        pair<int, int> curr={1, 1};
        int move=0;
        ll mask=(ll)1<<48;
        cout<<curr.first<<" "<<curr.second<<endl;
        while(move<2*n-2) {
            if(curr.second%2==0) {
                if(k&mask) {
                    curr.first++;
                } else {
                    curr.second++;
                }
            } else {
                if(k&mask) {
                    curr.second++;
                } else {
                    curr.first++;
                }
            }
            cout<<curr.first<<" "<<curr.second<<endl;
            mask=mask>>1;
            move++;
            if(curr.first==n || curr.second==n) {
                break;
            }
        }
        while(move<2*n-2) {
            curr.first=min(n, curr.first+1);
            curr.second=min(n, curr.second+1);
            cout<<curr.first<<" "<<curr.second<<endl;
            move++;
        }
    }
    return;
}

int main() {
#ifdef bipinpathak
    //(void)!freopen("input.txt", "r", stdin);
    //(void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}

