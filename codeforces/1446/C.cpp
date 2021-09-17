#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct node{
    int onecount=0, zerocount=0;
    node *zero=NULL, *one=NULL;
};

void add(int n, int d, node &root) {
    if(d>=0) {
        if(n&(1<<d)) {
            root.onecount++;
            if(root.one==NULL) {
                root.one=new node;
            }
            add(n, d-1, *root.one);
        } else {
            root.zerocount++;
            if(root.zero==NULL) {
                root.zero=new node;
            }
            add(n, d-1, *root.zero);
        }
    }
    return;
}

int go(int d, node &root) {
    int ans=1;
    if(d>=0) {
        int zero=min(1, root.zerocount), one=min(1, root.onecount);
        if(root.onecount) {
            ans=max(ans, zero+go(d-1, *root.one));
        }
        if(root.zerocount) {
            ans=max(ans, one+go(d-1, *root.zero));
        }
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    node root;
    int ans=n;
    while(n--) {
        int a;
        cin>>a;
        add(a, 30, root);
    }   
    cout<<ans-go(30, root)<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

