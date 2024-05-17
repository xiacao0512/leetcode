class Solution {
public:
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        TreeNode parent = TreeNode(0, root, nullptr);
        recursion(root, target, &parent, direction_left);
        return parent.left;
    }

private:
    void recursion(TreeNode *root, int target, TreeNode* parent, int direction)
    {
        if(root->left != nullptr) {
            recursion(root->left, target, root, direction_left);
        }

        if(root->right != nullptr) {
            recursion(root->right, target, root, direction_right);
        }

        if(root->left == nullptr && root->right == nullptr) {
            if(root->val == target) {
                if(direction == direction_left) {
                    parent->left = nullptr;
                } else if(direction == direction_right) {
                    parent->right = nullptr;
                }
            }
        }

        return;
    }

    const int direction_left = 0;
    const int direction_right = 1;
};
