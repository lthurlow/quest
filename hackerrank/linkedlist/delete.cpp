/*
  Delete Node at a given position in a linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node *Delete (Node *head, int position)
{
  // if it is first node, return the next field
  if (position == 0)
  {
    return head->next;
  }
  Node *iter = head;
  // otherwise iterate through to the position
  for (int i = 0; i < position - 1; i++)
  {
    // if the last element is NULL, kill the current element
    // this sort of logic only works if inputs are correct
    if (iter->next == NULL)
    {
      iter = NULL;
      return head;
    }
    iter = iter->next;
  }
  // skip over the element with next pointers.
  Node *y = iter->next;
  iter->next = y->next;
  return head;
}
