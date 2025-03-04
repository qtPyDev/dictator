#ifndef fileio_h
#define fileio_h


#include <stdio.h>
#include <string.h>
#include "lib/cJSON.h"


#define MAX_TYPE 20
#define MAX_TEXT 128


struct scene {
    int chapter;
    int episode;
    char type[MAX_TYPE];
    char text[MAX_TEXT];
};


int export_to_json(struct scene scn);


#endif
