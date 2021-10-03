#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct node{
    vector<int> oneIndexes, zeroIndexes;
    node *zero=NULL, *one=NULL;
};

void add(int index, int val, int m, node &root) {
    if(m>=0) {
        if(val&(1<<m)) {
            root.oneIndexes.push_back(index);
            if(root.one==NULL) {
                root.one=new node;
            }
            add(index, val, m-1, *root.one);
        } else {
            root.zeroIndexes.push_back(index);
            if(root.zero==NULL) {
                root.zero=new node;
            }
            add(index, val, m-1, *root.zero);
        }
    }
    return;
}

void go(int &mask, int &target, int &index, int &ans, int m, node &root) {
    if(m>=0) {
        int tv=(target&(1<<m))>0, mv=(mask&(1<<m))>0;
        int down=(tv^mv)>0;
        if(down && !root.oneIndexes.empty()) {
            go(mask, target, index, ans, m-1, *root.one);
        } else if(!down && !root.zeroIndexes.empty()) {
            go(mask, target, index, ans, m-1, *root.zero);
        }
        if(tv) {
            if(mv && !root.oneIndexes.empty() && root.oneIndexes.back()>=index) {
                ans=min(ans, *lower_bound(root.oneIndexes.begin(), root.oneIndexes.end(), index));   
            } else if(!mv && !root.zeroIndexes.empty() && root.zeroIndexes.back()>=index) {
                ans=min(ans, *lower_bound(root.zeroIndexes.begin(), root.zeroIndexes.end(), index));    
            }
        }
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    int m=19, ans=0, total=0;
    vector<int> zero(m+1, -1), a(n);
    node root;
    add(-1, 0, m, root);
    for(int i=0; i<n; i++) {
        cin>>a[i];
        for(int j=0; j<=m; j++) {
            if(a[i]&(1<<j)) {
                continue; 
            }
            zero[j]=i;
        }
        auto indexes=zero;
        indexes.push_back(-1);
        sort(indexes.rbegin(), indexes.rend());
        indexes.erase(unique(indexes.begin(), indexes.end()), indexes.end());
        int target=a[i];
        total^=a[i];
        for(auto &j : indexes) {
            if(j==i) {
                continue;
            }
            int low=i;
            go(total, target, j, low, m, root);
            ans=max(ans, i-low);
            if(target==0) {
                break;
            }
            if(j>=0) {
                target&=a[j];
            }
        }
        add(i, total, m, root);
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

