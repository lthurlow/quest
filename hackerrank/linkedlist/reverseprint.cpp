/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void ReversePrint (Node *head)
{
  // sneaky, they made it so head could be null on this problem
  if (head == NULL)
  {
    return;
  }
  // if not allowed to use extra space, use recursion!
  if (head->next != NULL)
  {
    ReversePrint (head->next);
  }
  printf ("%d\n", head->data);
  // This is a "method-only" submission.
  // You only need to complete this method.
}
