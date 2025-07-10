#include <stdio.h>
#include <stdlib.h>

struct bst_node{
    struct bst_node *lchild;
    int data;
    struct bst_node *rchild;
};

int stack[100],height=0,top=-1;
struct bst_node *queue[500];
int front=-1;
int rear=-1;

void push_and_sort(int data){
    if(top==-1){
        ++top;
        stack[top]=data;
    }


    else{
        if(data>stack[top]){
            ++top;
            stack[top]=data;
        }

        else{
            int temp=stack[top];
            stack[top]=data;
            ++top;
            stack[top]=temp;
        }
    }
}

void dequeue_and_output(){
    if(queue[front]==NULL)
    ++front;

    else{
    printf("%d,",queue[front]->data);
    ++front;
    }
}

void enqueue(struct bst_node *root){
if(front==-1)
++front;

++rear;
queue[rear]=root;
}

void level_order_trav(){
if(front>rear)
return;

else{
    if(queue[front]->lchild!=NULL)enqueue(queue[front]->lchild);
    if(queue[front]->rchild!=NULL)enqueue(queue[front]->rchild);
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
    if(root==NULL){
    push_and_sort(height);
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
    preorder_trav(root);
    enqueue(root);
    printf("\n");
    level_order_trav();
    printf("\n%d",rear);
    printf("%d",stack[top]);
}