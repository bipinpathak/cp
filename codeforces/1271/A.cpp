#include<bits/stdc++.h>
using namespace std;
int main() {
	long int a,b,c,d,e,f,ans=0,temp;
	cin>>a>>b>>c>>d>>e>>f;
	if(e>f) {
		temp=min(a,d);
		ans+=e*temp;
		d-=temp;
		temp=min(b,c);
		temp=min(temp,d);
		ans+=f*(temp);
	}
	else {
		temp=min(b,c);
		temp=min(temp,d);
		ans+=f*temp;
		d-=temp;
		temp=min(a,d);
		ans+=e*temp;
	}
	cout<<ans<<endl;
}