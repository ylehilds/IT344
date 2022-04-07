// IT344 LAB1
//
// NAME:
// 
// Write a C program that reads two strings from the command line arguments and 
// merge them into one string by taking the 1st character of string1, then 1st char 
// from string2, 2nd char from string1, 2nd char from string2, … etc, until the end 
// of one string, then append the rest of the other string. For example, two strings 
// "abcd" and "pqrstuv" will give you "apbqcrdstuv" as the result. 
//
// Build instruction:
// gcc -g -std=c99 strmerge.c -o strmerge

#include <stdio.h>
#include <stdlib.h>

// FUNCTION: strMerge
// Merge two strings (str1 & str2) into one (strDest) by taking the 1st character of str1, 
// then 1st char from str2, 2nd char from str1, 2nd char from str2, … etc, until the end of 
// one string, then append the rest of the other string. For example, two strings "abcd" and 
// "pqrstuv" will give you "apbqcrdstuv" as the result.
// 
// ccDest is the size of the destination buffer, in character count.
//
void strMerge(const char *str1, const char *str2, char *strDest, unsigned int ccDest)
{

int i=0;
int j=0;

    // print out input strings
    printf("string1 is %s\n", str1);
    printf("string2 is %s\n", str2);
while (str1[j]!=NULL || str2[j]!=NULL)
{
//temp = strDest;
	int x=j;
	int m=j;
	while (str1[j]==NULL && str2[x]!=NULL)
	{
		strDest[i]=str2[x];
		i++;
		x++;
		
	}
    while (str1[m]!=NULL && str2[x]==NULL)
    {
	  strDest[i]=str1[m];
	  i++;
	  m++;
    }
	
    if (str1[m]!=NULL || str2[x]!=NULL)
    {
      strDest[i]=str1[j];
      strDest[i+1]=str2[j];
      i++;
      i++;
      j++;
    }
	if (str1[m]==NULL && str2[x]==NULL)
	{
		break;
	}
}
    // TODO: merge the two strings into strDest, make sure it's NULL terminated
   printf("merged string is %s\n", strDest);
}

// FUNCTION: main
//
int main (int argc, char* argv[])
{
    char *str1;
    char *str2;

    char strNew[12800];

    if (argc == 3)
    {
        // if strings are provided via command line arguments
        str1 = argv[1];
        str2 = argv[2];
        strMerge(str1, str2, strNew, sizeof(strNew));
    }
    else
    {
        // no string provided, do the default tests
        str1 = "1234";
        //str2 = "567890";
		str2 = "567890";
        strMerge(str1, str2, strNew, sizeof(strNew));
        printf("should be        1526374890\n\n");

        str1 = "information";
        str2 = "tech";
        strMerge(str1, str2, strNew, sizeof(strNew));
        printf("should be        itnefcohrmation\n\n");
    }

    return 0;
}


