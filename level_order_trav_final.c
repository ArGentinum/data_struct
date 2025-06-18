#include <stdio.h>
#include <stdlib.h>

struct bst_node{
    struct bst_node *lchild;
    int data;
    struct bst_node *rchild;
    struct bst_node *link;
};
/*struct bst_node *queue[500];
int front=-1;
int rear=-1;
*/
struct bst_node *front=NULL,*rear=NULL,*prevnode;


void dequeue_and_output(){
    printf("%d,",front->data);
    front=front->link;
}

void enqueue(struct bst_node *root){
struct bst_node *newnode=root;

newnode->link=NULL;
if(front==NULL)
front=newnode;

else
rear->link=newnode;

rear=newnode;
}

void level_order_trav(){
if(front==NULL)
return;

else{
    if(front->lchild!=NULL)enqueue(front->lchild);
    if(front->rchild!=NULL)enqueue(front->rchild);
    dequeue_and_output();
    //printf("\n%d,",rear);
    level_order_trav();

}
}

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
    if(root==NULL)
    return;

    else {
    printf("%d,",root->data);
    preorder_trav(root->lchild);
    preorder_trav(root->rchild);
}
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
    root=insert(4,root);
    printf("preorder traversal:");
    preorder_trav(root);
    enqueue(root);
    printf("\nlevel order traversal:");
    level_order_trav();
    //printf("\n%d",rear->data);
}