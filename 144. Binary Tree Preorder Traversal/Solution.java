/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
    2
    /
   3

Output: [1,2,3]
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

class Solution {
    // Recursive method with List as returning value:
    public List<Integer> preorderTraversal1(TreeNode root) {
        List<Integer> pre = new LinkedList<Integer>();
        if(root==null) return pre;
        pre.add(root.val);
        pre.addAll(preorderTraversal(root.left));
        pre.addAll(preorderTraversal(root.right));
        return pre;
    }

    // Recursive method with Helper method to have a List as paramater, so we can modify the parameter and don't have to
    // instantiate a new List at each recursive call:
    public List<Integer> preorderTraversal2(TreeNode root) {
        List<Integer> pre = new LinkedList<Integer>();
        preHelper(root, pre);
        return pre;
    }

    public void preHelper(TreeNode root, List<Integer> pre) {
        if(root==null) return;
        pre.add(root.val);
        preHelper(root.left, pre);
        preHelper(root.right, pre);
    }

    public List<Integer> preorderTraversal3(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode curr = root;
        while(!stack.isEmpty() || curr != null) {
            if(curr != null) {
                stack.push(curr);
                result.add(curr.val);
                curr = curr.left;
            }
            else {
                curr = stack.pop();
                curr = curr.right;
            }
        }
        return result;
    }
}
