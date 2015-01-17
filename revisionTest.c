#include "expr_assert.h"	
#include "revision.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

 void test_fibo_returns_1_for_5_terms () {
 	int numberOfTerms = 5;
 	int *terms;
 	terms = (int *)malloc(sizeof(int)*numberOfTerms);
 	assertEqual(fibo(numberOfTerms,terms),1);
 	free(terms);
 };

 void test_fibo_returns_0_for_less_than_1_term () {
 	int numberOfTerms = 0;
 	int *terms;
 	terms = (int *)malloc(sizeof(int)*numberOfTerms);
 	assertEqual(fibo(numberOfTerms,terms),0);
 	free(terms);
 };

 void test_fibo_returns_1_for_1_term () {
 	int numberOfTerms = 1;
 	int *terms;
 	terms = (int *)malloc(sizeof(int)*numberOfTerms);
 	assertEqual(fibo(numberOfTerms,terms),1);
 	assertEqual(terms[0], 0);
 	free(terms);
 };

 void test_fibo_shows_all_terms_of_fibo_series_till_5_terms () {
 	int numberOfTerms = 5;
 	int *terms;
 	terms = (int *)malloc(sizeof(int)*numberOfTerms);
 	assertEqual(fibo(numberOfTerms,terms),1);
 	assertEqual(terms[0], 0);
 	assertEqual(terms[1], 1);
 	assertEqual(terms[2], 1);
 	assertEqual(terms[3], 2);
 	assertEqual(terms[4], 3);
 	free(terms);
 };

 void test_fibo_shows_all_terms_of_fibo_series_till_8_terms () {
 	int numberOfTerms = 8;
 	int *terms;
 	terms = (int *)malloc(sizeof(int)*numberOfTerms);
 	assertEqual(fibo(numberOfTerms,terms),1);
 	assertEqual(terms[0], 0);
 	assertEqual(terms[1], 1);
 	assertEqual(terms[2], 1);
 	assertEqual(terms[3], 2);
 	assertEqual(terms[4], 3);
 	assertEqual(terms[5], 5);
 	assertEqual(terms[6], 8);
 	assertEqual(terms[7], 13);
 	free(terms);
 };

 void test_concat_gives_concatenated_array (){
 	int array1[4] = {4,8,12,16}, array2[2] = {1,2};
 	int len_of_array1 = 4, len_of_array2 = 2;
 	int *result_array;

 	result_array = (int *)malloc(sizeof(int)*(len_of_array1+len_of_array2));

 	assertEqual(concat(array1, len_of_array1, array2, len_of_array2, result_array),6);
 	assertEqual(result_array[0], 4);
 	assertEqual(result_array[1], 8);
 	assertEqual(result_array[2], 12);
 	assertEqual(result_array[3], 16);
 	assertEqual(result_array[4], 1);
 	assertEqual(result_array[5], 2);
 	free(result_array);
 };

 void test_concat_gives_concatenated_array_of_ten_elements (){
 	int array1[4] = {4,8,12,16}, array2[6] = {1,2,5,8,9,2};
 	int len_of_array1 = 4, len_of_array2 = 6;
 	int *result_array;

 	result_array = (int *)malloc(sizeof(int)*(len_of_array1+len_of_array2));

 	assertEqual(concat(array1, len_of_array1, array2, len_of_array2, result_array),10);
 	assertEqual(result_array[0], 4);
 	assertEqual(result_array[1], 8);
 	assertEqual(result_array[2], 12);
 	assertEqual(result_array[3], 16);
 	assertEqual(result_array[4], 1);
 	assertEqual(result_array[5], 2);
 	assertEqual(result_array[6], 5);
 	assertEqual(result_array[7], 8);
 	assertEqual(result_array[8], 9);
 	assertEqual(result_array[9], 2);
 	free(result_array);
 };

 void test_filters_an_array_by_85_as_threshold () {
 	int scores[5] = {100,90,80,70,190};
 	int length = 5, threshold = 85, *result_array;
 	assertEqual(filter(scores, length, threshold, &result_array),3);
 	assertEqual(result_array[0], 100);
 	assertEqual(result_array[1], 90);
 	assertEqual(result_array[2], 190);
 	free(result_array);
 };

 void test_filters_an_array_by_20_as_threshold () {
 	int scores[5] = {330,10,20,70,1390};
 	int length = 5, threshold = 20, *result_array;

 	assertEqual(filter(scores, length, threshold, &result_array),4);
 	assertEqual(result_array[0], 330);
 	assertEqual(result_array[1], 20);
 	assertEqual(result_array[2], 70);
 	assertEqual(result_array[3], 1390);
 	free(result_array);
 };

 void test_reverses_an_array_from_1_2_3_4_to_4_3_2_1 (){
 	int array[4] = {1,2,3,4};
 	int length = 4;
 	assertEqual(reverse(array, length),1);
 	assertEqual(array[0],4 );
 	assertEqual(array[1],3 );
 	assertEqual(array[2],2 );
 	assertEqual(array[3],1 );
 };

 void test_reverses_an_array_from_12_42_63_74_67_to_67_74_63_42_12 (){
 	int array[] = {12, 42, 63, 74, 67, 78};
 	int length = 5;
 	assertEqual(reverse(array, length),1);
 	assertEqual(array[0],67 );
 	assertEqual(array[1],74 );
 	assertEqual(array[2],63 );
 	assertEqual(array[3],42 );
 };

 void test_reverses_an_array_and_returns_a_new_array () {
 	int array[] = {12,42,63,74,67,78};
 	int length = 5, *result_array;
 	result_array = (int *)malloc(sizeof(int)*length);
 	assertEqual(reverseReturnNewArray(array,length,result_array),1);
 	assertEqual(result_array[0],67 );
 	assertEqual(result_array[1],74 );
 	assertEqual(result_array[2],63 );
 	assertEqual(result_array[3],42 );
 	free(result_array);
 };

 void test_slices_an_array_from_desired_start_and_end_index () {
 	int array[] = {0,7,8,9,-1,-3},len_of_array, start_index, end_index;
 	int *result_array;
 	len_of_array = 6;
 	start_index = 2;
 	end_index = 5;
 	assertEqual(slice(array, len_of_array, start_index, end_index, &result_array),3);
 	assertEqual(result_array[0], 8);
 	assertEqual(result_array[1], 9);
 	assertEqual(result_array[2], -1);
 	free(result_array);
 };

 void test_slices_an_array_and_doesnt_modifies_the_original__array () {
 	int array[8] = {-3,-9,0,3,1,6,7,9},len_of_array, start_index, end_index;
 	int *result_array;
 	len_of_array = 8;
 	start_index = 2;
 	end_index = 7;
 	assertEqual(slice(array, len_of_array, start_index, end_index, &result_array),5);
 	assertEqual(result_array[0], 0);
 	assertEqual(result_array[1], 3);
 	assertEqual(result_array[2], 1);
 	assertEqual(result_array[3], 6);
 	assertEqual(result_array[4], 7);
 	assertEqual(array[0], -3);
 	assertEqual(array[1], -9);
 	assertEqual(array[2], 0);
 	assertEqual(array[3], 3);
 	assertEqual(array[4], 1);
 	assertEqual(array[5], 6);
 	assertEqual(array[6], 7);
 	assertEqual(array[7], 9);
 	free(result_array);
 };

 void test_prime_returns_the_primary_numbers_between_1_and_5 (){
 	int start_point = 1;
 	int end_point = 5;
 	int *result_array;
 	assertEqual(prime(start_point, end_point, &result_array), 3);
 	assertEqual(result_array[0], 2);
 	assertEqual(result_array[1], 3);
 	assertEqual(result_array[2], 5);
 	free(result_array);
 };

 void test_prime_returns_the_primary_numbers_between_1_and_10 (){
 	int start_point = 1;
 	int end_point = 10;
 	int *result_array;
 	assertEqual(prime(start_point, end_point, &result_array), 4);
 	free(result_array);
 };

 void test_prime_returns_the_primary_numbers_between_1_and_20 (){
 	int start_point = 1;
 	int end_point = 20;
 	int *result_array;
 	assertEqual(prime(start_point, end_point, &result_array), 8);
 	assertEqual(result_array[0], 2);
 	assertEqual(result_array[1], 3);
 	assertEqual(result_array[2], 5);
 	assertEqual(result_array[3], 7);
 	assertEqual(result_array[4], 11);
 	assertEqual(result_array[5], 13);
 	assertEqual(result_array[6], 17);
 	assertEqual(result_array[7], 19);
 	free(result_array);
 };

 void test_prime_returns_the_primary_numbers_between_1_and_100 (){
 	int start_point = 1;
 	int end_point = 100;
 	int *result_array;
 	assertEqual(prime(start_point, end_point, &result_array), 25);
 	assertEqual(result_array[0], 2);
 	assertEqual(result_array[1], 3);
 	assertEqual(result_array[2], 5);
 	assertEqual(result_array[3], 7);
 	assertEqual(result_array[4], 11);
 	assertEqual(result_array[5], 13);
 	assertEqual(result_array[6], 17);
 	assertEqual(result_array[7], 19);
 	assertEqual(result_array[8], 23);
 	assertEqual(result_array[9], 29);
 	assertEqual(result_array[10], 31);
 	assertEqual(result_array[11], 37);
 	assertEqual(result_array[12], 41);
 	assertEqual(result_array[13], 43);
 	assertEqual(result_array[14], 47);
 	assertEqual(result_array[15], 53);
 	assertEqual(result_array[16], 59);
 	assertEqual(result_array[17], 61);
 	assertEqual(result_array[18], 67);
 	assertEqual(result_array[19], 71);
 	assertEqual(result_array[20], 73);
 	assertEqual(result_array[21], 79);
 	assertEqual(result_array[22], 83);
 	assertEqual(result_array[23], 89);
 	assertEqual(result_array[24], 97);
 	free(result_array);
 };

 void test_prime_returns_the_primary_numbers_between_1_and_1000 (){
 	int start_point = 1;
 	int end_point = 1000;
 	int *result_array;
 	assertEqual(prime(start_point, end_point, &result_array), 168);
 };

 void test_string_compare_returns_32_for_comparison_between_hello_and_Hello () {
 	assertEqual(strCmp("hello","Hello"), 32);
 };

 void test_string_compare_returns_0_for_comparison_between_hello_and_hello () {
 	assertEqual(strCmp("hello","hello"), 0);
 };

 void test_string_compare_returns_0_for_comparison_between_hello_and_HELLO () {
 	assertEqual(strCmp("hello","HELLO"), 32);
 };

 void test_string_compare_returns_32_for_comparison_between_hello_and_HElLO () {
 	assertEqual(strCmp("hello","HELLO"), 32);
 };

 void test_string_compare_returns_negative_32_for_comparison_between_HELLO_and_hello () {
 	assertEqual(strCmp("HELLO","hello"), -32);
 };

 void test_string_compare_returns_3_for_comparison_between_hello_and_helllll () {
 	assertEqual(strCmp("hello","helllll"), 3);
 };

 void test_string_compare_returns_negative_3_for_comparison_between_helllll_and_hello () {
 	assertEqual(strCmp("helllll","hello"), -3);
 };

