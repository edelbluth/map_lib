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
// * map -> mp (avoid reserved name collision)
// * Added Delete-Key functionality (stub)
// -------------------------------------------------------------------

#include "map_lib.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct map_head *map_create(char* name)
{
    struct map_head *head = (struct map_head *) malloc(sizeof(struct map_head));
    head->first = NULL;
    head->name = (char *) malloc(strlen(name) + 1);
    strcpy(head->name, name);
    return head;
}

void map_set(struct map_head *m, char *name, char *value)
{
    if ((NULL == m) || (NULL == name) || (NULL == value))
    {
        return;
    }
    if (NULL == m->first)
    {
        struct map_t *e = (struct map_t *) malloc(sizeof(struct map_t));
        e->nxt = NULL;
        e->name = (char *) malloc(strlen(name) + 1);
        strcpy(e->name, name);
        e->value = (char *) malloc(strlen(value) + 1);
        strcpy(e->value, value);
        m->first = e;
        return;
    }
    struct map_t *ptr;
    struct map_t *last;
    for (ptr = m->first; ptr != NULL; ptr = ptr->nxt)
    {
        if (0 == strcmp(ptr->name, name))
        {
            if (NULL != ptr->value)
            {
                free(ptr->value);
            }
            ptr->value = (char *) malloc(strlen(value) + 1);
            strcpy(ptr->value, value);
            return;
        }
        last = ptr;
    }
    struct map_t *e = (struct map_t *) malloc(sizeof(struct map_t));
    e->nxt = NULL;
    e->name = (char *) malloc(strlen(name) + 1);
    strcpy(e->name, name);
    e->value = (char *) malloc(strlen(value) + 1);
    strcpy(e->value, value);
    last->nxt = e;
}

char *map_get(struct map_head *m, char *name)
{
    return map_get_def(m, name, NULL);
}

char *map_get_def(struct map_head *m, char *name, char *dflt)
{
    if ((NULL == m) || (NULL == m->first) || (NULL == name))
    {
        return dflt;
    }
    struct map_t *mp;
    for (mp = m->first; mp != NULL; mp = mp->nxt)
    {
        if (!strcmp(name, mp->name))
        {
            return mp->value;
        }
    }
    return dflt;
}

int map_del(struct map_head *m, char *name)
{
    if ((NULL == m) || (NULL == m->first) || (NULL == name))
    {
        return 0;
    }
    struct map_t *mx;
    mx = m->first;
    if (0 == strcmp(mx->name, name))
    {
        free(mx->name);
        free(mx->value);
        m->first = mx->nxt;
        free(mx);
        return 1;
    }
    struct map_t *flwr;
    for (mx = m->first; mx != NULL; mx = mx->nxt)
    {
        flwr = mx->nxt;
        if (NULL == flwr)
        {
            break;
        }
        if (0 == strcmp(flwr->name, name))
        {
            free(flwr->name);
            free(flwr->value);
            mx->nxt = flwr->nxt;
            free(flwr);
            return 1;
        }
    }
    return 0;
}
