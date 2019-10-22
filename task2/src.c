#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int x /* = Cj */, int y /* = tm + d */) {
    return ((x > y) ? x : y);
}

int main() {
    int p1[10], p2[10], p3[10];
    int rec1[10], rec2[10], rec3[10];
    memset(p1,0,10 * sizeof(int));
    memset(p2,0,10 * sizeof(int));
    memset(p3,0,10 * sizeof(int));
    memset(rec1,0,10 * sizeof(int));
    memset(rec2,0,10 * sizeof(int));
    memset(rec3,0,10 * sizeof(int));
    int e, n,i,m1,m2;
    int sid, sev, rid, rev;
    int tm;
    int d = 3;
    printf("\n enter the no of events (Max 9)\n");
    scanf("%d",&e);
    if (e > 9 || e < 1) {
        printf("Invalid number of events");
        exit(1);
    }
    printf("\n enter the no of send-receive message between p1, p2 and p3\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        printf("Enter details for Message %d \n", i);
        printf("<sender pid> <sender event> <receiver pid> <receiver event>\n");
        scanf("%d %d %d %d", &sid, &sev, &rid, &rev);
        if (sid == rid) {
            printf("Invalid entry \n");
            exit(0);
        }
        if (rid == 1) {
            rec1[rev] = (sid << 16) | sev;
        } else if (rid == 2) {
            rec2[rev] = (sid << 16) | sev;
        } else if (rid == 3) {
            rec3[rev] = (sid << 16) | sev;
        } else {
            printf("Invalid entry\n");
            exit(1);
        }
    }

    // set 0 as 1 so event 1 will be 1 + 3 = 4
    p1[0] = 1;
    p2[0] = 1;
    p3[0] = 1;

    for(i=1;i<=e;i++) {

        p1[i] = p1[i-1] + d;
        p2[i] = p2[i-1] + d;
        p3[i] = p3[i-1] + d;

        if (rec1[i]) {
            sev = rec1[i] & 0xffff;
            sid = rec1[i] >> 16;
            if (sid == 2) {
                tm = p2[sev];
            } else {
                tm = p3[sev];
            }
            p1[i] = max(p1[i], tm + d);
        } 

        if (rec2[i]) {
            sev = rec2[i] & 0xffff;
            sid = rec2[i] >> 16;
            if (sid == 1) {
                tm = p1[sev];
            } else {
                tm = p3[sev];
            }
            p2[i] = max(p2[i], tm + d);
        } 

        if (rec3[i]) {
            sev = rec3[i] & 0xffff;
            sid = rec3[i] >> 16;
            if (sid == 2) {
                tm = p2[sev];
            } else {
                tm = p1[sev];
            }
            p3[i] = max(p3[i], tm + d);
        } 
    }

    printf("Timestamps of processes are:\n");
    printf("\n**");
    for(i=1;i<=e;i++) {
        printf("---<E%d>",i);
    }

    printf("\nP1");
    for(i=1;i<=e;i++) {
        printf("---<%2d>",p1[i]);
    }

    printf("\nP2");
    for(i=1;i<=e;i++) {
        printf("---<%2d>",p2[i]);
    }

    printf("\nP3");
    for(i=1;i<=e;i++) {
        printf("---<%2d>",p3[i]);
    }
    printf("\n");
    return 0;
}