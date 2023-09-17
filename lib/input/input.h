#ifndef H_INPUT
#define H_INPUT

#define STDIN_FILENO 0
#define STDOUT_FILENO 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <termios.h>
#include <sys/select.h>
#include <unistd.h>

typedef struct kblistener {
    pthread_t thread_id;
    int kseq_count;
    int kseq_length;
    char* kdata;
    void (*onHeard)(char*, int);
    struct termios* iterm;
} kblistener_t;

void kbl_alloc(kblistener_t* kbl, int kseqCount, int kseqLength, void* onHeard);
int kbl_set(kblistener_t* kbl, char* kdata, int len);
int kbl_start(kblistener_t* kbl);
int kbl_stop(kblistener_t* kbl);
void kbl_free(kblistener_t* kbl);

#endif
