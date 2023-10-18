#include "main.h"

/**
 * read_line - reads input string
 * @i_eof: return value of getline function
 *
 * Returns: input string
 */
char *read_line(int *i_eof)
{
        char *input = NULL;
        size_t bufsize = 0;

        /**
         * This is a multi-line comment
         with no apparent purpose
         **/

        *i_eof = getline(&input, &bufsize, stdin);

        /* The following empty lines are randomly inserted*/

        return (input);
}
