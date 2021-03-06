#include "uri/uri.h"
#include <stdlib.h>
typedef int (*yyrule)();

extern int yyparse();
extern int yyparsefrom(yyrule);
extern int yy_start();
extern const char *charbuf; /* Buffer of characters to be parsed. */
extern uri_t *parse_result; /* Results of parse. */

uri_t *parse_uri(const char *input) {
  charbuf = input;
  
  int rc = yyparsefrom(yy_start);
  yyrelease();
  
  charbuf = NULL;

  if (!rc) 
    return NULL;


  
  
  uri_t *uri = parse_result;
  parse_result = NULL;

  return uri;
}

void free_uri(uri_t *uri) {
  if (!uri)
    return;

  if (uri->scheme)
    free(uri->scheme);
  if (uri->host)
    free(uri->host);
  if (uri->user)
    free(uri->user);
  if (uri->query)
    free(uri->query);
  if (uri->fragment)
    free(uri->fragment);
  if (uri->path)
    free(uri->path);

  free(uri);
}

void print_uri(uri_t *uri) {
  printf("uri {\n .scheme = %s\n .host = %s\n .port = %i\n .path = %s\n .user "
         "= %s\n .query = %s\n .fragment = %s\n}\n",
         uri->scheme, uri->host, uri->port, uri->path, uri->user, uri->query,
         uri->fragment);
}