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
    int n, m;
    cin>>n>>m;
    vector<vector<int>> t(n, vector<int> (2));
    for(int i=0; i<n; i++) {
        cin>>t[i][0];
        t[i][1]=i;
    }
    sort(t.begin(), t.end());
    vector<int> index(n);
    for(int i=0; i<n; i++) {
        index[t[i][1]]=i+1;
        reverse(t[i].begin(), t[i].end());
    }
    sort(t.begin(), t.end());
    vector<int> count(n+1), sum(n+1);
    for(int i=0; i<n; i++) {
        int target=m-t[i][1];
        int low=0, high=n;
        while(low<high) {
            int mid=(high+low+1)/2;
            if(get(mid, sum)<=target) {
                low=mid;
            } else {
                high=mid-1;
            }
        }
        cout<<i-get(low, count)<<" ";
        add(index[i], 1, count);
        add(index[i], t[i][1], sum);
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

