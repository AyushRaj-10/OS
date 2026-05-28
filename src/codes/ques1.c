#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int opr(int x1,int x2, char op){
  if(op == '+') return x1+x2;
  else if(op == '-') return x1-x2;
  else if(op == '*') return x1*x2;
  else return x1/x2;
}

int main()
{
  int x1,x2;
  char op;
  printf("Enter two numbers: ");
  scanf("%d %d",&x1,&x2);
  printf("Enter an operator (+, -, *, /): ");
  scanf(" %c",&op);
  int pid = fork();
  if(pid == 0){
    // child process
    int ans = opr(x1,x2,op);
    printf("Result = %d\n", ans);
  }
  else{
    wait(NULL);
    printf("Child process completed");
    
  }
  return 0;
}