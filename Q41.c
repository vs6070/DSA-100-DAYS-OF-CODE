// Problem Statement:
// Implement a Queue using a linked list supporting enqueue and dequeue operations.

// Input Format:
// - First line contains integer N
// - Next N lines contain queue operations

// Output Format:
// - Print dequeued elements
// - Print -1 if dequeue is attempted on an empty queue

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Queue:
    def __init__(self):
        self.front = None
        self.rear = None

    def enqueue(self, x):
        new_node = Node(x)

        if self.rear is None:
            self.front = self.rear = new_node
            return

        self.rear.next = new_node
        self.rear = new_node

    def dequeue(self):
        if self.front is None:
            print(-1)
            return

        temp = self.front
        print(temp.data)

        self.front = self.front.next

        if self.front is None:
            self.rear = None


n = int(input())
q = Queue()

for _ in range(n):
    op = input().split()

    if op[0] == "enqueue":
        q.enqueue(int(op[1]))
    elif op[0] == "dequeue":
        q.dequeue()