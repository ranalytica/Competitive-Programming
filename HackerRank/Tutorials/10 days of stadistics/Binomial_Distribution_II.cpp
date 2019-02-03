#include <bits/stdc++.h>

using namespace std;

double binomialCoefficients(int n, int k){
	double res = 1.0;
	if(k > n-k) k = n-k;
	for(int x=0; x < k; x++){
		res*=(double)(n-x);
		res/=(double)(x+1);
	}
	return res;
}

double binomialDistribution(int x, int n, double p){
	double q = 1.0-p;
	return binomialCoefficients(n,x)*pow(p,x)*pow(q,n-x);
}
int main(){
	ios_base::sync_with_stdio(false);
	cout.precision(3);
	cout.fixed;
	double percent, pistons;
	cin>>percent>>pistons;
	percent/=100.0;
	double noMore=0,atLeast=0;
	for(int x=0; x<=2; x++){
		noMore+=binomialDistribution(x,(int)pistons,percent);
	}
	for(int x=2; x<=(int)pistons; x++){
		atLeast+=binomialDistribution(x,(int)pistons,percent);
	}
	cout<<noMore<<"\n"<<atLeast<<endl;
	return 0;
}