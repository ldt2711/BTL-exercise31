#include <iostream>
using namespace std;

template<class T>
class node
{
private:
	T elem;
	node *next, *prev;
public:
	node(T e=0, node<T> *P=0, node<T> *N=0)
	{
		elem = e;
		next = N;
		prev = P;
	}
	void setElem(T e) {elem = e;}
	void setNext(node<T> *N) {next = N;}
	void setPrev(node<T> *P) {prev = P;}
	T getElem() {return elem;}
	node<T> *getNext() {return next;}
	node<T> *getPrev() {return prev;}
};