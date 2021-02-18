#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void q(int l, int r, int &res) {
    cout<<"? "<<l<<" "<<r<<endl;
    cin>>res;
    return;
}

void special(int l, int r, int second) {
    if(l==r) {
        cout<<"! "<<l<<endl;
        return;
    }
    int mid=l+(r-l)/2, res;
    if(second>l) {
        mid=(l+r+1)/2;
        q(mid, second, res);
        if(res==second) {
            special(mid, r, second);
            return;
        } else {
            special(l, mid-1, second);
            return;
        }
    } else {
        q(second, mid, res);
        if(res==second) {
            special(l, mid, second);
            return;
        } else {
            special(mid+1, r, second);
            return;
        }
    }
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
                special(mid+1, r, second);
                return;
            }

        } else if(second==r) {
            q(mid, r, res);
            if(res==second) {
                l=mid; 
            } else {
                special(l, mid-1, second);
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

