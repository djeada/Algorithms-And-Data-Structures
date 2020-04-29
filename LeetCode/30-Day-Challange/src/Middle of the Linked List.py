'''
Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.
'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        i = findLength(head)//2
        print(i)
        current = head
        while i > 0:
            current = current.next
            i -= 1
        return current

def findLength(head):
    counter = 0
    if head:
        current = head
        counter += 1
        while current.next:
            counter += 1
            current = current.next
    return counter
        
