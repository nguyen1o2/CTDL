#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cout<<"Nhap n= ";cin>>n;
    char a[n][20],tg[20];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"mang vua nhap la"<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}
	for(int i=1;i<n;i++){
		for(int j=n-1;j>=i;j--){
			if(strcmp(a[j],a[j-1])<0){
				strcpy(tg,a[j]);
			    strcpy(a[j],a[j-1]);
			    strcpy(a[j-1],tg);	
			}
		}
	}
	cout<<endl<<"mang sau khi sap xep la"<<endl;
		for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}
}