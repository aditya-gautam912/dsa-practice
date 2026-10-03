/*
 * Construct Binary Tree from Inorder and Postorder Traversal (LeetCode #106, Medium)
 *
 * Last element of postorder is the root. Find it in inorder —
 * left part is left subtree, right part is right subtree.
 * Recurse on right subtree FIRST (since we're reading postorder
 * backwards), then left subtree. Use hash map for O(1) index lookup.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VAL_RANGE 6001
#define OFFSET 3000

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int *inorderMap;
static int *postorder;
static int postIndex;

struct TreeNode *build(int inStart, int inEnd)
{
    if (inStart > inEnd)
        return NULL;

    int rootVal = postorder[postIndex--];
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = NULL;
    root->right = NULL;

    int inRoot = inorderMap[rootVal + OFFSET];

    /* Build right subtree FIRST (postorder reads root-right-left) */
    root->right = build(inRoot + 1, inEnd);
    root->left = build(inStart, inRoot - 1);

    return root;
}

/* LeetCode solution. Returns root of constructed tree. */
struct TreeNode *buildTree(int *inorderArr, int inorderSize,
                            int *postorderArr, int postorderSize)
{
    postorder = postorderArr;
    postIndex = postorderSize - 1;

    inorderMap = (int *)malloc(VAL_RANGE * sizeof(int));
    memset(inorderMap, -1, VAL_RANGE * sizeof(int));
    for (int i = 0; i < inorderSize; i++)
        inorderMap[inorderArr[i] + OFFSET] = i;

    return build(0, inorderSize - 1);
}

static void print_inorder(struct TreeNode *root)
{
    if (!root)
        return;
    print_inorder(root->left);
    printf("%d ", root->val);
    print_inorder(root->right);
}

int main(void)
{
    int in[]   = {9, 3, 15, 20, 7};
    int post[] = {9, 15, 7, 20, 3};
    struct TreeNode *root = buildTree(in, 5, post, 5);
    printf("Inorder of constructed tree: ");
    print_inorder(root);
    printf("\n");
    return 0;
}