

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinarySearchTree:
    
    def __init__(self):
        self.root = None
        self.n = 0

    def insert(self, v):
        if self.root is None:
            self.root = Node(v)
        else:
            self._insert(v, self.root)
        self.n += 1

    def _insert(self, v, p):
        if v < p.data:
            if p.left is None:
                p.left = Node(v)
            else:
                self._insert(v, p.left)
        else:
            if p.right is None:
                p.right = Node(v)
            else:
                self._insert(v, p.right)

    def remove(self, v):
        if self.root.data == v and self.root.left is None and self.root.right is None:
            self.root = None
        else:
            self._remove(v, self.root)
        self.n -= 1

    def _remove(self, v, p):
        '''
        Search for value v in the tree rooted at p.
        If the node containing v is found, remove it by:
        1. If the node has no children, remove it by setting the parent's
           reference to the node to None.
        2. If the node has one child, remove it by setting the parent's reference
           to the node to the node's child.
        3. If the node has two children, replace the node's value with the
              smallest value in the right subtree and remove the node containing
              the smallest value in the right subtree.
        4. The p is the root of the tree itself. Then the self.root needs to be 
              set to None if there are no other nodes in the tree.
        '''
        def _find_min(p):
            if p is None:
                return None
            while p.left is not None:
                p = p.left
            return p.data

        if p is None:
            return None

        if v < p.data:
            p.left = self._remove(v, p.left)
        elif v > p.data:
            p.right = self._remove(v, p.right)
        else:
            if p.left is None:
                return p.right
            elif p.right is None:
                return p.left
            else:
                p.data = _find_min(p.right)
                p.right = self._remove(p.data, p.right)
        return p



    def contains(self, v):
        return self._contains(v, self.root)

    def _contains(self, v, p):
        if p is None:
            return False
        if v < p.data:
            return self._contains(v, p.left)
        elif v > p.data:
            return self._contains(v, p.right)
        else:
            return True

    def clear(self):
        self.root = None
        self.n = 0

    def height(self):
        if self.root is None:
            return 0
        return self._height(self.root)

    def _height(self, p):
        if p is None:
            return 0
        return 1 + max(self._height(p.left), self._height(p.right))

    def size(self):
        return self.n

    def empty(self):
        return self.n == 0

    def in_order_traversal(self):
        v = []
        self._in_order_traversal(self.root, v)
        return v

    def _in_order_traversal(self, p, v):
        if p is None:
            return
        self._in_order_traversal(p.left, v)
        v.append(p.data)
        self._in_order_traversal(p.right, v)

    def pre_order_traversal(self):
        v = []
        self._pre_order_traversal(self.root, v)
        return v

    def _pre_order_traversal(self, p, v):
        if p is None:
            return
        v.append(p.data)
        self._pre_order_traversal(p.left, v)
        self._pre_order_traversal(p.right, v)
    
    def post_order_traversal(self):
        v = []
        self._post_order_traversal(self.root, v)
        return v
    
    def _post_order_traversal(self, p, v):
        if p is None:
            return
        self._post_order_traversal(p.left, v)
        self._post_order_traversal(p.right, v)
        v.append(p.data)
    
    def __str__(self):
        return str(self.in_order_traversal())

