#include<iostream>
#include<math.h>
using namespace std;

long pow(int a,int n){
	if(n==1) return a;
	else{
		if(n%2==0) return pow(a,n/2)*pow(a,n/2);
		else return pow(a,n/2)*pow(a,n/2)*a;
	}
}
int main(){
	int a,n;
	cout<<"Nhap a: ";cin>>a;
	cout<<"Nhap n: ";cin>>n;
	cout<<"a^n = "<<pow(a,n);
	return 0;
}