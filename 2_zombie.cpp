//Zombie_Process

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
int main() {
	int p = fork();
	if( p > 0) {
		cout<<"-----------Parent Process-----------"<<endl;
		cout<<"Before Child Process dies"<<endl;
		cout<<"Parent Process: "<<getpid()<<endl;
		cout<<"Child Process: "<<p<<endl;
		sleep(10);
		cout<<endl<<"-----------Parent Process-----------"<<endl;
		cout<<"After Child Process dies"<<endl;
		cout<<"Parent Process: "<<getpid()<<endl;
		cout<<"ChildProcess: "<<p<<endl<<endl;
		system("ps -a1");
	}
	else {
		cout<<endl<<"-----------Child Process-----------"<<endl;
		cout<<"Child Process: "<<getpid()<<endl;
		cout<<"Parent Process: "<<getppid()<<endl;
		exit(0);
	}
	return 0;
}





***************************************************************************

The C++ program you provided demonstrates the creation of a zombie process. A zombie process is a child process that has finished its execution but still has an entry in the process table. The parent process hasn't yet collected the exit status of the child.

Here's a step-by-step explanation of your code:

int p = fork();:

Forks the process, creating a child process.
Returns the process ID (PID) of the child to the parent and 0 to the child.
if( p > 0) { ... } else { ... }:

The parent process executes the code inside the if block.
The child process executes the code inside the else block.
Parent Process:

Prints information about the parent and child processes.
Sleeps for 10 seconds to simulate a delay during which the child becomes a zombie.
Prints information again after the child process dies.
Uses system("ps -a1"); to display the process table.
Child Process:

Prints information about the child process and its parent.
Exits immediately, becoming a zombie.
system("ps -a1");:

Invokes the ps command to display the process table.
To run the program:

Save the C++ code in a file, for example, zombie_process.cpp.

Open a terminal and navigate to the directory containing the file.

Compile the program using a C++ compiler. For example:

bash
Copy code
g++ zombie_process.cpp -o zombie_process
Run the compiled executable:

bash
Copy code
./zombie_process
Observe the output, including the process information displayed by the ps command.

Please note that the ps command may vary based on your operating system. If you encounter issues, you can adjust the command accordingly.






