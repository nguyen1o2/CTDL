#include<iostream>
#include<math.h>
using namespace std;

long pow(int n){
	if(n==0) return 1;
	else if(n==1) return 2;
	else{
		return 2*pow(n-1);
	}
}
// day so : 1,2,4,8,16
//     {1 neu n=0
//f(n)=
//     {2*f(n-1) th con lai
int main(){
	int n;
	cout<<"Nhap n: ";cin>>n;
	cout<<"So thu "<<n<<" trong day la: "<<pow(n);
	return 0;
}