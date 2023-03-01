package main

type DoubleNode struct {
	number int
	name   string
	perv   *DoubleNode
	next   *DoubleNode
}

func NewDoubleNode(number int, name string) *DoubleNode {
	return &DoubleNode{
		number: number,
		name:   name,
	}
}

func InsertNode1(head *DoubleNode, newNode *DoubleNode) {}

func InsertNode2(head *DoubleNode, newNode *DoubleNode)

func ShowNodeList(head *DoubleNode) {}

func DeleteNode(head *DoubleNode) {}
