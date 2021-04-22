#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> calc(int high) {
    vector<int> lp(high+1), primes;
    lp[1]=1;
    for(int i=2; i<=high; i++) {
        if(lp[i]==0) {
            lp[i]=i;
            primes.push_back(i);
        }
        for(auto p : primes) {
            if(p>high/i || p>lp[i]) {
                break;
            }
            lp[i*p]=p;
        }
    }
    return lp;
}

bool possible (int start, int end, int hops, vector<vector<int>> &jumps) {
    int curr=start;
    while(curr<=end && hops) {
        int choose=1, count=0;
        while(choose<=hops) {
            choose<<=1;
            count++;
        }
        choose>>=1;
        count--;
        curr=jumps[curr][count];
        hops-=choose;
    }
    return curr>end;
}   

int go(int l, int r, vector<vector<int>> &jumps) {
    int low=1, high=r-l+1;
    while(low<high) {
        int mid=low+(high-low)/2;
        if(possible(l, r, mid, jumps)) {
            high=mid;
        } else {
            low=mid+1;
        }
    }   
    return low;
}

void solve() {
    int n, q;
    cin>>n>>q;
    vector<int> a(n);
    int high=0;
    for(auto &i : a) {
        cin>>i;
        high=max(high, i);
    }
    auto lp=calc(high);
    vector<int> seen(high+1, n), next(n, n);
    for(int i=n-1; i>=0; i--) {
        if(i+1<n) {
            next[i]=next[i+1];
        }
        vector<int> curr;
        while(lp[a[i]]>1) {
            curr.push_back(lp[a[i]]);
            next[i]=min(next[i], seen[lp[a[i]]]);
            a[i]/=lp[a[i]];
        }
        for(auto j : curr) {
            seen[j]=i;
        }
    }
    vector<vector<int>> jumps(n, vector<int> (18, n));
    for(int i=n-1; i>=0; i--) {
        jumps[i][0]=next[i];
        for(int j=1; j<18 && jumps[i][j-1]<n; j++) {
            jumps[i][j]=jumps[jumps[i][j-1]][j-1];
        }
    }
    while(q--) {
        int l, r;
        cin>>l>>r;
        l--, r--;
        cout<<go(l, r, jumps)<<endl;
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

