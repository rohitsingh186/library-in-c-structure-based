#include "header.h"
int list_difference(struct book_record br1[],struct book_record br2[],struct book_record br3[])
{
	int i=0,j=0,k=0;
	int num1,num2;
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
			br3[k]=br1[i];
			k++;
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
			    br3[k]=br1[i];
			    k++;
		        i++;	
		    }
		    else
		    {
			    i++;
			    j++;
			}
	    }  	
    }
    while(i<num1)
    {
	    br3[k]=br1[i];
		i++;
		k++;	
	}
    return k;
}
