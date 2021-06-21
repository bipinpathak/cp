#include <bits/stdc++.h>
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

void go(int n, int d, node &root, int ans) {
    if(d==-1) {
        cout<<ans<<" ";
    } else {
        ans<<=1;
        if(root.onecount && ((n&(1<<d)) || root.zerocount==0)) {
            root.onecount--;
            if(!(n&(1<<d))) {
                ans++;
            }
            go(n, d-1, *root.one, ans);
        } else {
            root.zerocount--;
            if(n&(1<<d)) {
                ans++;
            }
            go(n, d-1, *root.zero, ans);
        }
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    node root;
    for(int i=0; i<n; i++) {
        int p;
        cin>>p;
        add(p, 29, root);
    }
    for(auto i : a) {
        go(i, 29, root, 0);
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
    auto start=clock();
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

