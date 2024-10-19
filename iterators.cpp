#ifndef ITERATORS_CPP
#define ITERATORS_CPP 1
#include <iostream>
#include "node.cpp"

// bo lap xuoi
template<class T>
class dl_ite
{
private:
	node<T> *cur;
public:
	dl_ite(node<T> *c=0) {cur=c;}
	void setCur(node<T> *c) {cur=c;}
	node<T> *getCur() {return cur;}
	T &operator*() {return cur->getElem();}
	bool &operator!=(dl_ite<T> it) {return cur!=it.cur;}
	dl_ite<T> operator++(int)
	{
		cur = cur->getNext();
		return cur;
	}
	dl_ite<T> operator++()
	{
		dl_ite<T> it = cur;
		cur = cur->getNext();
		return it;
	}
};
// bo lap nguoc
template<class T>
class dl_rite
{
private:
	node<T> *cur;
public:
	dl_rite(node<T> *c=0) {cur=c;}
	void setCur(node<T> *c) {cur=c;}
	node<T> *getCur() {return cur;}
	T &operator*() {return cur->getElem();}
	bool &operator!=(dl_rite<T> it) {return cur!=it.cur;}
	dl_rite<T> operator++(int)
	{
		cur = cur->getPrev();
		return cur;
	}
	dl_rite<T> operator++()
	{
		dl_rite<T> it = cur;
		cur = cur->getPrev();
		return it;
	}
};
#endif