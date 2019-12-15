#include<bits/stdc++.h>
using namespace std;
int main() {
	long int n,sx,sy,i,up=0,down=0,left=0,right=0;
	cin>>n>>sx>>sy;
	long int x[n],y[n];
	for(i=0;i<n;i++) {
		cin>>x[i]>>y[i];
		if(x[i]>sx) {
			right++;
		}
		if(x[i]<sx) {
			left++;
		}
		if(y[i]>sy) {
			up++;
		}
		if(y[i]<sy) {
			down++;
		}
	}
	if(max(right,left)>max(up,down)) {
		n=(right>left)?1:-1;
		cout<<max(left,right)<<endl<<sx+n<<" "<<sy;
	}
	else {
		n=(up>down)?1:-1;
		cout<<max(up,down)<<endl<<sx<<" "<<sy+n;
	}
}