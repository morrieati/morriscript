#include "morriscript.h"

#define STRING_ALLOC_SIZE (256)

static char *st_string_literal_buffer = NULL;
static int st_string_literal_buffer_size = 0;
static int st_string_literal_buffer_alloc_size = 0;

void ms_open_string_literal()
{
    st_string_literal_buffer_size = 0;
}

void ms_add_string_literal(int letter)
{
    if (st_string_literal_buffer_size == st_string_literal_buffer_alloc_size)
    {
        st_string_literal_buffer_alloc_size += STRING_ALLOC_SIZE;
        st_string_literal_buffer = realloc(st_string_literal_buffer, st_string_literal_buffer_alloc_size);
    }
    st_string_literal_buffer[st_string_literal_buffer_size] = letter;
    st_string_literal_buffer_size++;
}

void ms_reset_string_literal_buffer()
{
    free(st_string_literal_buffer);
    st_string_literal_buffer = NULL;
    st_string_literal_buffer_size = 0;
    st_string_literal_buffer_alloc_size = 0;
}

char *ms_close_string_literal()
{
    char *new_str;

    new_str = (char *)malloc(st_string_literal_buffer_size + 1);

    memcpy(new_str, st_string_literal_buffer, st_string_literal_buffer_size);
    new_str[st_string_literal_buffer_size] = '\0';

    return new_str;
}