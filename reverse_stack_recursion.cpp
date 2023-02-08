#include <iostream>
#include <stack>
using namespace std ;

void push_at_last(stack<int> &s, int k)
{
	if (s.empty())
	{
		s.push(k) ;
		return ;
	}

	int temp = s.top() ;
	s.pop() ;

	push_at_last(s,k) ;

	s.push(temp) ;
}

void reverse_recursive(stack<int> &s)
{
	// base case
	if (s.empty())
	{
		return ;
	}

	int temp = s.top() ;
	s.pop() ;
	
	reverse_recursive(s) ;

	push_at_last(s,temp) ;
}

int main ()
{
	int n ;
	cin>>n ;

	stack<int> s ;

	for (int i = 0; i < n; i++)
	{
		int ele ;
		cin>>ele ;
		s.push(ele) ;
	}

	reverse_recursive(s) ;

	// displaying the stack
	while (!s.empty())
	{
		cout<<s.top()<<endl ;
		s.pop() ;
	}

	return 0 ; 
}