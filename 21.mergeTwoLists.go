func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	var head *ListNode
	head = &ListNode{}
	merge(head, l1, l2)
	return head.Next
}

func merge(head *ListNode, l1 *ListNode, l2 *ListNode) {
	if l1 == nil && l2 == nil {
		return
	}
	if l1 == nil {
		head.Next = l2
		return
	}
	if l2 == nil {
		head.Next = l1
		return
	}
	if l1.Val <= l2.Val {
		head.Next = l1
		merge(head.Next, l1.Next, l2)
	} else {
		head.Next = l2
		merge(head.Next, l1, l2.Next)
	}
	return
}