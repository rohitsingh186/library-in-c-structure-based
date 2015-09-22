#include "header.h"
void num_avail_copies(struct book_record br[],char author_name[],char book_name[])
{
	int index;
	index=search_record(br,author_name,book_name);  /*SEARCHING RECORD*/
	if(index==-1)
	{
	    printf("This book is not present in the library");	
	}
	else
	{
	    printf("Number of copies available of the book '%s' is %d",book_name,br[index].copies_available);	
	}
}
