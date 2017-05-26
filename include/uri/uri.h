#ifndef URI_URI_H
#define URI_URI_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  char *scheme;
  char *host;
  int port;
  char *user;
  char *path;
  char *query;
  char *fragment;
} uri_t;

uri_t *parse_uri(const char *input);
void free_uri(uri_t *uri);
void print_uri(uri_t *uri);

#ifdef __cplusplus
}
#endif

#endif