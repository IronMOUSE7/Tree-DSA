#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node *left, *right;
};

struct node *createnode(int val){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->val=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node *insertleft(struct node *root,int val){
    root->left=createnode(val);
    return root->left;
    
}
struct node *insertright(struct node *root,int val){
    root->right=createnode(val);
    return root->right;
}

void inordertrav(struct node *root){
    if(root==NULL){
        return;
    }
    else{
        inordertrav(root->left);
        printf("%2d",root->val);
        inordertrav(root->right);
        
    }
}

void postordertrav(struct node *root){
    if(root==NULL){
        return;
    }
    else{
        postordertrav(root->left);
        postordertrav(root->right);
        printf("%2d",root->val);
    }
}
void preordertrav(struct node *root){
    if(root==NULL){
        return ;
        
    }
    else{
        printf("%2d",root->val);
        preordertrav(root->left);
        preordertrav(root->right);
    }
}

int main(){
    struct node *root=createnode(1);
    insertleft(root,6);
    insertright(root,8);
    insertleft(root->left,3);
    insertleft(root->right,9);
    insertright(root->right,5);
    insertright(root->left,2);
    
    preordertrav(root);
    printf("\n");
    inordertrav(root);
    printf("\n");
    postordertrav(root);
    printf("\n");
    return 0;
    
}