void add(int element, int i, int *array){
	array[i] = element + 1;
};

void test_forEachInt_is_performed_for_int_array_of_four_elements (){
	int array[4] = {1,2,3,4};
	int array_length = 4;
	void (*p)(int,int,int *) = &add;
	assertEqual(forEachInt(array, array_length, p),1);
	assertEqual(array[0], 2);
	assertEqual(array[1], 3);
	assertEqual(array[2], 4);
	assertEqual(array[3], 5);
};

void test_forEachInt_returns_0_for_no_array_elements (){
	int array[0] = {};
	int array_length = 0;
	void (*p)(int,int,int *) = &add;
	assertEqual(forEachInt(array, array_length, p),0);
};

void addIndex(int element, int i, int *array){
	array[i] = element + i;
};

void test_forEachInt_is_performed_for_int_array_of_eight_elements (){
	int array[8] = {1,2,3,4,5,6,7,8};
	int array_length = 8;
	void (*p)(int,int,int *) = &addIndex;
	assertEqual(forEachInt(array, array_length, p),1);
	assertEqual(array[0], 1);
	assertEqual(array[1], 3);
	assertEqual(array[2], 5);
	assertEqual(array[3], 7);
	assertEqual(array[4], 9);
	assertEqual(array[5], 11);
	assertEqual(array[6], 13);
	assertEqual(array[7], 15);
};

