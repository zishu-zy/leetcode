
#include "data_define.h"

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return root;
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        if (key > root->val)
            root->right = deleteNode(root->right, key);
        if (key == root->val) {
            if (!root->left && !root->right)
                return NULL;
            if (root->left && !root->right)
                return root->left;
            if (!root->left && root->right)
                return root->right;
            TreeNode *temp = root->right;
            while (temp->left)
                temp = temp->left;
            root->val = temp->val;
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
};

TEST(Solution, leetcode)
{
    TreeNode *input;
    TreeNode *output;
    TreeNode *expected;

    // input = initListNode({1, 2, 3, 4, 5});
    // output = initListNode({1, 2, 3, 4, 5});
    // output = Solution().deleteNode(output, 2, 4);
    // expected = initListNode({1, 4, 3, 2, 5});
    // EXPECT_TRUE(isEqualListNode(output, expected))
    //     << "\ninput:   " << getString(input) << "\nouput:   " << getString(output)
    //     << "\nexpected:" << getString(expected);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
