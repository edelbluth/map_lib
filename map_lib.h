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
// * Added default value if value not found
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

/**
 * @brief Create a new "associative array", and give it a name
 * @param name Name for the new "associative array"
 * @return Pointer to the new "associative array"
 */
struct map_head *map_create(char *name);

/**
 * @brief Set a value in the "associative array"
 * @param m Map Head of the "associative array"
 * @param name Key in the "associative array"
 * @param value Value in the "associative array"
 */
void map_set(struct map_head *m, char *name, char *value);

/**
 * @brief Get a value from the "associative array". If not found, return a default value.
 * @param m Map Head of the "associative array"
 * @param name Key in the "associative array"
 * @param dflt Value to return if key was not found in "associative array"
 * @return The value of the key if found, default value otherwise.
 */
char *map_get_def(struct map_head *m, char *name, char *dflt);

/**
 * @brief Get a value from the "associative array". If not found, return NULL.
 * @param m Map Head of the "associative array"
 * @param name Key in the "associative array"
 * @return The value of the key if found, NULL otherwise.
 */
char *map_get(struct map_head *m, char *name);

/**
 * @brief Delete an element from the "associative array"
 * @param m Map Head of the "associative array"
 * @param name Key in the "associative array"
 * @retval 0 if no element has been deleted
 * @retval 1 if element has been deleted
 */
int map_del(struct map_head *m, char *name);

#endif

