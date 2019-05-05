
import java.util.*;

class Prob94 {
    // iterative
    public List<Integer> inorderTraversal(TreeNode root) {
        List <Integer> l = new ArrayList <Integer> ();
        ArrayList <TreeNode> a = new ArrayList <TreeNode> ();
        a.add(root);
        
        while (a.size() > 0) {
            TreeNode node = a.remove(0);
            //a.remove
            if (node == null)
                continue;
            if (node.left == null) {
                l.add(node.val);
                a.add(0, node.right);
                continue;
            }
            else {
                a.add(0, node.left);
                node.left = null;
                a.add(1, node);
            }
            //System.out.println(a);
    
        }
        return l;
    }
    
    /* recursive 
    public List<Integer> inorderTraversal(TreeNode root) {
        List <Integer> l = new ArrayList <Integer> ();
        recur(l, root);
        return l;
    }
    public void recur (List <Integer> l, TreeNode node) {
        if (node == null)
            return;
        recur(l,node.left);
        l.add(node.val);
        recur(l,node.right);
        
    }
    */
}