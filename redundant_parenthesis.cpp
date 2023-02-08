#include <iostream>
#include <stack>
#include <string>
using namespace std ;

int is_redundant(string str)
{
	int flag = 1 ;
	stack<char> s ;

	// (((a+(b))+(c+d)))
	// ((a+(b))+(c+d))
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ')')
		{
			if (s.top() == '(')
			{
				flag = 0 ;
			}

			while (!s.empty() and s.top() != '(')
			{
				s.pop() ;
			}

			if (s.top() == '(')
			{
				s.pop() ;
			}
		}

		else
		{
			s.push(str[i]) ;
		}
	}
	
	return flag ;
}

int main ()
{
	int testcase ;
	cin>>testcase ;

	while (testcase--)
	{
		string str ;
		cin>>str ;

		if (!is_redundant(str))
		{
			cout<<"Duplicate"<<endl ;
		}

		else
		{
			cout<<"Not Duplicates"<<endl ;
		}
	}

	return 0 ;
}