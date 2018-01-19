#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctime>
#include<math.h>
void printarr(int arr[],int n)
{
    for(int j=0;j<n;j++)
    {
        printf("%d ",arr[j]);
    }
}
int min(int arr[],int low,int high)
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
void swap(int a[],int i,int j)
{
    if(1){
    int k=a[i];
    a[i]=a[j];
    a[j]=k;}
}
void ssort(int a[],int n)
{
    int i=min(a,0,n-1),j;
    if(i!=0)
    {
        swap(a,0,i);
    }
    for(j=1;j<n;j++)
    {
        i=min(a,j,n-1);
        swap(a,i,j);
    }
}
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
int part(int a[],int low,int high)
{
   int j=low-1,k=a[high];
   for(int i=low;i<high+1;i++)
   {
       if(a[i]<=k)
       {
          j++;
          swap(a,i,j);
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
void reverse(int arr[],int n)
{
	
		for(int i=0;i<n/2;i++)
		{
		    swap(arr,i,n-i-1);
	    }

}
int main(int argc,char *argv[])
{
    if(argc==5)
    {
    float startc,stopc;
    int i=atoi(argv[1]);         //sorting technique.
    int powaii=atoi(argv[3]);    // enter integer(1,2,3...) for selecting datasize
                                 // takes datasize as mentioned in mail (1 - 20),(2 - 200),(3 - 2000)
    int select = atoi(argv[2]);  // takes case
    int seed = atoi(argv[4]);    // seed for srand generating different random numbers
    int z=2*pow(10,powaii);
    int arr[z];
    srand(seed);

    if(select==2)
    {
	    
	    for(int j=0;j<z;j++)
	    {
	        arr[j] = rand()%z+1;
	    }
	}
	if(select == 1 && i == 3)
	{
		for(int j=0;j<z;j++)
	    {
	        arr[j] = rand()%z+1;
	    }
	}
	if(select == 1 && i!=3)
	{
		for(int j=0;j<z;j++)
	    {
	        arr[j] = j+1;
	    }
	}
	if(select==3)
	{
		for(int j=0;j<z;j++)
	    {
	        arr[j] = z-j;
	    }
	}
	    switch(i)
	    {
	        case 1:
	        	startc=clock();
	            ssort(arr,z);
	            //printarr(arr,n);
	            break;
	        case 2:
	            startc=clock();
	            isort(arr,z);
	            //printarr(arr,n);
	            break;
	        case 3:
	        	startc=clock();
	            qsort(arr,0,z);
	            //printarr(arr,n);
	            break;
	        case 4:
	        	reverse(arr,z);
	        	printarr(arr,z);
	    }
	    stopc=clock();
	    printf("%d %lf\n",z,(double)(stopc-startc)/CLOCKS_PER_SEC);
    }
    else
    {
        printf("enter correct no of arguments \n");
        printf("command : ./exec-file sorting-technique case data-size seed\n");
        printf("sort\n1.insertion\n2.selection\n3.quick\ncase:\n1.best\n2.average\n3.worst\ndata-size\n1.20\n2.200\n3.2000\n4.20000...\nseed - any positive int.\n");
    }
}
