##  二叉树
### 定义：
二叉树（Binary Tree） 是一种树型结构，特点是每个节点至多只有两棵子树（即二叉树中不存在度大于2的结点），并且，二叉树的子树有左右之分，其次序不能任意颠倒。
### 代码： 
```C++
 Definition for a binary tree node.
   struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode() : val(0), left(nullptr), right(nullptr) {}
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
   };
   ```
   ### 二叉树的性质

   #### 性质1：

    在二叉树的第i层上至多有 2^(i-1) 个结点（i>=1）

   #### 性质2：

   深度为k的二叉树至多有2^k-1个结点，（k>=1）.

   ### 二叉树的遍历方法——前、中、后序遍历
   #### 前序遍历（NLR）

   ##### 递归版本

   若二叉树为空，什么都不做，否则：

    1. 先访问根结点；

    2. 再前序遍历左子树；

    3. 最后前序遍历右子树；
代码：
```C++
void preorder(vector<int> &ans,TreeNode* root){
    if(root==NULL) return;
    ans.push_back(root->val);
    preorder(ans,root->left);
    preorder(ans,root->right);
}
```
##### 迭代版本（待补充）

#### 中序遍历

##### 递归版本

若二叉树为空，什么都不做，否则：

    1. 先中序遍历左子树；

    2. 再访问根结点；

    3. 最后中序遍历右子树；
代码：
```C++
void inorder(vector<int> &ans  ,TreeNode* root){
    if(root==NULL) return;
    inorder(ans,root->left);
    ans.push_back(root->val);
    inorder(ans,root->right);
}
```
##### 迭代版本（待补充）

#### 后序遍历

##### 递归版本

若二叉树为空，什么都不做，否则：

    1. 先后序遍历左子树；

    2. 再后序遍历右子树；

    3. 最后访问根结点；
代码：
```C++
void postorder(vector<int> &ans  ,TreeNode* root){
    if(root==NULL) return;
    postorder(ans,root->left);
    postorder(ans,root->right);
    ans.push_back(root->val);
}
```
##### 迭代版本（待补充）

### 待补充问题

#### 如何快速在每种遍历中找到前驱和后继？