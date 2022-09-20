#include<iostream>
using namespace std;

long sochuso(int n){
	if(n<10) return 1;
	else {
	return 1+sochuso(n/10);
	}
}
//            {  1 nếu n<10 
//Sochuso(n)=
//            { 1+Sochuso(n/10) trong các th còn lại
int main(){
	int n;
	do{
		cout<<"Nhap n: ";cin>>n;
	}
	while(n<0);
	cout<<"So chu so cua n = "<<sochuso(n);
	return 0;
}