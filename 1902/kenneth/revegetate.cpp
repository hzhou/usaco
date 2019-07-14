#include <stdio.h>

int main()
{
    FILE * In = fopen("revegetate.in", "r");
    int N, M;
    fscanf(In, "%d %d", &N, &M);
    int field[N+1];
    int P[M], Q[M];
    for(int i=0; i<M; i++)
    {
        fscanf(In, "%d %d", &P[i], &Q[i]);
        if(P[i]>Q[i])
        {
            int k=P[i];
            P[i]=Q[i];
            Q[i]=k;
        }
    }
    fclose(In);

    for(int i=1; i<=N; i++) //One field at a time
    {
        int type;
        for(int j=1; j<=4; j++) //Find smallest possible type for that field
        {
            bool viable=true;
            for(int k=0; k<M; k++)
            {
                if(Q[k]==i&&field[P[k]]==j) //Checks if current field must differ from a previous field
                {
                    viable=false;
                }
            }
            if(viable)
            {
                type=j;
                break;
            }
        }
        field[i]=type;
    }

    FILE * Out = fopen("revegetate.out", "w");
    for(int i=1;i<=N; i++)
    {
        fprintf(Out, "%d", field[i]);
    }
    fprintf(Out, "\n");
    fclose(Out);
}
