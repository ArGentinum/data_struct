#include <Stdio.h>
#include <stdlib.h>

struct bst_node{
struct bst_node *lchild;
int data;
struct bst_node *rchild;
};

struct bst_node *create(struct bst_node *root,int data){
root=(struct bst_node*)malloc(sizeof(struct bst_node));
root->data=data;
root->lchild=NULL;
root->rchild=NULL;
return root;
}

struct bst_node *insert(struct bst_node *root,int data){
if (root==NULL){
    root=create(root,data);
}

else if(data<=root->data){
    root->lchild=insert(root->lchild,data);
}

else
root->rchild=insert(root->rchild,data);

return root;
}

void preorder_trav(struct bst_node *root){
if (root==NULL)
return;

else{
    printf("%d,",root->data);
    preorder_trav(root->lchild);
    preorder_trav(root->rchild);
}
}

void postorder_trav(struct bst_node *root){
if(root==NULL)
return;

else{
    postorder_trav(root->lchild);
    postorder_trav(root->rchild);
    printf("%d,",root->data);
}
}

void inorder_trav(struct bst_node *root){
if(root==NULL)
return;

else{
    inorder_trav(root->lchild);
    printf("%d,",root->data);
    inorder_trav(root->rchild);
}

}

void main(){
    struct bst_node *root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,1);
    root=insert(root,15);
    root=insert(root,9);
    root=insert(root,5);
    root=insert(root,30);
    inorder_trav(root);
    puts("\n");
    postorder_trav(root);
    puts("\n");
    preorder_trav(root);
}