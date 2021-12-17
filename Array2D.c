int array[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int m = sizeof(array)/sizeof(array[0]);
int n = sizeof(array[0])/sizeof(int);

void main()
{
    Display(array, m, n);
}

/*
---------------------------
-- Display
---------------------------
*/

void Display(int array[m][n])
{
    printf("{ ");
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
            printf("%d, ", array[i][j]);
        printf("\n");
    }
    printf(" }");
}

/*
---------------------------
-- Sum
---------------------------
*/

void Sum(int array1[m][n], int array2[m][n], int array3[m][n])
{
    for(int i =0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
            array3[i][j] = array1[i][j] + array2[i][j];
    }
}

/*
---------------------------
-- differnce
---------------------------
*/

void Differnce(int array1[m][n], int array2[m][n], int array3[m][n])
{
    for(int i =0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
            array3[i][j] = array1[i][j] - array2[i][j];
    }
}
