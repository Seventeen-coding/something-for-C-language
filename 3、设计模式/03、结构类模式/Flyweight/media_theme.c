#include "media_theme.h"


Media_Theme *createtheme(const char *skin, const char *font)
{
    Media_Theme * theme = NULL;
    if(skin == NULL || font == NULL)
    {
        return NULL;
    }
    theme = malloc(sizeof (Media_Theme));
    if(theme == NULL)
    {
        return NULL;
    }
    strcpy(theme->skin,skin);
    strcpy(theme->font,font);
    return theme;
}
