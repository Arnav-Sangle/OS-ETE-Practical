#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

#define FIFO_NAME1 "com_pipe1"
#define FIFO_NAME2 "com_pipe2"

int main(){
	
	char s[300], vowel[20], send[50];

	
	int num, fd1, fd2, sig, k = 0, i, wordcnt = 1, charcnt = 0, linecnt = 0;

	
	fd1 = open(FIFO_NAME1, O_RDONLY);
	if (fd1 == -1) {
		perror("open");
		exit(1);
	}

	fd2 = open(FIFO_NAME2, O_WRONLY);
	if (fd2 == -1) {
		perror("open");
		exit(1);
	}

	
	num = read(fd1, s, 300);
	if (num == -1) {
		perror("read");
		exit(1);
	}

	
	s[num] = '\0';

	
	printf("tick: read %d bytes: \"%s\"\n", num, s);

	
	vowel[0] = '\0';

	
	for (i = 0; i < num; i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			vowel[k] = s[i];
			k++;
		}

		if (s[i] != ' ' && s[i] != '\0') {
			wordcnt++;
		}

		if (s[i] == '.' && (s[i + 1] == ' ' || s[i + 1] == '\0')) {
			linecnt++;
		} else if (s[i] != '.' && s[i] != ' ') {
			charcnt++;
		}
	}

	
	vowel[k] = '\0';

	
	sprintf(send, "for the given sentence the word count is %d\n vowel cnt is %d \n character count is %d \nlines are %d\n", wordcnt, k, charcnt, linecnt);

	
	sig = write(fd2, send, strlen(send));
	if (sig == -1) {
		perror("write");
		exit(1);
	} else {
		printf("\nwriten successfully to file 2\n");
	}

	
	close(fd1);
	close(fd2);

	return 0;
}
