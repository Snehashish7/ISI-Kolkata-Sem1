/*
Write a program to print a binary tree, rotated anti-clockwise by 90◦
on the screen. For example, for the tree on slide 7, your output should
like something like:
      F
   C
A
      E
   B
      D

strategy to think: reverse inorder with indentation.
*/

// debug once to understand how it is working.
#include <stdio.h>
#include <stdlib.h>

// Define the TNODE structure to represent each node in the tree
typedef struct tnode
{
   int data;
   int left, right;
   int parent;
} TNODE;

// Define the TREE structure that stores the tree and its nodes
typedef struct
{
   int capacity, num_nodes, root;
   TNODE *nodelist;
} TREE;

// Function to read the tree structure
void read_tree(TREE *T)
{
   int capacity;
   scanf("%d", &capacity);
   T->capacity = capacity;
   T->num_nodes = 0;
   T->nodelist = (TNODE *)malloc(capacity * sizeof(TNODE));

   // Initialize parent of root node as -1
   T->nodelist[0].parent = -1;
   for (int i = 0; i < capacity; i++)
   {
      TNODE node;
      scanf("%d %d %d", &node.data, &node.left, &node.right);
      T->nodelist[i].data = node.data;
      T->nodelist[i].left = node.left;
      T->nodelist[i].right = node.right;

      // Update parent pointers for left and right children
      if (T->nodelist[i].left != -1)
         T->nodelist[T->nodelist[i].left].parent = i;
      if (T->nodelist[i].right != -1)
         T->nodelist[T->nodelist[i].right].parent = i;
   }
}

// Function to print the tree structure (data, left, right, parent)
void print_tree(TREE *T)
{
   for (int i = 0; i < T->capacity; i++)
   {
      printf("Node: %d | Left: %d | Right: %d | Parent: %d\n",
             T->nodelist[i].data,
             T->nodelist[i].left,
             T->nodelist[i].right,
             T->nodelist[i].parent);
   }
}

// Function for reverse inorder traversal to print the tree rotated 90 degrees
void reverse_inorder(TREE *T, int root, int depth)
{
   if (root == -1)
      return;

   // Process right subtree first (reverse inorder traversal)
   reverse_inorder(T, T->nodelist[root].right, depth + 1);

   // Print current node with indentation based on depth
   for (int i = 0; i < depth; i++)
   {
      printf("   "); // Indentation for tree rotation effect
   }
   printf("%d\n", T->nodelist[root].data);

   // Process left subtree
   reverse_inorder(T, T->nodelist[root].left, depth + 1);
}

int main()
{
   TREE T;
   read_tree(&T);

   // Optional: print the tree structure (for debugging)
   print_tree(&T);

   printf("\nRotated tree view (90 degrees anti-clockwise):\n");
   reverse_inorder(&T, 0, 0); // Start reverse inorder from root with initial depth 0

   return 0;
}
/*
1 1 2
2 3 4
3 -1 -1
4 -1 -1
5 5 -1
6 6 -1
7 7 -1
8 -1 -1
*/