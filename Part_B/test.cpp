#include <iostream>
#include "DList.cpp"

signed main()
{
	dlist<int> L;
	L.push_front(5);
	for (int i = 1; i <= 10; i++)
	{
		i%2?L.push_front(i):L.push_back(i);
	}
	cout<<"Size : "<<L.size();
	cout<<"\n";
	cout<<"\nL : "; for(auto x:L) cout<<x<<" ";
	cout<<"\n";
	L.front()=10;L.back()=15;
	cout<<"\nL : "; for(auto x:L) cout<<x<<" ";
	cout<<"\n";
	L.pop_front();L.pop_front();
	cout<<"\nL : "; for(auto x:L) cout<<x<<" ";
	auto it = L.begin(); it++; it++;it++;
	L.insert(it,6);
	cout<<"\nL : "; for(auto x:L) cout<<x<<" ";
	it = L.begin(); it++;
	L.erase(it);
	cout<<"\nL : "; for(auto x:L) cout<<x<<" ";
	L.sort(0);
	cout<<"\nL : "; for(auto x:L) cout<<x<<" ";
}