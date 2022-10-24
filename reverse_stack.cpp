#include <iostream>
#include <stack>
using namespace std;
 
// Recursive function to insert an item at the bottom of a given stack
void insertAtBottom(stack<int> &s, int item)
{
    // base case: if the stack is empty, insert the given item at the bottom
    if (s.empty())
    {
        s.push(item);
        return;
    }
 
    // Pop all items from the stack and hold them in the call stack
    int top = s.top();
    s.pop();
    insertAtBottom(s, item);
 
    // After the recursion unfolds, push each item in the call stack
    // at the top of the stack
    s.push(top);
}
 
// Recursive function to reverse a given stack
void reverseStack(stack<int> &s)
{
    // base case: stack is empty
    if (s.empty()) {
        return;
    }
 
    // Pop all items from the stack and hold them in the call stack
    int item = s.top();
    s.pop();
    reverseStack(s);
 
    // After the recursion unfolds, insert each item in the call stack
    // at the bottom of the stack
    insertAtBottom(s, item);
}
 
int main()
{
    stack<int> s;
    for (int i = 1; i <= 5; i++) {
        s.push(i);
    }
 
    reverseStack(s);
 
    cout << "Reversed stack is ";
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
 
    return 0;
}
