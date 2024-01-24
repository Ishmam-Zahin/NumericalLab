#include<bits/stdc++.h>

using namespace std;

class FalsePositionMethod{
	double limit=2e6;
public:
	double funcValue(double x){
		return x*x*x+x*x+7;
	}

	double falsi(double a, double b){
		return (((a*funcValue(b))-(b*funcValue(a)))/(funcValue(b)-funcValue(a)));
	}

	double falsePosition(double a, double b){
		if(funcValue(a)*funcValue(b)>=0){
			cout<<"wrong gussed!\n";
		}
		else{
			double next;
			while(limit--){
				// cout<<"x\n";
				next=falsi(a, b);
				if(funcValue(next)==0){
					break;
				}
				else if(funcValue(next)*funcValue(a)<0){
					b=next;
				}
				else{
					a=next;
				}
			}
			return next;
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
		cout<<limit<<'\n';
		cout<<a<<' '<<b<<'\n';

		cout<<"ans: "<<falsePosition(a, b);
	}

};

int main(){
	FalsePositionMethod obj;
	obj.run();
}