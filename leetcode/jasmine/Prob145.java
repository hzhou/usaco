
import java.util.*;
class Prob145 {
    // iterative
    
    public List<Integer> postorderTraversal(TreeNode root) {
        List <Integer> l = new ArrayList <Integer> ();
        ArrayList <TreeNode> a = new ArrayList <TreeNode> ();
        a.add(root);
        
        while (a.size() > 0) {
            TreeNode node = a.remove(0);
            //a.remove
            if (node == null)
                continue;
            
            if  (node.left != null) {
                a.add(0, node.left);
                node.left = null;
                a.add(1, node);
            }
            else if (node.right != null) {
                a.add(0, node.right);
                node.right = null;
                a.add(1, node);
            }
            else {
                l.add(node.val);
            }
            //System.out.println(a);
    
        }
        return l;
    }
    
    // recursive 
    /*
    public List<Integer> postorderTraversal(TreeNode root) {
        List <Integer> l = new ArrayList <Integer> ();
        recur(l, root);
        return l;
    }
    public void recur (List <Integer> l, TreeNode node) {
        if (node == null)
            return;
        recur(l,node.left);
        recur(l,node.right);
        l.add(node.val);
        
        
    }
    */
    
}