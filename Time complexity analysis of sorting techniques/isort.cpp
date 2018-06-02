#include<stdio.h>
#include "isort.h"
void isort(int a[], int n)
{
   int i,j,k;
   for(i=1;i<n;i++)
   {
      j=a[i];
      k=i-1;
      for(k=i-1;k>=0;k--)
      {
            if(a[k]>j)
            {
               a[k+1]=a[k];
            }
            else
            {
               break;
            }
      }
      a[k+1]=j;
   }
}