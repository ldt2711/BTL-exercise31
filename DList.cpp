#ifndef DLIST_CPP
#define DLIST_CPP

#include "node.cpp"
#include <iostream>
using namespace std;

template<class T>
class dlist
{
private:
	node<T> *head, *trial;
	int n;
public:
	dlist() {head=trial=0; n=0;}
	~dlist()
	{
		while(n) pop_front();
	}
	
	
};
#endif