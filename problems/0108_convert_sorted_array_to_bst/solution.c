/*
 * Convert Sorted Array to Binary Search Tree (LeetCode #108, Easy)
 *
 * Height-balanced BST: pick the middle element as root,
 * recursively build left and right subtrees from the halves.
 * This guarantees minimal height difference.
 */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *build(int *nums, int left, int right)
{
    if (left > right)
        return NULL;

    int mid = left + (right - left) / 2;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = build(nums, left, mid - 1);
    root->right = build(nums, mid + 1, right);
    return root;
}

/* LeetCode solution. Returns root of height-balanced BST. */
struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    return build(nums, 0, numsSize - 1);
}

static void print_preorder(struct TreeNode *root)
{
    if (!root)
        return;
    printf("%d ", root->val);
    print_preorder(root->left);
    print_preorder(root->right);
}

int main(void)
{
    int nums[] = {-10, -3, 0, 5, 9};
    struct TreeNode *root = sortedArrayToBST(nums, 5);
    printf("Preorder of constructed BST: ");
    print_preorder(root);
    printf("\n");
    return 0;
}