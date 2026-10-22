

/*Heap Sort & Binary Tree — Questions + C++ Solutions

Sequence:
1.What is a Complete Binary Tree?
2.What is a Full/Perfect Binary Tree?
3.What is an Almost Complete Binary Tree?
4.What is the relation between Complete Binary Tree and Almost Complete Binary Tree?
5.Explain the properties of a Complete Binary Tree.
6.Write a program to check whether a binary tree is an Almost Complete/Complete Binary Tree.
7.Write a program to check whether a binary tree is a Full Binary Tree.
8.Given a binary tree in array representation, convert it into Preorder Traversal.
9.Explain Serialization and Deserialization of a Binary Tree.
10.Explain why Heap is a Priority Queue and implement Heap Sort.*/

/*Q1. What is a Complete Binary Tree?
Definition

A Complete Binary Tree is a binary tree in which:

Every level is completely filled except possibly the last level.
The last level is filled from left to right without any gaps.
Example
          1
        /   \
       2     3
      / \   /
     4   5 6

This is a Complete Binary Tree because the last level is filled from left to right.

Important Point

For a node at index i in a 0-based array:

Left Child  = 2*i + 1
Right Child = 2*i + 2
Parent      = (i-1)/2

This property makes a Complete Binary Tree very useful for implementing Heaps.*/



/*Q2. What is a Full Binary Tree?
Definition

A Full Binary Tree is a binary tree in which every node has either:

0 children, or
2 children

A node cannot have exactly one child.

Example
          1
        /   \
       2     3
      / \   / \
     4   5 6   7

Every node has either 0 or 2 children.

Important Formula

If a Full Binary Tree has:

I internal nodes
L leaf nodes

Then:

L = I + 1

Total nodes:

N = 2I + 1*/



/*Q3. What is an Almost Complete Binary Tree?

An Almost Complete Binary Tree generally means a tree that is filled level by level from left to right, with the possible exception of the final level.

In practice, this is essentially the same structural idea normally called a Complete Binary Tree.

Example:

          1
        /   \
       2     3
      / \   /
     4   5 6

The last level has nodes 4, 5, 6, starting from the left.*/

/*Q4. Relation Between Complete and Almost Complete Binary Tree

For DSA/Heap terminology, complete binary tree is the standard term.

Complete Binary Tree
        ↓
All levels completely filled
except possibly last level
        ↓
Last level filled from LEFT → RIGHT

This is why a Heap is represented efficiently using an array.*/



/*Q5. Properties of a Complete Binary Tree

Consider:

          1
        /   \
       2     3
      / \   / \
     4   5 6   7
    /
   8

For a 0-based array representation:

Index:  0  1  2  3  4  5  6  7
Value:  1  2  3  4  5  6  7  8

For any node at index i:

Left Child  = 2*i + 1
Right Child = 2*i + 2

For example, node 2 is at index 1.

Left child  = 2(1) + 1 = 3
Right child = 2(1) + 2 = 4

So:

2
/ \
4  5 */




