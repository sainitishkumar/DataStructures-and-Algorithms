#include<iostream>
#include "Queue.h"
using namespace std;
int min(int a[],int low,int high)
{
	int min=low;
	for(int i=low;i<=high;i++)
	{
		if(a[min]>a[i])
		{ 
			min=i;
		}	
	}
	return min;
}
void ARRIVAL(Queue q[],int EVENT_CLOCK[],int n,int size[],int &avg_time_spent,int &avg_idle_time)
{
	int i = min(size,0,n-1);
	q[i].enQueue();
	size[i]++;
	if(EVENT_CLOCK[i]<10000000) EVENT_CLOCK[i]+=q[i].front()->depTime;
	else EVENT_CLOCK[i] = q[i].front()->depTime;
	EVENT_CLOCK[n]+=rand()%300;
	avg_time_spent += q[i].depTime();
	avg_idle_time = (avg_time_spent - q[i].front()->depTime);
}
void DEPART(int next,Queue q[],int EVENT_CLOCK[])
{
	q[next].deQueue();
	if(q[next].length()!=0)
	{
		if(EVENT_CLOCK[next]<10000000) EVENT_CLOCK[next] += q[next].front()->depTime;
		else EVENT_CLOCK[next] =q[next].front()->depTime;
	}
	else EVENT_CLOCK[next] = 10000000;
}
int remCust(Queue q[],int n)
{
	int c=0;
	for(int i=0;i<n;i++)
	{
		c+=q[i].length();
	}
	return c;
}
void resetq(Queue q[],int n)
{
	for(int i=0;i<n;i++)
	{
		q[i].reset();
	}
}
void printQueues(Queue q[],int n)
{
	for(int i=0;i<n;i++)
	{
		q[i].printQueue();
	}	
}

int main(int argc,char *argv[])
{
	if(argc<3)cout<<"enter two arguments \n1.no of Queues and \n2.SIMULATION TIME";
	else
	{
		int n = atoi(argv[1]);
		int SIMULATION_TIME = atoi(argv[2]);
		Queue q[n];
		int size[n];
		int MAIN_CLOCK = 0;
		int EVENT_CLOCK[n+1];
		EVENT_CLOCK[n] = 0;
		int avg_time_spent = 0;
		int avg_time_waiting = 0;
		int avg_idle_time = 0;
		int J;
		for(int i=0;i<n;i++)
		{
			EVENT_CLOCK[i]=10000000;
			size[i]=0;
		}
		while(MAIN_CLOCK < SIMULATION_TIME)
		{
			J = min(EVENT_CLOCK,0,n);
			MAIN_CLOCK = EVENT_CLOCK[J];
			if(J == n)
			{
				ARRIVAL(q,EVENT_CLOCK,n,size,avg_time_spent,avg_idle_time);
			}
			else
			{
				DEPART(J,q,EVENT_CLOCK);
			}
		}
		cout<<"customers serviced: "<<id-remCust(q,n)<<endl;
		cout<<"customers remaining: "<<remCust(q,n)<<endl;
		cout<<"average time spent by each customer: "<<avg_time_spent/id<<endl;
		cout<<"avg idle time spent by each customer: "<<avg_idle_time/id<<endl;
		cout<<"avg idle time for checkout clerks: "<<(SIMULATION_TIME - (avg_idle_time/id + avg_time_spent/id))<<endl;
		resetq(q,n);
	}
}