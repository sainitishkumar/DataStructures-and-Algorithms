#include <iostream>
#include <cstdlib>
#include "list.h"
using namespace std;
linked_list <int> a;
template<typename T>
class stacks
{
public :void push(int x);
	void pop();
	int top();
	int isempty();
};

template<typename T>
void stacks<T> :: push(int x){
int k=a.length();
k++;
a.insert(x,k);
}

template<typename T>
void stacks<T> :: pop(){
int k=a.length();
if(k!=0){
int b=a.retrieve(k);
a.remove(k);
}
else{cout<<"Nothing elements to pop\n";}
}

template<typename T>
int stacks<T> :: top(){
int k=a.length();
int b=a.retrieve(k);
return b;
}

template<typename T>
int stacks<T> :: isempty(){
int k=a.length();
if(k==0)
return 1;
else
return 0;
}



