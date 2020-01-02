#include<sys/types.h>
#include<wait.h>
#include "errors.h"

int main(){
	int status;
	char line[128];
	int seconds;
	pid_t pid;
	char message[64];

	while(1){
		printf("Alarm> ");
		if (fgets(line, sizeof(line), stdin)==NULL) exit(0);
		if (strlen(line)<= 1) continue;
		/*
		*	parse input line into seconds (%d) and a message
		*  (%63[^\n]), consisting of up to 64 characters
		*/
		if(sscanf(line, "%d %64[^\n]", &seconds, message)<2){
			fprintf(stderr, "Bad Commands\n");

		} else {
			pid = fork();
			if(pid==(pid_t)-1) errno_abort("Fork");
			if(pid==(pid_t)0){
				/*
					in the child, wait and then print messages
				*/
				sleep(seconds);
				printf("(%d) %s\n", seconds, message);
				exit(0);
			} else {
				/*
					in the parent call wait pid()
				*/
				do {
					pid=waitpid((pid_t)-1, NULL, WNOHANG);
					if(pid==(pid_t)-1) errno_abort("Wait for child");

				} while (pid != (pid_t)0);

			}
		}

	}
}
