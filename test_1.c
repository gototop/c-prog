int a[10]={1 ,2, 3, 4, 5, 55, 8512, 151, 6161, 879};
int num = sizeof(a) / sizeof(a[0]);
void swap(int *_a, int *_b)
{
	int c;	
	int *tem = &c;
	
	*tem = *_a;
	*_a = *_b;
	*_b = *tem;	
}

int main()
{
	int i, j, tem;
	
	for(j=0;j<num-1;j++)
	{
		for(i=0;i<num-1;i++)
		{			
			if(a[i]>a[i+1])
			{
				swap(&a[i], &a[i+1]);
			}
		}
	}

	for(i=0;i<num;i++)
	{
		printf("%d ", a[i]);
	}	

	printf("\n");
	return 0;
}
