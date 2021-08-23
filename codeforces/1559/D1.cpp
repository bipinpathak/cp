#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int find_set(int v, vector<int> &parent) {
	if(parent[v]!=v) {
		parent[v]=find_set(parent[v], parent);
	}
    return parent[v];
}

void union_sets(int a, int b, vector<int> &parent, vector<int> &size) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
	return;
}

void solve() {
    int n, m1, m2;
    cin>>n>>m1>>m2;
    vector<int> parent1(n), parent2(n), size1(n), size2(n);
    for(int i=0; i<n; i++) {
        parent1[i]=parent2[i]=i;
        size1[i]=size2[i]=1;
    }
    while(m1--) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        union_sets(u, v, parent1, size1);
    }
    while(m2--) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        union_sets(u, v, parent2, size2);
    }
    vector<vector<int>> ans;
    for(int i=1; i<n; i++) {
        find_set(0, parent1);
        find_set(i, parent1);
        find_set(0, parent2);
        find_set(i, parent2);
        if(parent1[0]==parent1[i] || parent2[0]==parent2[i]) {
            continue;
        }
        ans.push_back({0, i});
        union_sets(0, i, parent1, size1);
        union_sets(0, i, parent2, size2);
    }   
    vector<int> left, right;
    find_set(0, parent1);
    find_set(0, parent2);
    set<vector<int>> seen={{parent1[0], parent2[0]}};
    for(int i=1; i<n; i++) {
        find_set(i, parent1);
        find_set(i, parent2);
        if(seen.count({parent1[i], parent2[i]})) {
            continue;
        }
        seen.insert({parent1[i], parent2[i]});
        if(parent1[i]==parent1[0]) {
            left.push_back(i); 
        }
        if(parent2[i]==parent2[0]) {
            right.push_back(i);
        }
    }
    while(!left.empty() && !right.empty()) {
        ans.push_back({left.back(), right.back()});
        union_sets(left.back(), right.back(), parent1, size1);
        union_sets(left.back(), right.back(), parent2, size2);
        left.pop_back(), right.pop_back();
    }
    cout<<ans.size()<<endl;
    for(auto i : ans) {
        for(auto j : i) {
            cout<<j+1<<" ";
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

