#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    int size;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr),size(1){}
};
TreeNode* insert(TreeNode* root,int val){
    if(root==nullptr){
        return new TreeNode(val);
    }
    else if(val < root->val){
        root->left=insert(root->left,val);
    }
    else if(val > root->val){
        root->right=insert(root->right,val);
    }
    root->size=0;
    if(root->left)root->size+=root->left->size;
    if(root->right)root->size+=root->right->size;
    root->size+=1;
    return root;
}
int ran_k(TreeNode* root,int x){
    int ans=0;
    while(root){
        if(x <= root->val){
            root=root->left;
        }
        else{
            if(root->left)ans+=root->left->size;
            ans++;
            root=root->right;
        } 
    }
    return ans+1;
}
void in_order(TreeNode* root){
    if(root==nullptr)return;
    in_order(root->left);
    cout<<root->val<<' ';
    in_order(root->right);
}
TreeNode* search(TreeNode* root,int val){
    if(root == nullptr)return nullptr;
    if(val < root->val){
        return search(root->left,val);
    }
    else if(val > root->val){
        return search(root->right,val);
    }
    else return root;
}
int height(TreeNode* root){
    if(root == nullptr)return 0;
    else return max(height(root->left),height(root->right))+1;
}

TreeNode* pre(TreeNode* root,int x){
    TreeNode* cand=nullptr;
    while(root != nullptr){
        if(x < root->val){
            root=root->left;
        }
        else{
            cand=root;
            root=root->right;
        }
    }
    return cand;
}
int main(){
    TreeNode* root = nullptr;

    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 13);

    in_order(root);
    TreeNode *p=search(root,7);
    cout<<p<<endl;
    cout<<p->val<<endl;
    cout<<ran_k(root,7)<<endl;
    return 0;
}