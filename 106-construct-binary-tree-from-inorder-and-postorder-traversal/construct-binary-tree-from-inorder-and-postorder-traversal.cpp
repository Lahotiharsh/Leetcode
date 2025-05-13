class Solution {
public:
    unordered_map<int,int> map;
    int idx;

    TreeNode* BuildTree(vector<int>& inorder, vector<int>& postorder, int s, int e) {
        if(s > e) return nullptr;
        int curr = postorder[idx--];
        TreeNode* root = new TreeNode(curr);
        int id = map[curr];
        root->right = BuildTree(inorder, postorder, id + 1, e);
        root->left = BuildTree(inorder, postorder, s, id - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++) map[inorder[i]] = i;
        idx = postorder.size() - 1;
        return BuildTree(inorder, postorder, 0, inorder.size() - 1);
    }
};