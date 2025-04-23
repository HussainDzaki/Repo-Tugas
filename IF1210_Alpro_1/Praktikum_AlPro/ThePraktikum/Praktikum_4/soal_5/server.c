#ifndef _SERVER_H
#define _SERVER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 256
#define MAX_BODY 512
/**
 * @brief Buka file bernama request.txt kemudian eksekusi. Output berupa file response.txt
 *
 */
void solution()
{
    FILE *FileReq = fopen("request.txt", "r");
    FILE *FileRes = fopen("response.txt", "w");

    char lines[MAX_LINE];
    char method[MAX_LINE];
    char path[MAX_LINE];
    char body[MAX_BODY] = "";
    char content[MAX_LINE] = "";
    char alamat[MAX_LINE];
    int contentlen;
    fscanf(FileReq, "%s %s %s", method, path, alamat);
    while (fgets(lines, MAX_LINE, FileReq) != NULL)
    {
        if (strstr(lines, "Content-Type:") != NULL)
        {
            strcpy(content, lines + 14);
        }
    }
    fgets(lines, MAX_BODY, FileReq);
    strcpy(body, lines);

    fprintf(FileRes, "%s 200 OK\n", alamat);
    fprintf(FileRes, "Content-Type: text/plain\n");
    
    fprintf(FileRes, "\n");
    fprintf(FileRes, "Method: %s\n", method);
    fprintf(FileRes, "Path: %s\n", path);
    if (content[0] != '\0')
    {
        fprintf(FileRes, "Content-Type: %s", content);
    }
    else{
        fprintf(FileRes, "Content-Type: N/A\n");
    }
    if ( body[0] != '\0' && body[0] == '{')
    {
        fprintf(FileRes, "Body: %s", body);
    }

    fclose(FileReq);
    fclose(FileRes);
    
}

#endif