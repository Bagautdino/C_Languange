#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>



void search(char *dir_name) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_info;
    char path[1024];

    if ((dir = opendir(dir_name)) == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue;
        }

        snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);

        if (lstat(path, &file_info) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(file_info.st_mode)) {
            search(path);
        } else {
            printf("%s\n", path);
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <dir>\n", argv[0]);
        return 1;
    }

    search(argv[1]);

    return 0;
}