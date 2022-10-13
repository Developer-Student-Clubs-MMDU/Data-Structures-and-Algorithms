/*

Problem statement :
Print Range of Number (like: 1 2 3 4 ...n ) without using a number in program(code) 
Input Format: Contain a single line of an integer N
Output : 1 2 3 4 5 ..N
Disclaimer: You cannot use numbers in programs like
int i = 1;
you can not use 1 in the code.

So as to solve this problem we should be aware of ASCII value and type casting
# ASCII value  - ASCII stands for American Standard Code for Information Interchange, a standard data-encoding format for electronic communication between computers. ASCII assigns standard numeric values to letters, numerals, punctuation marks, and other characters used in computers.
# Type casting - In simple words Type casting is when you assign a value of one data type to another type.
for example :
int value = 'a';        //explanation - here we are typecasting a character into a integer, the ascii value of character 'a' is 97, therefore the variable value will store 97
char d=65;             // explanation - here we are typecasting an integer into a character, the ascii value of character 'A' is 65, therefore the character variable d will store 'A'.

Approach : 
1. Take input from the user and store it in a integer variable
2. we have to start printing the range of numbers from 1 , but we cant use 1(number).Now here comes the role of type casting , create a integer variable and we have to initialise it with 1.
3. As ASCII values are numeric values we can perform mathematical operations, so as to intialise a variable with 1, we can do 'character'divided by 'character' 
4. Now run a for loop from the new created variable to the given input and print the numbers;

*/


#include <iostream>
using namespace std;

int main(){
    int input;
    cin>>input;
    int b='a'/'a';
    for(int i=b;i<=input;i++){
        cout<<i<<" ";
    }
  return 0;
}
