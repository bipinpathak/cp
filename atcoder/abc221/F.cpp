#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll mod=998244353;

int far(int u, vector<vector<int>> &adjacency) {
    int n=(int)adjacency.size(), ans=u;
    vector<int> done(n);
    queue<int> level;
    level.push(u);
    done[u]=1;
    while(!level.empty()) {
        n=(int)level.size();
        ans=level.front();
        level.pop();
        for(auto v : adjacency[ans]) {
            if(!done[v]) {
                level.push(v);
                done[v]=1;
            }
        }
    }
    return ans;
}

void mid(int p, int u, int b, vector<int> &path,  vector<vector<int>> &adjacency, int &ans) {
    path.push_back(u);
    if(u==b) {
        int n=(int)path.size();
        ans=path[n/2];
    } else for(auto v : adjacency[u]) {
        if(v==p) {
            continue;
        }
        mid(u, v, b, path, adjacency, ans);
        if(ans!=-1) {
            break;
        }
    }
    path.pop_back();
    return;
}

void dfs(int p, int u, ll curr, vector<vector<int>> &adjacency, ll &len, ll &count) {
    for(auto v : adjacency[u])  {
        if(v==p) {
            continue;
        }
        dfs(u, v, curr+1, adjacency, len, count);
    }
    if(curr>len) {
        len=curr;
        count=0;
    }
    count+=curr==len;
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adjacency(n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin>>a>>b;
        a--, b--;
        adjacency[a].push_back(b);
        adjacency[b].push_back(a);
    }
    int a=far(0, adjacency), b=far(a, adjacency), x=-1;
    vector<int> temp;
    mid(-1, a, b, temp, adjacency, x);
    ll ans=0, prevMax=0, prevCount=1, d=0;
    vector<ll> storeCounts;
    for(auto v : adjacency[x]) {
        ll currMax=0, currCount=0;
        dfs(x, v, 1, adjacency, currMax, currCount);
        if(currMax+prevMax>d) {
            ans=0;
            d=currMax+prevMax;
        }
        if(currMax+prevMax==d) {
            ans=(ans+(prevCount*currCount)%mod)%mod;
        }
        if(currMax>prevMax) {
            prevMax=currMax;
            prevCount=0;
            storeCounts.clear();
        }
        if(currMax==prevMax) {
            prevCount+=currCount;
            storeCounts.push_back(currCount);
        }
    }
    if(d==2*prevMax) {
        ll sum=0, add=1;
        for(auto i : storeCounts) {
            ans=(ans-(i*sum)%mod)%mod;
            sum=(sum+i)%mod;
            add=(add*(i+1))%mod;
        }
        add=(add-sum-1)%mod;
        ans=(ans+add)%mod;
    }
    if(ans<0) {
        ans+=mod;
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

