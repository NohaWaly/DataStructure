#include <iostream>

using namespace std;

class node
{
public:
    int value;
    node* next;
};

class Linkedlist
{
public:
    node* head;
    node* current;
    Linkedlist()
    {
        head=NULL;
    }
    void add(int v)
    {
        if (head==NULL)
        {
            //current=head;
            node* temp =new node;
            temp->value=v;
            temp->next=NULL;
            head=temp;

        }
        else
        {
            current=head;
            while(current->next!=NULL)
            {
                cout<<"while add";
                current=current->next;
            }
            node* temp=new node;
            current->next=temp;
            temp->value=v;
            temp->next=NULL;
           // current=temp;
        }
    }
    void print ()
    {

        current=head;

            while(current!=NULL)
            {
                cout<<"while print";
                cout<<endl<<current->value<<endl;
                current=current->next;
            }

    }
};
int main()
{
    Linkedlist a;
    a.add(5);
    a.add(6);
    a.print();

    return 0;
}
