#include<iostream>
#include<algorithm>
using namespace std;

bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)
{
   int mid=(startIndex+lastIndex)/2;
    if (startIndex>lastIndex)
	{
        return false;
    } 
	else if(element>array[mid])
	{
       binarySearchReacursive(array,mid+1,lastIndex,element);
    }
    else if(array[mid]==element)
	{
        return true;
    } 
	else 
	{
       binarySearchReacursive(array,startIndex,mid-1,element);
    }
   

}

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{
	int middle=(startIndex+lastIndex)/2;
   while(startIndex<=lastIndex)
   {
      if(array[middle]<element)
        startIndex=middle+1;
      else if (array[middle]==element)
      {
        return true;;
      }
      else
         lastIndex=middle-1;
      middle=(startIndex+lastIndex)/2;
   }
   if (startIndex>lastIndex)
   {
   	return false;
   }
}

int main()
{
     int n;
     cout<<"enter the size of array\n";
     cin>>n;
     int arr[n];
     cout<<"enter elements of array\n";
     for(int i=0;i<n;i++)
     {
     	cin>>arr[i];
	 }
	 int first=0,last=(n-1),search;
	 cout<<"enter element to search\n";
     cin>>search;
     sort(arr,arr+n);
     if(binarySearchReacursive(arr,first,last,search))
     {
     	cout<<"element found using reacursive function\n";
	 }
	 else
	 {
	 	cout<<"element not found \n";
	 }
     if(binarySearchIterative(arr,first,last,search))
     {
     	cout<<"element found using iterative function \n";
	 }
	 else
	 {
	 	cout<<"element not found\n";
	 }

  return 0;
}
