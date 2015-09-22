#include "header.h"
void initialize_record(struct book_record br[],int i)
{
	    br[i].author_name[0]='\0';
		br[i].book_name[0]='\0';
		br[i].publication_year=0;
		br[i].copies_available=0;	
}
