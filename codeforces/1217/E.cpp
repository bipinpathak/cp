#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node{
    vector<int> digits;
    node() {
        int high=1e9;
        for(int i=0; i<9; i++) {
            digits.push_back(high);
        }
        high*=2;
        digits.push_back(high);
    }
};

void update(int l, int r, int index, vector<node>&seg, int target, int val) {
    if(target<l || target>r) {
        return;
    }
    int high=1e9;
    if(l==r && l==target) {
        ll temp=val;
        for(int i=0; i<9; i++) {
            seg[index].digits[i]=high;
            if(temp%10) {
                seg[index].digits[i]=val;
            }
            temp/=10;
        }
        seg[index].digits.back()=2*high;
    } else {
        int mid=l+(r-l)/2;
        update(l, mid, index+1, seg, target, val);
        update(mid+1, r, index+2*(mid-l+1), seg, target, val);
        seg[index].digits.back()=min(seg[index+1].digits.back(), seg[index+2*(mid-l+1)].digits.back());
        for(int i=0; i<9; i++) {
            int leftChild=seg[index+1].digits[i], rightChild=seg[index+2*(mid-l+1)].digits[i];
            if(leftChild<high && rightChild<high) {
                seg[index].digits.back()=min(seg[index].digits.back(), leftChild+rightChild);
            }
            seg[index].digits[i]=min(leftChild, rightChild);
        }
    }
    return;
}

void query(int l, int r, int index, vector<node> &seg, int start, int end, vector<int> &ans) {
    if(!(end<l || start>r)) {
       if(start<=l && end>=r) {
           int high=1e9;
           ans.back()=min(ans.back(), seg[index].digits.back());
            for(int i=0; i<9; i++) {
                int curr=seg[index].digits[i];
                if(curr<high && ans[i]<high) {
                    ans.back()=min(ans.back(), curr+ans[i]);
                }
                ans[i]=min(ans[i], curr);
            }
       } else {
           int mid=l+(r-l)/2;
           query(l, mid, index+1, seg, start, end, ans);
           query(mid+1, r, index+2*(mid-l+1), seg, start, end, ans);
       }
    }
    return;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<node> seg(2*n+1);
    for(int i=1; i<=n; i++) {
        int x;
        cin>>x;
        update(1, n, 1, seg, i, x);
    }
    while(m--) {
        int t;
        cin>>t;
        if(t==1) {
            int index, val;
            cin>>index>>val;
            update(1, n, 1, seg, index, val);
        } else {
            int start, end;
            cin>>start>>end;
            int high=1e9;
            vector<int> ans(9, high);
            high*=2;
            ans.push_back(high);
            query(1, n, 1, seg, start, end, ans);
            if(ans.back()==high) {
                ans.back()=-1;
            }   
            cout<<ans.back()<<endl;
        }
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
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

