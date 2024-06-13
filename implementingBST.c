#include<stdio.h>
#include<stdlib.h>

struct BtNode{
    int data;
    struct BtNode *left;
    struct BtNode *right;
};

struct BtNode *addNode(struct BtNode *root,int data){
    struct BtNode *newNode=(struct BtNode*)malloc(sizeof(struct BtNode));
    newNode->data=data;
    newNode->left=newNode->right=NULL;

    if(root==NULL){
        return newNode;
    }

    if(root->data<=data){
        root->right=addNode(root->right,data);
    }else{
        root->left=addNode(root->left,data);
    }
    
    return root;
}

void preOrderTraversal(struct BtNode *root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(struct BtNode *root){
    if(root==NULL) return;
    inOrderTraversal(root->left);
    printf("%d ",root->data);
    inOrderTraversal(root->right);
}

int main(){
    struct BtNode *root=NULL;
    printf("Enter nodes data for elements of BST press -1 to exit input\n");

    while(1){
        int nodeData;
        scanf("%d",&nodeData);
        if(nodeData==-1) break;
        root=addNode(root,nodeData);
    }

    printf("PreOrder Traversal : ");
    preOrderTraversal(root);
    printf("\n");
    printf("In Order Traversal : ");
    inOrderTraversal(root);

    return 0;
}