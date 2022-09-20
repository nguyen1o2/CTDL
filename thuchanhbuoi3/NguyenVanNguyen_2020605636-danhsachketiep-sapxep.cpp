#include<bits/stdc++.h>
using namespace std;

struct SV{
      int maSV;
	  char hoTen[30];
	  float toan,ly,hoa;
	  float dientb(){
	  	return (toan+ly+hoa)/3;
	  }
};

void nhap(SV &sv){
	cout<<"Nhap maSV: ";cin>>sv.maSV;
	cout<<"Nhap hoTen: ";fflush(stdin);gets(sv.hoTen);
	cout<<"Nhap diem toan: ";cin>>sv.toan;
	cout<<"Nhap diem ly: ";cin>>sv.ly;
	cout<<"Nhap diem hoa: ";cin>>sv.hoa;
}

void xuat(SV sv){
	cout<<setw(10)<<sv.maSV<<setw(20)<<sv.hoTen<<setw(20)<<sv.toan<<setw(20)<<sv.ly<<setw(20)<<sv.hoa<<setw(20)<<sv.dientb();
}

void nhapds(SV ds[],int n){
	for(int i=0;i<n;i++){
		nhap(ds[i]);
	}
}

void xuatds(SV ds[],int n){
	for(int i=0;i<n;i++){
		xuat(ds[i]);
		cout<<endl;
	}
}

void xoa(SV ds[],int &n){
	int k;
	cout<<"Nhap vi tri can xoa: ";cin>>k;
	if(k>=0 && k<n){
		for(int i=k;i<=n;i++){
			ds[i-1]=ds[i];
		}
		n--;
	}
	else{
		cout<<"Vi tri xoa khong hop le";
	}
}

void chen(SV ds[],int &n){
	int x;
	cout<<"Nhap vi tri chen: ";cin>>x;
	SV svnew;
	nhap(svnew);
	for(int i=n;i>=x-1;i--){
		ds[i+1]=ds[i];
	}
	ds[x-1]=svnew;
	n++;
}

//sắp xếp nổi bọt
//void sort(SV ds[],int n){
//	SV tg;
//	for(int i=1;i<n;i++){
//		for(int j=n;j>i-1;j--){
//			if((ds[j].toan+ds[j].ly+ds[j].hoa)/3>(ds[j-1].toan+ds[j-1].ly+ds[j-1].hoa)/3){
//				tg=ds[j];
//				ds[j]=ds[j-1];
//				ds[j-1]=tg;
//			}
//		}
//	}
//}

//sắp xếp chọn
void sxchon(SV ds[],int n){
	for(int i=0;i<n-1;i++){
		SV tg;
		int m=i;
		for(int j=i+1;j<n;j++){
			if((ds[j].toan+ds[j].ly+ds[j].hoa)/3<(ds[m].toan+ds[m].ly+ds[m].hoa)/3)
			m=j;
		}
		if(m!=i){
			tg=ds[m];
			ds[m]=ds[i];
			ds[i]=tg;
		}
	}
}

//sắp xếp chèn
//void sxchen(SV ds[],int n){
//	for(int i=1;i<n;i++){
//		SV tam=ds[i];
//		int j=i-1;
//		while(j<-1 && (ds[j].toan+ds[j].ly+ds[j].hoa)/3<(tam.toan+tam.ly+tam.hoa)/3){
//			ds[j+1]=ds[i];
//			j--;
//		}
//		ds[j+1]=tam;
//	}
//}

int main(){
	SV ds[100];
	int n;
	cout<<"Nhap so sv: ";cin>>n;
	nhapds(ds,n);
	cout<<endl<<"========================================Thong Tin Sinh Vien======================================="<<endl;
	cout<<setw(10)<<"maSV"<<setw(20)<<"hoTen"<<setw(20)<<"toan"<<setw(20)<<"ly"<<setw(20)<<"hoa"<<setw(20)<<"dientb"<<endl;
	xuatds(ds,n);
	xoa(ds,n);
	cout<<"Danh sach sinh vien sau khi xoa"<<endl;
	cout<<setw(10)<<"maSV"<<setw(20)<<"hoTen"<<setw(20)<<"toan"<<setw(20)<<"ly"<<setw(20)<<"hoa"<<setw(20)<<"dientb"<<endl;
	xuatds(ds,n);
    chen(ds,n);
    cout<<"Danh sach sinh vien sau khi chen"<<endl;
    cout<<setw(10)<<"maSV"<<setw(20)<<"hoTen"<<setw(20)<<"toan"<<setw(20)<<"ly"<<setw(20)<<"hoa"<<setw(20)<<"dientb"<<endl;
    xuatds(ds,n);
    sxchon(ds,n);
//    sxchen(ds,n);
//    sort(ds,n);
    cout<<"Danh sach sinh vien sau khi sap xep"<<endl;
	cout<<setw(10)<<"maSV"<<setw(20)<<"hoTen"<<setw(20)<<"toan"<<setw(20)<<"ly"<<setw(20)<<"hoa"<<setw(20)<<"dientb"<<endl;
	xuatds(ds,n);
	return 0;
}