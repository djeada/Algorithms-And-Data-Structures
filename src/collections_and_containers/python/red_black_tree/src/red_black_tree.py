class Node:
    def __init__(self, value, is_red=True, left=None, right=None):
        self.value = value
        self.is_red = is_red
        self.left = left
        self.right = right

    def is_left_red(self):
        return self.left and self.left.is_red

    def is_right_red(self):
        return self.right and self.right.is_red


class RedBlackTree:
    def __init__(self):
        self.root = None
        self.n = 0

    def insert(self, value):
        def insert(p):
            if not p:
                return Node(value, is_red=True)

            if value < p.value:
                p.left = insert(p.left)
            elif value > p.value:
                p.right = insert(p.right)
            else:
                p.value = value

            if p.is_right_red() and not p.is_left_red():
                p = self.rotate_left(p)
            if p.is_left_red() and p.left.is_left_red():
                p = self.rotate_right(p)
            if p.is_left_red() and p.is_right_red():
                self.flip_colors(p)

            return self.balance(p)

        self.root = insert(self.root)
        self.root.is_red = False
        self.n += 1

    def remove(self, value):
        def remove(p):
            if not p:
                return None

            if value < p.value:
                p.left = remove(p.left)
            elif value > p.value:
                p.right = remove(p.right)
            else:
                if not p.left:
                    return p.right
                if not p.right:
                    return p.left

                min_value = self.find_min(p.right)
                p.value = min_value
                p.right = remove(p.right)

            return self.balance(p)

        self.root = remove(self.root)
        if self.root:
            self.root.is_red = False
        self.n -= 1

    def contains(self, value):
        def contains(p):
            if not p:
                return False
            if value < p.value:
                return contains(p.left)
            elif value > p.value:
                return contains(p.right)
            else:
                return True

        return contains(self.root)

    def clear(self):
        self.root = None
        self.n = 0

    def height(self):
        def height(p):
            if not p:
                return 0
            return 1 + max(height(p.left), height(p.right))

        return height(self.root)

    def size(self):
        return self.n

    def empty(self):
        return self.n == 0

    def in_order_traversal(self):
        def in_order_traversal(p, v):
            if not p:
                return
            in_order_traversal(p.left, v)
            v.append(p.value)
            in_order_traversal(p.right, v)

        v = []
        in_order_traversal(self.root, v)
        return v

    def pre_order_traversal(self):
        def pre_order_traversal(p, v):
            if not p:
                return
            v.append(p.value)
            pre_order_traversal(p.left, v)
            pre_order_traversal(p.right, v)

        v = []
        pre_order_traversal(self.root, v)
        return v

    def post_order_traversal(self):
        def post_order_traversal(p, v):
            if not p:
                return
            post_order_traversal(p.left, v)
            post_order_traversal(p.right, v)
            v.append(p.value)

        v = []
        post_order_traversal(self.root, v)
        return v

    def rotate_left(self, p):
        right = p.right
        p.right = right.left
        right.left = p
        right.is_red = p.is_red
        p.is_red = True
        return right

    def rotate_right(self, p):
        left = p.left
        p.left = left.right
        left.right = p
        left.is_red = p.is_red
        p.is_red = True
        return left

    def flip_colors(self, p):
        p.is_red = not p.is_red
        p.left.is_red = not p.left.is_red
        p.right.is_red = not p.right.is_red

    def move_red_left(self, p):
        self.flip_colors(p)
        if p.right and p.right.right and p.right.right.is_red:
            p = self.rotate_left(p)
            self.flip_colors(p)
        return p

    def move_red_right(self, p):
        self.flip_colors(p)
        if p.left and p.left.left and p.left.left.is_red:
            p = self.rotate_right(p)
            self.flip_colors(p)
        return p

    def balance(self, p):
        if p.right and p.right.is_red:
            p = self.rotate_left(p)
        if p.left and p.left.is_red and p.left.left and p.left.left.is_red:
            p = self.rotate_right(p)
        if p.left and p.left.is_red and p.right and p.right.is_red:
            self.flip_colors(p)
        return p

    def find_min(self, p):
        while p.left:
            p = p.left
        return p.value
