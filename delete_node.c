#include <stdio.h>
#include <stdlib.h>
 
struct bst_node{
    struct bst_node *lchild;
    int data;
    struct bst_node *rchild;
};

int min_data;

struct bst_node* find_min_and_delete(struct bst_node *root){
    if(root->lchild==NULL){
        min_data=root->data;
        if(root->rchild!=NULL){
        struct bst_node *temp=root->rchild;
        free(root);
        return temp;
        }
        free(root);
        return NULL;
    }

    else {
        root->lchild=find_min_and_delete(root->lchild);
    }
    return root;
    //return NULL;

}

struct bst_node *delete(struct bst_node *root){
    if(root->lchild==NULL&&root->rchild==NULL){
            free(root);
            return NULL;
        }

        //ELSE IF BLOCK TO BE CHANGED 
        else if(root->lchild!=NULL&&root->rchild==NULL||root->lchild==NULL&&root->rchild!=NULL){
            struct bst_node *temp;
            if(root->lchild==NULL){
                temp=root->rchild;
            }

            else if(root->rchild==NULL){
                temp=root->lchild;
            }

            free(root);
            return temp;
        }
        

        else if(root->lchild!=NULL&&root->rchild!=NULL){
            root->rchild=find_min_and_delete(root->rchild);
            root->data=min_data;
            return root;
             }
    }


struct bst_node *create(struct bst_node *root,int data){
root=(struct bst_node*)malloc(sizeof(struct bst_node));
root->data=data;
root->rchild=NULL;
root->lchild=NULL;
return root;
}

struct bst_node *insert(struct bst_node *root,int data){
if(root==NULL){
root=create(root,data);
return root;
}

else if(data>root->data)
root->rchild=insert(root->rchild,data);

else if(data<root->data)
root->lchild=insert(root->lchild,data);

return root;
}

void preorder_trav(struct bst_node *root){
if(root==NULL)
return;

else{
    printf("%d,",root->data);
    preorder_trav(root->lchild);
    preorder_trav(root->rchild);
}
}

struct bst_node *search(struct bst_node *root,int key){
    if(root==NULL){
    printf("%d not found int the bst!",key);return NULL;}

    else if(root->data==key)
    root=delete(root);

    else if(key>root->data)
    root->rchild=search(root->rchild,key);

    else if (key<root->data)
    root->lchild=search(root->lchild,key);

return root;
}


void main(){
struct bst_node *root=NULL;
int key;
root=insert(root,20);
root=insert(root,30);
root=insert(root,10);
root=insert(root,40);
root=insert(root,0);
root=insert(root,57);
root=insert(root,27);
root=insert(root,12);
root=insert(root,15);
root=insert(root,6);
root=insert(root,11);
root=insert(root,60);
root=insert(root,39);
preorder_trav(root);
printf("\n enter the element to delete in the existing rbt:");
scanf("%d",&key);
search(root,key);
puts("\nbst after deletion:");
preorder_trav(root);

//printf("\n%d",min_data);
}