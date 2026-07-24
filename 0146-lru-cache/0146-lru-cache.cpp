class LRUCache {
    struct Node{
        int key;
        int value;
        Node*next;
        Node*prev;
        Node(int k,int v)
        {
            key=k;
            value=v;
            next=nullptr;
            prev=nullptr;
        }
    };
public:
    Node*head,*tail;   
    unordered_map<int,Node*>mpp;
    int size;
    int currsize=0;
    LRUCache(int capacity) {
     head=new Node(-1,-1);
     tail=new Node(-1,-1);
     head->next=tail;
     tail->prev=head;
        size=capacity;
    }
    
    int get(int key) {
      if(currsize==0||!mpp.count(key))
      {
        return -1;
      }
      Node*newnode=mpp[key];
      join(newnode->prev,newnode->next);
      add(head,newnode);
      return newnode->value;
    }
    
    void put(int key, int value) {
        if(currsize!=size&&!mpp.count(key))
        {
            Node*newnode=new Node(key,value);
            add(head,newnode);
            mpp[key]=newnode;
            currsize++;
        }
        else if(mpp.count(key))
        {
            Node*newnode=mpp[key];
            join(newnode->prev,newnode->next);
            newnode->value=value;
            add(head,newnode);
        }
        else
        {
            Node*del=tail->prev;
            mpp.erase(del->key);
            join(del->prev,tail);
            delete del;
            Node*newnode=new Node(key,value);
            add(head,newnode);
            mpp[key]=newnode;
        }
    }
void add(Node*head,Node*newnode)
{
    Node*trail=head->next;//nedxt node
    newnode->next=trail;
    newnode->prev=head;
    head->next=newnode;
    trail->prev=newnode;
}
void join(Node*head,Node*tail)
{
    head->next=tail;
    tail->prev=head;
}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */