#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct node{
    int low=0, high=0;
};

void push(int l, int r, int index, vector<node> &seg, vector<int> &lazy) {
    int mid=l+(r-l)/2;
    lazy[index+1]+=lazy[index];
    seg[index+1].high+=lazy[index];
    seg[index+1].low+=lazy[index];
    lazy[index+2*(mid-l+1)]+=lazy[index];
    seg[index+2*(mid-l+1)].high+=lazy[index];
    seg[index+2*(mid-l+1)].low+=lazy[index];
    lazy[index]=0;
    return;
}

void update(int l, int r, int index, vector<node> &seg, int start, int end, int val, vector<int> &lazy) {
    if(!(end<l || start>r)) {
        if(start<=l && r<=end) {
            seg[index].high+=val;
            seg[index].low+=val;
            lazy[index]+=val;
        } else {
            push(l, r, index, seg, lazy);
            int mid=l+(r-l)/2;
            update(l, mid, index+1, seg, start, end, val, lazy);
            update(mid+1, r, index+2*(mid-l+1), seg, start, end, val, lazy);
            seg[index].low=min(seg[index+1].low, seg[index+2*(mid-l+1)].low);
            seg[index].high=max(seg[index+1].high, seg[index+2*(mid-l+1)].high);
        }
    }
    return;
}
 
node query(int l, int r, int index, vector<node> &seg, int start, int end, vector<int> &lazy) {
    node ans;
    ans.high=INT_MIN;
    ans.low=INT_MAX;
    if(!(end<l || start>r)) {
        if(start<=l && end>=r) {
            ans=seg[index];
        } else {
            push(l, r, index, seg, lazy); 
            int mid=l+(r-l)/2;
            auto left=query(l, mid, index+1, seg, start, end, lazy), right=query(mid+1, r, index+2*(mid-l+1), seg, start, end, lazy);
            ans.high=max(left.high, right.high);
            ans.low=min(left.low, right.low);
        }
    }
    return ans;
}
void solve() {
    int n;
    string s;
    cin>>n>>s;
    int m=1;
    for(auto &i : s) {
        m+=i=='R';
    }
    string build(m, '0');
    int curr=0, ans=0;
    vector<node> seg(2*m+1);
    vector<int> lazy(2*m+1);
    for(auto i : s) {
        if(i=='R') {
            curr++; 
        } else if(i=='L') {
            curr--;
        } else {
            int val=0;
            if(i=='(') {
                val++;
            } else if(i==')') {
                val--;
            }
            if(build[curr]=='(') {
                val--;
            } else if(build[curr]==')') {
                val++;
            }
            if(val) {
                update(1, m, 1, seg, curr+1, m, val, lazy);
                auto res=query(1, m, 1, seg, 1, m, lazy), last=query(1, m, 1, seg, m, m, lazy);
                if(res.low<0 || last.high) {
                    ans=-1;
                } else {
                    ans=res.high;
                }
            }   
            build[curr]=i;
        }
        cout<<ans<<" ";
        curr=max(curr, 0);
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

