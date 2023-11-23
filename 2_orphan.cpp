//Orphan Process

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
int main() {
	int p = fork();
	if( p > 0) {
		cout<<"-----------In Parent Process-----------"<<endl;
		cout<<"Parent Process1: "<<getpid()<<endl;
		cout<<"Child Process1: "<<p<<endl<<endl;
		exit(0);
		
	}
	else {
		cout<<"-----------In Child Process-----------"<<endl;
		cout<<"(Before parent process dies)"<<endl;
		cout<<"Child Process2: "<<getpid()<<endl;
		cout<<"Parent Process2: "<<getppid()<<endl;
		sleep(10);
		cout<<endl<<"-----------In Child Process-----------"<<endl;
		cout<<"(After parent process dies)"<<endl;
		cout<<"Child Process2: "<<getpid()<<endl;
		cout<<"Parent Process2: "<<getppid()<<endl;
		system("ps -a1");
	}
	return 0;
}

********************************************************
Explanation with commands:

int p = fork();:

Forks the process, creating a child process.
Returns the process ID (PID) of the child to the parent and 0 to the child.
if (p > 0) { ... } else { ... }:

The parent process executes the code inside the if block.
The child process executes the code inside the else block.
Parent Process:

Prints information about the parent and child processes.
exit(0);: Parent exits, creating an orphan child.
Child Process:

Prints information about the child process and its parent.
sleep(10);: Sleeps for 10 seconds (before parent process dies).
Prints information again after the parent process dies.
system("ps -a1");: Invokes the ps command to display the process table.
To run the program:

Save the C++ code in a file, e.g., orphan_process.cpp.
Open a terminal and navigate to the directory containing the file.
Compile the program using a C++ compiler, for example:
bash
Copy code
g++ orphan_process.cpp -o orphan_process
Run the compiled executable:
bash
Copy code
./orphan_process
Observe the output, including the process information displayed by the ps command.





