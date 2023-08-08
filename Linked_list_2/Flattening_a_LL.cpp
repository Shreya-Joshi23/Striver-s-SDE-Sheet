Node* mergeTwoLL(Node* a,Node* b){
	
	Node* res=new Node(0);
	Node* temp=res;

	while(a!=NULL && b!=NULL){
		
		if(a->data<=b->data){
			temp->child=a;
			temp=temp->child;
			a=a->child;
		}else{
			temp->child=b;
			temp=temp->child;
			b=b->child;
		}
		
	}

	if(a){
		temp->child=a;
	}

	if(b){
		temp->child=b;
	}

	return res->child;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head==NULL || head->next==NULL)
	return head;

	Node* L2=flattenLinkedList(head->next);
	head->next=NULL;
	
	Node* nhead=mergeTwoLL(head,L2);

	return nhead;
}