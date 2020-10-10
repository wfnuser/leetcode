/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func detectCycle(head *ListNode) *ListNode {
    first := head
    second := head

    for first != nil{
        second = second.Next
        if first.Next == nil {
            return nil
        }
        first = first.Next.Next

        if first == second {
            first = head
            for first != second {
                second = second.Next
                first = first.Next
            }
            return first
        }
    }

    return nil
}