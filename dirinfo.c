#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

//list all the files in the directory
void file_info( char * path){
  DIR * dir = opendir(path);
  int size = 0;
  struct stat * size_buff = malloc(sizeof(struct stat));
  struct dirent * file = readdir(dir);
  while(file){
    //specify which files are directories (if any)
    if(file->d_type == DT_DIR){
    printf( "Directory: %s\n", file->d_name);}
    else{
    //show the total size of all the regular files the directory
    stat(file->d_name, size_buff);
    size += size_buff->st_size;
    printf( "Regular File: %s\n", file->d_name);}
    file = readdir(dir);
}
  closedir(dir);
  printf("Total directory size: %d bytes\n", size);
}

int main( int argc, char *argv[]){
  //file_info(".");
  if( ! argv[1] || opendir(argv[1]) == NULL)
    printf("please enter a valid directory:\n");
  char directory[256];
  scanf( "%s", directory);
  DIR * d = opendir(directory);
  if (errno > 0) {
     printf("Error: %s\n",strerror(errno));
     return 0;
   }
  file_info( directory);
  return 0;
}
