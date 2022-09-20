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
int max(int n,int *a){
	int max=a[0];
	for(int i=0;i<n;i++){
		if(max<a[i]) max=a[i];
	}
	return max;
}
int min(int n,int *a){
	int min=a[0];
	for(int i=0;i<n;i++){
		if(min>a[i]) min=a[i];
	}
	return min;
}
int UCLN(int p,int q){
    if(p%q==0) return q;
    return UCLN(p,p%q);
}
int main(){
	int n,*a;
	cout<<"Nhap n: ";cin>>n;
	a= new int [n];
	nhap(n,a);
	xuat(n,a);
	int p=max(n,a);
	int q=min(n,a);
	cout<<"UCLN : "<<UCLN(p,q);
	return 0;
}