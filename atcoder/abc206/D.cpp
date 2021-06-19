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
    int n;
    cin>>n;
    vector<int> a(n);
    map<int, int> id;
    for(auto &i : a) {
        cin>>i;
        id[i]=0;
    }
    int count=0;
    for(auto &i : id) {
        i.second=count;
        count++;
    }
    for(auto &i : a) {
        i=id[i];
    }
    vector<int> parent(count), size(count, 1);
    for(int i=0; i<count; i++) {
        parent[i]=i;
    }
    for(int i=0; i<n-1-i; i++) {
        union_sets(a[i], a[n-1-i], parent, size);
    }
    int ans=0;
    set<int> done;
    for(int i=0; i<count; i++) {
        if(!done.count(find_set(i, parent))) {
            done.insert(parent[i]);
            ans+=size[parent[i]]-1;
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

