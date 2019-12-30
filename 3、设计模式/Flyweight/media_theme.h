#ifndef MEDIA_THEME_H
#define MEDIA_THEME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 256

typedef struct _Media_Theme{
    char skin[MAX_LEN];
    char font[MAX_LEN];
}Media_Theme;

Media_Theme *createtheme(const char *skin,const char *font);

#endif // MEDIA_THEME_H
