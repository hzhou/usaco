/*
 * LeetCode #145: Binary Tree Postorder Traversal
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

public class BinaryTreePostorderTraversal {
	public List<Integer> postorderTraversal(TreeNode root) {
		LinkedList<Integer> list = new LinkedList<>();
		Stack<TreeNode> stack = new Stack();
		TreeNode curr = root;
		while (curr != null || !stack.isEmpty()) {
			if (curr != null) {
				stack.push(curr);
				list.addFirst(curr.val);
				curr = curr.right;
			} else {
				curr = stack.pop();
				curr = curr.left;
			}
		}
		return list;
	}
}