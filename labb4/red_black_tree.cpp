#include "red_black_tree.h"

red_black_tree::red_black_tree() :root(nullptr) {}


void red_black_tree::in_order()const { in_order_helper(root); }

void red_black_tree::level_order()const { level_order_helper(root); }

bool red_black_tree::get_color(struct node *&node) {
	if (node == nullptr)
		return BLACK;

	return node->color;
}

void red_black_tree::insert(const int &value) {
	struct node*node = new_node(value);
	std::cout << node->color;
	root = bst_insert(root, node);
	fix_violation(node);
}

void red_black_tree::in_order_helper(struct node *root)const
{
	if (root == nullptr)
		return;

	in_order_helper(root->left);
	std::cout << root->value << "  ";
	in_order_helper(root->right);
}

void red_black_tree::level_order_helper(struct node *root)const
{
	if (root == nullptr)
		return;

	std::queue<struct node*> q;
	q.push(root);

	while (!q.empty())
	{
		node *temp = q.front();
		std::cout << temp->value  << "  ";
		q.pop();

		if (temp->left != nullptr)
			q.push(temp->left);

		if (temp->right != nullptr)
			q.push(temp->right);
	}
}

void red_black_tree::rotate_left(node *&ptr) {
	node *right_child = ptr->right;
	ptr->right = right_child->left;

	if (ptr->right != nullptr)
		ptr->right->parent = ptr;

	right_child->parent = ptr->parent;

	if (ptr->parent == nullptr)
		root = right_child;
	else if (ptr == ptr->parent->left)
		ptr->parent->left = right_child;
	else
		ptr->parent->right = right_child;

	right_child->left = ptr;
	ptr->parent = right_child;
}

void red_black_tree::rotate_right(node *&ptr)
{
	node *left_child = ptr->left;
	ptr->left = left_child->right;

	if (ptr->left != nullptr)
		ptr->left->parent = ptr;

	left_child->parent = ptr->parent;

	if (ptr->parent == nullptr)
		root = left_child;
	else if (ptr == ptr->parent->left)
		ptr->parent->left = left_child;
	else
		ptr->parent->right = left_child;

	left_child->right = ptr;
	ptr->parent = left_child;
}

void red_black_tree::fix_violation(struct node *ptr) {

	struct node *parent = nullptr;
	struct node *grand_parent = nullptr; 
	
	// sålänge ptr inte är roten OCH ptr är röd OCH ptr pappa är röd  ( två röda i rad)
	while (ptr != root && get_color(ptr) == RED && get_color(ptr->parent) == RED) {
		parent = ptr->parent;
		grand_parent = parent->parent;
		// om de kom från vänstra sidan
		if (get_color(parent) == get_color(grand_parent->left)) {
			struct node*uncle = grand_parent->right;
			if (get_color(uncle) == RED) {
				ptr = recoloring(grand_parent, uncle, parent);
			}
			else {
				if (get_color(ptr) == get_color(parent->right)) {
					rotate_left(parent);
					ptr = parent;
					parent = ptr->parent;
				}
				rotate_right(grand_parent);
				std::swap(parent->color, grand_parent->color);
				ptr->parent;
			}
		}
		else {
			struct node*uncle = grand_parent->left;
			if (get_color(uncle) == RED) {
				ptr = recoloring(grand_parent, uncle, parent);
			}
			else {
				if (get_color(ptr) == get_color(parent->left)) {
					rotate_right(parent);
					ptr = parent;
					parent = ptr->parent;
				}
				rotate_left(grand_parent);
				std::swap(parent->color, grand_parent->color);
				ptr = parent;
			}
		}
	}
	root->color = BLACK;
}

struct node *recoloring(struct node *&a, struct node *&b, struct node *&c) {
	a->color = RED;
	b->color = c->color = BLACK;
	return a;
}

struct node *new_node(int value)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->value = value;
	temp->left = temp->right = temp->parent = nullptr;
	temp->color = RED;
	return temp;
}



struct node* bst_insert(struct node* root, struct node* ptr)
{
	/* If the tree is empty, return node */
	if (root == nullptr) return ptr;

	/* Otherwise, recur down the tree */
	if (ptr->value < root->value) {
		root->left = bst_insert(root->left, ptr);
		root->left->parent = root;
	}

	else if (ptr->value >= root->value) {
		root->right = bst_insert(root->right, ptr);
		root->right->parent = root;
	}

	/* return the (unchanged) node pointer */
	return root;
}