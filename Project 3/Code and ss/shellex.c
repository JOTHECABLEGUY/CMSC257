/* $begin shellmain */
#include "csapp.h"
#define MAXARGS   128

/* Function prototypes */
void eval(char *cmdline);
int parseline(char *buf, char **argv);
int ownCmdHandler(char **argv); 
void intHandler(int);

/* Shell main function */
int main(int argc, char* argv[]) 
{
	char cmdline[MAXLINE]; /* Command line */

	/* Checks for -p before entering shell */
	while (1) {
		signal(SIGINT, intHandler);
		if(argc > 1){
			if(!strcmp(argv[1], "-p"))
				printf("%s>", argv[2]);
		}
		else
			printf("my257sh>");

		/* Read */                   
		Fgets(cmdline, MAXLINE, stdin); 
		if (feof(stdin))
			exit(0);

		/* Evaluate */
		eval(cmdline);
	} 
}
/* $end shellmain */

/* Builtin function to print working directory */
void printDir(){
	char cwd[MAXLINE];
	getcwd(cwd, sizeof(cwd));
	printf("Dir: %s\n", cwd);
}

/* Builtin help function print list of usable commands refers user to man pages for other commands */
void getHelp(){
	puts("\n***WELCOME TO MY257SH HELP***"
			"\n\t BY Jordan Dube"
			"\n List of available builtin commands:"
			"\n >pid"
			"\n >ppid"
			"\n >cd"
			"\n >ls"
			"\n >quit"
			"\n >./(executable name) -p (custom name) change the name" 
			"\nof the shell to the input custom name"
			"\n\t all other unix commands can be used, use \"man help\"" 
			"\n\t for help with non builtin commands.");
	return;
}

/* Builtin function to get pid of shell */
void pid(){
	printf("%d\n", getpid());
	return;
}

/* Builtin function to get ppid of shell */
void ppid(){
	printf("%d\n", getppid());
	return;
}

/* Builtin function to change the directory */
void changeDir(char* d, char** parsed){
	char f[MAXLINE];
	getcwd(f, sizeof(f));
	printDir();
	chdir(d);
	char g[MAXLINE];
	getcwd(g, sizeof(g));
	/* Checks if new directory is different than original directory */
	if (strcmp(f, g) != 0)
		printDir();
	return;
}

/* Command Handler to execute builtin commands */
int ownCmdHandler(char** parsed)
{
	int NoOfOwnCmds = 5, i, switchOwnArg = 0;
	char* ListOfOwnCmds[NoOfOwnCmds];
	ListOfOwnCmds[0] = "quit";
	ListOfOwnCmds[1] = "cd";
	ListOfOwnCmds[2] = "help";
	ListOfOwnCmds[3] = "pid";
	ListOfOwnCmds[4] = "ppid";

	/* Determines if passed function is a builtin command. If so, passes the function to the switch statement */
	for (i = 0; i < NoOfOwnCmds; i++) {
		if (strcmp(parsed[0], ListOfOwnCmds[i]) == 0) {
			switchOwnArg = i + 1;
			break;
		}
	}
	if (!strcmp(parsed[0], "&"))    /* Ignore singleton & */
		return 1;
	switch (switchOwnArg) {
		case 1:
			printf("Goodbye\n");
			raise(SIGTERM);
		case 2:
			changeDir(parsed[1], parsed);
			return 1;
		case 3:
			getHelp();
			return 1;
		case 4:
			pid();
			return 1;
		case 5:
			ppid();
			return 1;
		default:
			break;
	}
	return 0;
}

/* Signal handler to ignore input SIGTERM signal */ 
void intHandler(int sig){
	return;
}

/* $begin eval */
/* eval - Evaluate a command line */
void eval(char *cmdline) 
{
	char *argv[MAXARGS]; /* Argument list execvp() */
	char buf[MAXLINE];   /* Holds modified command line */
	int bg;              /* Should the job run in bg or fg? */
	pid_t pid;           /* Process id */
	int status;
	strcpy(buf, cmdline);
	bg = parseline(buf, argv); 
	if (argv[0] == NULL)  
		return;   /* Ignore empty lines */
	if (!ownCmdHandler(argv)) { 
		if ((pid = Fork()) == 0) {   /* Child runs user job */
			if (execvp(argv[0], argv) < 0) {
				printf("%s: Command not found.\n", argv[0]);
				exit(1);  
			}

		}
		/* Parent waits for foreground job to terminate */
		if (!bg) {
			if (waitpid(pid, &status, 0) < 0)
				unix_error("waitfg: waitpid error");   
			else
				printf("child exit status: %d\n", WEXITSTATUS(status)); /* Prints out child's exit status */
		}
		else  
			printf("%d %s", pid, cmdline);
	}
	return;
}
/* $end eval */

/* $begin parseline */
/* parseline - Parse the command line and build the argv array */
int parseline(char *buf, char **argv) 
{
	char *delim;         /* Points to first space delimiter */
	int argc;            /* Number of args */
	int bg;              /* Background job? */
	buf[strlen(buf)-1] = ' ';  /* Replace trailing '\n' with space */
	while (*buf && (*buf == ' ')) /* Ignore leading spaces */
		buf++;

	/* Build the argv list */
	argc = 0;
	while ((delim = strchr(buf, ' '))) {
		argv[argc++] = buf;
		*delim = '\0';
		buf = delim + 1;
		while (*buf && (*buf == ' ')) /* Ignore spaces */
			buf++;
	}
	argv[argc] = NULL;

	if (argc == 0)  /* Ignore blank line */
		return 1;

	/* Should the job run in the background? */
	if ((bg = (*argv[argc-1] == '&')) != 0)
		argv[--argc] = NULL;

	return bg;
}
/* $end parseline */
