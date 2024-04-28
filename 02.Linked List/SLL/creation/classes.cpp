#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(string data) 
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList 
{
public:
    Node* head;
    Node* tail;
    LinkedList() 
    {
        this->head = NULL;
        this->tail = NULL;
    }

    void insertAtHead(string data) 
    {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
        if (tail == NULL) 
        {
            tail = new_node;
        }
    }

    void insertAtTail(string data) {
        if (head == NULL) {
            insertAtHead(data);
            return;
        }
        Node* new_node = new Node(data);
        tail->next = new_node;
        tail = new_node;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main(){
    int n,i=0;
    cin>>n;
    LinkedList l;
    while(n>i){
        string d;
        cin>>d;
        l.insertAtHead(d);
        i++;
    }
  
    string p;
    cin>>p;

  //OUTPUT
    cout<<"Document: ";
    l.display();
    cout<<endl;
  
    l.insertAtTail(p);
    cout<<"Updated Document: ";
    l.display();
    cout<<endl;
    return 0;
}