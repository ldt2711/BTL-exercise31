#ifndef HOC_SINH_CPP
#define HOC_SINH_CPP 1
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class loai
{
private:
	string type;
public:
	loai(float a)
	{
		if(a>=8.0) type="Gioi";
		else if(a>=7.0) type="Kha";
		else if(a>=5.0) type="Trung Binh";
		else type="Yeu";
	}
	string getType() {return type;}
};

class hs
{
private:
	string mahs, name, gender;
	float toan, ly, hoa, dtb;
	loai t;
public:
	hs(string m="", string n="", string g="", float t=0.0, float l=0.0, float h=0.0): t(dtb) {mahs=m; name=n; gender=g; toan=t; ly=l; hoa=h; dtb=(t+l+h)/3.0;}
	void setId(string m) {mahs=m;}
	void setName(string n) {name=n;}
	void setGender(string g) {gender=g;}
	void setToan(float t) {toan=t;}
	void setLy(float l) {ly=l;}
	void setHoa(float h) {hoa=h;}
	string getId() {return mahs;}
	string getName() {return name;}
	string getGender() {return gender;}
	float getToan() {return toan;}
	float getLy() {return ly;}
	float getHoa() {return hoa;}
	float getDTB() {return dtb;}
	string getType() {return t.getType();}
	friend istream& operator>>(istream &is, hs &a)
	{
		is>>a.mahs;
		is.ignore();
		getline(is, a.name);
		is>>a.gender>>a.toan>>a.ly>>a.hoa;
		a.dtb=(a.toan+a.ly+a.hoa)/3.0;
		loai l(a.dtb);
		a.t = l;
		return is;
	}
	friend ostream& operator<<(ostream &os, hs a)
	{
		os<<setw(15)<<a.mahs<<"  |  "<<setw(15)<<a.name<<"  |  "<<setw(5)<<a.gender<<"  |  "<<setw(6)<<a.toan<<"  |  "<<setw(6)<<a.ly<<"  |  "<<setw(6)<<a.hoa<<"  |  "<<setw(8)<<a.dtb<<"  |  "<<setw(5)<<a.getType();
		return os;
	}
	bool operator>(const hs &other) const
	{
		return dtb>other.dtb;
	}
	bool operator<(const hs &other) const
	{
		return dtb<other.dtb;
	}
};

bool sst(hs a, hs b)
{
	return a.getName() < b.getName();
}
bool ssg(hs a, hs b)
{
	return a.getName() > b.getName();
}
#endif