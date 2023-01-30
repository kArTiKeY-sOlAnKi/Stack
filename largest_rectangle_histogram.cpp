#include <iostream>
#include <stack>
using namespace std ;

void largest_rectangle(int arr[], int n)
{
	stack<int> s ; // this stack will store the index of the rectangle
	s.push(0) ; // pushing the default value as the stack is empty currently
	int area = 0, x ;
	int temp[n] ;
	int a = 0 ;

	// traversing the array
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			int j = arr[i] ;
			int k = i ;
			while (j < arr[k - 1] and k > 0 and !s.empty())
			{
				s.pop() ;
				k-- ;
			}
			if (!s.empty())
			{
			    x = arr[i-1] * (i - s.top() - 1) ;
			    temp[a] = x ;
			    area = max(area,x) ;
			    a++ ;
			}
			else
			{
			    x = arr[i-1] * i ;
			    temp[a] = x ;
			    area = max(area,x) ;
			    a++ ;
			}
			
			s.push(i) ;
		}
		else
		{
			s.push(i) ;
		}
	}
	cout<<"Area : "<<area<<endl ;
	for (int i = 0; i < n; i++)
	{
	    cout<<temp[i]<<" " ;
	}
}

int main ()
{
	int histogram[] = {6,2,5,4,5,1,6} ;
	int n = sizeof(histogram)/sizeof(int) ;

	largest_rectangle(histogram,n) ;	

	return 0 ;
}