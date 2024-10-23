#include<iostream>
#define null NULL

using namespace std;

struct Tree{
    int data;
    struct Tree *left,*right;
};


 Tree* root=null;

bool isEmpty();

void insert(int data);

Tree* insertHelper(struct Tree * root,struct Tree * newNode);

void display(int order);

void displayHelperInorder(struct Tree*root);

void displayHelperpreorder(struct Tree*root);

void displayHelperpostorder(struct Tree*root);

bool search(int data);

bool searchHelper(struct Tree*root,int data);

void deletel(int data);

Tree*deleteHelper(struct Tree*root,int data);

int succosore(struct Tree*root);

int presuccosore(struct Tree*root);

int main(){



    return 0;
}

struct Tree *newNode(int data){
    struct Tree*temp=(struct Tree *)malloc(sizeof(struct Tree));
    temp->data=data;
    temp->left=temp->right=null;
    return temp;
}

bool isEmpty(){
    if(root==null){
        return true;
    }
    return false;
}

void insert(int data){
    root=insertHelper(root,newNode(data));
}

Tree* insertHelper(struct Tree * root,struct Tree * newNode){
    if(root==null){
        root=newNode;
        return root;
    }else if(newNode->data<=root->data){
        root->left=insertHelper(root->left,newNode);
    }else if(newNode->data>root->data){
        root->right=insertHelper(root->right,newNode);
    }

    return root;
}

void display(int order){
    if(!isEmpty()){
        switch (order)
        {
        case 1:
        cout<<endl;
            displayHelperInorder(root);
            break;
        case 2:
        cout<<endl;
            displayHelperpostorder(root);
            break;
        case 3:
        cout<<endl;
            displayHelperpreorder(root);
            break;
        default:
            cout<<"\nWrong Input!Try again.\n";
            break;
        }
    }else{
        cout<<"\nNo Tree.\n";
    }
}

void displayHelperInorder(struct Tree*root){
    if(root==null){
        return;
    }else{
        displayHelperInorder(root->left);
        cout<<root->data;
        displayHelperInorder(root->right);
    }
}

void displayHelperpreorder(struct Tree*root){
    if(root==null){
        return;
    }else{
        cout<<root->data;
        displayHelperpreorder(root->left);
        displayHelperpreorder(root->right);
    }
}

void displayHelperpostorder(struct Tree*root){
    if(root==null){
        return;
    }else{
        displayHelperpostorder(root->left);
        displayHelperpostorder(root->right);
        cout<<root->data;
    }
}

bool search(int data){
    if(isEmpty()){
        return false;
    }else{
        return searchHelper(root,data);
    }
}

bool searchHelper(struct Tree*root,int data){
    if(root->data==data){
        return true;
    }else if(root->data<data){
        return searchHelper(root->left,data);
    }else if(root->data>data){
        return searchHelper(root->right,data);
    }
    return false;
}

void deletel(int data){
    if(search(data)){
        deleteHelper(root,data);
    }else{
        cout<<"\nNo Tree.\n";
    }
}

struct Tree*deleteHelper(struct Tree*root,int data){
    if(root==null){
        return root;
    }else if(root->data<data){
        root->left=deleteHelper(root->left,data);
    }else if(root->data>data){
        root->right=deleteHelper(root->right,data);
    }else{//Node Found
        if(root->left==null&&root->right==null){
            root=null;
        }
        
        if(root->right!=null){
            root->data=succosore(root->right);
            root->right=deleteHelper(root->right,root->data);
        }
        if(root->left!=null){
            root->data=presuccosore(root->left);
            root->left=deleteHelper(root->left,root->data);
        }
    }

    return root;
}

int succosore(struct Tree*root){
    if(root->left==null){
        return root->data;
    }else{
        succosore(root->left);
    }
    return -1;
}

int presuccosore(struct Tree*root){
    if(root->right==null){
        return root->data;
    }else{
        presuccosore(root->right);
    }
    return -1;
}