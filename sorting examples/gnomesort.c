#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include &lt; iostream &gt;
using namespace std;


void gnomeSort(int elements, int arr[])
{
	int i = 0, temp;

	while( i &lt; elements ){

		if ( i == 0 || arr [i - 1] &lt;= arr[i] )
			i++;

		else{
			temp = arr[i];
			arr[i] = arr[i - 1];
			arr[--i] = temp;
		}

	}

}
int main()
{
	int n;
	int *a;
	cout &lt;&lt; "Please insert the number of elements to be sorted: ";
	cin &gt;&gt; n;	// The total number of elements
	a = (int *)calloc(n, sizeof(int));
	for(int i=0;i&lt; n;i++)
	{

		cout &lt;&lt; "Input " &lt;&lt; i &lt;&lt; " element: ";
		cin &gt;&gt;a[i]; // Adding the elements to the array
	}
	cout &lt;&lt; "Unsorted list:" &lt;&lt; endl;	// Displaying the unsorted array
	for(int i=0;i&lt; n;i++)
	{
		cout &lt;&lt; a[i] &lt;&lt; " ";
	}
	gnomeSort(n, a);
	cout &lt;&lt; "nSorted list:" &lt;&lt; endl;	// Display the sorted array
	for(int i=0;i &lt; n;i++)
	{
		cout &lt;&lt; a[i] &lt;&lt; " ";
	}
	return 0;
}