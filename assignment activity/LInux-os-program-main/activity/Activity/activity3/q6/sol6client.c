#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main() {
  int rett, nbytes;
  mqd_t mqid;
  struct mq_attr1 attr1;
  struct stat sb;
  attr1.mq_msgsize = 256;
  attr1.mq_maxmsg = 10;
  mqid = mq_open("/mque", O_CREAT | O_RDWR, 0555, &attr1);
  if (mqid < 0) {
    perror("mq_open");
    exit(1);
  }

  char str[10] = "hello.c";
  rett = mq_send(mqid, str, 10, 5);
  if (rett < 0) {
    perror("mq_send");
    exit(2);
  }

  int maxlen = 256, prio;

  nbytes = mq_receive(mqid, (char *)&sb, 1024, &prio);
  if (nbytes < 0) {
    perror("mq_recv");
    exit(2);
  }
  printf("---File Attributes---\n");
  printf("ID of device containing file    : %ld\n", (long)sb.st_dev);
  printf("Inode number                    : %ld\n", (long)sb.st_ino);
  printf("File type                       : ");
  switch (sb.st_mode & S_IFMT) {
  case S_IFBLK:
  // block device
    printf("block device\n");
    break;
  case S_IFCHR:
  // charcter device
    printf("character device\n");
    break;
  case S_IFDIR:
  // directory 
    printf("directory\n");
    break;
  case S_IFIFO:
  //fifo /pipe
    printf("FIFO/pipe\n");
    break;
  case S_IFLNK:
  // simulink
    printf("symlink\n");
    break;
  case S_IFREG:
  // regulary files
    printf("regular file\n");
    break;
  case S_IFSOCK:
  // socket
    printf("socket\n");
    break;
  default:
  // unknow files
    printf("unknown?\n");
    break;
  }
  printf("Mode                            : %lo (octal)\n", (unsigned long)sb.st_mode);
  printf("Link count                      : %ld\n", (long)sb.st_nlink);
  printf("User ID                         : %ld\n" , (long)sb.st_uid);
  printf("Group ID                        : %ld\n", (long)sb.st_gid);
  printf("Blocksize for file system I/O   : %ld bytes\n", (long)sb.st_blksize);
  printf("File size                       : %lld bytes\n", (long long)sb.st_size);
  printf("Number of 512B Blocks allocated : %lld\n", (long long)sb.st_blocks);
  printf("Last status change              : %s", ctime(&sb.st_ctime));
  printf("Last file access                : %s", ctime(&sb.st_atime));
  printf("Last file modification          : %s", ctime(&sb.st_mtime));
  mq_close(mqid);

  return 0;
}


