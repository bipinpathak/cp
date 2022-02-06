#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int ask(int i, int j, int k) {
    cout<<"? "<<i+1<<" "<<j+1<<" "<<k+1<<endl;
    int ans;
    cin>>ans;
    return ans;
}

void go(vector<int> &a) {
    vector<int> without(4);
    without[0]=ask(a[1], a[2], a[3]);
    without[1]=ask(a[0], a[2], a[3]);
    without[2]=ask(a[0], a[1], a[3]);
    without[3]=ask(a[0], a[1], a[2]);
    int highest=0, l=-1, r=-1;
    for(auto &i : without) {
        highest=max(highest, i);
    }
    for(int i=3; i>=0; i--) {
        if(without[i]!=highest) {
            if(r==-1) {
                r=i;
            } else {
                l=i;
                break;
            }
        }
    }
    l=a[max(l, 0)];
    r=a[max(r, 1)];
    a={l, r};
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a={0, 1, 2, 3};
    go(a);
    for(int i=4; i<n; i+=2) {
        a.push_back(i);
        a.push_back(i+1);
        if(a.back()==n) {
            a.back()=0;
            while(a.back()==a[0] || a.back()==a[1] || a.back()==a[2]) {
                a.back()++;
            }
        }
        go(a);
    }
    cout<<"! "<<a[0]+1<<" "<<a[1]+1<<endl;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}
