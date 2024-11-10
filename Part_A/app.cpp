#include <iostream>
#include <fstream>
#include <algorithm>
#include "hoc_sinh.cpp"
#include "danh_sach.cpp"
using namespace std;

int menu()
{
	int select;
	cout<<"\nAPP QUAN LY HOC SINH";
	cout<<"\n1. Nhap hoc sinh tu file";
	cout<<"\n2. Them hoc sinh";
	cout<<"\n3. Nhap ma hoc sinh cap nhat thong tin";
	cout<<"\n4. Nhap ma hoc sinh xoa";
	cout<<"\n5. Nhap ten hoc sinh tim kiem";
	cout<<"\n6. Sap xep danh sach theo diem trung binh";
	cout<<"\n7. Sap xep danh sach theo ten";
	cout<<"\n8. Hien thi danh sach hoc sinh";
	cout<<"\n9. Ghi danh sach hoc sinh ra file";
	cout<<"\n10. Thoat";
	cout<<"\n\nMoi ban chon chuc nang: ";
	cin>>select;
	if(select>=1 && select<=10) return select;
	return menu();
}

signed main()
{
	danh_sach C;
	hs b;
	int idx;
	string n;
	string ma;
	ifstream fin;
	ofstream fout;
	do
	{
		int mn=menu();
		system("cls");
		switch(mn)
		{
			case 1:
				fin.open("pupil.txt",ios::in);
				fin>>C;
				fin.close();
				break;
			case 8: cout<<C; break;
			case 10: return 0;
			case 9:
				fout.open("pupilout.txt",ios::out);
				fout<<C;
				fout.close();
				break;
			case 2:
				cout<<"\nNhap thong tin hoc sinh\n";
				cin>>b;
				C.getDS().push_back(b);
				break;
			case 3:
				cout<<"\nHay nhap ma hoc sinh: ";
				cin>>ma;
				idx = C.findById(ma);
				if(idx==-1) cout<<"\nKhong co thong tin hoc sinh can tim!";
				else
				{
					cout<<"\nHay nhap thong tin cap nhat\n";
					cin>>C.getDS()[idx];
				}
				break;
			case 4:
				cout<<"\nHay nhap ma hoc sinh: ";
				cin>>ma;
				idx = C.findById(ma);
				if(idx==-1) cout<<"\nKhong co thong tin hoc sinh can tim!";
				else C.getDS().erase(C.getDS().begin()+idx);
				break;
			case 6:
				cout<<"\n1. Giam dan";
				cout<<"\n2. Tang dan";
				cout<<"\nHay chon cach sap xep: ";
				cin>>idx;
				if(idx==1) sort(C.getDS().begin(), C.getDS().end(), greater<hs>());
				if(idx==2) sort(C.getDS().begin(), C.getDS().end());
				break;
			case 5:
				cout<<"\nHay nhap ten hoc sinh: ";
				cin.ignore();
				getline(cin, n);
				idx = C.findByName(n);
				if(idx==-1) cout<<"\nKhong co thong tin hoc sinh can tim!";
				else
				{
					cout<<"\nThong tin hoc sinh\n";
					cout<<C.getDS()[idx];
					cout<<"\n";
				}
				break;
			case 7:
				cout<<"\n1. Giam dan";
				cout<<"\n2. Tang dan";
				cout<<"\nHay chon cach sap xep: ";
				cin>>idx;
				if(idx==1) sort(C.getDS().begin(), C.getDS().end(), ssg);
				if(idx==2) sort(C.getDS().begin(), C.getDS().end(), sst);
				break;
		}
		system("pause");
	}
	while(1);
}