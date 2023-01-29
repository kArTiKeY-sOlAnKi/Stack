#include <iostream>
#include <stack>
using namespace std ;

void insert_bottom(stack<int> &s, int x)
{
	// base case
	if (s.empty())
	{
		s.push(x) ;
		return ;
	}

	// rec case
	int data = s.top() ;
	s.pop() ;
	insert_bottom(s,x) ;
	s.push(data) ;
}

void recursive_reverse(stack<int> &s)
{
	// base case
	if (s.empty())
	{
		return ;
	}

	// otherwise
	// pop out the top elements and insert it at the bottom of "reversed smaller stack"
	int x = s.top() ;
	s.pop() ;

	recursive_reverse(s) ;
	insert_bottom(s,x) ;
}

int main ()
{
	stack<int> s ;
	s.push(1) ;
	s.push(2) ;
	s.push(3) ;
	s.push(4) ;

	recursive_reverse(s) ;

	cout<<"Reversed Stack is :"<<endl ;
	while (!s.empty())
	{
		cout<<s.top()<<endl ;
		s.pop() ;
	}

	return 0 ;
}
