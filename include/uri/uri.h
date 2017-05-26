#ifndef URI_URI_H
#define URI_URI_H

#include "element.h"

uri_t *parse_uri(const char *input);
void free_uri(uri_t *uri);

void print_uri(uri_t *uri);
#endif