#include <stdio.h>
#include <stdlib.h>

int *createSet();
void deleteSet(int *s);
int isEmpty(int *s);
int cardinality(int *s);
int isElement(int x, int *s);
int addElement(int x, int **s);
int removeElement(int x, int *s);
int isSubset(int *a, int *b);
int isEqual(int *a, int *b);
int isDisjoint(int *a, int *b);
int *intersection(int *a, int *b);
int *Union(int *a, int *b);
int *difference(int *a, int *b);

int *createSet()
{
    return (int *)calloc(100, sizeof(int));
}

void deleteSet(int *s)
{
    if (s != NULL) {
        free(s);
    }
}

int isEmpty(int *s)
{
    for (int i = 0; i < 100; i++) {
        if (s[i] != 0) {
            return 0;
        }
    }
    return 1;
}

int cardinality(int *s) {
    int count = 0;
    for (int i = 0; i < 100; i++) {
        count += s[i];
    }
    return count;
}

int isElement(int x, int *s) {
    for (int i = 0; i < 100; i++) {
        if (s[i] == x) {
            return 1;
        }
    }
    return 0;
}

int addElement(int x, int **s) {
    if ((*s == NULL) || (x < 0 || x >= 100)) {
        return 0;
    }

    if ((*s)[x] == 1) {
        return 0;
    }

    (*s)[x] = 1;
    return 1;
}

int removeElement(int x, int *s) {
    if ((s == NULL) || (x < 0 || x >= 100)) {
        return 0;
    }

    if (s[x] == 0) {
        return 0;
    }

    s[x] = 0;
    return 1;
}

int isSubset(int *a, int *b) {
    for (int i = 0; i < 100; i++) {
        if (a[i] > b[i]) {
            return 0;
        }
    }
    return 1;
}

int isEqual(int *a, int *b) {
    int i;
    for (int i = 0; i < 100; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

int isDisjoint(int *a, int *b) {
    for (int i = 0; i < 100; i++) {
        if (a[i] == 1 && b[i] == 1) {
            return 0;
        }
    }
    return 1;
}

int *intersection(int *a, int *b) {
    int *s = createSet();
    for (int i = 0; i < 100; i++) {
        s[i] = a[i] * b[i];
    }
    return s;
}

int *Union(int *a, int *b) {
    int *s = createSet();
    for (int i = 0; i < 100; i++) {
        if (a[i] == 1 || b[i] == 1) {
            s[i] = 1;
        }
        else {
            s[i] = 0;
        }
    }
    return s;
}

int *difference(int *a, int *b) {
    int *s = createSet();
    for (int i = 0; i < 100; i++) {
        if (a[i] == 1) {
            s[i] = a[i] - b[i];
        }
    }
    return s;
}

int main()
{

}
