#include "header.h"
enum status delete_record(struct book_record br[],char author_name[],char book_name[])
{
	enum status delete_rec;
	int i,index,num;
	num=get_num_records(br);
	index=search_record(br,author_name,book_name);  /*SEARCHING RECORD*/
	if(index==-1) /*NOT FOUND*/
	{
	    delete_rec=NO;
	    printf("book is not present in the record\n\n");	
	}
	else /*FOUND*/
	{
	    i=index;
		while(i<(num-1)) /*KEEPING SORTED*/
		{
		    br[i]=br[i+1];
			i++;	
		}	
		initialize_record(br,(num-1));
		delete_rec=YES;
	}
	return delete_rec;
}
