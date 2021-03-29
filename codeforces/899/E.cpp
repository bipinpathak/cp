#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    priority_queue<vector<int>> store;
    vector<int> next(n), prev(n);
    int len=0, index;
    for(int i=0; i<n; i++) {
        next[i]=i+1;
        prev[i]=i-1;
        if(i==0 || a[i]!=a[i-1]) {
            if(len) {
                store.push({len, -index});
            }
            len=0;
            index=i;
        }
        len++;
    }
    if(len) {
        store.push({len, 1-n});
    }
    int ans=0;
    while(!store.empty()) {
        auto curr=store.top();
        index=-curr[1];
        store.pop();
        if(a[index]==-1) {
            continue;
        }
        ans++;
        int last=index, val=a[index];
        while(last<n && a[last]==val) {
            a[last]=-1;
            last=next[last];
        }
        index=prev[index];
        if(index>=0) {
            next[index]=last;
        }
        if(last<n) {
            prev[last]=index;
        }
        if(index>=0 && last<n && a[index]==a[last]) {
            int count=2, temp=last;
            while(next[temp]<n && a[next[temp]]==a[last]) {
                count++;
                temp=next[temp];
            }
            temp=index;
            while(prev[temp]>=0 && a[prev[temp]]==a[index]) {
                count++;
                temp=prev[temp];
            }
            store.push({count, -temp});
        }
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

