#include <stdio.h>
#include <string.h>
#include "cjson/cJSON.h"



#define MAX_TEXT 128


struct scene {
    int chapter;
    int episode;
    char type[20];
    char text[MAX_TEXT];
};


int export_to_json(struct scene scn) {
    cJSON *json = cJSON_CreateObject();
    cJSON_AddNumberToObject(json, "chapter", scn.chapter);
    cJSON_AddNumberToObject(json, "episode", scn.episode);
    cJSON_AddStringToObject(json, "type", scn.type);
    cJSON_AddStringToObject(json, "text", scn.text);

    char *json_str = cJSON_Print(json);

    FILE *fp = fopen("dictator_test.json", "w");
    if (fp == NULL) {
        printf("ERROR: Unable to open the file.\n");
        return 1;
    }

    printf("%s\n", json_str);
    fputs(json_str, fp);
    fclose;

    cJSON_free(json_str);
    cJSON_Delete(json);

    return 0;
}


int main() {
    struct scene scn;

    scn.chapter = 1;
    scn.episode = 2;
    strcpy(scn.type, "dialogue");
    strcpy(scn.text, "this is a sentence !");

    export_to_json(scn);
}
