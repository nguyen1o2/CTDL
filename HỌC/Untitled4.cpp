#include<iostream>
using namespace std;
void nhap(int n,int *a){
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"]=";
		cin>>a[i];
	}
}
void xuat(int n,int *a){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
}
long tongchuso(int x){
	if(x<10) 
	return x;
	else 
	return tongchuso(x/10)+x%10;
} 
long sum(int n,int *a){
	int sum=0;
	for(int i=0;i<n;i++){
		if(a[i]>0)
		sum+=tongchuso(a[i]);
	}
	return sum;
}
int main(){
	int n,*a;
	cout<<"Nhap n = ";cin>>n;
	a=new int [n];
	nhap(n,a);
	xuat(n,a);
	cout<<"\nTong cac so duong trong day la: "<<sum(n,a);
}