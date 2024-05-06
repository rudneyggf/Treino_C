// APENAS WINDOWS

#include <windows.h>

#define Cs4 277
#define C6 1046
#define B6 1975
#define C7 2093

void sominicio() {
    Beep(Cs4, 100);
    Beep(C6, 100);
    Beep(C7, 100);
}

void somvitoria() {
    Beep(B6, 200);
    Beep(C7, 950);
}

void somderrota() {
    Beep(C6, 200);
    Beep(Cs4, 950);
}
