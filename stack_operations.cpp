#include <iostream>
#include <vector>
using namespace std ;

class stack
{
	private:
		vector<int> v ;

	public:
		// function to push data into the stack
		void push(int data)
		{
			v.push_back(data) ;
		}

		// boolean function to check if the stack is empty or not
		bool empty()
		{
			return v.size() == 0 ;
		}

		// function to pop elements from the stack
		void pop()
		{
			if (!empty())
			{
				v.pop_back() ;
			}
		}

		// function to display the top value of the stack
		int top()
		{
			return v[v.size() - 1] ;
 		}

};

int main ()
{
	stack s ; // s is the object of class stack

	for (int i = 1; i <= 5; i++)
	{
		s.push(i*i) ;
	}

	// try to print the content of the stack by popping each element
	while (!s.empty())
	{
		cout<<"Top most element of stack : "<<s.top()<<endl ;
		s.pop() ;
	}

	return 0 ;
}