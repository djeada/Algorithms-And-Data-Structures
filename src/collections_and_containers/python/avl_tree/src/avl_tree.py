class AvlTree:
    class Node:
        def __init__(self, value):
            self.value = value
            self.left = None
            self.right = None
            self.balance_factor = 0

    def __init__(self):
        self.root = None
        self.n = 0

    def insert(self, value):
        def insert(p):
            if not p:
                return self.Node(value)

            if value < p.value:
                p.left = insert(p.left)
            else:
                p.right = insert(p.right)

            right_height = self._height(p.right) if p.right else 0
            left_height = self._height(p.left) if p.left else 0
            p.balance_factor = right_height - left_height
            return self.balance(p)

        self.root = insert(self.root)
        self.n += 1

    def remove(self, value):
        def remove(p):
            if not p:
                return None

            if value == p.value:
                if not p.left:
                    return p.right
                if not p.right:
                    return p.left

                min_value = self.find_min(p.right)
                p.value = min_value
                p.right = remove(p.right)
            elif value < p.value:
                p.left = remove(p.left)
            else:
                p.right = remove(p.right)

            right_height = self._height(p.right) if p.right else 0
            left_height = self._height(p.left) if p.left else 0
            p.balance_factor = right_height - left_height
            return self.balance(p)

        self.root = remove(self.root)
        self.n -= 1

    def contains(self, value):
        def contains(p):
            if not p:
                return False
            if value == p.value:
                return True
            elif value < p.value:
                return contains(p.left)
            else:
                return contains(p.right)

        return contains(self.root)

    def clear(self):
        self.root = None
        self.n = 0

    def height(self):
        return self._height(self.root)

    def _height(self, p):
        if not p:
            return 0
        return 1 + max(self._height(p.left), self._height(p.right))

    def size(self):
        return self.n

    def empty(self):
        return self.n == 0

    def in_order_traversal(self):
        def in_order_traversal(p, v):
            if p:
                in_order_traversal(p.left, v)
                v.append(p.value)
                in_order_traversal(p.right, v)

        v = []
        in_order_traversal(self.root, v)
        return v

    def pre_order_traversal(self):
        def pre_order_traversal(p, v):
            if p:
                v.append(p.value)
                pre_order_traversal(p.left, v)
                pre_order_traversal(p.right, v)

        v = []
        pre_order_traversal(self.root, v)
        return v

    def post_order_traversal(self):
        def post_order_traversal(p, v):
            if p:
                post_order_traversal(p.left, v)
                post_order_traversal(p.right, v)
                v.append(p.value)

        v = []
        post_order_traversal(self.root, v)
        return v

    def balance(self, p):
        if not p:
            return None

        if p.balance_factor == 2:
            if not p.right:
                return p
            if p.right.balance_factor < 0:
                p.right = self.rotate_right(p.right)
            return self.rotate_left(p)
        elif p.balance_factor == -2:
            if not p.left:
                return p
            if p.left.balance_factor > 0:
                p.left = self.rotate_left(p.left)
            return self.rotate_right(p)
        return p

    def rotate_left(self, p):
        q = p.right
        p.right = q.left
        q.left = p
        return q

    def rotate_right(self, p):
        q = p.left
        p.left = q.right
        q.right = p
        return q

    def find_min(self, p):
        while p.left:
            p = p.left
        return p.value
