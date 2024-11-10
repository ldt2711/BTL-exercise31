#ifndef DLIST_CPP
#define DLIST_CPP 1

#include "node.cpp"
#include "iterators.cpp"
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

template<class Q>
class dlist
{
private:
	node<Q> *head, *trail;
	long n;
public:
	// bo lap xuoi
	typedef dl_ite<Q> iterator;
	iterator begin() {return head;}
	iterator end() {return NULL;}
	// bo lap nguoc
	typedef dl_rite<Q> reverse_iterator;
	reverse_iterator rbegin() {return NULL;}
	reverse_iterator rend() {return head;}

	dlist() {head=trail=0; n=0;}
	~dlist()
	{
		while(n) pop_front();
	}
	void setHead(node<Q> *H) {head=H;}
	node<Q> *getHead() {return head;}
	void setTrail(node<Q> *T) {trail=T;}
	node<Q> *getTrail() {return trail;}
	void setN(int _n) {n=_n;}
	int getN() {return n;}
	bool empty() {return n==0;}
	int size() {return n;}
	Q &front() {return head->getElem();}
	Q &back() {return trail->getElem();}
	// create new node with next = head -> prev of head = new node -> head = new node
	void push_front(Q x)
	{
		if(n==0) head=trail= new node<Q>(x);
		else{
			head = new node<Q>(x,head);
			head->getNext()->setPrev(head);
		}
		n++;
	}
	// create new node with prev = trail -> next of trail = new node -> trail = new node
	void push_back(Q x)
	{
		if(n==0) head=trail= new node<Q>(x);
		else{
			trail = new node<Q>(x,0,trail);
			trail->getPrev()->setNext(trail);
		}
		n++;
	}
	// create temp node = head -> head = next of head -> prev of head = null -> delete temp
	void pop_front()
	{
		node<Q> *t = head;
		head = head->getNext();
		if(head) head->setPrev(0);
		delete t;
		n--;
		if(n==0) trail=0;
	}
	// traverse to the second-to-last node ->  next of that node = null -> delete trail -> let trail = that node
	void pop_back()
	{
		node<Q> *t = trail;
		trail = trail->getPrev();
		if(trail) trail->setNext(0);
		delete t;
		n--;
		if(n==0) head=0;
	}
	// let prev current node = new node with: prev = prev current node, next = current node
	void insert(iterator it, Q x)
	{
		if(it.getCur()==head) return push_front(x);
		if(it.getCur()==NULL) return push_back(x);
		node<Q> *p = it.getCur()->getPrev();
		p->setNext(new node<Q>(x,it.getCur(),p));
		it.getCur()->setPrev(p->getNext());
		n++;
	}
	void erase(iterator it)
	{
		if(it.getCur()==head) return pop_front();
		if(it.getCur()==trail) return pop_back();
		node<Q> *p = it.getCur()->getPrev(), *j = it.getCur()->getNext();
		p->setNext(j);
		j->setPrev(p);
		delete it.getCur();
		n--;
	}
	void sort(bool (*cmp)(const Q&, const Q&) = less<Q>())
	{
		for(node<Q> *p=head; p!=0; p=p->getNext())
			for(node<Q> *j=p->getNext(); j!=0; j=j->getNext())
				if(cmp(j->getElem(),p->getElem())) swap(j->getElem(),p->getElem());
	}
};
#endif