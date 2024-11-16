#include<stdio.h>
#include<stdlib.h>
typedef struct node * Tree;
/* define the tree */
struct node{
    int data;
    Tree left;
    Tree right;
};
/* define functions */
Tree Build(int a[][2],int row, int r );
void Print(Tree node);
int Search(Tree node, int num);
/* define the global variable */ 
int size=0;
/* main program*/
int main(){
    int m;
    scanf("%d",&m);
    static int a[200000][2];
    int i,j;
    /*  input part */
    for(i=0;i<m;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    /* find the index of the root node */
    for(i=0;i<m;i++){
        if(a[i][1]==-1){
            break;
        }
    }
    /* use funtions */
    Tree treeA=(Tree)malloc(sizeof(struct node));
    treeA=Build(a,m,i);
    int n;
    scanf("%d",&n);
    static int b[200000][2];
    /*  input part */
    for(i=0;i<n;i++){
        scanf("%d %d",&b[i][0],&b[i][1]);
    }
    /* find the index of the root node */
    for(i=0;i<n;i++){
        if(b[i][1]==-1){
            break;
        }
    }
     /* use funtions */
    Tree treeB=(Tree)malloc(sizeof(struct node));
    treeB=Build(b,n,i);
    int num;
    scanf("%d",&num);
    /* sort the array */
    for(i=0;i<m;i++){
        /* use select sorting */
        int min=i;
        for(j=i;j<m;j++){
            if(a[j][0]<a[min][0]){
                /* change the value of 'min' */
                min=j;
            }
        }
        int value=a[min][0];
        a[min][0]=a[i][0];
        a[i][0]=value;
    }
    /* use 'flag' to judge */
    int flag=0;
    for(i=0;i<m;i++){
        /* search num-a[i][0] in the treeB */
        if(Search(treeB,num-a[i][0])==1){
            /* judge the value of 'flag' */
            if(flag==0){
                /* change the vlaue and print 'true' */
                flag=1;
                printf("true\n");
            }
            /* make sure the results are  differernt */
            if(i==m-1 || a[i][0]!=a[i+1][0])
            /* print the result */
            printf("%d = %d + %d\n",num,a[i][0],num-a[i][0]);
        }
    }
    /* judge the value of flag */
    if(flag==0){
        printf("false\n");
    }
    /* print trees in preoder traversal*/
    size=m;
    Print(treeA);
    printf("\n");
    size=n;
    Print(treeB);
    printf("\n");
    system("pause");
}
/*  the funtion Build, variable r is the index of the root node */
Tree Build(int a[][2],int row, int r ){
    int i;
    /* create the new node */
    Tree new=(Tree)malloc(sizeof(struct node));
    new->data=a[r][0];
    new->left=NULL;
    new->right=NULL;
    for(i=0;i<row;i++){
        /* find the child nodes of the root node */
        if(a[i][1]==r){
            /* compare the data to judge its position */
            if(a[i][0]<a[r][0]){
                /* use recursive algorithm to build the tree */
                new->left=Build(a,row,i);
            }
            else if(a[i][0]>=a[r][0]){
                new->right=Build(a,row,i);
            }
        }
    }
    /* note that return the root node */
    return new;
}
/*  the funtion Print, print the tree in preorder traversal */
void Print(Tree node){
    /* judge whether the node is NULL */
    if(node==NULL){
        return ;
    }
    else{
        /* use 'size' to judge the position of the last node */
        size=size-1;
        /* print the root node firstly */
        printf("%d",node->data);
        /* aviod extra space on the end */
        if(size>0){
            printf(" ");
        }
        /* use recursive algorithm */
        Print(node->left);
        Print(node->right);
    }
}
/* the funtion Search, judge whether the 'num' is in the tree */
int Search(Tree node, int num){
    while(node){
        /* find the 'num' */
        if(node->data==num){
            return 1;
        }
        /* compare the data and change the node */
        else if(node->data<num){
           /* return the right node */
            node=node->right;
        }
        else{
           /* return the left node */
            node=node->left;
        }
    }
    /* not found */
    return 0;
}
