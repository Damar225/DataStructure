#define MAX 50

void main()
{
    int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
    int arows, acolumns, brows, bcolumns;

    printf("please enter the first array rows and columns\n");
    scanf("%d %d", &arows, &acolumns);
    CreateArray(a, arows, acolumns);
    Display(a, arows, acolumns);

    printf("please enter the second array rows and columns\n");
    scanf("%d %d", &brows, &bcolumns);
    CreateArray(b, brows, bcolumns);
    Display(b, brows, bcolumns);

    Product(a, arows, acolumns, b, brows, bcolumns, c);
    printf("The product of the two arrays:\n");
    Display(c, arows, bcolumns);

}

/*
---------------------------
-- Product of Two 2D Arrays
---------------------------
*/

void Product(int a[MAX][MAX], int ar, int ac, int b[MAX][MAX], int br, int bc, int c[MAX][MAX])
{
    if(ac == br)
    {
        c[ar][bc];
        for(int i =0; i< ar; i++)
        {
            for(int j =0; j<bc;j++)
            {
                for(int k =0; k<bc;k++)// k<ar
                    c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    else
    {
        printf("Product can not be done.\n");
    }
}


/*
---------------------------
-- Create Array
---------------------------
*/


void CreateArray(int array[MAX][MAX], int rows, int columns)
{
    printf("please enter each element of the array\n");
    for(int i = 0; i< rows; i++)
    {
        for(int j =0; j< columns; j++)
            scanf("%d", &array[i][j]);
    }
}

/*
---------------------------
-- Display Array
---------------------------
*/

void Display(int array[MAX][MAX], int rows, int columns)
{
    printf("{ ");
    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<columns; j++)
            printf("%d, ", array[i][j]);
        printf("\n");
    }
    printf(" }\n");
}

/*
---------------------------
-- Sum
---------------------------
*/

void Sum(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX], int rows, int columns)
{
    for(int i =0; i<rows; i++)
    {
        for(int j = 0; j<columns; j++)
            c[i][j] = a[i][j] + b[i][j];
    }
}

/*
---------------------------
-- differnce
---------------------------
*/

void Differnce(int a[MAX][MAX], int b[MAX][MAX], int c[MAX][MAX], int rows, int columns)
{
    for(int i =0; i<rows; i++)
    {
        for(int j = 0; j<columns; j++)
            c[i][j] = a[i][j] - b[i][j];
    }
}





