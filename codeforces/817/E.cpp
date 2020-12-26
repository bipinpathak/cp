#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
	int oneCount=0, zeroCount=0;
	node *one=NULL, *zero=NULL;
};

void add(int p, int s, node &trie, int d) {
	if(d>=0) {
		int x=1;
		x=x<<d;
		if(p&x) {
			trie.oneCount+=s;
			if(trie.one==NULL) {
				trie.one=new node;
			}
			add(p, s, *trie.one, d-1);
		} else {
			trie.zeroCount+=s;
			if(trie.zero==NULL) {
				trie.zero=new node;
			}
			add(p, s, *trie.zero, d-1);
		}
	}
	return;
}

void go(int p, int l, node &trie, int d, int &ans) {
	if(d>=0) {
		int x=1;
		x=x<<d;
		if(trie.zeroCount) {
			if((p&x)==(l&x)) {
				go(p, l, *trie.zero, d-1, ans);
			} else if(l&x) {
				ans+=trie.zeroCount;
			}
		}
		if(trie.oneCount) {
			if((p&x)!=(l&x)) {
				go(p, l, *trie.one, d-1, ans);	
			} else if(l&x) {
				ans+=trie.oneCount;
			}
		}
	}
	return;
}

void solve() {
	int q;
	cin>>q;
	node trie;
	trie.oneCount=trie.zeroCount=0;
	while(q--) {
		int t, p;
		cin>>t>>p;
		if(t==1) {
			add(p, 1, trie, 26);
		} else if(t==2) {
			add(p, -1, trie, 26);
		} else {
			int l, ans=0;
			cin>>l;
			go(p, l, trie, 26, ans);
			cout<<ans<<endl;
		}
	}
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}

