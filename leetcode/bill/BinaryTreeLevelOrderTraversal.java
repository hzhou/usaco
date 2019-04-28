/*
 * LeetCode #102: Binary Tree Level Order Traversal
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

class BinaryTreeLevelOrderTraversal {
	public List<List<Integer>> levelOrder(TreeNode root) {
		if (root == null) return new ArrayList();
		List<List<Integer>> list = new ArrayList();
		Queue <TreeNode> queue = new LinkedList();
		queue.add(root);
		TreeNode curr;
		while (!queue.isEmpty()) {
			List<Integer> level = new ArrayList();
			int nodes = queue.size();
			for (int i = 0; i < nodes; i++) {
				curr = queue.poll();
				level.add(curr.val);
				if (curr.left != null) {
					queue.add(curr.left);
				}
				if (curr.right != null) {
					queue.add(curr.right);
				}
			}
			list.add(level);
		}
		return list;
	}
}