# Templated-Linked-List

Functionality:
The Linked List is templated, allowing users to store any data type.
The Linked List utilizes non-contiguous memory to aid in efficient memory management.
The Linked List allows for fast node insertion and removal without the need to rebuild the entire data structure.
The program provides both iterative (PrintForward, PrintReverse) and recursive (PrintForwardRecursive, PrintReverseRecursive) methods to traverse and print the list.

Program Structure:
Node Class: Each node contains the actual data being stored and pointers to the subsequent and previous nodes.
Linked List Class: Maintains pointers to the head and tail nodes, a count of nodes, and provides interface functions to manipulate and query the list.
The Linked List is implemented as doubly-linked with both 'next' and 'previous' pointers for bidirectional traversal.
Exception Handling: The program incorporates error handling, specifically for out-of-range accesses.

Credits:
The UF CISE department provided the four main files for testing the header file and provided the objectives for this project.
