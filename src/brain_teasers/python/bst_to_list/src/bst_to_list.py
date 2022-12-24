from typing import List


class TreeNode:
    def __init__(self, value: int, left: "TreeNode" = None, right: "TreeNode" = None):
        self.value = value
        self.left = left
        self.right = right


class ListNode:
    def __init__(self, value: int, next: "ListNode" = None):
        self.value = value
        self.next = next
        self.prev = None


class DoubleLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_before(self, node: ListNode, value: int) -> ListNode:
        """Insert a new node with the given value before the given node."""
        # Create the new node
        new_node = ListNode(value)
        # If the given node is None, set the new node as the head and tail
        if not node:
            self.head = new_node
            self.tail = new_node
        # Otherwise, insert the new node before the given node
        else:
            # Set the new node's next to the given node
            new_node.next = node
            # If the given node is the head, set the new node as the head
            if node == self.head:
                self.head = new_node
            # Otherwise, set the new node's prev to the given node's prev and the given node's prev's next to the new node
            else:
                new_node.prev = node.prev
                node.prev.next = new_node
            # Set the given node's prev to the new node
            node.prev = new_node
        # Return the new node
        return new_node

    def insert_after(self, node: ListNode, value: int) -> ListNode:
        """Insert a new node with the given value after the given node."""
        # Create the new node
        new_node = ListNode(value)
        # If the given node is None, set the new node as the head and tail
        if not node:
            self.head = new_node
            self.tail = new_node
        # Otherwise, insert the new node after the given node
        else:
            # Set the new node's prev to the given node
            new_node.prev = node
            # If the given node is the tail, set the new node as the tail
            if node == self.tail:
                self.tail = new_node
            # Otherwise, set the new node's next to the given node's next and the given node's next's prev to the new node
            else:
                new_node.next = node.next
                node.next.prev = new_node
            # Set the given node's next to the new node
            node.next = new_node
        # Return the new node
        return new_node

    def delete(self, node: ListNode) -> None:
        """Delete the given node."""
        # If the node is the head, set the head to the node's next
        if node == self.head:
            self.head = node.next
        # Otherwise, set the node's prev's next to the node's next
        else:
            node.prev.next = node.next
        # If the node is the tail, set the tail to the node's prev
        if node == self.tail:
            self.tail = node.prev
        # Otherwise, set the node's next's prev to the node's prev
        else:
            node.next.prev = node.prev

    def __iter__(self):
        node = self.head
        while node:
            yield node.value
            node = node.next

    def __str__(self):
        return " -> ".join(map(str, self))

    def to_list(self) -> List[int]:
        return list(self)


def bst_to_double_linked_list(root: TreeNode) -> DoubleLinkedList:
    """Convert a binary search tree to a double linked list."""
    # Create the double linked list
    double_linked_list = DoubleLinkedList()
    # Create a stack to store the nodes
    stack = []
    # Start at the root node
    node = root
    # Traverse the tree
    while node or stack:
        # If the current node is not None, push it onto the stack and go to the left child
        if node:
            stack.append(node)
            node = node.left
        # Otherwise, pop the top node from the stack, add it to the double linked list, and go to the right child
        else:
            node = stack.pop()
            double_linked_list.insert_before(double_linked_list.head, node.value)
            node = node.right
    # Return the double linked list
    return double_linked_list
