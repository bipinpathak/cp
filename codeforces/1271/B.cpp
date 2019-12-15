#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,i,b=0,w=0,j=0,count=0;
	string s;
	cin>>n>>s;
	int a[n];
	for(i=0;i<n;i++) {
		if(s.at(i)=='W') {
			w++;
		}
		else {
			b++;
		}
	}
	if(w==0 || b==0) {
		cout<<"0"<<endl;
	}
	else if(w%2+b%2==2) {
		cout<<"-1"<<endl;
	}
	else {
		if(w%2 || (w%2==0 && b%2==0 && w<b)) {
			for(i=0;i<n-1;i++) {
				if(s.at(i)=='B') {
					a[j]=i+1;
					j++;
					count++;
					s.at(i)='W';
					s.at(i+1)=(s.at(i+1)=='W')?'B':'W';
				}
			}
		}
		else  {
			for(i=0;i<n-1;i++) {
				if(s.at(i)=='W') {
					a[j]=i+1;
					j++;
					count++;
					s.at(i)='B';
					s.at(i+1)=(s.at(i+1)=='W')?'B':'W';
				}
			}
		}
		cout<<count<<endl;
		for(i=0;i<j;i++) {
			cout<<a[i]<<" ";
		}
	}
}