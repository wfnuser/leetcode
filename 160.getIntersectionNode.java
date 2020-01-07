/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == null || headB == null) return null;
        int len1 = 0;
        int len2 = 0;
        ListNode a = headA, b = headB;
        while (a != null) {
            a = a.next;
            len1++;
        }
        while (b != null) {
            b = b.next;
            len2++;
        }
        a = headA;
        b = headB;
        if (len1 > len2) {
            int num = len1 - len2;
            while (num > 0) {
                a = a.next;
                num--;
            }
        } else {
            int num = len2 - len1;
            while (num > 0) {
                b = b.next;
                num--;
            }
        }
        while (a != null) {
            if (a == b) return a; 
            else {
                a = a.next;
                b = b.next;
            }
        }
        return null; 
    }
}