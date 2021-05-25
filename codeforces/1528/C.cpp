#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void input(int n, vector<vector<int>> &adjacency) {
    for(int u=2; u<=n; u++) {
        int p;
        cin>>p;
        adjacency[p-1].push_back(u-1);
    }
    return;
}

void build(int u, int &t, vector<int> &in, vector<int> &out, vector<vector<int>> &adjacency) {
    in[u]=t++;
    for(auto v : adjacency[u]) {
        build(v, t, in, out, adjacency);
    }       
    out[u]=t++;
    return;
}

void minUpdate(int l, int r, int curr, int index, vector<int> &active, vector<int> &seg) {
    if(l<=index && index<=r) {
        if(l==r) {
            seg[curr]=index;
        } else {
            int mid=l+(r-l)/2;
            minUpdate(l, mid, curr+1, index, active, seg);
            minUpdate(mid+1, r, curr+2*(mid-l+1), index, active, seg);
            if(active[seg[curr+1]]<active[seg[curr]]) {
                seg[curr]=seg[curr+1];
            }
            if(active[seg[curr+2*(mid-l+1)]]<active[seg[curr]]) {
                seg[curr]=seg[curr+2*(mid-l+1)];
            }
        }
    }
    return;
}


int minQuery(int l, int r, int curr, int start, int end, vector<int> &seg, vector<int> &active) {
    int ans=-1;
    if(!(start>r || end<l)) {
        if(start<=l && r<=end) {
            ans=seg[curr];
        } else {
            int mid=l+(r-l)/2, left, right;
            left=minQuery(l, mid, curr+1, start, end, seg, active);
            right=minQuery(mid+1, r, curr+2*(mid-l+1), start, end, seg, active);
            if(left!=-1) {
                if(ans==-1 || active[left]<active[ans]) {
                    ans=left;
                }
            }
            if(right!=-1) {
                if(ans==-1 || active[right]<active[ans]) {
                    ans=right;
                }
            }
        }
    }
    return ans;
}

void maxUpdate(int l, int r, int curr, int index, vector<int> &active, vector<int> &seg) {
    if(l<=index && index<=r) {
        if(l==r) {
            seg[curr]=index;
        } else {
            int mid=l+(r-l)/2;
            maxUpdate(l, mid, curr+1, index, active, seg);
            maxUpdate(mid+1, r, curr+2*(mid-l+1), index, active, seg);
            if(active[seg[curr+1]]>active[seg[curr]]) {
                seg[curr]=seg[curr+1];
            }
            if(active[seg[curr+2*(mid-l+1)]]>active[seg[curr]]) {
                seg[curr]=seg[curr+2*(mid-l+1)];
            }
        }
    }
    return;
}


int maxQuery(int l, int r, int curr, int start, int end, vector<int> &seg, vector<int> &active) {
    int ans=-1;
    if(!(start>r || end<l)) {
        if(start<=l && r<=end) {
            ans=seg[curr];
        } else {
            int mid=l+(r-l)/2, left, right;
            left=maxQuery(l, mid, curr+1, start, end, seg, active);
            right=maxQuery(mid+1, r, curr+2*(mid-l+1), start, end, seg, active);
            if(left!=-1) {
                if(ans==-1 || active[left]>active[ans]) {
                    ans=left;
                }
            }
            if(right!=-1) {
                if(ans==-1 || active[right]>active[ans]) {
                    ans=right;
                }
            }
        }
    }
    return ans;
}

void go(int u, vector<vector<int>> &adjacency, int &curr, int &ans, vector<int> &minActive, vector<int> &minSeg, vector<int> &maxActive, vector<int> &maxSeg, vector<int> &in, vector<int> &out, int &t) { 
    int child=minQuery(1, t-1, 1, in[u], t-1, minSeg, minActive), parent=maxQuery(1, t-1, 1, 1, in[u], maxSeg, maxActive), val=0;
    bool childFound=false, parentFound=false;
    if(child!=-1 && minActive[child]<out[u]) {
        childFound=true;
    }
    if(!childFound && parent!=-1 && maxActive[parent]>out[u]) {
        parentFound=true;
        val=maxActive[parent];
        maxActive[parent]=0;
        minActive[parent]=t;
        maxUpdate(1, t-1, 1, parent, maxActive, maxSeg);
        minUpdate(1, t-1, 1, parent, minActive, minSeg);
        curr--;
    }
    if(!childFound) {
        maxActive[in[u]]=minActive[in[u]]=out[u];
        maxUpdate(1, t-1, 1, in[u], maxActive, maxSeg);
        minUpdate(1, t-1, 1, in[u], minActive, minSeg);
        curr++;
    }
    ans=max(ans, curr);
    for(auto v : adjacency[u]) {
        go(v, adjacency, curr, ans, minActive, minSeg, maxActive, maxSeg, in, out, t);
    }
    if(!childFound) {
        maxActive[in[u]]=0;
        minActive[in[u]]=t;
        maxUpdate(1, t-1, 1, in[u], maxActive, maxSeg);
        minUpdate(1, t-1, 1, in[u], minActive, minSeg);
        curr--;
    }
    if(parentFound) {
        maxActive[parent]=minActive[parent]=val;
        minUpdate(1, t-1, 1, parent, minActive, minSeg);
        maxUpdate(1, t-1, 1, parent, maxActive, maxSeg);
        curr++;
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adjacencyS(n), adjacencyK(n);
    input(n, adjacencyS);
    input(n, adjacencyK);
    vector<int> in(n), out(n);
    int t=1;
    build(0, t, in, out, adjacencyK);
    vector<int> minActive(t, t), maxActive(t, 0), minSeg(2*t), maxSeg(2*t);
    for(int i=1; i<t; i++) {
        minUpdate(1, t-1, 1, i, minActive, minSeg);
        maxUpdate(1, t-1, 1, i, maxActive, maxSeg);
    }
    int curr=0, ans=0;
    go(-0, adjacencyS, curr, ans, minActive, minSeg, maxActive, maxSeg, in, out, t);
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
    auto start=clock();
    int tc = 1;
    cin>>tc;
    for(int i=0; i<tc; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

