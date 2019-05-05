import java.util.*;


  //Definition for a binary tree node.
  class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
  }

class Prob144 {
    //iterative
    public List<Integer> preorderTraversal(TreeNode root) {
    List <Integer> l = new ArrayList <Integer> ();
        Stack <TreeNode> s = new Stack <TreeNode> ();
        s.push(root);
        while (!s.isEmpty()) {
            TreeNode node = s.pop();
            if (node == null)
                continue;
            l.add(node.val);
            s.push(node.right);
            s.push(node.left);
        }
        return l;
    }
    
    //recursive
    /*
    public List<Integer> preorderTraversal(TreeNode root) {
        List <Integer> l = new ArrayList <Integer> ();
        recur(l, root);
        return l;
    }
    public void recur (List <Integer> l, TreeNode node) {
        if (node == null)
            return;
        l.add(node.val);
        recur(l,node.left);
        recur(l,node.right);
        
    }
    */
}