void incrementCharBy1 (char element, int index, char *array) {
	int asciiOfElement = (int)element;
	int incrementOfAscii = asciiOfElement + 1;
	array[index] = (char)incrementOfAscii;
};

void test_forEachChar_is_performed_for_5_array_elements () {
	char charArray[5] = {'h','e','l','l','o'};
	int array_length = 5;
	void (*p)(char, int, char *) = &incrementCharBy1;
	assertEqual(forEachChar(charArray, array_length, p), 1);
	assertEqual(charArray[0], 'i');
	assertEqual(charArray[1], 'f');
	assertEqual(charArray[2], 'm');
	assertEqual(charArray[3], 'm');
	assertEqual(charArray[4], 'p');
};

void test_forEachChar_returns_0_for_no_array_elements (){
	char charArray[0] = {};
	int array_length = 0;
	void (*p)(char,int,char *) = &incrementCharBy1;
	assertEqual(forEachChar(charArray, array_length, p),0);
};

void addFloat(float element, int i, float *array){
	array[i] = element + 1.0;
};

void test_forEachFloat_is_performed_for_four_elements (){
	float array[] = {1.2,2.34,3.12,4.15};
	int array_length = 4;
	void (*p)(float,int,float *) = &addFloat;
	assertEqual(forEachFloat(array, array_length, p),1);
	assertEqual(array[0], (float)2.2);
	assertEqual(array[1], (float)3.34);
	assertEqual(array[2], (float)4.12);
	assertEqual(array[3], (float)5.15);
};

