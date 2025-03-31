#include<iostream>
using namespace std;
char evalue[]="\nEnter the value : ";
char echoice[]="\nEnter the operation : ";
char coption[]="\n1. Add at front \n2. Add at last \n3. Print node "\
                "\n4. Delete from front \n5. Delete from the last \n6. Delete from the k front position \n7. Delete from the last k position"\
                "\n8. detect the loop\n9. reverse the linkedlist \n10. Check if linked list is palindrom or not ";
char pvalue[]="\n Enter the node position you want to delete: ";
typedef struct node
{
    int n;
    struct node *next;
}Node;
static Node* f_create(void)
{
    Node* temp = new Node;
    if(temp==nullptr)
    {
        cerr<<"No Dynamic memory Allocation"<<endl;
        return nullptr;
    }

    fputs(evalue,stdout);
    cin>>temp->n;
    temp->next=nullptr;
    return temp;

}
void f_Add_Front(Node **head)
{
    if(*head==NULL)
    {
        *head=f_create();
    }
    else 
    {
        Node* local = *head;
        *head=f_create();
        if(*head==nullptr)  
        {
                return ;
        }
        (*head)->next=local;
    }

}
void f_Add_Last(Node **head)
{
    if(*head==NULL)
    {
        *head=f_create();
    }
    else 
    {
        Node* local = *head;
        while(local->next!=nullptr)
        local=local->next;
        local->next= f_create();
    }

}
void f_Print(Node* head)
{
    if(head==nullptr)
    return;
    else 
    {
        cout<<head->n<<endl;
        f_Print(head->next);
    }
    return;
}
void f_delete_front(Node**head)
{
    if(*head==nullptr)
    return;
    else 
    {
        Node*temp = (*head)->next;
        delete *head;
        *head=temp;
    }
    return;
}
void f_delete_back(Node**head)
{
    if(*head==nullptr)
    return;
    else if ((*head)->next==nullptr)
    {
        delete *head;
        *head=nullptr;
    }
    else 
    {
        Node* local = *head,*prev=nullptr;

        while(local->next!=nullptr)
        {       
            prev=local;
            local=local->next;
        }
        delete local;
        prev->next=nullptr;
    }
return;
}
void  f_delete_k_node_from_last(Node **head,int pos)
{
    if(*head==nullptr)
    {
        cerr<<"No Nodes are present";
    }
    else 
    {
        int count=0;
        Node * tra= *head;
        while(tra->next!=nullptr)
        {
            tra=tra->next;
            count++;
        }
       // Check if position is valid
    if (pos > count || pos <= 0) {
        cerr << "Position is incorrect\n";
        return;
    }

    // Special case: Delete the head node
    if (pos == count) {
        Node* temp = *head;
        *head = (*head)->next; // Move head to the next node
        delete temp;
        return;
    }

    // General case: Find the node before the target node
    int targetPos = count - pos - 1;
    tra = *head;
    while (targetPos-- > 0) {
        tra = tra->next;
    }

    // Remove the target node
    Node* temp = tra->next;
    tra->next = tra->next->next;
    delete temp;
    }
}
void f_delete_k_node_from_front(Node** head, int pos)
{
    if(*head==nullptr)
    {
        cerr<<"No node present"<<endl;
        return;
    }
    else 
    {
        int count =0;
        Node * tra= *head;
        while(tra->next->next!=nullptr && count<=pos)
        {
            tra=tra->next;
            count++;
        }
        if(count>pos)
        {
            cerr<<"Position is not available"<<endl;
        }
        else 
        {
            Node * local= tra->next->next;
            tra->next= tra->next->next;
            delete local;
        }
    }
return ;
}
void f_AllDelete(Node**head)
{
    if(*head==nullptr)
    return;
    else 
    {
        f_AllDelete(&((*head)->next));
        (*head)->next=nullptr;
    }
    return;
}
void  f_create_loop(Node *head)
{
    Node * p_temp= head, *p_tra=head;
    while(p_tra->next!=nullptr)
    p_tra=p_tra->next;
    p_tra->next=p_temp;
}
void f_detect_loop(Node *head)
{
    Node *fast=head, *slow=head;
    while(fast !=nullptr && fast-> next!=nullptr)
    {
        fast= fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            cout<<"The Loop is present \n";
            return;
        }
    }
    cout<<"The Loop is not present \n";
    return;
}
Node* f_reverse(Node *head)
{
    Node *curr= head,*prev=nullptr, *next=nullptr;
    while (curr!=nullptr)
    {
       next=curr->next;
       curr->next=prev;
       prev=curr;
       curr=next;
    }
    return prev;
}
static Node* f_find_middle(Node *head)
{
    Node * fast = head, *slow = head;
    while(fast !=nullptr && fast->next !=nullptr)
    {
        slow = slow ->next;
        fast = fast->next->next;
    }
    return slow;
}
void f_check_palindrom(Node *head)
{
    Node * mtra= f_find_middle(head);
    Node * ftra=head;
    mtra= f_reverse(mtra);
    Node* mstra=mtra;
    while(mtra!=nullptr)
    {
        if(mtra->n!=ftra->n)
        {
            cout<<"The linkedlist is not pelindrom"<<endl;
            mtra=f_reverse(mstra);
            return;
        }
        else 
        {
            mtra= mtra->next;
            ftra=ftra->next;
            
        }
    } 
    if(mtra==nullptr)
    {
        cout<<"The linkedlist is  pelindrom"<<endl;
        mtra=f_reverse(mstra);
    }
}

int main()
{
    int n;
    Node* head=NULL;
    while(1)
    {
        
        fputs(coption,stdout);
        fputs(echoice,stdout);
        cin>>n;
        switch(n)
        {
            case 1 : 
                f_Add_Front(&head);
                break;
            case 2 :
                f_Add_Last(&head);
                break;
            case 3 :
                f_Print(head);
                break;
            case 4 : 
                f_delete_front(&head);
                break;
            case 5 :
                f_delete_back(&head);
                break;
            case 6: 
                fputs(pvalue,stdout);
                cin>>n;
                f_delete_k_node_from_front(&head,n);
                break;
            case 7: 
                fputs(pvalue,stdout);
                cin>>n;
                f_delete_k_node_from_last(&head,n);
                break;
            case 8: 
                f_create_loop(head);
                f_detect_loop(head);
                break;
            case 9:
                head=f_reverse(head);
                break;
            case 10:
                f_check_palindrom(head);
                break;
             
            default : 
            f_AllDelete(&head);
            exit(0);
        }
    }

    return 0;
}