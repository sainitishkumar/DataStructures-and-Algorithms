#include <iostream>
#include <cstdlib>
using namespace std;

int l=0;

template<typename T>
struct node
{
    T data;
    struct node<T>*next;
};


template<typename T>
class linked_list
{
private:struct node <T> *head,*tail;
public:	void initialize(int x);
	void insert(int x,int p);
        void remove(int p);
        void print();
	bool locate(int x);
	bool isempty();
	int retrieve(int p);
	int length();
	int previous(int p);
	node<T>* first();
	node<T>* last();
};

template<typename T>
void linked_list<T> :: initialize(int x)
{
	node<T> *temp,*t;
	temp=new node<T>;
	t = new node<T>;
    	temp->data=x;
    	temp->next=NULL;
	t=temp;
	head=temp;
	tail=temp;
	l++;
}

template<typename T>
void linked_list<T>:: insert(int x,int p)
{
	
	int j;
	node<T> *temp,*t;
	temp=new node<T>;
	t=new node<T>;
    	temp->data=x;
    	temp->next=NULL;
	t=head;
        if(p==1)
        {
            	head=temp;
		t=head;
		l++;
        }
        else if(p<=l+1)
        {
            for(j=1;j<p-1;j++)
            {
                t=t->next;
            }
            t->next=temp;
	    l++;
        }
	else
{cout<<"given position is not there to insert\n";}
}
template<typename T>
void linked_list<T>:: remove(int p)
{
	node<T> *t;
	t= new node<T>;
	t=head;
    	int j;
	if(p<=l){
    	if(p==1)
    	{
		l--;
        	t=t->next;
		delete(head);
        	head=t;
    	}
    	else
    	{
		l--;
            	for(j=1;j<p-1;j++)
            	{
                	t=t->next;
            	}
        	t->next=t->next->next;
    	}
	}
	else
{cout<<"given position is not there to remove\n";}
}
template<typename T>
void linked_list<T> :: print()
{
	node<T> *t;
	t= new node<T>;
    	t=head;
	if(l==0){cout<<"no elements to print\n";}
	else{
    	while(t!=NULL)
    	{
        	cout<< t->data<<" ";
        	t=t->next;
    	}
	}
	
}
template<typename T>
bool linked_list<T> :: locate(int x)
{
	node<T> *t;
	t= new node<T>;
	t=head;
	int i;
	for(i=0;t->next!=NULL;i++)
	{
		if(t->data==x){
		return true;}
		t=t->next;
	}
	return false;
}
template<typename T>
int linked_list<T> :: retrieve(int p)
{
	node<T> *t;
	t= new node<T>;
	t=head;
	if(p<=l){
	for(int i=1;i<=p && t->next!=NULL;i++)
	{
		t=t->next;
	}
	return t->data;}
	return 0;
	
}
template<typename T>
node<T>* linked_list<T> :: first()
{
	
	if(head!=NULL)
	return head;
	else
	return NULL;
}
template<typename T>
node<T>* linked_list<T> :: last()
{
	node<T> *t;
	t= new node<T>;
	t=head;
	while(t->next!=NULL)
	t=t->next;
	tail = t;
	return t;
}

template<typename T>
bool linked_list<T> :: isempty()
{
	if(l==0)
	return true;
	else
	return false;
}
template<typename T>
int linked_list<T> :: length()
{
	node<T> *t;
	int c=0;
	t= new node<T>;
	t=head;
	if(l!=0){
	while(t->next!=NULL){
	t=t->next;
	c++;	
	}
	c++;}
	
	return c;
}
template<typename T>
int linked_list<T> :: previous(int p)
{
	int i,x;
	node<T> *t;
	t= new node<T>;
	t=head;
	if(p==1){cout<<"Not possible\n";return 0;}
	else{
	for(i=1;i<p-1;i++)
	t=t->next;
	x=t->data;
	return x;}
}

