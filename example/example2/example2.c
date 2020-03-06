#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// A vulnerable function
void vuln_func(char *buf) {
    char vulnerable_buffer[16];

    // a buffer overflow vulnerability
    strcpy(vulnerable_buffer, buf);
}

int main() {
    char buf[128];
    fgets(buf, 128, stdin);

    int *value = (int*)buf;

    if (*value == 0x55534f5f) {  // if first 4 character of buf is _OSU
        printf("Content: %s\n", buf);
        vuln_func(buf);
        exit(0);
    }
    printf("Wrong password!\n");
    exit(-1);
}
