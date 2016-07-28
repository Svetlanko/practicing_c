#include <stdio.h>
#include <string.h>

#define MAXLINES 5000    //maximum number of lines to sort
#define MAXLEN 1000  //max length of any input line

char *lineptr[MAXLINES];  //pointers to text lines 
int getline(char *, int);
char *alloc(int);

int readlines(char *line_pointers[], int number_of_lines);
void writelines(char *line_pointers[], int number_of_lines);
void qsort(char *lineptr[], int left, int right);

int main(void) {
	int number_of_lines;
	
	if ((number_of_lines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, number_of_lines - 1);
		writelines(lineptr, number_of_lines);
		return 0;
	} else {
		printf("Error: input too big to sort. Limit is %i\n", MAXLINES);
		return 1;
	}
}

//==================================================
int readlines(char *line_pointers[], int maxlines) {
	int length, number_of_lines;
	char *p, line[MAXLEN];
	
	number_of_lines = 0;
	while ((length = getline(line, MAXLEN)) > 0) {
		if (number_of_lines >= maxlines || (p = alloc(length)) == NULL)
			return -1;
		else {
			line[length-1] = '\0'; // to delete new line
			strcpy(p, line);
			line_pointers[number_of_lines++] = p;
		}
	}
	return number_of_lines;
}

void writelines(char *line_pointers[], int number_of_lines) {
	int i;
	
	for (i=0; i < number_of_lines; i++)
		printf("%s\n", line_pointers[i]);
}

void qsort(char *v[], int left, int right) {
	int i, last;
	void swap(char *v[], int i, int j);
	
	if (left >= right) 
		return;
		
	swap(v, left, (left + right)/2);
	last = left;
	for (i= left+1; i <= right; i++) {
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	}
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void swap(char *v[], int i, int j) {
	char *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}