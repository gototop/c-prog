int array[10]={1 ,2, 3, 4, 5, 55, 8512, 151, 6161, 879};
int num = sizeof(array) / sizeof(array[0]);
int offset =  sizeof(array[0]);
int (*compare)(int a, int b);

void swap(int *_a, int *_b)
{
	int c;
	int *tem = &c;

	*tem = *_a;
	*_a = *_b;
	*_b = *tem;	
}

int ascend(int a, int b)
{
	return a > b;
}

int descend(int a, int b)
{
	return b > a;
}

void bubble(int _array[], int (*compare)(int a, int b))
{
	int i, j, tem;
	
	for(j=0;j<num-1;j++)
	{
		for(i=0;i<num-1;i++)
		{			
			if((*compare)( _array[i], _array[i+1] ))
			{
				swap( &_array[i], &_array[i+1] );
			}
		}
	}

	for(i = 0; i < num; i++)
	{
		printf("%d ", _array[i]);
	}	
	printf("\n");
}

int main()
{
	bubble(array, ascend);
	bubble(array, descend);
}
