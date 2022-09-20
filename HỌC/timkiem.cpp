#include<iostream>
using namespace std;

void nhap(int *a,int n){
	for(int i=0;i<n;i++){
		cout<<"a["<<i<<"]=";
		cin>>a[i];
	}
}
void xuat(int *a,int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
}
void timkiem(int *a,int n,int x){
	int dem=0;
	for(int i=0;i<n;i++){
		if(a[i]==x){
			dem++;
		}
	}
}
int banerySearch(int *a,int n,int l,int r,int x){
	if(l>r) return -1;
	else{
	int mid=(l+r)/2;
	if(a[mid]==x) return mid;
	else id(a[mid]>x) return banerySearch(a,n,)	
	}
}
int main(){
	int *a,n,x;
	cout<<"Nhap n = ";cin>>n;
	a=new int [n];
	nhap(a,n);
	xuat(a,n);
	cout<<"Nhap x: ";cin>>x;
	cout<<"x nam o vi tri thu: ";
	cout<<banerySearch(a,n,0,n-1,x);
	return 0;
}