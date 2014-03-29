double array[10]={1 ,2, 3, 4, 5, 55, 8512, 151, 6161, 879};
int num = sizeof(array) / sizeof(array[0]);
int (*compare)(void *a, void *b);

union number{
	int inte;
	double doub;
};

#define SWAP_IMPL(type, a, b) \
	int c; \
	void *tem = &c; \
	*((type *) tem) = *((type *) a); \
	*((type *) a) = *((type *) b); \
	*((type *) b) = *((type *) tem);

void swap(void *_a, void *_b, int size)
{
	if(size==4)
	{
		SWAP_IMPL(int, _a, _b)
	}else if(size==8)
	{
		SWAP_IMPL(double, _a, _b)
	}
}
#undef SWAP_IMPL

int ascend(void *a, void *b)
{
	if(sizeof(array[0])==4){
		return *((int*)a) > *((int*)b);	
	}else if(sizeof(array[0])==8){
		return *((double*)a) > *((double*)b);
	}
}

int descend(void *a, void *b)
{
	if(sizeof(array[0])==4){
		return *((int*)a) < *((int*)b);	
	}else if(sizeof(array[0])==8){
		return *((double*)a) < *((double*)b);
	}
}

void bubble(void *_array, int (*compare)(void *a, void *b), int size)
{
	int i, j;
	union number *value;
	value = _array;

	for(j=0;j<num-1;j++)
	{
		for(i=0;i<num-1;i++)
		{			
			if((*compare)( _array + size*i, _array + size*(i+1)))
			{
				swap( _array + size*i, _array + size*(i+1), size );
			}
		}
	}

	if(size==4){
		for(i = 0; i < num; i++)
		{
			value->inte = *((int *)_array + i);
			printf("%d ", value->inte );
		}	
	}else if(size==8){
		for(i = 0; i < num; i++)
		{
			value->doub = *((double *)_array + i);
			printf("%f ", value->doub );
		}
	}
	
	printf("\n");
}

int main()
{
	bubble(&array, ascend, sizeof(array[0]));
	bubble(&array, descend, sizeof(array[0]));
}
