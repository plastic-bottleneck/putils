#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

#define ANSI_COLOR_BLUE  "\x1b[34m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

void print_colored(const char *text, const char *color) {
    printf("%s%s%s", color, text, ANSI_COLOR_RESET);
}

int compare_entries(const struct dirent **a, const struct dirent **b) {
    return strcmp((*a)->d_name, (*b)->d_name);
}

void list_entries(const char *dirname, int show_sizes) {
    struct dirent **entries;
    int num_entries = scandir(dirname, &entries, NULL, compare_entries);

    if (num_entries < 0) {
        perror("ERROR: Error scanning directory");
        return;
    }

    for (int i = 0; i < num_entries; ++i) {
        struct dirent *entry = entries[i];
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", dirname, entry->d_name);

        struct stat file_stat;
        if (stat(full_path, &file_stat) == -1) {
            continue;
        }

        if (show_sizes) {
            if (entry->d_type == DT_DIR) {
                print_colored(entry->d_name, ANSI_COLOR_GREEN);
                printf("/ (%ld KB)\n", (long)(file_stat.st_size / 1024));
            } else {
                print_colored(entry->d_name, ANSI_COLOR_BLUE);
                if (file_stat.st_size < 1024) {
                    printf(" (%ld B)\n", (long)file_stat.st_size);
                } else {
                    printf(" (%ld KB)\n", (long)(file_stat.st_size / 1024));
                }
            }
        } else {
            print_colored(entry->d_name, ANSI_COLOR_RESET);
            printf(" ");
            
            if ((i + 1) % 10 == 0 || i == num_entries - 1) {
                printf("\n");
            }
        }

        free(entry);
    }

    free(entries);
}

int main(int argc, char *argv[]) {
    int show_sizes = 0;
    const char *dirname = ".";

    if (argc > 1) {
        if (strcmp(argv[1], "-l") == 0) {
            show_sizes = 1;
            if (argc > 2) {
                dirname = argv[2];
            }
        } else {
            dirname = argv[1];
        }
    }

    list_entries(dirname, show_sizes);

    return 0;
}
