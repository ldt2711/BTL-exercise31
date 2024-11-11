#include <iostream>
#include <fstream>
#include <algorithm>
#include "hoc_sinh.cpp"
#include "danh_sach.cpp"
using namespace std;

class menu
{
private:
	danh_sach ds;
public:
	void app()
	{
		int select;
		do
		{
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
			system("cls");
			switch(select)
			{
				case 1: {
					ifstream fin;
					fin.open("pupil.txt",ios::in);
					fin>>ds;
					fin.close();
					break;
				}
				case 8:
					cout<<ds;
					break;
				case 10:
					break;
				case 9: {
					ofstream fout;
					fout.open("pupilout.txt",ios::out);
					fout<<ds;
					fout.close();
					break;
				}
				case 2: {
					ds.addHS();
					break;
				}
				case 3: {
					string str;
					cout<<"\nHay nhap ma hoc sinh: ";
					cin>>str;
					ds.updateById(str);
					break;
				}
				case 4: {
					string str;
					cout<<"\nHay nhap ma hoc sinh: ";
					cin>>str;
					ds.eraseById(str);
					break;
				}
				case 6: {
					int idx;
					cout<<"\n1. Giam dan";
					cout<<"\n2. Tang dan";
					cout<<"\nHay chon cach sap xep: ";
					cin>>idx;
					if(idx==1) sort(ds.getDS().begin(), ds.getDS().end(), greater<hs>());
					if(idx==2) sort(ds.getDS().begin(), ds.getDS().end());
					cout<<"\nDa sap xep danh sach sinh vien";
					break;
				}
				case 5: {
					string str;
					cout<<"\nHay nhap ten hoc sinh: ";
					cin.ignore();
					getline(cin, str);
					ds.printInfoByName(str);
					break;
				}
				case 7: {
					int idx;
					cout<<"\n1. Giam dan";
					cout<<"\n2. Tang dan";
					cout<<"\nHay chon cach sap xep: ";
					cin>>idx;
					if(idx==1) sort(ds.getDS().begin(), ds.getDS().end(), ssg);
					if(idx==2) sort(ds.getDS().begin(), ds.getDS().end(), sst);
					cout<<"\nDa sap xep danh sach sinh vien";
					break;
				}
				default:
					cout<<"\ndshuc nang khong hop le";
			}
			system("pause");
		}
		while(select != 10);
	}
};



signed main()
{
	menu mn;
	mn.app();
}