#include<stdio.h>
#include "qsort.h"
int minq(int arr[],int low,int high)
{
    int min=arr[low],minind=low;
    for(int i=low;i<=high;i++)
    {
        if(arr[i]<=min)
        {
            min=arr[i];
            minind=i;
        }
    }
    return minind;
}
void swapq(int a[],int i,int j)
{
    if(1){
        int k=a[i];
        a[i]=a[j];
        a[j]=k;}
}
int part(int a[],int low,int high)
{
   int j=low-1,k=a[high];
   for(int i=low;i<high+1;i++)
   {
       if(a[i]<=k)
       {
          j++;
          swapq(a,i,j);
       }
   }
   return j;
}
void qsort(int a[],int low,int n)
{
    if(low<n){
    int p=part(a,low,n-1);
    qsort(a,low,p-1);
    qsort(a,p+1,n);
}
}
