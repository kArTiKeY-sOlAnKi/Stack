#include <iostream>
#include <stack>
using namespace std ;

void histogram_area(int arr[], int n)
{
	stack<int> s ; // creating a stack
	s.push(0) ; // pushing index of the first element in the array as stack was empty
	int area = 0, temp[n] = {0} ; // array created to store the values of area calculated by the code
	
	int i = 1, j = 0, count = 0, k, val ; // i is at second element of the array

	while (i < n)
	{
		if (arr[i] < arr[s.top()])
		{
			val = s.top() ;
			s.pop() ;
			if (s.empty())
			{
				area = arr[i-1] * i ;
				temp[j++] = area ;
				s.push(i) ;
				count++ ;
				i++ ;
			}
			else
			{
				k = i ;
				area = arr[val] * (i - s.top() - 1) ;
				temp[j++] = area ;
				count++ ;
				while (arr[s.top()] > arr[k] and k > 0 and !s.empty())
				{
				    val = s.top() ;
				    s.pop() ;
				    if (s.empty())
				    {
				        area = arr[val] * k ;
				        temp[j++] = area ;
				        count++ ;
				        break ;
				    }
				    area = arr[val] * (k - s.top() - 1) ;
				    temp[j++] = area ;
				    count++ ;
				    continue ;
				}
				s.push(i) ;
				i++ ;
			}
		}
		
		else
		{
			s.push(i) ;
			i++ ;
		}
	}
	
	if (!s.empty())
	{
	    while (!s.empty())
	    {
	        val = s.top() ;
	        s.pop() ;
	        if (s.empty())
	        {
	            area = arr[val] * i ;
	            temp[j++] = area ;
	            count++ ;
	            break ;
	        }
	        else
	        {
	            area = arr[val] * (i - s.top() - 1) ;
	            temp[j++] = area ;
	            count++ ;
	        }
	    }
	}
	cout<<"Testing Area Array : " ;
	for (i = 0; i < count; i++)
	{
		cout<<temp[i]<<" " ;
	}

	int max_area = 0 ;
	for (i = 0; i < count; i++)
	{
		max_area = max(max_area, temp[i]) ;
	}

	cout<<endl<<"Area is : "<<max_area<<endl ;
}

int main ()
{
	// int arr[] = {6,2,5,4,5,1,6} ;
	int arr[] = {7,3,6,5,6,2,7} ;
	int n = sizeof(arr)/sizeof(int) ;

	histogram_area(arr,n) ;

	return 0 ;
}