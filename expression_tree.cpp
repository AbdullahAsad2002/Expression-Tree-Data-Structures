#include<iostream>
using namespace std;
#include<cstring>
struct ETNode
{
    char ch;
   struct ETNode *RC,*LC;
};
int isOperator(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c=='/' || c=='%')
    {
        return 2;
    }
    else if (c == '+' || c=='-')
    {
        return 1;
    }
    else if (c == '(' || c==')')
    {
        return -1;
    }
    else
    {
        return 0;
    }  
}
ETNode* expressionTree(char *postfix,ETNode** root)
{   
    // ETNode* root=NULL;
    ETNode* stack[10];
    int top = -1;
    for (int i = 0; i < strlen(postfix); i++)
    {
        struct ETNode *temp = new ETNode();
        temp->ch = postfix[i];
        temp->LC = NULL;
        temp->RC = NULL;
        if (isOperator(postfix[i]) == 0)
        {
            stack[++top] = temp;
        }
        else
        {
            temp->RC = stack[top--];
            temp->LC = stack[top--];
            stack[++top] = temp;
        }
    }
        *root = stack[top--];
        return *root;
}
// void InOrder(ETNode* node)
// {   
//     cout<<"(";
//     if (node->LC != NULL)
//     {
//         InOrder(node->LC);
//     }
//     cout<<node->ch;
//         if (node->RC != NULL)
//     {
//         InOrder(node->RC);
//     }
//     cout<<")";
// }
// void postorder(struct ETNode *root) {
//    if (root != NULL) {
//       postorder(root->LC);
//       postorder(root->RC);
//       cout<<root->ch<<" ";
//    }
// }
// void preorder(struct ETNode *root) {
//    if (root != NULL) {
//       cout<<root->ch<<" ";
//       postorder(root->LC);
//       postorder(root->RC);
//    }
// }
// Preorder traversal
void preorderTraversal(struct ETNode* node) {
  if (node == NULL)
    return;

  cout << node->ch << " ";
  preorderTraversal(node->LC);
  preorderTraversal(node->RC);
}

// Postorder traversal
void postorderTraversal(struct ETNode* node) {
  if (node == NULL)
    return;

  postorderTraversal(node->LC);
  postorderTraversal(node->RC);
  cout << node->ch << " ";
}

// Inorder traversal
void inorderTraversal(struct ETNode* node) {
  if (node == NULL)
    return;

  cout<<"(";
  inorderTraversal(node->LC);
  cout << node->ch << " ";
  inorderTraversal(node->RC);
  cout<<")";
}
int main()
{   
    ETNode * root=NULL;
   char postfix[]="ab+cd-*";
   expressionTree(postfix,&root);
//    cout<<root<<endl;
   inorderTraversal(root);
   cout<<endl;
   postorderTraversal(root);
   cout<<endl;
   preorderTraversal(root);
   cout<<endl;
//    InOrder(root);
    return 0;
}
//             *
//         +        -
//     a      b  c     d

// *in{
//     +in{
//         ain{

//         }
//     }
// }
// *+ab-cd 
