#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int find(int target, vector<int> &a) {
    int low=0, high=(int)a.size()-1;
    while(low<high) {
        int mid=(high+low)/2;
        if(a[mid]>target) {
            high=mid;
        } else {
            low=mid+1;
        }
    }
    return low;
}

void solve() {
    int n, m, k, q;
    cin>>n>>m>>k>>q;
    vector<int> left(n, m), right(n, -1), good(q);
    left[0]=right[0]=0;
    while(k--) {
        int r, c;
        cin>>r>>c;
        r--, c--;
        left[r]=min(left[r], c);
        right[r]=max(right[r], c);
    }
    for(auto &i : good) {
        cin>>i;
        i--;
    }
    sort(good.begin(), good.end());
    vector<ll> col={0}, cost={-1};
    ll ans=1e18;
    int prevRow=-1;
    for(int i=0; i<n; i++) {
        if(left[i]>right[i]) {
            continue;
        }
        ans=1e18;
        m=(int)cost.size();
        for(int j=0; j<m; j++) {
            cost[j]+=i-prevRow;
            ans=min(ans, cost[j]+right[i]-left[i]+min(abs(col[j]-left[i]), abs(col[j]-right[i])));
        }
        prevRow=i;
        vector<ll> updateCol, updateCost;
        int index;
        index=find(left[i], good);
        updateCol.push_back(good[index]);
        updateCost.push_back(1e18);
        if(index) {
            index--;
            updateCol.push_back(good[index]);
            updateCost.push_back(1e18);
        }
        index=find(right[i], good);
        updateCol.push_back(good[index]);
        updateCost.push_back(1e18);
        if(index) {
            index--;
            updateCol.push_back(good[index]);
            updateCost.push_back(1e18);
        }
        q=(int)updateCol.size();
        for(int j=0; j<m; j++) {
            for(int k=0; k<q; k++) {
                ll d=abs(col[j]-right[i])+abs(updateCol[k]-left[i]);
                d=min(d, abs(col[j]-left[i])+abs(updateCol[k]-right[i]));
                updateCost[k]=min(updateCost[k], cost[j]+right[i]-left[i]+d); 
            }
        }
        col=updateCol;
        cost=updateCost;
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

