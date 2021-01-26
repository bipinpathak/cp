#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct road{
	int from, to;
	ll limit;
};

bool custom(road const &a, road const &b) {
	return a.limit<b.limit;
}

int find_set(int v, vector<int> &parent) {
	if(parent[v]!=v) {
		parent[v]=find_set(parent[v], parent);
	}
    return parent[v];
}

void make_set(int v, vector<int> &parent, vector<int> &size) {
    parent[v] = v;
    size[v] = 1;
	return;
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
	int n, m, k;
	cin>>n>>m>>k;
	vector<road> roads(m);
	for(auto &i : roads) {
		cin>>i.from>>i.to>>i.limit;
		i.from--;
		i.to--;
	}
	sort(roads.begin(), roads.end(), custom);
	vector<int> parent(n, -1), size(n);
	ll ans=0, used=0, low=0, high=2*k;
	for(auto i : roads) {
		if(parent[i.from]==-1) {
			make_set(i.from, parent, size);
		}
		if(parent[i.to]==-1) {
			make_set(i.to, parent, size);
		}
		if(find_set(i.from, parent)!=find_set(i.to, parent)) {
			union_sets(i.from, i.to, parent, size);
			ans+=max((ll)0, i.limit-k);
			used=max(used, i.limit);
		}
		if(i.limit<=k) {
			low=max(low, i.limit);
		}
		else {
			high=min(high, i.limit);
		}
	}
	if(used<k) {
		ans+=min(k-low, high-k);
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
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

