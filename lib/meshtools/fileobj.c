#include "fileobj.h"

int fobj_read(char* fileName, mesh_t* mesh) {
    FILE* f = fopen(fileName, "rb");
    if (f == NULL) {
        printf("failed to open file.\n");
        return -1;
    }
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char *content = malloc(fsize + 1);
    fread(content, fsize, 1, f);
    fclose(f);
    
    int vertexCount = 0;
    int faceCount = 0;
    for (int i = 0; i < fsize - 1; ++i) {
        if (content[i] == 'v' && content[i+1] == ' ') {
            vertexCount++;
        } else if (content[i] == 'f' && content[i+1] == ' ') {
            faceCount++;
        }
    }
    
    content[fsize] = 0;
    
    mesh_alloc(mesh, vertexCount, faceCount);
    for (int i = 0, vi = 0, fi = 0, fii = 0; i < fsize; ++i) {
        while (content[i] == ' ') ++i;
        if (content[i] == '#') {
            // ignore comments
        } else {
            // read command
            char command[7];
            int k = 0;
            for (; content[i] != ' '; k++,++i) {
                command[k] = content[i];
            }
            command[k] = '\0';
            while (content[i] == ' ') ++i;
            
            if (strcmp(command, "v") == 0) {
                // vertex command
                for (int c = 0; c < 3; c++) {
                    char vertexComponentStr[256];
                    int j = 0;
                    for (; content[i] != ' ' && content[i] != '\n'; j++, ++i) {
                        vertexComponentStr[j] = content[i];
                    }
                    vertexComponentStr[j] = '\0';
                    
                    double vertexComponent = atof(vertexComponentStr);
                    switch (c) {
                        case 0:
                            mesh->vertices[vi].x = vertexComponent;
                            break;
                        case 1:
                            mesh->vertices[vi].y = vertexComponent;
                            break;
                        case 2:
                            mesh->vertices[vi].z = vertexComponent;
                            break;
                        default:
                            fprintf(stderr, "obj_read() failed\n");
                            return 1;
                    }
                    while (content[i] == ' ') ++i;
                }
                ++vi;
            } else if (strcmp(command, "f") == 0) {
                // face command
                int faceLength = 0;
                for (; content[i] != '\n'; faceLength++) {
                    char faceComponent[16];
                    int j = 0;
                    for (; content[i] != ' ' && content[i] != '\n'; j++, ++i) {
                        // TODO: should read other coordinates too, currently just cutting them off
                        faceComponent[j] = content[i];
                    }
                    faceComponent[j] = '\0';
                    
                    mesh->faces[fi].vertices[faceLength] = atoi(faceComponent);
                    while (content[i] == ' ') ++i;
                }
                mesh->faces[fi].vertex_count = faceLength;
                ++fi;
            }
        }
        // traverse to EOL
        while (content[i] != '\n') ++i;
    }
    
    free(content);
    return 0;
}
