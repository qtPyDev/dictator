#include "proj_export.h"



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

    cJSON_free(json_str);
    cJSON_Delete(json);

    return 0;
}

