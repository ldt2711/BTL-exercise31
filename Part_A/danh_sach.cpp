#ifndef DANH_SACH_CPP
#define DANH_SACH_CPP 1
#include "hoc_sinh.cpp"
#include <vector>
#include <string>
using namespace std;

class danh_sach
{
private:
	vector<hs> l;
public:
	danh_sach() {}
	vector<hs> &getDS() {return l;}
	int findById(string id)
	{
		for (int i=0; i < l.size(); i++)
		{
			if(l[i].getId() == id)
			{
				return i;
			}
		}
		return -1;
	}
	int findByName(string name)
	{
		for (int i = 0; i < l.size(); i++)
		{
			if(l[i].getName() == name)
			{
				return i;
			}
		}
		return -1;
	}
	void addHS()
	{
		hs b;
		cout<<"\nNhap thong tin hoc sinh\n";
		cin>>b;
		l.push_back(b);
	}
	void updateById(string id)
	{
		int idx;
		idx = findById(id);
		if(idx==-1) cout<<"\nKhong co thong tin hoc sinh can tim!";
		else
		{
			cout<<"\nHay nhap thong tin cap nhat\n";
			cin>>l[idx];
		}
	}
	void eraseById(string id)
	{
		int idx;
		idx = findById(id);
		if(idx==-1) cout<<"\nKhong co thong tin hoc sinh can tim!";
		else l.erase(l.begin()+idx);
	}
	void printInfoByName(string name)
	{
		int idx;
		idx = findByName(name);
		if(idx==-1) cout<<"\nKhong co thong tin hoc sinh can tim!";
		else
		{
			cout<<"\nThong tin hoc sinh\n";
			cout<<l[idx];
			cout<<"\n";
		}
	}
	friend istream& operator>>(istream &is, danh_sach &ds)
	{
		int n;
		is>>n;
		for (int i = 0; i < n; ++i)
		{
			hs s;
			is>>s;
			ds.l.push_back(s);
		}
		return is;
	}
	friend ostream& operator<<(ostream &os, danh_sach ds)
	{
		for(auto x:ds.l) os<<x<<"\n";
		return os;
	}
};
#endif