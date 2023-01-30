#include <iostream>
#include <vector>
using namespace std ;

class minmax_stack
{
	private:
		vector<int> stack ;
		vector<int> min_stack ;
		vector<int> max_stack ;

	public:
		 void push (int data)
		 {
		 	int current_min = data ;
		 	int current_max = data ;

		 	if (min_stack.size())
		 	{
		 		current_min = min(min_stack[min_stack.size() - 1],data) ;
		 		current_max = max(max_stack[max_stack.size() - 1],data) ;
		 	}

		 	min_stack.push_back(current_min) ;
		 	max_stack.push_back(current_max) ;
		 	stack.push_back(data) ;
		 }

		int get_min ()
		{
			return min_stack[min_stack.size() - 1] ;
		}

		int get_max ()
		{
			return max_stack[max_stack.size() - 1] ;
		}

		int top ()
		{
			return stack[stack.size() - 1] ;
		}

		void pop ()
		{
			min_stack.pop_back() ;
			max_stack.pop_back() ;
			stack.pop_back() ;
		}

		bool empty ()
		{
			return stack.size()==0 ;
		}
};

int main ()
{
	minmax_stack s ;

	s.push(1) ;
	s.push(5) ;
	s.push(3) ;
	s.push(8) ;

	cout<<"Maximum till now : "<<s.get_max()<<endl ;
	s.pop() ;
	cout<<"Minimum till now : "<<s.get_min()<<endl ;
	cout<<"Maximum till now : "<<s.get_max()<<endl ;

	s.pop() ;
	s.pop() ;
	cout<<"Topmost element of the stack : "<<s.top()<<endl ;
	cout<<"Maximum Till now : "<<s.get_max()<<endl ;

	return 0 ;
}