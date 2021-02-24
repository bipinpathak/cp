#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(vector<int> &a, vector<int> &change) {
    int n=(int)a.size();
    vector<int> used(n), ans;
    int last=-1;
    for(auto i : change) {
        int index=i+last;
        last=index;
        while(index>=0 && !used[index]) {
            ans.push_back(a[index]);
            used[index]=1;
            index--;
        }
    }
    reverse(ans.begin(), ans.end());
    a=ans;
    return;
    }

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
        i--;
    }
    vector<vector<int>> ans;
    while(1) {
        vector<int> seen(n+1, n);
        int index=n;
        for(int i=0; i<n; i++) {
            if(seen[a[i]+1]<n) {
                index=i;
                break;
            } 
            seen[a[i]]=i;
        }
        if(index==n) {
            break;
        }
        vector<int> temp;
        int first=seen[a[index]+1];
        temp.push_back(first);
        first++;
        while(a[first]==a[first-1]+1) {
            first++;
        }
        temp.push_back(first-seen[a[index]+1]);
        temp.push_back(index-first+1);
        temp.push_back(n-index-1);
        ans.push_back({});
        for(auto j : temp) {
            if(j) {
                ans.back().push_back(j);
            }
        }
        go(a, ans.back());
    }
    cout<<ans.size()<<endl;
    for(auto i : ans) {
        cout<<i.size()<<" ";
        for(auto j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
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
    while(t--) {
        solve();
    }
    return 0;
}

