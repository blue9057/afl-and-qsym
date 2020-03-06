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

    int x = buf[0];     // 0x5f
    int y = buf[1];     // 0x4f
    int z = buf[2];     // 0x53
    int w = buf[3];     // 0x55

    if ((x+y)*(z+w) == 29232 && (x+y+z)*w == 21845) {
        // if first 4 character of buf is _OSU
        printf("Content: %s\n", buf);
        vuln_func(buf);
        exit(0);
    }
    printf("Wrong password!\n");
    exit(-1);
}
