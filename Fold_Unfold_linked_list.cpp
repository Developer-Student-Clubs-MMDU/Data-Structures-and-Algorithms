/*      
                               Fold and unfold linked list
                               ===========================
## Fold Of LinkedList

Given a singly linkedlist : l0 -> l1 -> l2 -> l3 -> l4 -> l5 -> l6 ..... -> ln-1 -> ln 
reorder it : l0 -> ln -> l1 -> ln-1 -> l2 -> ln-2 -> l3 -> ln-3 -> ..... 

## Unfold Of LinkedList

Given a singly linkedlist : l0 -> ln -> l1 -> ln-1 -> l2 -> ln-2 -> l3 -> ln-3 -> ..... 
reorder it :  l0 -> l1 -> l2 -> l3 -> l4 -> l5 -> l6 ..... -> ln-1 -> ln

## Approach

- to fold linked list
By looking at the expected input and output, we can notice the pattern that in the output- first node is connected to last node,
last node is linked to second node, second node is linked to second last node and so on..
1.) Find mid node of given array
2.)create a new pointer(new head) which points the node after the mid node.
3.)update mid->next to NULL(so that we get two independent LL- first half and second half)
4.)reverse the second half linked list,udate 'new head' with head returned by reverse function
5.)Now link node of  'first half linked list and second half linked list' alternatively

-to unfold Linked list
By looking at the expected input and output, we can notice the pattern that in the output-first node is linked to next to next node and
second node is connected to its next to next node. Inshort we can say nodes at odd position are linked and  nodes at odd positions are linked in this way we get two 
independent linked list, then reverse the even nodes linked list and then link the last node of odd nodes linked list with the head of evn nodes linked list.
1.)Create 4 pointers , 2 pointers pointing the forst node and two pointers pointing the second node
2.)Now move 2 pointers (one pointing the first node and one pointing the second node )to their next to next  nodes respectively and link them until NULL in found.
3.)Now we have two independent linked  list with head of first linked list being the first node of input linked list and head of second linked list being the second node of input linked list.
4.)now reverse  the linked list whose head was second node of the onput linked list, udate head of second linked list with head returned by reverse function
5.) Now link the last  node of first linked list with the  new head of second linked list

*/



#include <iostream>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

// Find mid ponit with two pointer approach - O(n)
ListNode *midpoint(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// reverse linked list with three pointer approach -O(n)
ListNode *reversell(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *fwrd = NULL;
    while (curr != NULL)
    {
        fwrd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwrd;
    }
    return prev;
}

// Function to fold linked list
void fold(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    ListNode *mid = midpoint(head);
    ListNode *nhead = mid->next;
    mid->next = NULL;
    nhead = reversell(nhead);
    ListNode *c1 = head;
    ListNode *c2 = nhead;
    ListNode *f1 = NULL;
    ListNode *f2 = NULL;
    while (c2 != NULL && c1 != NULL)
    {
        f1 = c1->next;
        f2 = c2->next;

        c1->next = c2;
        c2->next = f1;

        c1 = f1;
        c2 = f2;
    }
    ListNode *curr = head;
    return;
}

// function to unfold linked list
void unfold(ListNode *head)
{
    if(head==NULL ||head->next==NULL){
        return  ;
    }
    ListNode *fhead=head;
    ListNode *shead=head->next;
    ListNode *cfhead=head;
    ListNode *cshead=head->next;
    ListNode *forward;
    while(cshead!=NULL && cshead->next!=NULL){
        
        forward=cshead->next;
        
        cfhead->next=forward;
        cshead->next=forward->next;
        
        cfhead=cfhead->next;
        cshead=cshead->next;
    }
    cfhead->next=NULL;
    
    
    shead=reversell(shead);
    cfhead->next=shead;
}



void printList(ListNode *node)
{
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }

    ListNode *head = dummy->next;
    cout<<"Initial Linked list :"<<endl;
    printList(head);
    fold(head);
    cout<<"Folded Linked list :"<<endl;
    printList(head);
    unfold(head);
    cout<<"unfolded Linked list :"<<endl;
    printList(head);

    return 0;
}
