#include <stdio.h>
#include <stdlib.h>

struct bst_node{
    struct bst_node *lchild;
    int data;
    struct bst_node *rchild;
};

struct bst_node *queue[100],*prevnode;
int front=-1,rear=-1;


void enqueue(struct bst_node *temp){
if(rear==100){//queue is full
printf("queue is full!");
}

else{
    if(front==-1)
    ++front;

++rear;
queue[rear]=temp;
}
}

void dequeue_and_output(){
if(front==-1||front>rear)
printf("no elements in the queue to dequeue!");

else{
    struct bst_node *temp=queue[front];
printf("%d,",temp->data);
++front;
}
}

void level_order_trav(struct bst_node *root){
 if(front==rear&&queue[front]==NULL&&queue[rear]==NULL)
 return;

else{
    if(queue[front]==NULL){
        ++front;
        level_order_trav(queue[front]);
    }

    else{
        enqueue(root->lchild);
        enqueue(root->rchild);
        dequeue_and_output();
        level_order_trav(queue[front]);
    }
}


}
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

struct bst_node *find_min(struct bst_node *root){
if(root==NULL)
return prevnode;

else{
    prevnode=root;
    root=find_min(root->lchild);
}
return root;
}



struct bst_node *find_max(struct bst_node *root){
    if(root==NULL)
    return prevnode;

else{
    prevnode=root;
    root=find_max(root->rchild);
}
return root;
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
    root=insert(root,-1);
    root=insert(root,-2);
    root=insert(root,87);
    root=insert(root,100);
    root=insert(root,-59);
    root=insert(root,500);
    /*
    preorder_trav(root);
    
    printf("\nenter the element to search in the bst:");
    scanf("%d",&key);
    search(root,key);
    
    enqueue(root);
    puts("\n");
    level_order_trav(root);
    */
    struct bst_node *minnode=find_min(root);
    struct bst_node *maxnode=find_max(root);

    printf("\nmin element in the bst is:%d",minnode->data);
    printf("\nmax element in the bst is:%d",maxnode->data);
}

