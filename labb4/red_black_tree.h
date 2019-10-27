#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H



#include <stdlib.h>  
#include <queue>
#include <iostream>
// Every node is red or BLACK

// Root is always BLACK

// New insertions are always RED

// Every path from root - leaf has the same number of BLACK nodes

// No path can have two consecutive RED

// Nulls are considered BLACK



// Reblance: BLACK Aunt - rotate : BAR

// RED aunt - Color flip 

// After rotation Black parent 2 red children

// After color flip red parent 2 black children

enum Color { RED, BLACK };

struct node *new_node(int value);
struct node *recoloring(struct node*&a, struct node *&b, struct node *&c);
struct node* bst_insert(struct node* node, struct node *pt);

struct node
{
	int value;
	struct node *left, *right, *parent;
	bool color;
};

class red_black_tree {
	struct node *root;
protected:
	void in_order_helper(struct node *root)const;
	void level_order_helper(struct node *root)const;
	void fix_violation(struct node *node);
	bool get_color(struct node *&node);
public:
	red_black_tree();
	void rotate_left(node *&ptr);
	void rotate_right(node *&ptr);
	void insert(const int &value);
	void in_order()const;
	void level_order()const;
};


#endif