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
// * Minor Refactoring
// * Added Delete-Key functionality
// * Added List Head struct
// -------------------------------------------------------------------

#ifndef __MAP_LIB_H__
#define __MAP_LIB_H__

struct map_t
{
   struct map_t *nxt;
   char *name;
   char *value;
};

struct map_head
{
    char *name;
    struct map_t *first;
};

struct map_head *map_create(char *name);
void map_set(struct map_head *m, char *name, char *value);
char *map_get_def(struct map_head *m, char *name, char *dflt);
char *map_get(struct map_head *m, char *name);
int map_del(struct map_head *m, char *name);

#endif

