class Prob64 {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int [][] total = new int [m][n];
        findSum(m,n,0,0,grid[0][0], total, grid);
        return(total[m-1][n-1]);
        
    }
    public void findSum (int m, int n, int i, int j, int cost, int [][] total, int [][] grid) {
        if (total[i][j] != 0 && cost >= total[i][j])
            return;
        total[i][j] = cost;
        //System.out.println(i + " " + j);
        //System.out.println(total[i][j]);
        if (i+1 != m) {
            findSum(m,n,i+1,j,cost+grid[i+1][j], total, grid);
        }
        if (j+1 != n) {
            findSum(m,n,i,j+1,cost+grid[i][j+1], total, grid);
        }
    }
}