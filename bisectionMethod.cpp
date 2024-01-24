#include<bits/stdc++.h>

using namespace std;

class BisectionMethod{
	const double limit = 0.0001;
public:
	double funcValue(double x){
		return x*x*x+x*x-1;
	}

	double bisection(double a, double b){
		if(funcValue(a)*funcValue(b)>=0){
			cout<<"gussed wrong!";
		}
		else{
			double mid;
			while(abs(abs(a)-abs(b))>=limit){
				mid=(a+b)/2;
				if(funcValue(mid)==0){
					break;
				}
				else if(funcValue(a)*funcValue(mid)<0){
					b=mid;
				}
				else{
					a=mid;
				}
			}

			return mid;
		}
	}

	void run(){
		srand(time(0));
		double a, b;
		while(true){
			a=(rand()%100)*(-1);
			b=rand()%100;

			if(funcValue(a)*funcValue(b)<0) break;
		}
		// cout<<limit<<'\n';
		// cout<<a<<' '<<b<<'\n';
		cout<<"ans: "<<bisection(a, b);
	}
};

int main(){
	BisectionMethod obj;
	obj.run();
}