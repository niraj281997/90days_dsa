#include<iostream>
#include<memory>
using namespace std;

class ListNode
{
    private:
        int val;
        ListNode *next;
    public: 
        ListNode() : val(0),next(nullptr){}
        ListNode(int a, ListNode* add =nullptr): val(a),next(add){}
        int f_val()
        {
            int n;
            cout<<"Enter the value :";
            cin>>n;
            return n;
        }
        void f_add(ListNode ** head)
        {
            if(*head==nullptr)
            {
                *head= new ListNode(f_val());
            }
            else 
            {
                ListNode* tra = *head;
                while(tra->next!=nullptr)
                {
                    tra=tra->next;
                }
                tra->next= new ListNode(f_val());
            }

        }
        void f_print(ListNode *head)
        {
            if(head==nullptr)
            return;
            else 
            {
            cout<<head->val<<endl;
            f_print(head->next);
            //cout<<head->val;
            }
        return;
        }
        void f_add_first(ListNode **head)
        {
            if(*head==nullptr)
            {
                
                *head= new ListNode(f_val());
            }
            else 
            {
                ListNode *local= new ListNode(f_val());
                local->next = *head;
                *head= local;
            }
        }
        void f_add_last(ListNode **head)
        {
             if(*head==nullptr)
            {
                
                *head= new ListNode(f_val());
            }
            else 
            {
                ListNode *local= *head;
                while(local->next!=nullptr)
                {
                    local=local->next;
                }
                 local ->next = new ListNode(f_val());

            }
        }
        void f_delete_first(ListNode **head)
        {
            if(*head==nullptr)
            {
                cout<<"No elements present"<<endl;
            }
            else 
            {
                if((*head)->next==nullptr)
                {
                    delete ((*head));
                    *head=nullptr;
                }
                else 
                {
                    ListNode* tra = *head;
                    (*head)=(*head)->next;
                    delete (tra);
                }
                
            }
        return;
        }
        void f_delete_last(ListNode **head)
        {
            if(*head==nullptr)
            {
                cout<<"No elements present"<<endl;
            }
            else 
            {
                
                if((*head)->next==nullptr)
                {
                    delete ((*head));
                    *head=nullptr;
                }
                else 
                {
                    ListNode* tra = *head;
                    while(tra->next->next!=nullptr)
                    {
                        tra=tra->next;
                    }
                    delete(tra->next);
                    tra->next=nullptr;
                }

            }
            return;
        }
        void f_delete_all(ListNode **head)
        {
            if(*head==nullptr)
            return;
            {
                f_delete_all(&((*head)->next));
                delete(*head);
                *head=nullptr;
            }
        }

};
int main()
{
ListNode *head =nullptr;
ListNode Node;
int n;
while (1)
{
    cout<<"1. add\n2. print\n";
    cout<<"3. Add at first\n4. Add at last\n";
    cout<<"5. delete at first\n6. delete at last\n";
    cin>>n;
    switch(n)
    {
        case 1 : 
            Node.f_add(&head);break;
        case 2 :
            cout<<"***********************************\n\n\n\n\n"<<endl;
            Node.f_print(head);
            cout<<"***********************************\n\n\n\n\n"<<endl;break;
        case 3: 
            Node.f_add_first(&head);break;
        case 4 :
            Node.f_add_last(&head);break;
        case 5 :
            Node.f_delete_first(&head);break;
        case 6 :
            Node.f_delete_last(&head);break;
        default: 
            Node.f_delete_all(&head);
            exit(0);
    }
}

    return 0;
}