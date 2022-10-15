//header files 
#include <bits/stdc++.h>
using namespace std;
 
//Queue class
class Queue {
    public :
        stack<int> stack1;
 
        // Insert a number in queue
        void insert(int num)
        {
            stack1.push(num);
        }
     
        // Delete an item from the queue
        int deQueue()
        {
            if (stack1.empty()) {
                cout << "Queue is empty";
                return 0;
            }
     
            // pop an item from the stack
            int num = stack1.top();
            stack1.pop();
     
            // if stack becomes empty, return
            // the popped item
            if (stack1.empty())
                return num;
     
            // recursive call
            int item = deQueue();
     
            // push popped item back to the stack
            stack1.push(num);
     
            // return the result of deQueue() call
            return item;
        }
};
 
int main()
{
    Queue q;
    q.insert(1);
    q.insert(2);
    q.insert(3);
 
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
 
    return 0;
}
