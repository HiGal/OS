#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void increase_age (int frames);
int old_index (int frames);

struct FrameTable{
	int page_number;
	int age;
}*FrameTable;

struct PageTable{
	int frame_num;
	bool valid;
}*PageTable;


int main(void)
{


	printf("Number of frames\n");
	int frames;
	scanf("%d", &frames);

	PageTable = malloc(sizeof(PageTable));
	FrameTable = malloc(sizeof(FrameTable)*frames);

	FILE *file_path = fopen("input.txt", "r");

	for (int i = 0; i < frames; ++i)
	{
		FrameTable[i].age = 0;
	}

	int request;
	int ftable_counter = 0;
	int miss_counter = 0;
	int request_counter = 0;
	int hit_counter = 0;

	while(!feof(file_path)){
		fscanf(file_path,"%d", &request);
		request_counter++;
		if(PageTable[request].valid == false){
			FrameTable[ftable_counter].page_number = request;
			PageTable[request].valid = true;
			PageTable[request].frame_num = ftable_counter;
			miss_counter++;
			ftable_counter++;
		}else{
			hit_counter++;
		}

		if(ftable_counter == frames){
			break;
		}
	}

	while(!feof(file_path)){
		fscanf(file_path,"%d", &request);
		request_counter++;
		increase_age(frames);
		if (PageTable[request].valid == false){
			int old_page = old_index(frames);
			PageTable[FrameTable[old_page].page_number].valid = false;
			FrameTable[old_page].page_number = request;
			FrameTable[old_page].age = 0;
			PageTable[request].valid = true;
			PageTable[request].frame_num = old_page;
			miss_counter++;
		}else{
			hit_counter++;
		}
		
	}

	printf("Total miss  %d\n", miss_counter);
	printf("Total hit  %d\n", hit_counter);
	printf("Total hit/miss ratio %f\n",(float)hit_counter / (float)miss_counter );
	fclose(file_path);
	
	free(PageTable);
	free(FrameTable);
	return 0;
}

void increase_age(int frames){
	for (int i = 0; i < frames; ++i)
	{
		FrameTable[i].age++;
	}
}

int old_index(int frames){
	int oldest = -1;
	int index;
	for (int i = 0; i < frames; ++i)
	{
		if(oldest<FrameTable[i].age){
			oldest = FrameTable[i].age;
			index = i;
		}
	}
	return index;
}