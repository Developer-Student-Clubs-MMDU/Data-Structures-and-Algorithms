/*
Problem statement:convert infix to postfix using stack 
Input a+b*c-d
Output abc*+d-

Algo:
A loop will run from 0 to infix length,
if its an alphabet ,then add in postfix,
else if its '(' add in postfix 
if its ')' push it in stack ,
 
if there is any operator then 
  one with higher precedence added in postfix 
  one with lower one is push in stack 

  at last all the remaining element present in stack will be added in postfix

 PsuedoCode:
 loop start
 1.if infix[i]>operand then postfix+=infix[i]
 2.else if infix[i]='(' push in stack 
 3.else if infix[i]=')'  ,pop and print stack till its empty
 4.else if infix[i]=operator , then 
 5.if stack==empty,push infix[i] to stack
 6.else if stack not empty
 precedence(infix[i]>stack.top),push i to stack 
 else if equal and i=='^' ,push i to stack
else if stack not empty and precedence(infix[i]<stack.top),pop and print stack

at last push remaining operator to stack
end loop
pop and print remaining operator on stack




*/








#include<iostream>
#include<stack> //header file to include stack
using namespace std;



bool isOperator(char c) // bool function which will return true if character is operand else false
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int precedence(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 

string InfixToPostfix(stack<char> s, string infix)
{
	string postfix;

	for(int i=0;i<infix.length();i++) // loop from 0 to infix length
	{
		if((infix[i] >= 'a' && infix[i] <= 'z')||(infix[i] >= 'A' && infix[i] <= 'Z'))//condition which will check if first position of infix is an alphabate or not
		{
			postfix+=infix[i];//if its an alphabet ,will be added in postfix
		}
		else if(infix[i] == '(')//checking if infix contain any open bracket
        {
			s.push(infix[i]);// if it contains ,pushing that in stack created
		}
		else if(infix[i] == ')')//checking if infix contain any closed bracket 
		{
			while((s.top()!='(') && (!s.empty()))//loop will run if stack is not empty and does not contain '(' on top  
			{
                // first storing the element on top of stack
				char temp=s.top();
                //adding it in postfix
				postfix+=temp;
                //now removing that element from stack
				s.pop();
			}

			if(s.top()=='(')//this is the loop if both '(' and')' are present
			{
				s.pop();
			}
		}
		else if(isOperator(infix[i]))//if any operator is present 
		{
			if(s.empty())// if stack is empty
			{
				s.push(infix[i]);//then push operator onto the stack 
			}
			else
			{
				if(precedence(infix[i])>precedence(s.top()))//if new operator contain higher precedence than that on top of stack
				{
					s.push(infix[i]);//push that in the stack
                    	}	
				else if((precedence(infix[i])==precedence(s.top()))&&(infix[i]=='^'))// if new operator contain same precedence as top of the stack 
				{
					s.push(infix[i]);//push it in stack
				}
				else
				{
                    //if stack not empty and new operator has less precedence than top of stack 
					while((!s.empty())&&( precedence(infix[i])<=precedence(s.top())))
					{
						postfix+=s.top();//add top of stack to postfix
						s.pop();//then pop  it 
					}
					s.push(infix[i]);
				}
			}
		}
	}
    // for the remaining element present in stack ,one by one take it from stack ,enter into postfix and then pop it from stack
	while(!s.empty())
	{
		postfix+=s.top();
		s.pop();
	}
	
	return postfix;
}

int main() 
{  

  	string infix_exp, postfix_exp;

  	cout<<"Enter the Infix Expression :"<<endl;
  	cin>>infix_exp; // entering the infix expression 
  	stack <char> stack;
	cout<<"INFIX EXPRESSION: "<<infix_exp<<endl;
  	postfix_exp = InfixToPostfix(stack, infix_exp);//calling the fuction which will convert infix to postfix
  	cout<<endl<<"POSTFIX EXPRESSION: "<<postfix_exp<<endl;;
	  
	return 0;
}
