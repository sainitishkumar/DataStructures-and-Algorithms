#include<iostream>
#include"stack_list.h"
#include<string>
#include <math.h>

using namespace std; 
 
bool IsOperand(char C) 
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}

bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '^')
		return true;

	return false;
}
int IsRightAssociative(char op)
{
	if(op == '^') return true;
	return false;
}

int Operator_weight(char op)
{
	int w = -1; 
	switch(op)
	{
	case '+':w = 1;
		break;
	case '-':
		w = 1;
		break;
	case '*':
		w = 2;
		break;
	case '/':
		w = 2;
		break;
	case '^':
		w = 3;
		break;
	}
	return w;
}
int order(char op1, char op2)
{
	int op1Weight = Operator_weight(op1);
	int op2Weight = Operator_weight(op2);
	if(op1Weight == op2Weight)
	{
		if(IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ?  true: false;
}    
                       
string infix_postfix(string expression)                     
{	
	stacks<char> S;                                               
	string postfix = "";
	int a=expression.length();
	int j;
	int op=0,cl=0;
	if(expression[0]=='*'||expression[0]=='/'||IsOperator(expression[a-1])){ return "invalid infix";}
	else{                                      
	for(int i=0;i<expression.length();i++)
	{
		if(i==0 && expression[0]=='-' && expression[1]!='('){postfix+="-";}
		else if(i==0 && expression[0]=='-' && expression[1]=='(')
		{op++;
		postfix+="0 ";
		for(j=0;j<a&&expression[j]!=')';j++);
		}
		else if(i==0 && expression[0]=='+'){}
		else{
		if(expression[i]==' ') continue;  
		else if(IsOperator(expression[i])) 
		{
			if(!IsOperator(expression[i-1])){
			while(!S.isempty() && S.top() != '(' && order(S.top(),expression[i]))
			{
				postfix+=" ";
				postfix+= S.top();
				S.pop();
			}
			postfix+=" ";
			S.push(expression[i]);
			}
			else if(expression[i]=='-' &&IsOperator(expression[i-1]))
			{
				postfix+= "-";
			}
			
		}
		else if(IsOperand(expression[i]))     
		{
			postfix +=expression[i];
		}
		else if (expression[i] == '(') 
		{op++;
			S.push(expression[i]);
			if(expression[i+1]=='-'){postfix+="-";i++;}
			else if(expression[i+1]=='+'){i++;}
		}
		else if(expression[i] == ')') 
		{	cl++;
			while(!S.isempty() && S.top() !=  '(') {
				postfix+=" ";
				postfix += S.top();
				S.pop();
			}
			if(i==j){postfix+=" -";cl++;}
			S.pop();
		}
	}
	}
	while(!S.isempty()) {
		postfix += " ";
		postfix += S.top();
		S.pop();
	
	}
	if(op==cl)
	return postfix;
	else
	return "invalid infix";
	}
}
int evaluation(string postfix)
{
int l = postfix.length();
stacks<int> in;
char ch='\0';
int j=0,c=1,k=1;
for(int i=0;i<l;i++)
{
	if(postfix[i]!=' ' && postfix[i]=='-' && (postfix[i+1]>='0'&&postfix[i+1]<='9')){k=-1;}
	else if(postfix[i]!=' ' && (!IsOperator(postfix[i])))
	{
		j = (j*(c-1)*10)+int((postfix[i]-48)*k);
		if(c<2){c++;}
	}
	else if(postfix[i]==' ')
	{
		in.push(j);
		j=0;
		c=1;
		k=1;
	}
	else if(IsOperator(postfix[i]))
	{
		ch=postfix[i];	
	}
	if(in.isempty() || ch=='\0'){}
	else
	{
		int a=in.top();
		in.pop();
		int b=in.top();
		in.pop();
		if(ch=='+'){in.push(a+b);}
		else if(ch=='-'){in.push(b-a);}
		else if(ch=='*'){in.push(a*b);}
		else if(ch=='/'){in.push(b/a);}
		else if(ch=='^'){in.push(pow(b,a));}
		ch='\0';
		i++;
	}

}
return in.top();
}

int main() 
{
	string expression; 
	cout<<"Enter Infix : \n";
	getline(cin,expression);
	string postfix = infix_postfix(expression);
	int l = expression.length();
	if(!IsOperator(expression[l-1]) && expression[0]!='*' && expression[0]!='/' && expression[0]!=')' && expression[l-1]!='(' && l>2){
	cout<<"Postfix  : "<<postfix<<"\n";
	}
	else{cout<<"invalid infix"<<endl;}
	if(postfix=="invalid infix" || l<=2){cout<<"no result";}
	else{
	int res = evaluation(postfix);
	cout<<res<<endl;}
}

