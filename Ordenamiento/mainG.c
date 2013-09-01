#include <stdio.h>

int cmp(void *data1,void *data2){
	return *((int*)data1)-*((int*)data2);
}

#define NELEMS(a) (sizeof((a))/sizeof(int))

int main(void){	
	int i,sz;
	int arr[] = { 2, 4, 1, 3, 7, 8, 6 };
	sz = NELEMS(arr);	
	void *arr_ptr[sz];
	for(i = 0; i < sz; i++ )
		arr_ptr[i] = &arr[i];

	bsortg(arr_ptr,sz,cmp);

	for(i = 0; i < sz; i++ )
		printf("%d ",*((int*)arr_ptr[i]));
	puts("");

	
	


	return 0;
}
