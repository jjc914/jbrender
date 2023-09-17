#include "input.h"

static int term_start(struct termios* iterm) {
    struct termios nterm;
    if (tcgetattr(STDIN_FILENO, iterm)) {
        return 1;
    }
    nterm = *iterm;
    nterm.c_lflag &= ~(ECHO);
    nterm.c_lflag &= ~(ICANON);
    if (tcsetattr(STDIN_FILENO, TCSANOW, &nterm)) {
        return 1;
    }
    return 0;
}

static int term_stop(struct termios* iterm) {
    if (tcsetattr(STDIN_FILENO, TCSANOW, iterm)) {
        return 1;
    }
    return 0;
}

static int empty_ibuff() {
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(STDIN_FILENO, &rfds);

    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;

    select(STDIN_FILENO + 1, &rfds, NULL, NULL, &timeout);
    return !FD_ISSET(STDIN_FILENO, &rfds);
}

static int kmatch(kblistener_t* kbl, char* kseq) {
    for (int i = 0; i < kbl->kseq_count; ++i) {
        int matched = 1;
        for (int seqi = 0; seqi < kbl->kseq_length; ++seqi) {
            if (kseq[seqi] != kbl->kdata[i * kbl->kseq_length + seqi]) {
                matched = 0;
                break;
            }
        }
        if (matched) return 1;
    }
    return 0;
}

static void* thread_start(void* arg) {
    fprintf(stdout, "kblistener thread started\n");
    
    kblistener_t* kbl = (kblistener_t*)arg;
    while (1) {
        char kseq[kbl->kseq_length];
        if (read(STDIN_FILENO, &kseq[0], 1) != 1) {
            fprintf(stderr, "read(...) failed\n");
        }
        
        int i;
        for (i = 1; !empty_ibuff() && i < kbl->kseq_length; ++i) {
            if (read(STDIN_FILENO, &kseq[i], 1) != 1) {
                fprintf(stderr, "read(...) failed\n");
            }
        }
        
        if (kmatch(kbl, kseq)) {
            (*kbl->onHeard)(kseq, kbl->kseq_length);
        }
    }
    return NULL;
}

void kbl_alloc(kblistener_t* kbl, int kseqCount, int kseqLength, void* onHeard) {
    kbl->kseq_count = kseqCount;
    kbl->kseq_length = kseqLength;
    kbl->kdata = malloc(kseqCount * kseqLength * sizeof(char));
    kbl->onHeard = onHeard;
    kbl->iterm = malloc(sizeof(struct termios));
}

int kbl_set(kblistener_t* kbl, char* kdata, int len) {
    if (len != kbl->kseq_count * kbl->kseq_length) return 1;
    memcpy(kbl->kdata, kdata, len * sizeof(char));
    return 0;
}

int kbl_start(kblistener_t* kbl) {
    if (term_start(kbl->iterm)) {
        return 1;
    }
    if (pthread_create(&kbl->thread_id, NULL, thread_start, (void*)kbl)) {
        return 1;
    }
    return 0;
}
    
int kbl_stop(kblistener_t* kbl) {
    fprintf(stdout, "kblistener thread stopped\n");
    // stop thread
    if (pthread_cancel(kbl->thread_id)) {
        return 1;
    }
    return term_stop(kbl->iterm);
}

void kbl_free(kblistener_t* kbl) {
    free(kbl->kdata);
    free(kbl->iterm);
}
