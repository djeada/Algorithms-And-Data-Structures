class Heap:
    def __init__(self, size=10):
        self.size = size
        self.Heap = [0] * self.size
        self.pos = -1

    def full(self):
        if self.pos == self.size:
            return True
        return False

    def wstaw(self, item):
        if self.full():
            print("Heap is full!")
            return

        self.pos = self.pos + 1
        self.Heap[self.pos] = item
        self.repair_top(self.pos)

    def sort(self):
        for i in range(0, self.pos + 1):
            temp = self.Heap[0]
            self.Heap[0] = self.Heap[self.pos - i]
            self.Heap[self.pos - i] = temp
            self.repair_bottom(0, self.pos - i - 1)

    def repair_top(self, i):
        parent_pos = int((i - 1) / 2)

        while parent_pos >= 0 and self.Heap[parent_pos] < self.Heap[i]:
            temp = self.Heap[i]
            self.Heap[i] = self.Heap[parent_pos]
            self.Heap[parent_pos] = temp
            i = parent_pos
            parent_pos = (int)((i - 1) / 2)


    def repair_bottom(self, i, end):
        while i <= end:
            left = 2 * i + 1
            right = 2 * i + 2

            if left < end:
                idx_to_change = None

                if right > end:
                    idx_to_change = left

                else:
                    if self.Heap[left] > self.Heap[right]:
                        idx_to_change = left
                    else:
                        idx_to_change = right

                    if self.Heap[i] < self.Heap[idx_to_change]:
                        temp = self.Heap[i]
                        self.Heap[i] = self.Heap[idx_to_change]
                        self.Heap[idx_to_change] = temp
                    else:
                        break

                    i = idx_to_change
            else:
                break

