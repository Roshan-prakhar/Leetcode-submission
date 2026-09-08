struct Node
{
    public:
    int val;
    int key;
    Node* next;
    Node* prev;
    Node(int key,int val)
    {
        this->key=key;
        this->val=val;
        next=nullptr;
        prev=nullptr;
    }
};

class LRUCache {
    private:
    unordered_map<int,Node*>hash;
    Node* head;
    Node* tail;
    int sze;
    int capacity;
    void addfront(Node* node)
    {
        node->next=head->next;
        head->next->prev=node;
        head->next=node;
        node->prev=head;
    }
    void RemoveNode(Node* node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
public:

    LRUCache(int capacity) {
         sze=0;
       this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        int idx=key;
        if(hash.find(idx)==hash.end())
        {
            return -1;
        }
        else 
        {
            Node* curr=hash[idx];
            RemoveNode(curr);
            addfront(curr);
            return curr->val;
        }        
    }
    
    void put(int key, int value) {
        int idx=key;
        if(hash.find(idx)!=hash.end())
        {
            Node* curr=hash[idx];
            curr->val=value;
            RemoveNode(curr);
            addfront(curr);
        }
        else
        {
          if(sze==capacity)
          {
              Node* deletenode=tail->prev;
              RemoveNode(deletenode);
              hash.erase(deletenode->key); //node ka sara componemts mere pas hai
             Node* newnode=new Node(key,value);
             addfront(newnode);
             hash[key]=newnode;
          }
          else
          {
               Node* newnode=new Node(key,value);
             hash[key]=newnode;
             addfront(newnode);
             sze++;
          }
        }

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */