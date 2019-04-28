/*
 * LeetCode #94: Binary Tree Inorder Traversal
 */

import java.util.*;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) {
		val = x;
	}
}

public class BinaryTreeInOrderTreeTraversal {
	public List<Integer> inorderTraversal(TreeNode root) {
		List<Integer> list = new ArrayList();
		Stack <TreeNode> stack = new Stack();
		TreeNode curr = root;
		while (curr != null || stack.size() != 0) {
			while (curr != null) {
				stack.push(curr);
				curr = curr.left;
			}
			curr = stack.pop();
			list.add(curr.val);
			curr = curr.right;
		}
		return list;
	}
}
