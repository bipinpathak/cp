#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void add(int index, int val, vector<int> &a) {
    int n=(int)a.size();
    while(index<n) {
        a[index]+=val;
        index+=index&-index;
    }
    return;
}

int get(int index, vector<int> &a) {
    int ans=0;
    while(index) {
        ans+=a[index];
        index-=index&-index;
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), all;
    for(auto &i : a) {
        cin>>i;
        all.push_back(i);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    int m=(int)all.size();
    map<int, int> val;
    for(int i=0; i<m; i++) {
        val[all[i]]=i+1;
    }
    vector<int> active(m+1);
    for(auto &i : a) {
        i=val[i];
        add(i, 1, active);
    }
    ll count=0;
    while(!a.empty()) {
        int curr=a.back();
        a.pop_back();
        add(curr, -1, active);
        n--;
        int low=get(curr-1, active), high=n-get(curr, active);
        count+=min(low, high);
    }
    cout<<count<<endl;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

