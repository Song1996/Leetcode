# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def ListNode2int(self, l):
        """
        :type l: List Node
        :type v: int 
        """
        v, k = 0, 1
        while l != None:
            v += l.val*k
            k *= 10
            l = l.next
        return v

    def int2ListNode(self,v):
        if v ==0:
            return ListNode(0)
        l = []
        while v>0:
            l.append(ListNode(v%10))
            v = v//10
        n = l[0]
        for i in range(1,len(l)):
            n.next = l[i]
            n = l[i]
        return l[0]

    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        vl1 = self.ListNode2int(l1)
        vl2 = self.ListNode2int(l2)
        l = self.int2ListNode(vl1+vl2)
        return l
