/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
tack using Linked List
Difficulty: EasyAccuracy: 53.98%Submissions: 210K+Points: 2Average Time: 40m
Implement a Stack using a Linked List. The stack has dynamic size and can grow until memory is available.
The Stack must support the following operations:

(i) push(x): Insert an element x at the top of the stack.
(ii) pop(): Remove the element from the top of the stack.
(iii) peek(): Return top element if not empty, else -1.
(iv) isEmpty(): Return true if the stack is empty else return false.
(v) size(): Return the number of elements currently in the stack.

There will be a sequence of queries queries[][] in numeric form: 

1 x : Call push(x)
2: Call pop()
3: Call peek()
4: Call isEmpty()
5: Call size()
Implement only the functions push, pop, peek, isEmpty, and size. The driver code handles input and output.

Examples:






------------------------------------------------------
so consider when your doing normal linked list for 5,4,2 you do
5->4->2;
if now you pop 2 4 will be top but for consective pop operation you cant
go previous as it is single linked list so the idea behind this is to implemen 



2->4->5 now the next helps us to travel consectively for pop operation wihout any problem
this is some tricky impleention to be remebered
*/





class myStack {
    Node*head=nullptr;
    Node*curr=head;
    int len=0;
  public:
    myStack() {
        // Initialize your data members
    }

    bool isEmpty() {
        return len==0;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        if(len==0)
        {
            curr=new Node(x);
            len=1;
        }
        else
        {
            Node*temp=new Node(x);
            temp->next=curr;
            curr=temp;
            len++;
        }
    }

    void pop() {
        // Removes the top element of the stack
        if(len!=0)
        {
        Node*temp=curr;
        curr=curr->next;
        delete temp;
        len--;
        }
        
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(len==0)return -1;
        return curr->data;
    }

    int size() {
        // Returns the current size of the stack.
        return len;
    }
};