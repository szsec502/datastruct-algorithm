package main

import "fmt"

type Node struct {
	number int
	name   string // number和name是数据域
	next   *Node  // 指针域，指向下一个节点
}

// 创建一个节点
func NewNode(number int, name string) *Node {
	return &Node{
		number: number,
		name:   name,
	}
}

/*
第一种插入方法
1. 声明一个临时节点指向头节点，用这个临时节点做后续操作
2. 遍历链表找到最后一个节点
3. 将新节点插入到链表的尾部
*/
func InsertNodeToTail(head *Node, newNode *Node) {
	lastNode := head // lastNode为临时节点，用于后续遍历使用

	for lastNode.next != nil { // 如果不是最后一个元素继续遍历
		lastNode = lastNode.next // 将下一个节点赋值给当前节点
	}

	lastNode.next = newNode // 将当前节点插入到链表的最后一个元素里
}

/*
第二种插入方法
这种方法跟第一中方法类似，只是循环判断条件不一样而已

1. 先找到最后一个节点
2. 创建一个临时节点，用于后续遍历使用
3. 将新节点插入到链表的尾部
*/
func InsertNodeToTail1(head *Node, newNode *Node) {
	lastNode := head // 创建一个临时节点

	for {
		if lastNode.next == nil { // 遍历链表判断是否为链表最后一个节点, 等于nil说明找到了
			break
		}

		lastNode = lastNode.next // 让lastNode不断指向下一个节点
	}

	lastNode.next = newNode // 将新节点插入到链表的尾部
}

/*
第三种插入方法
根据number的大小进行插入
1. 找到适合的节点
2. 创建一个临时节点，用于后续遍历使用
3. 让临时节点的number和下一个节点的number进行比较, 然后插入节点
*/
func InsertNodeToTail2(head *Node, newNode *Node) {
	lastNode := head
	flag := true

	for {
		if lastNode.next == nil { // 已经是最后一个节点
			break
		} else if lastNode.next.number >= newNode.number { // newNode应该插入到lastNode的后面
			break
		} else if lastNode.next.number == newNode.number { // 相等就不追加
			flag = false // flag设置为false,跳出循环
			break
		}

		lastNode = lastNode.next
	}

	if !flag {
		fmt.Println("已经存在节点")
		return
	} else {
		newNode.next = lastNode.next // lastNode的下一个节点插入到newNode的下一个节点
		lastNode.next = newNode      // newNode节点插入到lastNode的下一个节点
	}
}

func ShowNodeList(head *Node) {
	if head.next == nil {
		return
	}

	lastNode := head.next
	info := "["
	for lastNode != nil {
		info += fmt.Sprintf("{number : %v, name : %s}", lastNode.number, lastNode.name)
		lastNode = lastNode.next
	}
	info += "]"
	fmt.Println(info)
}

// 删除指定节点
func DeleteNode1(head *Node, newNode *Node) {
	lastNode := head

	for lastNode.next != nil {
		if lastNode.next.number == newNode.number {
			lastNode.next = lastNode.next.next
			return
		}
		lastNode = lastNode.next
	}
}

// 根据number删除节点
func DeleteNode2(head *Node, number int) {
	lastNode := head
	flag := false

	for {
		if lastNode.next == nil {
			break
		} else if lastNode.next.number == number {
			flag = true
			break
		}
		lastNode = lastNode.next
	}

	if flag {
		lastNode.next = lastNode.next.next
	} else {
		fmt.Println("没有找到相关的number号")
	}
}

func main() {
	headeNode := new(Node)

	node1 := NewNode(1, "tom")
	node2 := NewNode(2, "jack")
	node3 := NewNode(3, "json")
	node4 := NewNode(4, "cat")
	node5 := NewNode(5, "dog")

	InsertNodeToTail(headeNode, node1)
	InsertNodeToTail1(headeNode, node2)
	InsertNodeToTail2(headeNode, node3)
	InsertNodeToTail2(headeNode, node4)
	InsertNodeToTail2(headeNode, node5)

	ShowNodeList(headeNode)

	DeleteNode1(headeNode, node3)
	DeleteNode2(headeNode, 4)

	ShowNodeList(headeNode)
}
