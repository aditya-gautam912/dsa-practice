/*
 * Construct Binary Tree from Preorder and Inorder Traversal (LeetCode #105, Medium)
 *
 * First element of preorder is the root. Find it in inorder —
 * elements left of it form left subtree, right of it form right
 * subtree. Recurse on both halves. Use a hash map (array since
 * values -3000..3000) for O(1) inorder index lookup.
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
static int *preorder;
static int preIndex;

struct TreeNode *build(int inStart, int inEnd)
{
    if (inStart > inEnd)
        return NULL;

    int rootVal = preorder[preIndex++];
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = rootVal;
    root->left = NULL;
    root->right = NULL;

    int inRoot = inorderMap[rootVal + OFFSET];
    root->left = build(inStart, inRoot - 1);
    root->right = build(inRoot + 1, inEnd);
    return root;
}

/* LeetCode solution. Returns root of constructed tree. */
struct TreeNode *buildTree(int *preorderArr, int preorderSize,
                            int *inorderArr, int inorderSize)
{
    preorder = preorderArr;
    preIndex = 0;

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
    int pre[] = {3, 9, 20, 15, 7};
    int in[]  = {9, 3, 15, 20, 7};
    struct TreeNode *root = buildTree(pre, 5, in, 5);
    printf("Inorder of constructed tree: ");
    print_inorder(root);
    printf("\n");
    return 0;
}