#include <bits/stdc++.h>
#include <math.h>
#include <type_traits>
using namespace std;
using ll = long long;

struct node{
	int index=-1;
	vector<node*> next;
	node() {
		for(int i=0; i<27; i++) {
			next.push_back(NULL);
		}
	}
};

node* build() {
	node *add = new node();
	return add;
}

void addPattern(string p, node *head, int index) {
	auto curr=head;
	for(auto i : p) {
		int c=i-'a';
		if(i=='_') {
			c=26;
		}
		if(curr->next[c]==NULL) {
			curr->next[c]=build();
		}
		curr=curr->next[c];
	}
	curr->index=index;
	return;
}

void match(string s, node *head, vector<int> &matches) {
	auto  curr=head;
	queue<node*> active;
	active.push(curr);
	for(auto i : s) {
		int n=(int)active.size();
		int index=i-'a';
		while(n--) {
			curr=active.front();
			active.pop();
			if(curr->next[index]!=NULL) {
				active.push(curr->next[index]);
			}
			if(curr->next[26]!=NULL) {
				active.push(curr->next[26]);
			}
		}
		if(active.empty()) {
			break;
		}
	}
	while(!active.empty()) {
		matches.push_back(active.front()->index);
		active.pop();
	}
	return;
}

void go(int u, vector<int> &visited, vector<int>&ans, vector<vector<int>> &adjacency, bool &cycle) {
	visited[u]=1;
	for(auto v : adjacency[u]) {
		if(visited[v]==0) {
			go(v, visited, ans, adjacency, cycle);
		} else if(visited[v]==1) {
			cycle=1;
			break;
		}
	}
	visited[u]=2;
	ans.push_back(u);
	return;
}

void solve() {
	int n, m, k;
	cin>>n>>m>>k;
	node *head=build();
	for(int i=0; i<n; i++) {
		string s;
		cin>>s;
		addPattern(s, head, i);
	}
	vector<vector<int>> adjacency(n);
	bool cycle=false;
	for(int i=0; i<m && !cycle; i++) {
		string s;
		int u;
		cin>>s>>u;
		u--;
		vector<int> next;
		match(s, head, next);
		if(next.empty()) {
			cout<<"NO"<<endl;
			return;
		}
		cycle=true;
		for(auto v : next) {
			if(v==u) {
				cycle=false;
				continue;
			}
			adjacency[u].push_back(v);
		}
	}
	vector<int> ans, visited(n);
	for(int i=0; i<n && !cycle; i++) {
		if(!visited[i]) {
			go(i, visited, ans, adjacency, cycle);
		}
	}
	reverse(ans.begin(), ans.end());
	if(cycle) {
		cout<<"NO"<<endl;
	} else {
		cout<<"YES"<<endl;
		for(auto i : ans) {
			cout<<i+1<<" ";
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
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}

