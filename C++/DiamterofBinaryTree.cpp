#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};
 
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
 
    return node;
}
 
void display(Node * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<"  ";
    display(root->left);
    display(root->right);
}
int height(Node * root){
    if(root==NULL)
    return -1;

    return max(height(root->left),height(root->right))+1;
}

int diameterOfTree(Node * root){

    if(root==NULL){
        return 0;
    }
    int ld=diameterOfTree(root->left);
    int rd=diameterOfTree(root->right);

    int diaFromMid=height(root->left)+height(root->right)+2;

    return max(ld,max(rd,diaFromMid));


}


struct Node* constructBST(int preorder[], int start, int end)
{

    if (start > end) {
        return NULL;
    }
 
      struct Node* node = newNode(preorder[start]);
 
    int i;
    for (i = start; i <= end; i++)
    {
        if (preorder[i] > node->data) {
            break;
        }
    }
 
   
    node->left = constructBST(preorder, start + 1, i - 1);
 
  
    node->right = constructBST(preorder, i, end);
 
    
    return node;
}
 
int main(void)
{
   
    int preorder[] = { 15, 10, 8, 12, 20, 16, 25 };
    int n = sizeof(preorder)/sizeof(preorder[0]);
 
   
    struct Node* root = constructBST(preorder, 0, n - 1);
 
   //display(root);
   
  int t= height(root);
  int j=diameterOfTree(root);
  cout<<"Height"<<t<<endl;
  cout<<"dia"<<j;
    //display(newroot);
    
    return 0;
}