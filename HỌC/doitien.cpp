#include<iostream>
using namespace std;

void doitien(int sotien){
	int menhgia[5]={10000,5000,2000,1000,500};
	int sototien[5]={0};
	int i=0;
	
	while(i<5 && sotien>0){
		sototien[i]=sotien/menhgia[i];
		sotien=sotien%menhgia[i];
		i++;
	}
	cout<<"So to tien doi duoc la:\n";
	for(int j=0;j<5;j++){
		if(sototien[j]>0){
			cout<<sototien[j]<<" to menh gia : "<<menhgia[j]<<endl;
		}
	}
}
int main(){
	int sotien;
	do{
		cout<<"Nhap so tien can doi: ";cin>>sotien;
	}
	while(sotien<500);
    doitien(sotien);
	return 0;
}