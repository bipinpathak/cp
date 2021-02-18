#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void q(int l, int r, int &res) {
    cout<<"? "<<l<<" "<<r<<endl;
    cin>>res;
    return;
}

void go(int l, int r) {
    if(l==r) {
        cout<<"! "<<l<<endl;
        return;
    }
    int second, res;
    q(l, r, second);
    while(1) {
        if(r==l+1) {
            if(l==second) {
                l++;
            }
            go(l, l);
            return;
        }
        int mid=l+(r-l)/2;
        if(second==l) {
            q(l, mid, res);
            if(res==second) {
                r=mid;
            } else {
                go(mid+1, r);
                return;
            }

        } else if(second==r) {
            q(mid, r, res);
            if(res==second) {
                l=mid; 
            } else {
                go(l, mid-1);
                return;
            }
        } else {
            q(l, second, res);
            if(res==second) {
                r=second;
            } else {
                l=second;
            }
        }
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    go(1, n);
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

