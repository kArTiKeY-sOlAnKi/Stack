#include <iostream>
#include <vector>
using namespace std ;

template <typename T>

class Stack
{
	private:
		vector<T> v ;

	public:
		// function to add elements to top of stack
		void push(int data)
		{
			v.push_back(data) ;
		}

		// boolean function to check if the stack is empty or not
		bool empty()
		{
			return v.size()==0 ;
		}

		// function to pop element from the stack
		void pop()
		{
			if (!empty())
			{
				v.pop_back() ;
			}
		}

		// function to return the size of the stack
		T top()
		{
			return v[v.size() - 1] ;
		}
};

int main ()
{
	Stack<char> s ;

	for (int i = 65; i <= 70; i++)
	{
		s.push(i) ;
	}

	while (!s.empty())
	{
		cout<<"Top most element of the stack : "<<s.top()<<endl ;
		s.pop() ;
	}

	return 0 ;
}