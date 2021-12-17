
void main()
{
    int SIZE = 10;
    int array[10] = {1, 2, 3, 4, 5};
    int N = 5;

    DeleteElementAtPosition(array, &N, 2);
    PrintArray(array, SIZE);
}

/*
--------------------------------
- Deletion
--------------------------------
*/

void DeleteElementFromStart(int array[], int *N)
{
    for(int i =0; i < (*N)-1; i++)
    {
        array[i] = array[i+1];
    }
    (*N)--;
    array[*N] = 0;
}

void DeleteElementFromEnd(int array[], int *N)
{
    array[*N-1] = 0;
    (*N)--;
}

void DeleteElementAtPosition(int array[], int *N, int position)
{
    for(int i =position; i < (*N)-1; i++)
    {
        array[i] = array[i+1];
    }
    (*N)--;
    array[*N] = 0;
}

/*
--------------------------------
- General
--------------------------------
*/

void CreateArray(int array[], int N)
{
    printf("Please Enter the array elements:\n");
    for(int i =0; i<N; i++)
        scanf("%d", &array[i]);
}

void PrintArray(int array[], int SIZE)
{
    printf("Array Elements {");
    for(int i =0; i < SIZE; i++)
        printf("%d, ", array[i]);
    printf("}\n");
}

/*
--------------------------------
- Insertion
--------------------------------
*/

void InsertAtStart(int array[], int *N, int SIZE)
{
    int element;

    printf("Please Enter element to insert at start:\n");
    scanf("%d", &element);
    if(N == SIZE)
        printf("Overflow!");
    else
    {
        for(int i = (*N); i >0; i--)
        {
            array[i] = array[i-1];
        }
        array[0] = element;
        (*N)++;
    }

}

void InsertAtPosition(int array[], int *N, int SIZE, int position)
{
    int element;

    printf("Please Enter element to insert at %d:\n", position);
    scanf("%d", &element);
    if(N == SIZE)
        printf("Overflow!");
    else
    {
        for(int i = (*N); i >position; i--)
        {
            array[i] = array[i-1];
        }
        array[position] = element;
        (*N)++;
    }

}

void InsertAtEnd(int array[], int *N, int SIZE)
{
    int element;

    printf("Please Enter element to insert at End:\n");
    scanf("%d", &element);
    if(N == SIZE)
        printf("Overflow!");
    else
    {
        array[*N] = element;
        (*N)++;
    }

}
