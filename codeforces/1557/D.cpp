#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;

void push(int l, int r, int index, vector<int> &seg, vector<int> &lazy, vector<int> &store) {
    int mid=l+(r-l)/2;
    if(store[lazy[index+1]]>store[lazy[index]]) {
        lazy[index+1]=lazy[index];
    }
    if(store[seg[index+1]]>store[lazy[index]]) {
        seg[index+1]=lazy[index];
    }
    if(store[lazy[index+2*(mid-l+1)]]>store[lazy[index]]) {
        lazy[index+2*(mid-l+1)]=lazy[index];
    }
    if(store[seg[index+2*(mid-l+1)]]>store[lazy[index]]) {
        seg[index+2*(mid-l+1)]=lazy[index];
    }
    lazy[index]=n;
    return;
}

void update(int l, int r, int index, vector<int> &seg, int start, int end, int val, vector<int> &lazy, vector<int> &store) {
    if(!(end<l || start>r)) {
        if(start<=l && r<=end) {
            if(store[val]<store[seg[index]]) {
                seg[index]=val;
            }
            if(store[val]<store[lazy[index]]) {
                lazy[index]=val;
            }
        } else {
            push(l, r, index, seg, lazy, store);
            int mid=l+(r-l)/2;
            update(l, mid, index+1, seg, start, end, val, lazy, store);
            update(mid+1, r, index+2*(mid-l+1), seg, start, end, val, lazy, store);
            seg[index]=seg[index+1];
            if(store[seg[index]]>store[seg[index+2*(mid-l+1)]]) {
                seg[index]=seg[index+2*(mid-l+1)];
            }
        }
    }
    return;
}
 
int query(int l, int r, int index, vector<int> &seg, int start, int end, vector<int> &lazy, vector<int> &store) {
    int ans=n;
    if(!(end<l || start>r)) {
        if(start<=l && end>=r) {
            ans=seg[index];
        } else {
            push(l, r, index, seg, lazy, store); 
            int mid=l+(r-l)/2;
            int left=query(l, mid, index+1, seg, start, end, lazy, store), right=query(mid+1, r, index+2*(mid-l+1), seg, start, end, lazy, store);
            ans=left;
            if(store[ans]>store[right]) {
                ans=right;
            }
        }
    }
    return ans;
}
 
void solve() {
    cin>>n>>m;
    vector<vector<pair<int, int>>> lines(n);
    vector<int> all;
    while(m--) {
        int i, l, r;
        cin>>i>>l>>r;
        i--;
        lines[i].push_back({l, r});
        all.push_back(l);
        all.push_back(r);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    m=(int)all.size();
    map<int, int> index;
    for(int i=0; i<m; i++) {
        index[all[i]]=i+1; 
    }
    vector<int> seg(2*m+1, n), lazy(2*m+1, n), store(n+1, n), prev(n);
    for(int i=0; i<n; i++) {
        int best=i;
        for(auto line : lines[i]) {
            int l=index[line.first], r=index[line.second];
            int offer=query(1, m, 1, seg, l, r, lazy, store);
            if(store[offer]<store[best]) {
                best=offer;
            }
        }
        store[i]=store[best]-1;
        prev[i]=best;
        for(auto line : lines[i]) {
            int l=index[line.first], r=index[line.second];
            update(1, m, 1, seg, l, r, i, lazy, store);
        }
    }
    int best=query(1, m, 1, seg, 1, m, lazy, store);
    set<int> good;
    while(1) {
        good.insert(best);
        if(best==prev[best]) {
            break;
        }
        best=prev[best];
    }
    cout<<n-(int)good.size()<<endl;
    for(int i=0; i<n; i++) {
        if(!good.count(i)) {
            cout<<i+1<<" ";
        }
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

