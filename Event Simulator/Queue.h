#include<iostream>
#include<cstdlib>
using namespace std;
extern int id=0;

struct queueNode
{
	int custNum;
	int totalItems;
	int serviceTime;
	int depTime;
	struct queueNode *next;
};
typedef struct queueNode queueNode;
typedef queueNode* nodePtr;

class Queue
{
	nodePtr head;
	int size;
public:
	Queue(nodePtr h=NULL,int c=0)
	{
		head = h;
		size = c;
	}
	int length();
	void printQueue();
	nodePtr front();
	void enQueue();
	void deQueue();
	void reset();
	int depTime();
};
int Queue::depTime()
{
	int dep = 0;
	nodePtr q=head;
	while(q!=NULL)
	{
		dep += q->depTime;
		q = q->next;
	}
	return dep;
}
int Queue::length(){
	return size;
}

void Queue::reset()
{
	while(size!=0){
		deQueue();
	}
}

void Queue::printQueue()
{
	nodePtr q = head;
	while(q!=NULL){
		cout<<q->custNum<<" ";
		q=q->next;
	}
	cout<<endl;
}

void Queue::enQueue()
{
	nodePtr n = new queueNode;
	n->custNum = ++id;
	n->totalItems = rand()%25+1;
	n->serviceTime = (n->totalItems)*30;
	n->next = NULL;
	if(size==0){
		n->depTime = n->serviceTime;
		head=n;
		size+=1;
		return;
	}
	nodePtr t=head;
	while(t->next!=NULL)
	{
		t=t->next;
	}
	n->depTime = t->depTime + n->serviceTime;
	t->next=n;
	size+=1;
	return;
}

void Queue::deQueue()
{
	if(size==0) return;
	nodePtr t = head;
	head=head->next;
	delete t;
	size-=1;
}

nodePtr Queue::front()
{
	if(size==0) return NULL;
	return head;
}