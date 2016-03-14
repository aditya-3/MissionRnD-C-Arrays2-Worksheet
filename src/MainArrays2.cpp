/*
Well Done for completing the first part of the C Course ,If you didnt finish 
Do complete them and come here again . 

Use MainArrays2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.s

Objectives of C-Arrays-2 Lesson:

->Handling Arrays of Structures
->Sorting Arrays
->Learning Complexities of your Algorithm

*/
#include <stdio.h>
#include "FunctionHeadersArrays2.h"
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int main(){

	//Test countGreaterNumbers

	//Test findSingleOccurenceNumber

	//Test mergeSortedArray

	//Test sortedArraysCommonElements

	
		struct transaction A[3] = { { 10, "09-10-2003", "First" }, { 20, "21-10-2006", "Second" }, { 30, "03-03-2005", "Third" } };
		struct transaction B[3] = { { 40, "21-10-2006", "Fourth" }, { 50, "13-11-2007", "Fifth" }, { 60, "13-08-2008", "Sixth" } };
		//int A[3] = { 1, 2, 3 }, B[3] = { 4, 5, 6 };
		struct transaction *result = sortedArraysCommonElements(A, 3, B, 3);

	return 0;
}