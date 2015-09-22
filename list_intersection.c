#include "header.h"
int list_intersection(struct book_record br1[],struct book_record br2[],struct book_record br3[])
{
	int num1,num2;
	int i=0,j=0,k=0;
	num1=get_num_records(br1);
    num2=get_num_records(br2);
    while((i<num1) && (j<num2))
	{
	     if(strcmp(br1[i].author_name,br2[j].author_name)>0)
		{
		    j++;
		}	
		else if(strcmp(br1[i].author_name,br2[j].author_name)<0)
		{
		    i++;
		}
		else
		{
		    if(strcmp(br1[i].book_name,br2[j].book_name)>0)
		    {
			    j++;	
		    }	
		    else if(strcmp(br1[i].book_name,br2[j].book_name)<0)
        	{
			    i++;	
		    }
		    else
		    {
			    if(br1[i].copies_available<br2[j].copies_available)	
			    {
				    br3[k]=br1[i];
					k++;
					i++;
					j++;	
				}
				else if(br1[i].copies_available>br2[j].copies_available)
				{
				    br3[k]=br2[j];
					k++;
					j++;
					i++;	
				}
				else
				{
				    if(br1[i].publication_year<br2[j].publication_year)
					{
					    br3[k]=br2[j];
						k++;
						j++;
						i++;	
					}	
					else
					{
					    br3[k]=br1[i];
						k++;
						j++;
						i++;	
					}
				}
			}
	    }  	
    }
    return k;
}
