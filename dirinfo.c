#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
  DIR * curdir = opendir( ".");
  struct dirent *file = readdir( curdir);
  while( file){
    printf( "%s\n", file->d_name);
    file = readdir( curdir);
  }
}
  
  
