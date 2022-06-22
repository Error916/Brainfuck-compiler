#include <stdio.h>

#define DATASIZE 1023

void brainfuck(char *cmd_ptr, char *input){
	int b_flag;
	char cmd;
	char data[DATASIZE] = {0};
	char *dp = &data[DATASIZE/2];

	while(cmd = *cmd_ptr++){
		switch(cmd){
			case '>':
				dp++;
				break;
			case '<':
				dp--;
				break;
			case '+':
				(*dp)++;
				break;
			case '-':
				(*dp)--;
				break;
			case '.':
				printf("%c", *dp);
				break;
			case ',':
				*dp = *input++;
				break;
			case '[':
				if(!*dp){
					for(b_flag = 1; b_flag; cmd_ptr++){
						if(*cmd_ptr == '[') b_flag++;
						else if(*cmd_ptr == ']') b_flag--;
					}
				}
				break;
			case ']':
				if(*dp){
					cmd_ptr -= 2;
					for(b_flag = 1; b_flag; cmd_ptr--){
						if(*cmd_ptr == ']') b_flag++;
						else if(*cmd_ptr == '[') b_flag--;
					}
					cmd_ptr++;
				}
				break;
		}
	}

	printf("\n");
}

int main(int argc, char **argv){

	if(argc != 3){
		printf("use: %s program input\n", argv[0]);
	}

	brainfuck(argv[1], argv[2]);

	return 0;
}
