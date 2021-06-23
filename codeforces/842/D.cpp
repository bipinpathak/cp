#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    int onecount=0, zerocount=0, level=0;
    node *zero=NULL, *one=NULL;
};

void add(int n, node &root) {
    if(root.level>=0) {
        if(n&(1<<root.level)) {
            root.onecount++;
            if(root.one==NULL) {
                root.one=new node;
                root.one->level=root.level-1;
            }
            add(n, *root.one);
        } else {
            root.zerocount++;
            if(root.zero==NULL) {
                root.zero=new node;
                root.zero->level=root.level-1;
            }
            add(n, *root.zero);
        }
    }
    return;
}

int go(int &val, int &mask, node &root) {
    int ans=0;
    if(root.level>=0) {
        int d=(1<<root.level), curr=val&d, change=mask&d;
        if(curr) {
            ans+=change?root.onecount:root.zerocount;
        }
        if(curr^change && root.onecount) {
            ans+=go(val, mask, *root.one);
        }       
        if(!(curr^change) && root.zerocount) {
            ans+=go(val, mask, *root.zero);
        }
    }
    return ans;
}

void solve() {
    int n, m;
    cin>>n>>m;
    node root;
    root.level=20;
    set<int> seen;
    while(n--) {
        int a;
        cin>>a;
        seen.insert(a);
    }
    for(auto i : seen) {
        add(i, root);
    }
    n=(int)seen.size();
    int val=0;
    while(m--) {
        int x;
        cin>>x;
        val^=x;
        int low=0, high=n;
        while(low<high) {
            int mid=(high+low+1)/2, count=go(mid, val, root); 
            if(count>=mid) {
                low=mid;
            } else {
                high=mid-1;
            }
        }
        cout<<low<<endl;
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

