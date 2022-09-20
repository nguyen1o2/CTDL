#include<bits/stdc++.h>
using namespace std;

struct SinhVien{
	char Masv[10];
	char Tensv[30];
	float Diemtk;
};

struct Node{
	SinhVien info;
	Node *next;
};

typedef struct Node *TRO;
void create(TRO &l){
	l=NULL;
}

void nhap1sv(SinhVien &sv){
	cout<<"Nhap masv: ";fflush(stdin);gets(sv.Masv);
	cout<<"Nhap tensv: ";fflush(stdin);gets(sv.Tensv);
	cout<<"Nhap diemtk: ";cin>>sv.Diemtk;
}

void xuat1sv(SinhVien sv){
	cout<<sv.Masv<<setw(20)<<sv.Tensv<<setw(20)<<sv.Diemtk<<endl;
}

void xuatds(TRO l){
	while(l!=NULL){
		xuat1sv(l->info);
		l=l->next;
	}
}

void add_last(TRO &l,SinhVien sv){
	//TRO p=new Node;
	Node *p= new Node;
	p->info=sv;
	p->next=NULL;
	if(l==NULL){
		l=p;
	}
	else{
		TRO q=l;
		while(q->next!=NULL){
		    q=q->next;
		}
		q->next=p;
	}
}

void nhapds(TRO &l){
	int count=1,n;
	cout<<"Nhap so luong sinh vien: ";cin>>n;
	while(true)
	{
	do{
		SinhVien tg;
		cout<<"Nhap thong tin sinh vien thu: "<<count<<endl;
		nhap1sv(tg);
        add_last(l,tg);
        count++;
	}
	while(count<=n);
	break;
	}
} 

void add_fist(TRO &l,SinhVien sv){
	TRO p = new Node;
	p->info=sv;
	p->next=l;
	l=p;
}

void chenvaodau1sv(TRO &l){
	SinhVien sv;
	nhap1sv(sv);
	add_fist(l,sv);
}

void sapxep(TRO l){
	SinhVien tg;
	TRO M,Q,R;
//	TRO p=l;//i=0
//	TRO q=p->next;//j=1
    R=l;
	while(R->next!=NULL){
		M=R;
		Q=R->next;
		while(Q!=NULL){
		if(Q->info.Diemtk<M->info.Diemtk){
			M=Q;
		}
		Q=Q->next;	
		}
		tg=R->info;
		R->info=M->info;
		M->info=tg;
		R=R->next;
	}
}
void xoa(TRO &l){
    int d=1,n;
    cout<<"Nhap vi tri xoa: ";cin>>n;
	TRO Q,M=l;
	while(M!= NULL &&  d<n){
		M->next;
		d++;
	}
	Q=M->next;
	M->next=Q->next;
	delete(Q);	
}
int main(){
	TRO sv1;
	create(sv1);
    nhapds(sv1);
	cout<<"=============Danh sach sinh vien============"<<endl;
	cout<<"Masv"<<setw(20)<<"Tensv"<<setw(20)<<"Diemtk"<<endl;
	xuatds(sv1);
	sapxep(sv1);
	cout<<"===========Danh sach sx sinh vien==========="<<endl;
	cout<<"Masv"<<setw(20)<<"Tensv"<<setw(20)<<"Diemtk"<<endl;
	xuatds(sv1);
	chenvaodau1sv(sv1);
	cout<<"========Danh sach khi them sinh vien========"<<endl;
	cout<<"Masv"<<setw(20)<<"Tensv"<<setw(20)<<"Diemtk"<<endl;
	xuatds(sv1);
	xoa(sv1);
	cout<<"========Danh sach khi xoa sinh vien========"<<endl;
	cout<<"Masv"<<setw(20)<<"Tensv"<<setw(20)<<"Diemtk"<<endl;
	xuatds(sv1);
	return 0;
}
