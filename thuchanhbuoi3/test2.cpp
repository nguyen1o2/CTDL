#include<bits/stdc++.h>
#define MAX 8

using namespace std;

struct SV{
      int maSV;
	  char hoTen[30];
	  float toan,ly,hoa;
	  float dientb(){
	  	return (toan+ly+hoa)/3;
	  }
};

struct vector{
	int count;
	SV e[MAX];
};
vector &v;

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
void nhapds(vector &v){
	for(int i=0;i<v.count;i++){
		v.nhap(e[i]);
	}
}
void xuatds(vector &v){
	for(int i=0;i<v.count;i++){
		v.xuat(e[i]);
	}
}

void xoa_pt_dau_tien(vector &v){
 if (v.count < 0){
 cout<<"\nDanh sach rong...!";
 return;
 }
 for (int i = 1; i <= v.count; i++){
 v.e[i-1] = v.e[i];
 }
 v.count--;
}

int insert(vector &v, int k, SV X){
 if (k <= v.count + 1 && k > 0 && !full(v)){
 for (int i = v.count; i >= k-1; i--)
 v.e[i + 1] = v.e[i] ;
 v.e[k - 1] = X;
 v.count ++;
 return 1;
 }
 else return 0;
}

int main(){
	vector sv;
	nhapds(sv);
	xuatds(sv);
	return 0;
}