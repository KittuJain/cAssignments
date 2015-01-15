#include <stdio.h>
#include "revision.h"

int fibo (int numberOfTerms,int *terms){
	int i;
	terms[0] = 0;
	terms[1] = 1;
	if(numberOfTerms<1){
		return 0;
	}else{
		for(i = 2; i < numberOfTerms; i++){
			terms[i] = terms[i-1] + terms [i-2];
		};		
		return 1;
	}
}

int concat(int *array1, int len_of_array1, int *array2, int len_of_array2, int *result_array){
	int i, j;
	int len_of_both_arrays = len_of_array1 + len_of_array2;

	for(i = 0; i < len_of_array1; i++){
		result_array[i] = array1[i];
	};
	for(j = 0; j < len_of_array2; j++){
		result_array[len_of_array1+j] = array2[j];
	};
	return len_of_both_arrays;
}

int filter(int *array, int length, int threshold, int **result_array){
	int i,length_of_filtered_array=0,len=0;

	for(i = 0; i < length; i++){
		if(array[i]>=threshold){
			length_of_filtered_array++;
		}
	}
	*result_array = (int *)malloc(sizeof(int)*length_of_filtered_array);

	for(i = 0; i < length; i++){
		if(array[i]>=threshold){
			(*result_array)[len] = array[i];
			len++;
		}
	}
	return length_of_filtered_array;
}


int reverse(int *array, int length){
	int i, j, tempArray[length];
	for(i = 0; i < length; i++)
		tempArray[i] = array[i];

	for (i = 0; i < length; ++i)
		array[i] = tempArray[length-1-i];

	return 1;
}

int reverseReturnNewArray(int *array, int length, int *result_array){
	int i;
	for (i = 0; i < length; ++i)
		result_array[i] = array[length-1-i];
	return 1;
}

int slice(int *array,int len_of_array,int start_index, int end_index, int **result_array){
	int i, len_of_sliced_array = 0, length = 0;
	len_of_sliced_array = end_index - start_index;

	*result_array = (int *)malloc(sizeof(int)*len_of_sliced_array);
	for(i = 0; i < len_of_array; i++){
		if(i >= start_index && i < end_index){
			(*result_array)[length] = array[i];
			length++;
		}
	}
	return len_of_sliced_array;
}

int isPrime (int number) {
	int counter, flag = 1;

	if(number == 1)
		flag = 0;
	for(counter = 2; counter <= number / 2; counter++){
		if (number % counter == 0 && counter != number)
			flag=0;
	}
	return flag;
}

int prime(int start_point, int end_point, int **result_array){
	int isPrime(int);
	int counter, length_of_prime=0, length=0;

	for(counter = start_point; counter <= end_point; counter++){
		if(isPrime(counter) == 1){
			length_of_prime++;
		}
	}
	*result_array = (int *)malloc(sizeof(int)*length_of_prime);
	for(counter = start_point; counter <= end_point; counter++){
		if(isPrime(counter) == 1){
			(*result_array)[length] = counter;
			length++;
		}
	}
	return length_of_prime;
}

int strCmp(char *string1,char *string2){
	int i, length, count;
	length = (strlen(string1) > strlen(string2)) ? strlen(string1) : strlen(string2);

	for(i=0; i < length; i++){
		if((int)string1[i] == (int)string2[i])
			count = 0;
		else
			return (int)string1[i] - (int)string2[i];
	}
	return count;
}

int forEachInt(int *array, int array_length, void (*function_ptr)(int,int,int *)){
	int i;
	if(array_length == 0)
		return 0;
	for(i = 0; i < array_length; i++){
		function_ptr(array[i],i,array);
	}
	return 1;
}

int forEachChar(char *array, int array_length, void (*function_ptr)(char,int,char *)){
	int i;
	if(array_length == 0)
		return 0;
	for(i = 0; i < array_length; i++){
		function_ptr(array[i],i,array);
	}
	return 1;
}

int forEachFloat(float *array, int array_length, void (*function_ptr)(float,int,float *)){
	int i;
	if(array_length == 0)
		return 0;
	for(i = 0; i < array_length; i++){
		function_ptr(array[i],i,array);
	}
	return 1;
}

int intArrayFilter(int *array, int array_length, int **resultArray, int (*function_ptr)(int)){
	int count,len=0;
	if(array_length == 0)
		return 0;

	for(count = 0; count < array_length; count++){
		if(function_ptr(array[count]) == 1){
			len++;
		}
	}

	*resultArray = (int *)malloc(sizeof(int)*len);
	len=0;
	for(count = 0; count < array_length; count++){
		if(function_ptr(array[count]) == 1){
			(*resultArray)[len] = array[count];
			len++;
		}
	}
	return 1;
}

int floatArrayFilter(float *array, int array_length, float **resultArray, int (*function_ptr)(float)){
	int count,len=0;
	if(array_length == 0)
		return 0;

	for(count = 0; count < array_length; count++){
		if(function_ptr(array[count]) == 1){
			len++;
		}
	}

	*resultArray = (float *)malloc(sizeof(float)*len);
	len=0;
	for(count = 0; count < array_length; count++){
		if(function_ptr(array[count]) == 1){
			(*resultArray)[len] = array[count];
			len++;
		}
	}
	return 1;
}

int charArrayFilter(char *array, int array_length, char **resultArray, int (*function_ptr)(char)){
	int count,len=0;
	if(array_length == 0)
		return 0;
	for(count = 0; count < array_length; count++){
		if(function_ptr(array[count]) == 1){
			len++;
		}
	}

	*resultArray = (char *)malloc(sizeof(char)*len);
	len=0;
	for(count = 0; count < array_length; count++){
		if(function_ptr(array[count]) == 1){
			(*resultArray)[len] = array[count];
			len++;
		}
	}
	return 1;
}

int * mapInt(int *array, int array_length, int (*function_ptr)(int,int,int *)){
	int counter,*resultArray;
	if(array_length == 0)
		return 0;
	resultArray = (int *)malloc(sizeof(int)*array_length);

	for(counter = 0; counter < array_length; counter++){
		resultArray[counter] = function_ptr(array[counter],counter,array);
	}
	return resultArray;
}

float  * mapFloat(float *array, int array_length, float (*function_ptr)(float,int,float *)){
	int counter;
	float *resultArray;
	if(array_length == 0)
		return 0;
	resultArray = (float *)malloc(sizeof(float)*array_length);

	for(counter = 0; counter < array_length; counter++){
		resultArray[counter] = function_ptr(array[counter],counter,array);
	}
	return resultArray;
}

char * mapChar(char *array, int array_length, char (*function_ptr)(char,int,char *)){
	int counter;
	char *resultArray;
	if(array_length == 0)
		return 0;
	resultArray = (char *)malloc(sizeof(char)*array_length);

	for(counter = 0; counter < array_length; counter++){
		resultArray[counter] = function_ptr(array[counter],counter,array);
	}
	return resultArray;
}

int reduceInt (int *array, int array_length, int (*function_ptr)(int,int,int,int *), int initialValue){
	int counter,result = 0;
	if(array_length == 0)
		return 0;

	for(counter = 1; counter < array_length; counter++){
		result = function_ptr(initialValue,array[counter],counter,array);
		initialValue = result;
	}
	return result;
}

float reduceFloat (float *array, int array_length, float (*function_ptr)(float,float,int, float *), float initialValue){
	int counter;
	float result = 0.0;
	if(array_length == 0)
		return 0;

	for(counter = 1; counter < array_length-1; counter++){
		result = function_ptr(initialValue,array[counter],counter,array);
		initialValue = result;
		
	}
	return result;
}