void toUpperCase (char *string, int index, char **string_array) {
	int i;
	char* temp = (char*)malloc(sizeof(char) * strlen(string));
	for(i = 0; i < strlen(string); i++){
		temp[i] = toupper(string[i]);
	}
	temp[i] = '\0';
	string_array[index] = temp;
}

void test_forEachString () {
	char *array[4] = {"Hello", "Star", "World", "King"};
	int array_length = 4;
	void (*p)(char *,int, char **) = &toUpperCase;
	assertEqual(forEachString(array, array_length, p), 1);
	assertEqual(strcmp(array[0], "HELLO"),0);
	assertEqual(strcmp(array[1], "STAR"),0);
	assertEqual(strcmp(array[2], "WORLD"),0);
	assertEqual(strcmp(array[3], "KING"),0);
}

void test_forEachString_gives_0_for_no_length () {
	char *array[0] = {};
	int array_length = 0;
	void (*p)(char *,int, char **) = &toUpperCase;
	assertEqual(forEachString(array, array_length, p), 0);
}

int isGreaterThan2 (int element) {
	return element > 2;
}

 void test_filter_of_arrays (){
 	int array[4] = {2,3,4,5};
 	int array_length = 4;
 	int *resultArray;
 	int (*p)(int) = &isGreaterThan2;
 	assertEqual(intArrayFilter(array, array_length, &resultArray, p), 1);
 	assertEqual(resultArray[0], 3);
 	assertEqual(resultArray[1], 4);
 	assertEqual(resultArray[2], 5);
 }

 void test_filter_of_arrays_of_zero_size_gives_0 (){
 	int array[] = {};
 	int array_length = 0;
 	int *resultArray;
 	int (*p)(int) = &isGreaterThan2;
 	assertEqual(intArrayFilter(array, array_length, &resultArray, p), 0);
 }

 int isGreaterThan4 (float element){
 	return element > 2.0;
 }

 void test_filter_of_float_array_filters_array (){
 	float array[6] = {1.9, 3.3, 2.2, 4.44, 8.78, 8.8};
 	int array_length = 6;
 	float *resultArray;
 	int (*p)(float) = &isGreaterThan4;
 	assertEqual(floatArrayFilter(array, array_length, &resultArray, p), 1);
 	assertEqual(resultArray[0], (float)3.3);
 	assertEqual(resultArray[1], (float)2.2);
 	assertEqual(resultArray[2], (float)4.44);
 	assertEqual(resultArray[3], (float)8.78);
 	assertEqual(resultArray[4], (float)8.8);
 }

 void test_filter_of_float_arrays_of_zero_size_gives_0 (){
 	float array[] = {};
 	int array_length = 0;
 	float *resultArray;
 	int (*p)(float) = &isGreaterThan4;
 	assertEqual(floatArrayFilter(array, array_length, &resultArray, p), 0);
 }

int isElementGreaterThanAsciiOfO (char element) {
 	int asciiOfElement = (int)element;
 	int asciiOfO = (int)('o');
 	return asciiOfElement > asciiOfO;
}

void test_filter_of_char_array_filters_array (){
 	char char_array[5] = {'w','o','r','l','d'};
 	int array_length = 5;
 	char *resultArray;
 	int (*p)(char) = &isElementGreaterThanAsciiOfO;
 	assertEqual(charArrayFilter(char_array, array_length, &resultArray, p), 1);
 	assertEqual(resultArray[0], 'w');
 	assertEqual(resultArray[1], 'r');
}

void test_filter_of_char_arrays_of_zero_size_gives_0 (){
 	char array[] = {};
 	int array_length = 0;
 	char *resultArray;
 	int (*p)(char) = &isElementGreaterThanAsciiOfO;
 	assertEqual(charArrayFilter(array, array_length, &resultArray, p), 0);
}

