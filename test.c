#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int x;
    FILE *file = fopen("/proc/meminfo", "r");
    
    if (file == NULL) {
        printf("Dosya açılamadı.\n");
        return 1;
    }

    else {
        for (x = 0; x < 3; x++) {
            char line[256];
            fgets(line, sizeof(line), file);
            printf("%s", line);
        }
    }
    fclose(file);
    return 0;
}