#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void verti(vector<vector<int>> &a, int col) {
	int n=(int)a.size();
	for(int i=0; i<n; i++) {
		a[i][col]=!a[i][col];
	}
	return;
}

void hori(vector<vector<int>> &a, int row) {
	int n=(int)a.size();
	for(int j=0; j<n; j++) {
		a[row][j]=!a[row][j];
	}
	return;
}

bool solve() {
	int n;
	cin>>n;
	vector<vector<int>> a(n), b(n);
	for(auto &i : a) {
		string s;
		cin>>s;
		for(auto &j : s) {
			i.push_back(j-'0');
		}
	}
	cin.ignore();	
	for(auto &i : b) {
		string s;
		cin>>s;
		for(auto &j : s) {
			i.push_back(j-'0');
		}
	}
	for(int j=0; j<n; j++) {
		if(a[0][j]!=b[0][j]) {
			verti(a, j);
		}
	}
	for(int row=1; row<n; row++) {
		if(a[row][0]!=b[row][0]) {
			hori(a, row);
		}
		for(int j=0; j<n; j++) {
			if(a[row][j]!=b[row][j]) {
				return false;
			}
		}
	}
    return true;
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
        if(solve()) {
			cout<<"YES"<<endl;	
        } else {
			cout<<"NO"<<endl;
		}
    }
    return 0;
}

