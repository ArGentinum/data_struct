
#include <stdio.h>
#include <stdlib.h>

struct bst_node{
    struct bst_node *lchild;
    int data;
    struct bst_node *rchild;
};

int fin_height=0,height=0;


struct bst_node *create(int data,struct bst_node *root){
root=(struct bst_node*)malloc(sizeof(struct bst_node));
root->data=data;
root->lchild=NULL;
root->rchild=NULL;
return root;
}

struct bst_node *insert(int data,struct bst_node *root){
if(root==NULL){
root=create(data,root);
return root;
}

else if(data>root->data)
root->rchild=insert(data,root->rchild);

else if(data<root->data)
root->lchild=insert(data,root->lchild);

return root;
}

void preorder_trav(struct bst_node *root){
    if(root==NULL){
    if(fin_height<height)
    fin_height=height;
    return;
    }

    else {
    //printf("%d,",root->data);
    if(root->lchild!=NULL)
    ++height;

    preorder_trav(root->lchild);

    if(root->rchild!=NULL)
    ++height;

    preorder_trav(root->rchild);
}
--height;
}

void main(){
    struct bst_node *root=NULL;
    root=insert(10,root);
    root=insert(20,root);
    root=insert(30,root);
    root=insert(5,root);
    root=insert(6,root);
    root=insert(25,root);
    root=insert(31,root);
root=insert(40,root);
root=insert(45,root);
    
    preorder_trav(root);
    printf("%d",fin_height);
}