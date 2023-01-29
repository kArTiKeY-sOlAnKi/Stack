#include <iostream>
#include <stack>
using namespace std ;

bool is_valid(char *s)
{
	stack<char> c ;

	for (int i = 0; s[i] != '\0'; i++)
	{
		char ch = s[i] ;

		if (ch == '(')
		{
			c.push(ch) ;
		}

		if (ch == '{')
		{
			c.push(ch) ;
		}

		else if (ch == ')')
		{
			if (c.empty() or c.top() != '(')
			{
				return false ;
			}

			c.pop() ;
		}

		else if (ch == '}')
		{
			if (c.empty() or c.top() != '{')
			{
				return false ;
			}

			c.pop() ;
		}
	}

	return c.empty() ;
}

int main ()
{
	char s[100] = "((a + b) { + (c - d + f ) } )" ;
	cout<<"String is : "<<s<<endl ;

	if (is_valid(s))
	{
		cout<<"Valid Statement" ;
	}

	else
	{
		cout<<"Invalid Statement" ;
	}

	return 0 ;
}