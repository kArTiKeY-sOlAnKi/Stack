#include <iostream>
#include <stack>
#include <string.h>
using namespace std ;

void reverse_str(char *str)
{
	// S = “reverse the string”  -- original string
	// Output: “string the reverse”  -- output shd be in this format
	stack<char> s ;

	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		while (str[i] != ' ')
		{
			if (i == 0)
			{
				s.push(str[i]) ;
				break ;
			}

			s.push(str[i]) ;
			i-- ;
		}

		while (!s.empty())
		{
			cout<<s.top() ;
			s.pop() ;
		}

		cout<<" " ;
	}
}

int main ()
{
	char str[100] ;
	cin.getline(str,100) ;

	cout<<"Original String is : "<<str<<endl ;

	cout<<"Reversed String is : " ;
	reverse_str(str) ;

	return 0 ;
}