int isElementHello (char *element){
	if(strcmp(element,"hello") == 0)
		return 1;
	return 0;
}

void test_filter_of_string_array_filters_array (){
 	char *char_array[2] = {"hello","world"};
 	int array_length = 2;
 	char **resultArray;
 	int (*p)(char*) = &isElementHello;
 	assertEqual(stringArrayFilter(char_array, array_length, &resultArray, p), 1);
	assertEqual(strcmp(resultArray[0], "hello"),0);
	// assertEqual(strcmp(resultArray[1], "null"),0);
}

void test_filter_of_string_array_of_0_elements_gives_0 (){
 	char *char_array[0] = {};
 	int array_length = 0;
 	char **resultArray;
 	int (*p)(char*) = &isElementHello;
 	assertEqual(stringArrayFilter(char_array, array_length, &resultArray, p), 0);
}

int addIndexInElement(int element, int index, int *array){
 	return element + index;
}

 void test_mapInt_is_performed_for_int_array_of_eight_elements (){
 	int array[8] = {1,2,3,4,5,6,7,8};
 	int array_length = 8;
 	int (*p)(int,int,int *) = &addIndexInElement;
 	int *mapFunction = mapInt(array, array_length, p);
 	assertEqual((mapFunction)[0], 1);
 	assertEqual((mapFunction)[1], 3);
 	assertEqual((mapFunction)[2], 5);
 	assertEqual((mapFunction)[3], 7);
 	assertEqual((mapFunction)[4], 9);
 	assertEqual((mapFunction)[5], 11);
 	assertEqual((mapFunction)[6], 13);
 	assertEqual((mapFunction)[7], 15);
 };

 float addForMapFloat(float element, int index, float *array){
 	return element + index;
 }

 void test_mapFloat_is_performed_for_float_array_of_eight_elements (){
 	float array[8] = {1.4, 2.6, 3.2, 4.1, 5.87, 6.4, 7.2, 8.1};
 	int array_length = 8;
 	float (*p)(float,int,float *) = &addForMapFloat;
 	float *mapFunction = mapFloat(array, array_length, p);
 	assertEqual(mapFunction[0], (float)1.4);
 	assertEqual(mapFunction[1], (float)3.6);
 	assertEqual(mapFunction[2], (float)5.2);
 	assertEqual(mapFunction[3], (float)7.1);
 	assertEqual(mapFunction[4], (float)9.87);
 	assertEqual(mapFunction[5], (float)11.4);
 	assertEqual(mapFunction[6], (float)13.2);
 	assertEqual(mapFunction[7], (float)15.1);
 }

 char incrementCharBy2 (char element, int index, char *array) {
 	int asciiOfElement = (int)element;
 	int incrementOfAscii = asciiOfElement + 2;
 	return (char)incrementOfAscii;
 }

void test_mapChar_is_performed_for_5_array_elements () {
 	char charArray[5] = {'h','e','l','l','o'};
 	int array_length = 5;
 	char (*p)(char, int, char *) = &incrementCharBy2;
 	char *mapFunction = mapChar(charArray, array_length, p);
 	assertEqual((mapFunction)[0], 'j');
 	assertEqual((mapFunction)[1], 'g');
 	assertEqual((mapFunction)[2], 'n');
 	assertEqual((mapFunction)[3], 'n');
 	assertEqual((mapFunction)[4], 'q');
}

char *map_gives_hi (char * string,int index, char **string_array){
	if(!(strcmp(string,"Hello"))){
		string = "hi";
	}
	return string;
}

void test_mapString_is_performed_for_2_array_elements () {
 	char *charArray[2] = {"Hello","You"};
 	int array_length = 2;
 	char *(*p)(char*, int, char **) = &map_gives_hi ;
 	char **mapFunction = mapString(charArray, array_length, p);
 	assertEqual(strcmp(mapFunction[0], "hi"),0);
 	assertEqual(strcmp(mapFunction[1], "You"),0);
}

int addTwoValues (int previousValue, int currentValue){
	return previousValue + currentValue;
}

void test_reduceInt_of_1_2_3_4_gives_10 () {
	int array[4] = {1,2,3,4};
	int array_length = 4;
	int (*p)(int, int) = &addTwoValues;
	assertEqual(reduceInt(array, array_length, p, array[0]), 10);
}

