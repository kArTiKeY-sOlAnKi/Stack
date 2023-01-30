#include <iostream>
#include <stack>
using namespace std ;

void transfer(stack<int> &s1, stack<int> &s2, int n)
{
	for (int i = 0; i < n; i++)
	{
		s2.push(s1.top()) ;
		s1.pop() ;
	}
}

void stack_reverse(stack<int> &s1)
{
	// helper stack
	stack<int> s2 ;

	int n = s1.size() ;

	for (int i = 0; i < n; i++)
	{
		// pick the element at top & insert it at the bottom
		int x = s1.top() ;
		s1.pop() ;

		// transfer the n-i-1 elements from stack s1 to stack s2
		transfer(s1,s2,n-i-1) ;

		// insert the element stored in x in stack s1
		s1.push(x) ;

		// transfer the n-i-1 elements from stack s2 to s1
		transfer(s2,s1,n-i-1) ;
	}
}

int main ()
{
	stack<int> s1 ;

	s1.push(1) ;
	s1.push(2) ;
        s1.push(3) ;
	s1.push(4) ;

	stack_reverse(s1) ;

	while (!s1.empty())
	{
		cout<<"Top most element of the stack : "<<s1.top()<<endl ;
		s1.pop() ;
	}

	return 0 ;
}