// map_lib
// A simple associative-array library for C
//
// License: MIT / X11
// Copyright (c) 2009 by James K. Lawless
// jimbo@radiks.net http://www.radiks.net/~jimbo
// http://www.mailsend-online.com
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//
// -------------------------------------------------------------------
// Portions Copyright (c) 2013 by Juergen Edelbluth
// dev@jued.de https://github.com/edelbluth/map_lib
// Published under the same license (MIT / X11)
// -------------------------------------------------------------------
// Forked from:
// https://github.com/jimlawless/map_lib/
// commit d3977cebcd229428fa9958aa840dbd1c003c3815
// -------------------------------------------------------------------
// Changes by Juergen Edelbluth
// * Formatting
// * stricmp -> strcmp (making the map case sensitive)
// map -> mp (avoid reserved name collision)
// -------------------------------------------------------------------

#include "map_lib.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct map_t *map_create()
{
    struct map_t *m;
    m = (struct map_t *) malloc(sizeof(struct map_t));
    m->name = NULL;
    m->value = NULL;
    m->nxt = NULL;
}

void map_set(struct map_t *m, char *name, char *value)
{
    struct map_t *mp;
    if(m->name == NULL)
    {
        m->name = (char *) malloc(strlen(name) + 1);
        strcpy(m->name, name);
        m->value = (char *) malloc(strlen(value) + 1);
        strcpy(m->value, value);
        m->nxt = NULL;
        return;
    }
    for(mp = m; ; mp = mp->nxt)
    {
        if (!stricmp(name, mp->name))
        {
            if (mp->value != NULL)
            {
                free(mp->value);
                mp->value = (char *) malloc(strlen(value) + 1);
                strcpy(mp->value, value);
                return;
            }
        }
        if (mp->nxt == NULL)
        {
            mp->nxt = (struct map_t *) malloc(sizeof(struct map_t));
            mp = mp->nxt;
            mp->name = (char *) malloc(strlen(name) + 1);
            strcpy(mp->name, name);
            mp->value = (char *) malloc(strlen(value) + 1);
            strcpy(mp->value, value);
            mp->nxt = NULL;
            return;
        }
    }
}

char *map_get(struct map_t *m, char *name)
{
    struct map_t *mp;
    for(mp = m; mp != NULL; mp = mp->nxt)
    {
        if(!stricmp(name, mp->name))
        {
            return mp->value;
        }
    }
    return NULL;
}
