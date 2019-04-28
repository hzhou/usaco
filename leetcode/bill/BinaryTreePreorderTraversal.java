/*
 * LeetCode #144: Binary Tree Preorder Traversal
 */

import java.util.*;

public class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) {
		val = x;
	}
}

public class BinaryTreePreorderTraversal {
	public List<Integer> preorderTraversal(TreeNode root) {
		List<Integer> list = new ArrayList();
		Stack<TreeNode> stack = new Stack();
		TreeNode curr = root;
		while (curr != null || !stack.isEmpty()) {
			while (curr != null) {
				stack.push(curr);
				list.add(curr.val);
				curr = curr.left;
			}
			curr = stack.pop();
			curr = curr.right;
		}
		return list;
	}
}