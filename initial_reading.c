#include "header.h"
void initial_reading(struct book_record br[],int n)
{
	int i,num;
	char dumbo[2];
	/*SCANNING FROM USER*/
	num=get_num_records(br);
	for(i=num;i<(num+n);i++)
	{
	    printf("\n\nBook No.: %d\n",i);
		gets(dumbo);
	    printf("Author's Name:  ");
	    gets(br[i].author_name);
	    remove_space_make_uppercase(br[i].author_name);
	    printf("Book Name:  ");
	    gets(br[i].book_name);
	    remove_space_make_uppercase(br[i].book_name);
        printf("Publication Year:  ");
	    scanf("%u",&br[i].publication_year);
	    printf("Copies Available:  ");
	    scanf("%u",&br[i].copies_available);	
	}
	/*MODIFYING DATAs FROM FILE*/
	for(i=0;i<num;i++)
	{
	    remove_space_make_uppercase(br[i].author_name);
	    remove_space_make_uppercase(br[i].book_name);
    }
	/*EDITING DATA*/
	sort_list(br);
	list_unique(br);
	printf("\n\n***********Edited data is as follows:");
	/*PRINTING RECORDS*/
	num=get_num_records(br);
	for(i=0;i<num;i++)
	{
		printf("\n\nBook No.: %d\n",(i+1));
		printf("Author Name:  ");
	    puts(br[i].author_name);
	    printf("Book Name:  ");
		puts(br[i].book_name);
		printf("Publication Year:  %u\n",br[i].publication_year);
		printf("Copies Available:  %u",br[i].copies_available);	
	}
}
