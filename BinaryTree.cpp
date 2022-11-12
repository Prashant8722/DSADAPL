#include <iostream>
#include<queue>
using namespace std;
template <typename T>
class BinaryTreeNode{
 public:
 T data;
 BinaryTreeNode<T>* left;
 BinaryTreeNode<T>* right;
};
//To initialise a BinaryTreeNode
BinaryTreeNode<char>* newNode(char data)

{
 BinaryTreeNode<char>* Node = new BinaryTreeNode<char>();
 Node->data = data;
 Node->left = NULL;
 Node->right = NULL;
 return (Node);
}
int search(char arr[], int strt, int end, char value) {
 int i;
 for (i = strt; i <= end; i++)
 {
 if (arr[i] == value)
 return i;
 }
 return i;
}
//to build a tree
BinaryTreeNode<char>* createTree(char in[], char pre[], int inStrt, int inEnd)
{
 static int preIndex = 0;
 if (inStrt > inEnd)
 return NULL;
 BinaryTreeNode<char>* tNode = newNode(pre[preIndex++]);
 if (inStrt == inEnd)
 return tNode;
 int inIndex = search(in, inStrt, inEnd, tNode->data);
 tNode->left = createTree(in, pre, inStrt, inIndex - 1);
 tNode->right = createTree(in, pre, inIndex + 1, inEnd);
 return tNode;
}

//Inorder Traversal
void printInorder(BinaryTreeNode<char>* node) {
 if (node == NULL)
 return;
 printInorder(node->left);
 cout<<node->data<<" ";
 printInorder(node->right);
}
//Preorder Traversal
void printPreorder(BinaryTreeNode<char> *root) {
 if(root==NULL) {
 return;
 }
 cout<<root->data<<" ";
 printPreorder(root->left);
 printPreorder(root->right);
}
//Postorder Traversal
void printPostorder(BinaryTreeNode<char> *root) {
 if(root==NULL) {
 return;
 }
 printPostorder(root->left);
 printPostorder(root->right);
 cout<<root->data<<" ";
}
//Levelwise Traversal
void printLevelWise(BinaryTreeNode<char> *root) {
 if(root == NULL){
 return;
 }
 
 queue <BinaryTreeNode<char>*> pendingNode;
 pendingNode.push(root);
 
 while(pendingNode.size() != 0){

 int size1 = pendingNode.size();
 for(int i=0;i<size1;i++){
 BinaryTreeNode<char> *front = pendingNode.front();
 pendingNode.pop();
 cout << front -> data << " ";
 if(front->left != NULL){
 pendingNode.push(front->left);
 }
 if(front -> right != NULL){
 pendingNode.push(front->right); 
 }
 }
 cout << endl;
 
 } 
 
}
void findMinMax(BinaryTreeNode<char> *node, int *min, int *max, int hd) {
 if (node == NULL) 
return;
 if (hd < *min) *min = hd;
 else if (hd > *max) *max = hd;
 findMinMax(node->left, min, max, hd-1);
 findMinMax(node->right, min, max, hd+1);
}
void printVerticalLine(BinaryTreeNode<char> *node, int line_no, int hd) {
 if (node == NULL) 
return;
 if (hd == line_no)
 cout<<node->data <<" ";
 printVerticalLine(node->left, line_no, hd-1);
 printVerticalLine(node->right, line_no, hd+1);
}

//Vertical Order Traversal 
void verticalOrder(BinaryTreeNode<char> *root)
{
 int min = 0, max = 0;
 findMinMax(root, &min, &max, 0);
 for (int line_no = min; line_no <= max; line_no++) {
 printVerticalLine(root, line_no, 0);
 cout<<endl;
 }
}
//To check Whether Tree is symmetric or not
bool isSymmetricHelper(BinaryTreeNode<char>* left_part, BinaryTreeNode<char>* 
right_part) {
 if(left_part == NULL || right_part == NULL) {
 return left_part == right_part;
 }
 if(left_part->data != right_part->data) {
 return false;
 }
 if(isSymmetricHelper(left_part->left, right_part->right) && 
isSymmetricHelper(left_part->right, right_part->left)) {
 return true;
 } 
 return false;
}
bool isSymmetric(BinaryTreeNode<char>* root) {
 if(root == NULL) 
return true;
 return isSymmetricHelper(root, root);
}
int main()
{
//Inorder and Preorder char sequence to create tree
 char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' }; 
 char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' }; 

 int len = sizeof(in) / sizeof(in[0]);
 BinaryTreeNode<char>* root = createTree(in, pre, 0, len - 1);
 int choice=0;
 
 do
 {
 cout<<"\n!!!Computation on Binary Tree!!! ";
 cout<<"\nPress 0 to Exit ";
 cout<<"\nPress 1 to print Preorder ";
 cout<<"\nPress 2 to print Inorder ";
 cout<<"\nPress 3 to print PostOrder ";
 cout<<"\nPress 4 to print Level order ";
 cout<<"\nPress 5 to print Vertical order ";
 cout<<"\nPress 6 to check Symmetric ";
 cout<<"\nEnter the choice: ";
 cin>>choice;
 
 switch(choice)
 {
 case 0:
 cout<<"\nExit from program" << endl;
 break;
 case 1: 
 cout<<"PreOrder Traversal: ";
 printPreorder(root);
 cout<<endl;
 break;
 case 2:
 cout<<endl<<"InOrder Traversal: ";
 printInorder(root);
 cout<<endl;
 break;
 case 3:
 cout<<endl<<"PostOrder Traversal: ";
 printPostorder(root);
 cout<<endl;
 break;
 case 4:

 cout<<endl<<"Level Order Traversal: "<<endl;
 printLevelWise(root); 
 break;
 case 5:
 cout<<endl<<"Vertical Order Traversal: "<<endl;
 verticalOrder(root);
 break;
 case 6:
 cout<<endl<<"Check is tree symmetric: ";
 if(isSymmetric(root)) {
 cout<<"Symmetric";
 } else {
 cout<<"Not symmetric";
 }
 cout<<endl; 
 break;
 default:
 cout<<"\nInvalid Choice!";
 break;
 }
 
 } while(choice!=0);
 return 0;
}
