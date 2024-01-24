#include<bits/stdc++.h>

using namespace std;

class NewtonForwardInterpolationMethod{
public:

	double newtonForward(double target, vector<double> &x, vector<double> &y){
		double h=x[1]-x[0];
		double u=(target-x[0])/h;
		vector<double> f;
		f.push_back(y[0]);
		int n=x.size();
		for(int i=1; i<n; i++){
			for(int j=0; j<n-i; j++){
				// cout<<y[j+1]<<'\n';
				y[j]=y[j+1]-y[j];
			}
			f.push_back(y[0]);
		}

		double fact=1;
		double ans=0;
		double uu=1;
		for(int i=0; i<n; i++){
			if(i==0) ans+=f[i];
			else{
				fact*=i;
				uu=uu*(u-(i-1));
				ans+=((uu/fact)*f[i]);
			}
		}
		return ans;
	}
	void run(){
		double targetValue;
		cin>>targetValue;
		vector<double> x;
		vector<double> y;
		double xx, yy;
		while(cin>>xx>>yy){
			// cout<<xx<<yy<<'\n';
			x.push_back(xx);
			y.push_back(yy);
		}
		double ans = newtonForward(targetValue, x, y);
		cout<<ans<<'\n';
	}
};

int main(){
	NewtonForwardInterpolationMethod obj;
	obj.run();
}