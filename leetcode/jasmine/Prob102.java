import java.util.*;
class Prob102 {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> a =  new ArrayList<List<Integer>> (); 
        List<List<TreeNode>> tList =  new ArrayList<List<TreeNode>> (); 
        if (root == null)
            return a;
        a.add(new ArrayList <Integer> ());
        a.get(0).add(root.val);
        tList.add(new ArrayList <TreeNode> ());
        tList.get(0).add(root);
       
        int current = 0;
        while (true) {
            a.add(new ArrayList <Integer> ());
            tList.add(new ArrayList <TreeNode> ());
            for (TreeNode n : tList.get(current)) {
                if (n.left != null) {
                    a.get(current+1).add(n.left.val);
                    tList.get(current+1).add(n.left);
                }
                if (n.right != null) {
                    a.get(current+1).add(n.right.val);
                    tList.get(current+1).add(n.right);
                }
                
            }
            //System.out.println(a);
            if (a.get(current+1).size() == 0) {
                a.remove(current+1);
                break;
            }
            current++;
        }
        
        return a;
    }
}