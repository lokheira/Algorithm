#include <iostream>
#include <string.h>
using namespace std;

char* prefix(char* haystack_start, char* needle_start)
{
    char* haystack = haystack_start;
    char* needle = needle_start;


    while(*haystack && *needle){
        if(*(haystack++) != *(needle++))
            return NULL; 
    }

    if(*needle) return NULL;

    return haystack_start;
}
