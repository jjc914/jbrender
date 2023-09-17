#ifndef H_FILEOBJ
#define H_FILEOBJ

#include <string.h>

#include "mesh.h"

int fobj_read(char* fileName, mesh_t* mesh);
int fobj_write(char* fileName, mesh_t* mesh);

#endif
