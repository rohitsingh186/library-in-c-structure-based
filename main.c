#include "header.h"
main()
{
	/*DECLARATIONS*/
	char Author_Name[A_NAME_LEN],Book_Name[B_NAME_LEN],dumbo[A_NAME_LEN];
	unsigned int pub_year,copies_avail;
    int i,num_read_rec,inserted,option,index,num;
    char c,choice;
    FILE *fp;
	struct book_record book1[TOTAL_RECORDS];
	struct book_record book2[TOTAL_RECORDS];
	struct book_record book3[2*TOTAL_RECORDS];
	struct book_record book4[TOTAL_RECORDS];
	struct book_record book5[TOTAL_RECORDS];
	/*INITIALIZATION*/
	for(i=0;i<TOTAL_RECORDS;i++)
	{
	    initialize_record(book1,i);
    }
    /*READING DATA FROM FILE*/
    fp=fopen("record.txt","a");
    fclose(fp);
    printf("*****READING FROM FILE*****");
    i=0;
    fp=fopen("record.txt","r");
    while((c=getc(fp)) != EOF)
    {
		fseek(fp,-sizeof(char),1);
	    fscanf(fp,"%s %s %u %u",book1[i].author_name,book1[i].book_name,&book1[i].publication_year,&book1[i].copies_available);
	    i++;
	}
	fclose(fp);
	printf("\n***** END READING FROM FILE*****\n\n");
	/*INITIAL DATA ENTERING*/
	num=get_num_records(book1);
	printf("$$$$$$$$$Enter the number of records you want to enter initially. Please enter a number upto %d:  ",(TOTAL_RECORDS-num));
	inserted=0;
	while(inserted==0)
	{
		scanf("%d",&num_read_rec);
	    if(num_read_rec<=(TOTAL_RECORDS-num))	
	    {
		    initial_reading(book1,num_read_rec);
			inserted=1;	
		}
		else
		{
		    printf("\n\n$$$$$$$$$Please enter a number upto %d only:  ",(TOTAL_RECORDS-num));	
		}
	}
	/*OPTIONS*/
	do
	{
	    printf("\n\n*********Enter your choice as per the operations you want to do. ENTER\n1: Search Book\n2: Insert/Update Record\n3: Delete a Record\n4: Number of Active Records\n5: Is the List EMPTY\n6: Is the List FULL\n7:Top Most Author\n8: List Unique\n9: List Union\n10: List intersection\n11: List Difference\n12: List Symmetric Difference\n\n$$$$$$$$$Your Option:  ");
        scanf("%d",&option);
        switch(option)
        {
			case 1:{/*SEARCH RECORD*/
			            printf("\n\n***********SEARCH RECORD***********");
				        printf("\n\n$$$$$$$$$Enter the Data for Searching\n\n");
						gets(dumbo);
						printf("Author:  ");
	                    gets(Author_Name);
	                    remove_space_make_uppercase(Author_Name);
	                    printf("Book:  ");
	                    gets(Book_Name);
	                    remove_space_make_uppercase(Book_Name);
	                    index=search_record(book1,Author_Name,Book_Name);
	                    if(index==-1)
	                    {
						    printf("\n*****The Book is Not Present in this Record\n");	
						}
						else
						{
						    /*PRINTING DATA*/
							printf("\n\n*****Result for given Data is:\n\n");
		                    printf("Author Name:  ");
	                        puts(book1[index].author_name);
	                        printf("Book Name:  ");
		                    puts(book1[index].book_name);
		                    printf("Publication Year:  %u\n",book1[index].publication_year);
		                    printf("Copies Available:  %u",book1[index].copies_available);		
						}
				        break;
			       }
		    case 2:{/*INSERT RECORD*/    
		                printf("\n\n***********INSERT RECORD***********");
				        printf("\n\n$$$$$$$$$Enter the Data to be Inserted or Updated:\n\n");
	                    gets(dumbo);
						printf("Author:  ");
	                    gets(Author_Name);
	                    remove_space_make_uppercase(Author_Name);
	                    printf("Book:  ");
	                    gets(Book_Name);
	                    remove_space_make_uppercase(Book_Name);
	                    printf("publication year:  ");
	                    scanf("%u",&pub_year);
	                    printf("copies available:  ");
	                    scanf("%u",&copies_avail);
	                    if(insert_record(book1,Author_Name,Book_Name,pub_year,copies_avail)==1)
	                    {
	                        printf("\n\n*****DATA INSERTED");	
	                    }
	                    else
	                    {
	                        printf("\n\n*****DATA CAN'T BE INSERTED as the Record is Full");	
	                    }
		    	        break;
		           }	
		    case 3:{/*DELETE RECORD*/
		                printf("\n\n***********DELETE RECORD***********");
				        printf("\n\n$$$$$$$$$$Enter the Data to be Deleted.ENTER Author Name and Book Name respectively:\n\n");
	                    gets(dumbo);
	                    printf("Author:  ");
	                    gets(Author_Name);
	                    remove_space_make_uppercase(Author_Name);
	                    printf("Book:  ");
	                    gets(Book_Name);
	                    remove_space_make_uppercase(Book_Name);
	                    if(delete_record(book1,Author_Name,Book_Name)==1)
	                    {
						    printf("\n*****DATA DELETED\n");	
						}
						else
						{
						    printf("\n*****Data is NOT PRESENT in the Record\n");	
						}
		    	        break;
		           }
		    case 4:{/*NUMBER OF ACTIVE RECORDS*/
		                printf("\n\n***********NUMBER OF RECORDS***********");
				        printf("\n\n*****Number of Active Records Present in the Library is %d\n",get_num_records(book1));
		    	        break;
		           }
		    case 5:{/*IS THE LIST EMPTY*/
		                printf("\n\n***********IS LIST EMPTY***********");
				        if(is_empty(book1)==1)
				        {
						    printf("\n\n*****The List is Empty\n");	
						}
						else
						{
						  	printf("\n\n*****The list is Not Empty\n");
						}
		    	        break;
		           }
		    case 6:{/*IS THE LIST FULL*/
		                printf("\n\n***********IS LIST FULL***********");
				        if(is_full(book1)==1)
				        {
						    printf("\n\n*****The List is Full\n");	
						}
						else
						{
						  	printf("\n\n*****The list is Not Full\n");
						}
		    	        break;
		           }
		    case 7:{/*TOP MOST AUTHOR*/
		                printf("\n\n***********TOP MOST AUTHOR***********");
		                gets(dumbo);
		                printf("\n\n$$$$$$$$$Enter Name of the Book:  ");
		                gets(Book_Name);
		                remove_space_make_uppercase(Book_Name);
		                index=get_topmost_author(book1,Book_Name);
		                if(index==-1)
		                {
						    printf("\n\n*****This Book is Not Present in the Record\n\n");	
						}
						else
						{
						    printf("\n\n*****TopMost author of the book '%s' is:  %s",Book_Name,book1[index].author_name);	
						}
		    	        break;
		           }
		    case 8:{/*LIST UNIQUE*/
		                printf("\n\n***********LIST UNIQUE***********");
				        list_unique(book1);
		    	        break;
		           }
		    case 9:{/*LIST UNION*/     
		                printf("\n\n***********LiST UNION***********\n\n");
		    	        /*INITIALIZATION*/
	                    for(i=0;i<TOTAL_RECORDS;i++)
	                    {
	                        initialize_record(book2,i);
                        }
                        for(i=0;i<(2*TOTAL_RECORDS);i++)
	                    {
	                        initialize_record(book3,i);
                        }
                      	/*INITIAL DATA ENTERING*/
	                    printf("$$$$$$$$$Enter the number of records you want to enter initially. Please enter a number upto %d:  ",TOTAL_RECORDS);
	                    inserted=0;
	                    while(inserted==0)
	                    {
		                    scanf("%d",&num_read_rec);
	                        if(num_read_rec<=TOTAL_RECORDS)	
	                        {
		                        initial_reading(book2,num_read_rec);
			                    inserted=1;	
		                    }
		                    else
		                    {
		                        printf("\n\n$$$$$$$$$Please enter a number upto %d only:  ",TOTAL_RECORDS);	
		                    }
	                    }
	                    num=list_union(book1,book2,book3);
	                    printf("num=%d",num);
	                    printf("\n\n*****Merged Data is as follows:");
	                    /*PRINTING RECORDS*/
	                    for(i=0;i<num;i++)
	                    {
		                    printf("\n\nBook No.: %d\n",(i+1));
		                    printf("Author Name:  ");
	                        puts(book3[i].author_name);
	                        printf("Book Name:  ");
		                    puts(book3[i].book_name);
		                    printf("Publication Year:  %u\n",book3[i].publication_year);
		                    printf("Copies Available:  %u",book3[i].copies_available);
	                    }
						break;
		           }
		    case 10:{/*LIST INTERSECTION*/
		                printf("\n\n***********LIST INTERSECTION***********");
			            /*INITIALIZATION*/
	                    for(i=0;i<TOTAL_RECORDS;i++)
	                    {
	                        initialize_record(book2,i);
                        }
                        for(i=0;i<TOTAL_RECORDS;i++)
	                    {
	                        initialize_record(book4,i);
                        }
                      	/*INITIAL DATA ENTERING*/
	                    printf("$$$$$$$$$Enter the number of records you want to enter initially. Please enter a number upto %d:  ",TOTAL_RECORDS);
	                    inserted=0;
	                    while(inserted==0)
	                    {
		                    scanf("%d",&num_read_rec);
	                        if(num_read_rec<=TOTAL_RECORDS)	
	                        {
		                        initial_reading(book2,num_read_rec);
			                    inserted=1;	
		                    }
		                    else
		                    {
		                        printf("\n\n$$$$$$$$$Please enter a number upto %d only:  ",TOTAL_RECORDS);	
		                    }
	                    }
	                    num=list_intersection(book1,book2,book4);
	                    printf("\n\n*****Common Data is as follows:");
	                    /*PRINTING RECORDS*/
	                    for(i=0;i<num;i++)
	                    {
		                    printf("\n\nBook No.: %d\n",(i+1));
		                    printf("Author Name:  ");
	                        puts(book4[i].author_name);
	                        printf("Book Name:  ");
		                    puts(book4[i].book_name);
		                    printf("Publication Year:  %u\n",book4[i].publication_year);
		                    printf("Copies Available:  %u",book4[i].copies_available);
	                    }
		    	        break;
		           }
		    case 11:{/*LIST DIFFERENCE*/
			            printf("\n\n***********LIST DIFFERENCE***********");     
		    	        /*INITIALIZATION*/
	                    for(i=0;i<TOTAL_RECORDS;i++)
	                    {
	                        initialize_record(book2,i);
                        }
                        for(i=0;i<TOTAL_RECORDS;i++)
	                    {
	                        initialize_record(book4,i);
                        }
                      	/*INITIAL DATA ENTERING*/
	                    printf("$$$$$$$$$Enter the number of records you want to enter initially. Please enter a number upto %d:  ",TOTAL_RECORDS);
	                    inserted=0;
	                    while(inserted==0)
	                    {
		                    scanf("%d",&num_read_rec);
	                        if(num_read_rec<=TOTAL_RECORDS)	
	                        {
		                        initial_reading(book2,num_read_rec);
			                    inserted=1;	
		                    }
		                    else
		                    {
		                        printf("\n\n$$$$$$$$$Please enter a number upto %d only:  ",TOTAL_RECORDS);	
		                    }
	                    }
	                    num=list_difference(book1,book2,book4);
	                    printf("\n\n*****Record Difference of Record 1 & Record 2 is as follows:");
	                    /*PRINTING RECORDS*/
	                    for(i=0;i<num;i++)
	                    {
		                    printf("\n\nBook No.: %d\n",(i+1));
		                    printf("Author Name:  ");
	                        puts(book4[i].author_name);
	                        printf("Book Name:  ");
		                    puts(book4[i].book_name);
		                    printf("Publication Year:  %u\n",book4[i].publication_year);
		                    printf("Copies Available:  %u",book4[i].copies_available);
	                    }
						break;
		           }
		    case 12:{/*LIST SYMMETRIC DIFFERENCE*/
			            printf("\n\n***********LIST SYMMETRIC DIFFERENCE***********");     
		    	        /*INITIALIZATION*/
						for(i=0;i<TOTAL_RECORDS;i++)
	                    {
	                        initialize_record(book2,i);
                        }
                        for(i=0;i<(2*TOTAL_RECORDS);i++)
	                    {
	                        initialize_record(book3,i);
                        }
                        for(i=0;i<TOTAL_RECORDS;i++)
	                    {
	                        initialize_record(book4,i);
                        }
                        for(i=0;i<TOTAL_RECORDS;i++)
	                    {
	                        initialize_record(book5,i);
                        }
                      	/*INITIAL DATA ENTERING*/
	                    printf("$$$$$$$$$Enter the number of records you want to enter initially. Please enter a number upto %d:  ",TOTAL_RECORDS);
	                    inserted=0;
	                    while(inserted==0)
	                    {
		                    scanf("%d",&num_read_rec);
	                        if(num_read_rec<=TOTAL_RECORDS)	
	                        {
		                        initial_reading(book2,num_read_rec);
			                    inserted=1;	
		                    }
		                    else
		                    {
		                        printf("\n\n$$$$$$$$$Please enter a number upto %d only:  ",TOTAL_RECORDS);	
		                    }
	                    }
	                    num=list_symmetric_difference(book1,book2,book3,book4,book5);
	                    printf("\n\n*****Record Symmetric Difference of Record 1 & Record 2 is as follows:");
	                    /*PRINTING RECORDS*/
	                    for(i=0;i<num;i++)
	                    {
		                    printf("\n\nBook No.: %d\n",(i+1));
		                    printf("Author Name:  ");
	                        puts(book3[i].author_name);
	                        printf("Book Name:  ");
		                    puts(book3[i].book_name);
		                    printf("Publication Year:  %u\n",book3[i].publication_year);
		                    printf("Copies Available:  %u",book3[i].copies_available);
	                    }
						break;
		           }
		    default :{
			            break; 
			         }
		}
		/*WRITING INTO THE FILE*/
	    printf("\n\n*****WRITING INTO FILE*****");
        fp=fopen("record.txt","w");
        i=0;
        num=get_num_records(book1);
        for(i=0;i<num;i++)
        {
            fprintf(fp,"%s %s %u %u",book1[i].author_name,book1[i].book_name,book1[i].publication_year,book1[i].copies_available);
        }
        fclose(fp);
        printf("\n*****END WRITING INTO FILE*****");
		/*ASKING FOR CHOICE*/
		printf("\n\n********If You wan't to continue? PRESS\ny: CONTINUE\nn: STOP\n");
		gets(dumbo);
		printf("\n$$$$$$$$$Choose:  ");
		scanf("%c",&choice);
	}
	while(choice!='n');
}
