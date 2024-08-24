#include <iostream>

class Node{
    public:
        int value;
        Node* next;
        
        Node(int val) : value(val), next(nullptr){} 
};

class Linkedlist{
    private:
      Node* head;
      Node* tail;
    public: 

        Linkedlist(): head(nullptr), tail(nullptr){}

        void insertBegin(int data){
            Node* newNode = new Node(data);
            if(!head){
                head = tail = newNode;
            }else{
                newNode -> next = head;
                head = newNode;
            }
            head = newNode;
        }

        void insertEnd(int data){
            if(!head){
                insertBegin(data);
                return;
            }
            Node* newNode = new Node(data);
            if(head == tail){
                tail = newNode;
                head -> next = newNode;
                return;
            }
            tail -> next = newNode;
            tail = newNode;
            return;
        }

        void removeFirst(){
            if(head == nullptr){
                return;
            }
            Node* temp = nullptr;
            if(head->next == nullptr){
                temp = head;
                head = nullptr;
                delete temp;
                return;
            }
                temp = head;
                head = head->next;
                delete temp;
                return;

        }

        void removeLast(){
            if(tail == nullptr)return;

            if(tail == head){
                return removeFirst();
            }
            
            Node* prevNode = head;
            while(prevNode->next->next != nullptr){
                prevNode = prevNode->next;
            }
            Node* temp = tail;
            tail = prevNode;
            tail->next = nullptr; 
            delete temp;

        }

        void removeItem(int data){
            if(!head) return; // this just means its an empty list , ato first case.

            if(head->value == data){
                removeFirst(); // this is our 2nd 
                return;
            }
            if(tail->value == data){
                removeLast(); // and 3rd case.
                return;
            }
            // 4th case...
            Node* prev = head;
            Node* current = head;
            current = current->next; 
            
                                
            while(current != NULL){
                if(current->value == data){
                    prev->next = current->next;
                    delete current;
                    return;
                }
                current = current->next;
                prev = prev -> next;
            }

        }
        int peekFirst(){
            if(head == NULL){
                return 0;
            }
            return head->value;
        }
        int peekLast(){
            if(tail == NULL){
                return 0;
            }
            return tail->value;
        }

        void print(){
            if(!head){
                std::cout<<"List is empty ...";
                return;}
            Node* temp = head;
            while(temp){
                std::cout << temp -> value << " ";
                temp = temp -> next;
            }
        }



};


int main() {
    Linkedlist list;

    list.insertEnd(1);
    list.insertEnd(2);
    
    list.insertEnd(3);
    list.insertEnd(4);
    
    list.insertEnd(5);
    list.insertEnd(6);
    
    list.removeItem(1);

    int x = list.peekLast();
    std::cout << x << std::endl;
    list.print();

    return 0;
}
