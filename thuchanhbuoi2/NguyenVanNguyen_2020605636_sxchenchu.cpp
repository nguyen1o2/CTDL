#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cout<<"Nhap n: ";cin>>n;
	char a[n][100],x[100];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"mang vua nhap la"<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	for (int i=1; i<n; i++){
        strcpy(x,a[i]);
        int j = i-1; 
    while (j>-1 && strcmp(a[j],x)>0){
        strcpy(a[j+1],a[j]);
        j--;
        }
    strcpy(a[j+1],x);
    }
	cout<<endl<<"sap xep thanh: "<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}