#include <stdio.h>
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
    return root;
}

else if(data<root->data)
root->lchild=insert(root->lchild,data);

else if(data>root->data)
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


void search(struct bst_node *root,int data){
    if (root==NULL){
        printf("\nelement not found in the bst!");
        return;
    }

    else if(root->data==data){
        printf("\nelement found in the bst!");
        return;
    }

    else if(data>root->data)
    search(root->rchild,data);

else if(data<root->data)
search(root->lchild,data);
}


void main(){
    struct bst_node *root=NULL;
    int key;
    root=insert(root,20);
    root=insert(root,50);
    root=insert(root,1);
    root=insert(root,27);
    root=insert(root,90);
    root=insert(root,5);
    root=insert(root,10);
    root=insert(root,0);
    preorder_trav(root);
    printf("\nenter the element to search in the bst:");
    scanf("%d",&key);
    search(root,key);

}

