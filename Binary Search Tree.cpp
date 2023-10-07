#include <iostream>
#include<limits>
using namespace std;
class Node {
public:
	int data;
	Node* left, *right;
	Node(int input = 0) {
		data = input;
		left = right = NULL;
	}

 };

class BST {
public:
	Node* root;
	BST() {
		root = NULL;
	}
	Node* Insert(Node* tree, int item) {
		if (tree == NULL){
			Node* newnode = new Node(item);
			tree = newnode;
		}
		else if (item < tree->data){
			tree->left = Insert(tree->left, item);
		}

		else {
			tree->right = Insert(tree->right, item);
		}
		return tree;
	}
	void Insert(int item) {
		root = Insert(root, item);
	}
	Node* Findmax(Node* tree) {
		if (tree == NULL)
			return NULL;
		else if (tree->right == NULL){
			return tree;
		}
		else
			return Findmax(tree->right);
	}
	Node* Delete(Node* tree, int key) {
		if (tree == NULL){
			return NULL;}
		if (Search(key)){
        if (key < tree->data)
			tree->left = Delete(tree->left, key);
		else if (key > tree->data)
			tree->right = Delete(tree->right, key);
		else if (key == tree->data) { //the key is on the root itself
			Node* right_temp = new Node();
			Node* left_temp = new Node();
			if (tree->right == NULL && tree->left == NULL) { //the root is leaf
				tree = NULL;
			}
			else if (tree->right != NULL && tree->left == NULL) {//the root has only one right child
				left_temp = tree->right->left;
				right_temp = tree->right->right;
				tree->data = tree->right->data;
				delete tree->right;
				tree->left = left_temp;
				tree->right = right_temp;
			}
			else if (tree->right == NULL && tree->left != NULL) {//the root has only one left child
				left_temp = tree->left->left;
				right_temp = tree->left->right;
				tree->data = tree->left->data;
				delete tree->left;
				tree->left = left_temp;
				tree->right = right_temp;
			}
			else {//if the root has 2 childs (internal node)
				Node* max = Findmax(tree->left);
				tree->data = max->data;
				tree->left = Delete(tree->left, max->data);
			}
		}
		return tree;
		}
		else{
            return NULL;
		}
	}

	bool Delete(int key) {
		Node* after = Delete(root, key);
		if (after == NULL)
			return false;
        else
            return true;
	}
	Node* Search(Node* tree, int key) {
		if (tree == NULL)
			return NULL;
		else if (key == tree->data)
			return tree;
		else if (key > tree->data)
			return Search(tree->right, key);
		else
			return Search(tree->left, key);
	}
	bool Search (int key) {
		Node* found = Search(root, key);
		if (found == NULL)
			return false;
		else
			return true;
	}
	void PreOrder(Node* tree) {
		if (tree == NULL)
			return;
		cout << tree->data << "\t";
		PreOrder(tree->left);
		PreOrder(tree->right);
	}
	void PreOrder() {
		PreOrder(root);
	}
	void PostOrder(Node* tree) {
		if (tree == NULL)
			return;
		PostOrder(tree->left);
		PostOrder(tree->right);
		cout << tree->data << "\t";
	}
	void PostOrder() {
		PostOrder(root);
	}
	void InOrder(Node* tree) {
		if (tree == NULL)
			return;
		InOrder(tree->left);
		cout << tree->data << "\t";
		InOrder(tree->right);
	}
	void InOrder() {
		InOrder(root);
	}
	int Find_max(){
		if (Findmax(root) == NULL)
			return NULL;
		else
			return Findmax(root)->data;
	}

};

int main() {
	// TEST
	BST test;

	int number_of_items;
	int item;
	while (true){
	int process=0;
	cout << endl << "Please choose the desired process: \n 1. Insert Item. \n 2. Delete Item. \n 3. Search. \n 4. Findmax. \n 5. PreOrder. \n 6. InOrder. \n 7. PostOrder. \n 8. End" << endl;
	cout << endl <<"Process Number: ";
	cin >> process;


	if (process == 1){
	cout << "Please enter the number of items you want to insert: " << endl;
	cin >> number_of_items;
	for (int i = 0; i < number_of_items; i++) { //user inputs items
		cout << "Please Enter Item " << i + 1 << ": ";
		cin >> item;
		test.Insert(item);
	}
	}
	else if (process == 2){
		cout << "Please enter the item you want to delete: " << endl;
		cin >> item;
		if (test.Delete(item)==false)
			cout << "Item doesn't exist." << endl;
		else{
			test.Delete(item);
			cout << "Item Deleted" << endl;}
	}
	else if (process == 3){
	int search_item;
	cout << endl << "Please enter the item you want to search: ";
	cin >> search_item;
	if (test.Search(search_item) == true) //user searches for item
		cout << "Item Found!" << endl;
	else
		cout << "Item not found!" << endl;
	}
	else if(process==4){
		if (test.Find_max() == NULL)
			cout << "No items in the tree!" << endl;
		else{
			cout <<test.Find_max()<<endl;
		}

	}
	else if(process ==5){
        test.PreOrder();
        cout << endl;
	}
	else if(process==6){
	    test.InOrder();
	    cout << endl;
	}
	else if(process==7){
	    test.PostOrder();
	    cout << endl;
	}
	else if(process==8){
	    break;
	}
	else{
	    cerr << "Invalid input! Please enter a valid integer." << endl;
	    cin.clear();
	    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
	    }

	/*
	READY TEST
	test.Insert(10);
	test.Insert(50);
	test.Insert(5);
	test.Insert(70);
	test.Insert(58);
	test.Insert(80);
	test.Insert(7);
	test.PreOrder();
	cout << endl;
	test.Delete(70);
	test.PreOrder();
	if (test.Search(5) == true)
		cout << endl << "Item Found!" << endl;
	else
		cout << endl << "Item not found!" << endl;
	test.PreOrder();
	cout << endl;
	test.InOrder();
	cout << endl;
	test.PostOrder();
	test.Insert(5);
	test.Insert(3);
	test.Insert(2);
	test.Insert(4);
	test.InOrder();
	cout << endl;
	test.Delete(5);
	test.InOrder();
*/



}

