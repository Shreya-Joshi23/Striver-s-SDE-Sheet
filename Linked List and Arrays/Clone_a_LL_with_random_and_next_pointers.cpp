class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL)return NULL;
        
        Node* cur=head;

        //STEP 1:Inserting dummy nodes in between original linked list
        while(cur!=NULL){
            Node* temp=cur->next;
            cur->next=new Node(cur->val);
            cur->next->next=temp;
            cur=temp;
        }

        cur=head;
        //Step 2:Setting random pointers

        while(cur!=NULL){
            if(cur->next!=NULL)
             cur->next->random=(cur->random!=NULL)?(cur->random->next):NULL;
             cur=cur->next->next;
        }

        //Setting next pointers
        cur=head;
        
        Node* nhead=head->next;
        Node* temp=nhead;

        while(cur!=NULL){
           if(cur->next!=NULL)
           cur->next=cur->next->next;
           if(temp->next!=NULL)
           temp->next=temp->next->next;
           temp=temp->next;
           cur=cur->next;
        }

        return nhead;

    }
};