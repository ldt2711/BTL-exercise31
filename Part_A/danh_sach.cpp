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