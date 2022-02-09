#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll one=1;

struct node{
    int onecount=0, zerocount=0;
    vector<int> indexes;
    node *zero=NULL, *one=NULL;
};

void add(ll n, int d, node &root, int &i) {
    if(d>=0) {
        if(n&(one<<d)) {
            root.onecount++;
            if(root.one==NULL) {
                root.one=new node;
            }
            add(n, d-1, *root.one, i);
        } else {
            root.zerocount++;
            if(root.zero==NULL) {
                root.zero=new node;
            }
            add(n, d-1, *root.zero, i);
        }
    } else {
        root.indexes.push_back(i);
    }
    return;
}

void go(ll n, int d, node &root, int &i) {
    if(d>=0) {
        if(root.onecount && (!(n&(one<<d)) || root.zerocount==0)) {
            go(n, d-1, *root.one, i);
        } else {
            go(n, d-1, *root.zero, i);
        }
    } else if(!root.indexes.empty()) {
        i=root.indexes.back();
    }
    return;
}

void solve() {
    ll n, k;
    cin>>n>>k;
    vector<ll> a(n), ans;
    for(auto &i : a) {
        cin>>i;
    }
    if(k==0) {
        for(int i=0; i<n; i++) {
            ans.push_back(i);
        }
    } else {
        ll shift=-1;
        ll temp=k;
        while(temp) {
            shift++;
            temp>>=1;
        }
        map<ll, vector<int>> groups;
        for(int i=0; i<n; i++) {
            groups[a[i]>>(shift+1)].push_back(i);
        }
        for(auto &[key, g] : groups) {
            vector<vector<int>> sub(2);
            for(auto &i : g) {
                ll p=(a[i]&(one<<shift))>0;
                sub[p].push_back(i);
            }
            bool done=false;
            node root;
            if(!sub[0].empty() && !sub[1].empty()) {
                for(auto &i : sub[0]) {
                    add(a[i], 32, root, i);
                }
                for(auto &i : sub[1]) {
                    int j=i;
                    go(a[i], 32, root, j);
                    if((a[i]^a[j])>=k) {
                        ans.push_back(i);
                        ans.push_back(j);
                        done=true;
                        break;
                    }
                }
            }
            for(int i=0; i<2 && !done; i++) {
                if(!sub[i].empty()) {
                    ans.push_back(sub[i].back());
                    done=true;
                }
            }
        }
    }
    if(ans.size()<2) {
        cout<< -1<<endl;
        return;
    }
    cout<<ans.size()<<endl;
    for(auto &i : ans) {
        cout<<i+1<<" ";
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
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

