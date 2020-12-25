#include<stdio.h>

#define rol 70
#define col 25  
int main()
{

    int i, j, size, ch, base, lr, lc, address;

    printf("\nEnter the coordinates of the point you wanna calculate address of:");
    printf("\nEnter the i:");
    scanf("%d",&i);
    printf("\nEnter the j:");
    scanf("%d",&j);
    printf("\nEnter base address: ");
    scanf("%d",&base);
    printf("\nEnter LR: ");
    scanf("%d",&lr);
    printf("\nEnter LC: ");
    scanf("%d",&lc);
    printf("\nEnter Size: ");
    scanf("%d",&size);
    
    

    printf("\nRow Major / Column Major (0/1)");
    scanf("%d",&ch);
    
            switch (ch)
            {
            case 0:
                printf("\n*****ADDRESS CALCULATION USING ROW MAJOR FORMULA*****\n");
                printf("\nFORMULA: Address of ARR[i][j] = BASE ADDRESS + SIZE[COL * (i-lr) + (j-lc)]\n");

                printf("\nBASE ADDRESS:  %d",base);
                printf("\nAddress of ARR[%d][%d] = BASE ADDRESS + %d[%d*(%d-%d) + (%d-%d)]",i,j,size,col,i,lr,j,lc);
                address=base + size*((col * (i-lr)) + (j-lc));
                printf("\nAddress of ARR[%d][%d] = %d",i,j,address);

            
            case 1:
                printf("\n*****ADDRESS CALCULATION USING COLUMN MAJOR FORMULA*****\n");
                printf("\nFORMULA: Address of ARR[i][j] = BASE ADDRESS + SIZE[ROL * (j-lc) + (i-lr)]\n");

                printf("\nBASE ADDRESS:  %d",base);
                printf("\nAddress of ARR[%d][%d] = BASE ADDRESS + %d[%d*(%d-%d) + (%d-%d)]",i,j,size,rol,j,lc,i,lr);
                address=(int)base + size*((rol * (j-lc)) + (i-lr));

                printf("\nAddress of ARR[%d][%d] = %d",i,j,address);

                break;

            default:
                break;
            }
        
return 0;
}