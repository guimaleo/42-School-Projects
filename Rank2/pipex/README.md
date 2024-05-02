# Pipex
This project will let you discover in detail a UNIX mechanism that you already know by using it in your program


The time has finally come to delve into the intricacies of UNIX. It's amusing how one of my most cherished discoveries during Libft at Rank 1 was about file descriptors. I still recall the struggles I faced during testing...

Nah, I couldn't confine myself to the basics of sending output to STDOUT. I wanted to see it in action, to create archives, append data, and more.

**Yeah, it was truly worth it!**

I suppose now that we need to know how to do it, having experienced my own struggles before, understanding the concepts of pipes for Pipex comes more easily.


![mario](https://github.com/guimaleo/pipex/assets/128752196/9a1a0fd4-19c9-4919-ba7c-f37a295749a5)


<details>
  <summary>Pipex Allowed Functions</summary>

- open
  - int  open(const char *path, int oflag, ...);
- close
  -  int  close(int fildes);
- read
  - ssize_t  read(int fildes, void *buf, size_t nbyte);
- write
  -  ssize_t write(int fildes, const void *buf, size_t nbyte);
- malloc
  - void  *malloc(size_t size);
- free
  - void  free(void *ptr);
- perror
  - void  perror(const char *s);
- strerror
  - char  *strerror(int errno);
- access
  - int  access(const char *path, int **amode**)
- dup and dup2
  - int  dup(int fildes);
  - int  dup2(int fildes, int fildes2);
- execve
  - int  execve(const char *path, char *const argv[], char *const envp[]);
- exit
  - void  exit(int **status**)
- fork
  - pid_t  fork(*void*);
- pipe
  - int  pipe(int fildes[2]);
- unlink
  - int  unlink(const char *path);
- wait and waitpid
  - pid_t  wait(int *stat_loc);
  - pid_t  wait(pid_t pid, int *stat_loc, int options);

</details>
