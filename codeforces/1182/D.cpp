#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int last(vector<int> &source, vector<vector<int>> &adjcency) {
    int n=(int)adjcency.size(), ans=0;
    vector<int> used(n);
    queue<int> active;
    while(!source.empty()) {
        active.push(source.back());
        ans=source.back();
        used[source.back()]=1;
        source.pop_back();
    }
    while(!active.empty()) {
        int m=(int)active.size();
        while(m--) {
            int u=active.front();
            active.pop();
            for(auto v : adjcency[u]) {
                if(!used[v]) {
                    active.push(v);
                    ans=v;
                    used[v]=1;
                }
            }
        }
    }
    return ans;
}

void go(int u, int p, vector<vector<int>> &adjcency, vector<int> &distance) {
    for(auto v : adjcency[u]) {
        if(v==p) {
            continue;
        }
        distance[v]=1+distance[u];
        go(v, u, adjcency, distance);
    }
    return;
}

bool check(int u, vector<vector<int>> &adjcency, vector<int> &degree) {
    int n=(int)adjcency.size(); 
    vector<int> distance(n);
    go(u, -1, adjcency, distance);
    map<int, int> seen;
    for(int i=0; i<n; i++) {
        if(seen.find(distance[i])==seen.end()) {
            seen[distance[i]]=degree[i];
        } else if(degree[i]!=seen[distance[i]]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adjcency(n);
    vector<int> degree(n);
    for(int i=0; i<n-1; i++) {
        int u, v;
            cin>>u>>v;
        u--, v--;
        adjcency[u].push_back(v);
        adjcency[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
        vector<int> active;
    for(int i=0; i<n; i++) {
        if(degree[i]==1) {
            active.push_back(i);
        }
    }
    if((int) active.size()==2) {
        cout<<active.front()+1<<endl;
        return;
    }
    int mid=last(active, adjcency);
    if(check(mid, adjcency, degree)) {
        cout<<mid+1<<endl;
        return;
    }
    active.push_back(0);
    int a=last(active, adjcency);
    int leaf=a;
    if(check(leaf, adjcency, degree)) {
        cout<<leaf+1<<endl;
        return;
    }
    active.push_back(a);
    int b=last(active, adjcency);
    leaf=b;
    if(check(leaf, adjcency, degree)) {
        cout<<leaf+1<<endl;
        return;
    }
    vector<int> distanceA(n), distanceB(n);
    go(a, -1, adjcency, distanceA);
    go(b, -1, adjcency, distanceB);
    int curr=n;
    for(int i=0; i<n; i++) {
        if(distanceA[i]==distanceB[i] && distanceA[i]<curr && degree[i]==1) {
            curr=distanceA[i];
            leaf=i;
        }
    }
    if(check(leaf, adjcency, degree)) {
        cout<<leaf+1<<endl;
        return;
    }
    cout<<-1<<endl;
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

