#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <conio.h>
#include <string.h>
#define TOTAL_RECORDS 10
#define A_NAME_LEN 32
#define B_NAME_LEN 100
enum status{NO,YES};
struct book_record
{
	char author_name[A_NAME_LEN];
	char book_name[B_NAME_LEN];
	unsigned int publication_year;
	unsigned int copies_available;
};
void sort_list(struct book_record []);
void initialize_record(struct book_record [],int);
int get_num_records(struct book_record []);
int num_records(struct book_record [],int,int);
void list_unique(struct book_record []);
void delete_list_unique(struct book_record [],int);
enum status is_empty(struct book_record []);
enum status is_full(struct book_record []);
int search_record(struct book_record [],char [],char []);
int find_record(struct book_record [],char [],char [],int,int);
void num_avail_copies(struct book_record [],char [],char []);
enum status delete_record(struct book_record [],char [],char []);
enum status insert_record(struct book_record [],char [],char [],unsigned int,unsigned int);
void initial_reading(struct book_record [],int);
int get_topmost_author(struct book_record [],char []);
int list_union(struct book_record [],struct book_record [],struct book_record []);
int list_intersection(struct book_record [],struct book_record [],struct book_record []);
int list_difference(struct book_record [],struct book_record [],struct book_record []);
int list_symmetric_difference(struct book_record [],struct book_record [],struct book_record [],struct book_record [],struct book_record []);
void remove_space_make_uppercase(char []);

#endif