int addPVandCV (int previousValue, int currentValue) {
 return previousValue + currentValue;
}
void test_reduce_for_int_should_return_6_when_the_initial_value_is_0 () {
 int array[3] = {1, 2, 3};
 int array_length = 3;
 int (*p)(int, int) = &addPVandCV;

 assertEqual(reduceInt(array, array_length, p, array[0]), 6);
}

int giveGreatestValue (int previousValue, int currentValue) {
 return (previousValue > currentValue) ? previousValue : currentValue;
}

void test_reduce_for_int_should_return_6_as_a_greater_value_in_the_array () {
 int array[6] = {1, 2, 3, 6, 4, 5};
 int array_length = 6;
 int (*p)(int, int) = &giveGreatestValue;
 assertEqual(reduceInt(array, array_length, p, array[0]), 6);
}

int giveSmallest (int previousValue, int currentValue) {
 return (previousValue < currentValue) ? previousValue : currentValue;
}

void test_reduce_for_int_should_return_6_as_a_smallest_value_in_the_array () {
 int array[6] = {1, 2, 3, 6, 4, 5};
 int array_length = 6;
 int (*p)(int, int) = &giveSmallest;
 assertEqual(reduceInt(array, array_length, p, array[0]), 1);
}

float addFloatValues (float previousValue, float currentValue){
	return previousValue + currentValue;
}

void test_reduceFloat () {
	float array[6] = {1.2,2.2,3.5,4.3,5.1};
	int array_length = 6;
	float (*p)(float, float) = &addFloatValues;
	assertEqual(reduceFloat(array, array_length, p, array[0]), (float)16.3);
}

float giveSmallestValue (float previousValue, float currentValue) {
 return (previousValue < currentValue) ? previousValue : currentValue;
}

void test_reduce_for_float_should_return_1_as_a_smallest_value_in_the_array () {
 float array[6] = {1.3, 2.8, 9.3, 1.6, 4.9, 5.3};
 int array_length = 6;
 float (*p)(float, float) = &giveSmallestValue;
 assertEqual(reduceFloat(array, array_length, p, array[0]), (float)1.3);
}

float giveGreatest (float previousValue, float currentValue) {
 return (previousValue > currentValue) ? previousValue : currentValue;
}

void test_reduce_for_float_should_return_9_as_a_greatest_value_in_the_array () {
 float array[6] = {1.3, 2.8, 9.3, 1.6, 4.9, 5.3};
 int array_length = 6;
 float (*p)(float, float) = &giveGreatest;
 assertEqual(reduceFloat(array, array_length, p, array[0]), (float)9.3);
}

char giveCharOfGreatestAsciiValue (char previousValue, char currentValue){
	return ((int)previousValue > (int)currentValue) ? previousValue : currentValue;
}

void test_reduceChar () {
	char array[5] = {'h','e','l','l','o'};
	int array_length = 5;
	char (*p)(char, char) = &giveCharOfGreatestAsciiValue;
	assertEqual(reduceChar(array, array_length, p, array[0]), 'o');
}

char * isElementOfGreatestLength (char *previousValue, char *currentValue) {
	return (strlen(previousValue) > strlen(currentValue)) ? previousValue : currentValue;
}

void test_reduceString () {
	char *array[4] = {"hello","guys","whats","up"};
	int array_length = 4;
	char *(*p)(char*, char*) = &isElementOfGreatestLength;
	assertEqual(strcmp(reduceString(array, array_length, p, array[0]),"whats"), 0);
}

void test_indexOf_guys_in_hello_guys_is_7 () {
	char *string = "hello guys";
	char *sub_string = "guys";
	assertEqual(indexOf(string,sub_string), 6);
}

void test_indexOf_guys_in_hello_world_is_negative_1 () {
	char *string = "hello world";
	char *sub_string = "guys";
	assertEqual(indexOf(string,sub_string), -1);
}

void test_indexOf_guys_in_hello_gs_is_negative_1 () {
	char *string = "hello gs";
	char *sub_string = "guys";
	assertEqual(indexOf(string,sub_string), -1);
}

void test_indexof_str_is_0_in_string () {
 char *mainString = "String";
 char *sub_str = "Str";
 assertEqual(indexOf(mainString, sub_str), 0);
};

void test_indexof_str_is_2_in_string () {
 char *mainString = "String";
 char *sub_str = "rin";
 assertEqual(indexOf(mainString, sub_str), 2);
};

void test_indexof_str_is_minus_1_when_sub_string_is_not_matching_with_string () {
 char *mainString = "String";
 char *sub_str = "ren";
 assertEqual(indexOf(mainString, sub_str), -1);
};
