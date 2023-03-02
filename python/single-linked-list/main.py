class Node:
    """
    节点类类似于如下golang中的结构体:
    type Node struct {
        val  int // 数据域
        next *Node // 指针域
    }
    """
    def __init__(self, val: int = 0, next = None) -> None:
        self.val = val # 数据域
        self.next = next # 指针域


class LinkedList:
    def __init__(self) -> None:
        self.head = None


    def new_linked_list(self, data):
        self.head = Node(data)
        current = self.head

        for item in range(len(data)):
            node = Node(data[item])
            current.next = node
            current = current.next

    def get_linked_length(self) -> int:
        count = 0
        current = self.head

        while current:
            count += 1
            current = current.next
        return count

    def find_element(self, val) -> bool:
        current = self.head

        while current:
            if val == current.val:
                return True

            current = current.next

        return False

    def delete_node_from_front(self) -> None:
        if self.head:
            self.head = self.head.next

    def delete_node_from_rear(self) -> None:
        if not self.head.next:
            return

        current = self.head
        while current.next.next:
            current = current.next

        current.next = None

