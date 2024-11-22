#include <stdio.h>
int binary_search(int arr[],int n,int search_element)
{
    int s = 0;
    int e = n-1;
    int mid = (s + e)/2;
    while (s <= e)
    {
        if (arr[mid] == search_element)
        {
            return mid;
        }
        else if (arr[mid]>search_element)
        {
            e=mid-1;
        }
        else 
        {       
            s = mid+1;
        }
        return -1;
    }
    
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
    int result = binary_search(arr,n,search_element);
    if(result ==-1)
    {
        printf("Element not found");
    }
    else
    {
        printf("%d",result);
    }

return 0;
}