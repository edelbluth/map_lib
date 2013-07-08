#include <stdio.h>
#include "map_lib.h"

void display_both(struct map_t *m, char *first)
{
    printf("Std: %s %s\n", first, map_get(m, first));
    printf("Def: %s %s\n", first, map_get_def(m, first, "Default Value"));
}

void map_test(struct map_t *test)
{
    printf("==============================================\n");

    // display them out of order
    display_both(test, "Two");
    display_both(test, "Four");
    display_both(test, "One");
    display_both(test, "Eight");

    printf("\n");
}

int main(int argc, char** argv)
{
    struct map_t *test_map;
    test_map = map_create();

    map_set(test_map, "One", "Won");
    map_set(test_map, "Two", "Too");
    map_set(test_map, "Four", "Fore");

    map_test(test_map);

    map_set(test_map, "Two", "To");

    map_test(test_map);

    map_set(test_map, "Eight", "Ate");

    map_test(test_map);

    printf("Delete 'Two': %d\n", map_del(test_map, "Two"));

    map_test(test_map);

    printf("Delete 'Two': %d\n", map_del(test_map, "Two"));
    printf("Delete 'Eight': %d\n", map_del(test_map, "Eight"));
    printf("Delete 'Four': %d\n", map_del(test_map, "Four"));

    map_test(test_map);

    printf("Delete 'One': %d\n", map_del(test_map, "One"));
    map_test(test_map);

    return 0;
}

