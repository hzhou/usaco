//Kenneth Zhao

#include <stdio.h>



int main()
{
    FILE * In = fopen("leftout.in", "r");
    int N;
    fscanf(In, "%d", &N);
    char grid[N][N];
    for(int i=0; i<N; i++)
    {
        fscanf(In, "%s", grid[i]);
    }
    fclose(In);

    for(int i=0; i<N; i++)
    {
        if(grid[i][0]=='L')
        {
            for(int j=0; j<N; j++)
            {
                if(grid[i][j]=='L') grid[i][j]='R';
                else grid[i][j]='L';
            }
        }
    }
    for(int i=1; i<N; i++)
    {
        if(grid[0][i]=='L')
        {
            for(int j=0; j<N; j++)
            {
                if(grid[j][i]=='L') grid[j][i]='R';
                else grid[j][i]='L';
            }
        }
    }

    int count;
    for(int i=1; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(grid[i][j]=='L')
            {
                count++;
            }
        }
    }

    bool exist=true;
    int outR, outC;
    if(count==1) //one cow is facing left
    {
        for(int i=1; i<N; i++)
        {
            for(int j=1; j<N; j++)
            {
                if(grid[i][j]=='L')
                {
                    outR=i;
                    outC=j;
                    break;
                }
            }
        }
    }
    else if(count==N-1) //one row/col is facing left
    {
        bool done=false;
        for(int i=1; i<N-1; i++)
        {
            for(int j=1; j<N; j++)
            {
                if(grid[i][j]=='L')
                {
                    done=true;
                    if(grid[i+1][j]=='L')
                    {
                        outR=0;
                        outC=j;
                    }
                    else
                    {
                        outR=i;
                        outC=0;
                    }
                }
                if(done) break;
            }
            if(done) break;
        }
        if(!done)
        {
            outR=N-1;
            outC=0;
        }
    }
    else if(count==(N-1)*(N-1)) //all facing left
    {
        outR=0;
        outC=0;
    }
    else
    {
        exist=false;
    }

    FILE * Out = fopen("leftout.out", "w");
    if(!exist)
    {
        fprintf(Out, "%d\n", -1);
    }
    else
    {
        fprintf(Out, "%d %d\n", outR+1, outC+1);
    }
    fclose(Out);
}
