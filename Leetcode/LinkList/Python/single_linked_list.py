class Node(object):
    def __init__(self, data, next=None):
        self.data = data
        self.next = next


class LinkedList(object):
    """

    """
    def __init__(self):
        # define a head node, default None
        self._head = None

    def is_empty(self):
        """
        """
        return self._head == None

    def append_first(self, data):
        """Add a new data in the first list
        """
        new_node = Node(data)
        new_node._next = self._head
        self._head = new_node

    def append_last(self, data):
        """Add a new data node in the last list
        """
        new_node = Node(data)

        if self._head is None:
            self._head = new_node
            return

        last_node = self._head
        while last_node._next is not None:
            last_node = last_node._next

        last_node._next = new_node

    def insert_before(self, prev_node, data):
        """Insert a new data node in a specific position which is before a node
        """
        # make sure if the given prev_node exists 
        if prev_node is None: 
            print('The given previous node must inLinkedList.')
            return
        # create a new node
        new_node = Node(data)

        # new node must point to a node that prev node pointed
        new_node._next = prev_node._next
        # change prev_node point to current new node
        prev_node._next = new_node

    def find(self, target, next_node, n_nodes):
        """Find the first node from nth succscor node at the target node

        """
        while n_nodes>0:
            curr_node = next_node._next
            if taget == curr_node.data:
                return curr_node
            return None


    def remove(self, target):
        """Delete a node from linked list

        """
        cur_node = self._head

        if cur_node is None:
            raise ValueError('Cannot delet')
        else:
            if cur_node.data == target:
                self._head = cur_node._next
                cur_node = None
                return 

        while (cur_node is not None) and (cur_node.data != target):
            # define a prev node
            prev_node = cur_node
            cur_node = cur_node._next

        if cur_node is None:
            raise ValueError('Cannot delete')

        prev_node._next = cur_node._next
        cur_node = None


    def pprint(self):
        cur_node = self._head
        while cur_node:
            print(cur_node.data)
            cur_node = cur_node._next
