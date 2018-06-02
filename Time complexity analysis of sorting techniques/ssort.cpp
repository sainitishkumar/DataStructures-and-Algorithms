#include<stdio.h>
#include "ssort.h"
int mins(int arr[],int low,int high)
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
void swaps(int a[],int i,int j)
{
    if(1){
    int k=a[i];
    a[i]=a[j];
    a[j]=k;}
}
void ssort(int a[],int n)
{
    int i=mins(a,0,n-1),j;
    if(i!=0)
    {
        swaps(a,0,i);
    }
    for(j=1;j<n;j++)
    {
        i=mins(a,j,n-1);
        swaps(a,i,j);
    }
}