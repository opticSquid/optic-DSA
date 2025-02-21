# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        current = dummy

        while list1 and list2:
            if list1.val <= list2.val:
                current.next = list1
                list1 = list1.next
            else:
                current.next = list2
                list2 = list2.next
            current = current.next

        current.next = list1 or list2

        return dummy.next


def print_list(node: Optional[ListNode]):
    while node:
        print(f"{node.val}->")
        node = node.next
    print()


l1 = [1, 2, 5, 7]
l2 = [1, 3, 4, 6, 8]


def create_linked_list(lst):
    dummy = ListNode()
    current = dummy
    for val in lst:
        current.next = ListNode(val)
        current = current.next
    return dummy.next


list1 = create_linked_list(l1)
list2 = create_linked_list(l2)

print("List 1:")
print_list(list1)
print("List 2:")
print_list(list2)

solution = Solution()
merged_list = solution.mergeTwoLists(list1, list2)
print("Merged List:")
print_list(merged_list)
