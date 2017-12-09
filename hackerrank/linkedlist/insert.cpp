/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
    Node* x = new Node();
    x->data = data;
    x->next = NULL;
		// prepend to list
    if (position == 0){
        x->next = head;
        return x;
    }
		// iterate to the position before position and we will use next
		// pointer to insert to next place
    Node* iter = head;
    for (int i=0; i < position-1; i++){
				// because we are using next, check if we are going off list
        if (iter->next == NULL){
            iter->next = x;
            return head;
        }
        iter = iter->next;
    }
		// we know that element iter is not null because check, so we can append
    Node* y = iter->next;
    iter->next = x;
    x->next = y;
    return head;
}
