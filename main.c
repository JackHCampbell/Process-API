#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
 int filedesc = open("result.txt", O_CREAT | O_TRUNC | O_WRONLY, S_IWUSR);
//creating a new file named result.txt
  int rc = fork();
  if (rc < 0) {
    // fork failed; exit
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    // child (new process)
   write(filedesc,"If they write concurrently, then the child writes after the parent.\n", 68);
  } else {
    // parent goes down this path (original process)
    write(filedesc,"Both parent and child can access the file.\n", 42);
}
}