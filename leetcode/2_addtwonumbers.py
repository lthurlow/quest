# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


# You are given two non-empty linked lists representing two non-negative integers.
# The digits are stored in reverse order and each of their nodes contain a single digit. 
# Add the two numbers and return it as a linked list.
# You may assume the two numbers do not contain any leading zero, except the number 0 itself.
class Solution:
    
    # add two nodes together, return the carry value
    # gets called three times, for the three cases.
    # DRY: Do not Reply Yourself
    def addNodes(self, sum_node, node1, node2, carry) -> int:
        sum_node.val = (node1.val + carry)
        if node2:
            sum_node.val += node2.val
        # there is probably a smarter way to handle carry case
        carry = 1 if sum_node.val - 9 > 0 else 0
        # we only want 1's digit so modulo 10's place, no single digit can add about 18.
        sum_node.val = sum_node.val % 10
        return carry
    
    # update the linked list by moving each list forward by one node
    # DRY: Do not Reply Yourself
    def nextNode(self, sum_node, node1, node2, carry) -> None:
        node1 = node1.next
        if node2:
            node2 = node2.next
        # when we increment node pointers, check if we are done adding, if so - no need to
        # create a new node value.  Also check if there is a carry, in the case we need to
        # carry a one to a new node.
        if (node1 or node2 or carry):
            sum_node.next = ListNode(0)
            sum_node = sum_node.next
        return sum_node, node1, node2
    
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # our linked list to return, fine to set to 0, as lists are non-empty, so None cant be answer
        ret_ll = ListNode(0)
        # we will keep track of our head pointer to return when we finish adding
        head = ret_ll
        # initial carry value is 0
        carry = 0

        # lets start by iterating both lists at once, and when one is None,
        # we can finish off adding that list individually into result list
        while (l1 != None and l2 != None):
            carry = self.addNodes(ret_ll, l1, l2, carry)
            ret_ll, l1, l2 = self.nextNode(ret_ll, l1, l2, carry)

        # if l2 is None, then iterate through l1
        while (l1 != None):
            carry = self.addNodes(ret_ll, l1, None, carry)
            ret_ll, l1, _ = self.nextNode(ret_ll, l1, None, carry)

        # and vise-versa if l1 is None, then iterate through l2
        while (l2 != None):
            carry = self.addNodes(ret_ll, l2, None, carry)
            ret_ll, l2, _ = self.nextNode(ret_ll, l2, None, carry)
        
        # interesting case when we are finish adding and there is a carry left over
        # because in nextNode we check if carry, this means that when there is carry over
        # we increment our new node from zero to one to handle that case.
        if carry:
            ret_ll.val += 1

        # return pointer to head of list
        return head
