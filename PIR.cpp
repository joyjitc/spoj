#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	// cin.tie(0);
	int t;
	cin>>t;
	long u,v,w,U,V,W,u_,v_,w_;
	double vol;
	cout<<fixed;
	cout.precision(4);
	while(t--){
		cin>>u>>v>>w>>W>>V>>U;
		u_ = v*v + w*w - U*U;
		v_ = w*w + u*u - V*V;
		w_ = u*u + v*v - W*W;
		vol = (4*u*u*v*v*w*w) - (u*u*u_*u_) - (v*v*v_*v_) - (w*w*w_*w_) + (u_*v_*w_);
		vol = sqrt(vol);
		vol = vol/12.0;
		cout<<vol<<"\n";
	}
}