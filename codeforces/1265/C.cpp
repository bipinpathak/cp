#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,i,g=0,s=0,b=0,p=1,b1=0;
		cin>>n;
		long int a[n];
		for(i=0;i<n;i++) {
			cin>>a[i];
			if(i==0) {
				g++;
			}
			else if(i<n/2) {
				if(a[i]<a[i-1]) {
					if(s==0) {
						p++;
					}
					else if(s>g && b==0) {
						p++;
					}
					else {
						b1=0;
					}
				}
				if(p==1) {
					g++;
				}
				else if(p==2) {
					s++;
				}
				else if(p==3) {
					b++;
					b1++;
				}
			}
		}
		if(a[n/2]==a[(n/2)-1]) {
				b-=b1;
			}
		if(g<s && g<b) {
			cout<<g<<" "<<s<<" "<<b<<endl;
		}
		else {
			cout<<"0 0 0"<<endl;
		}
	}
}