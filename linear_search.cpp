#include <stdio.h>
int linear_search(int arr[],int n,int search_element)
{
 for (int i = 0; i < n; i++)
 {
    if(search_element == arr[i] )
    return i;}

   return -1;
}
int main()
{ 
    int arr[5];
    int n = sizeof(arr)/sizeof(arr[0]); 
   int search_element;
    printf("Enter the elements of array:-\n");
    for ( int i = 0; i < 5;++i)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to search:");
    scanf("%d",&search_element);
    int result= linear_search(arr,n,search_element);
    if(result == -1){
    printf("Element not found");
    }
    else{
        printf("%d",result);
    }
}