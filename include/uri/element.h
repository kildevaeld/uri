#ifndef URI_PARSER_ELEMENT_H
#define URI_PARSER_ELEMENT_H

typedef enum {
  Scheme,
  Authority,
  Path,
  String,
  Integer,
  HirhierarchicalPart,
} Token;

typedef struct {
  char *user;
  char *host;
  int port;
} authority_t;

typedef struct {
  char *path;
  authority_t *authority;
} hirhierarchical_part_t;

typedef union {
  authority_t *authority;
  hirhierarchical_part_t *part;
  char *string;
  int integer;
} value_t;

typedef struct Element {
  Token token;
  value_t value;
} element;

typedef struct {
  char *scheme;
  char *host;
  int port;
  char *user;
  char *path;
  char *query;
  char *fragment;

} uri_t;

element *mk_hirhierarchical_part(element *path, element *auth);
element *mk_authority(element *u, element *h, element *p);
// element *mk_element(Token token, const char *value);

uri_t *mk_uri(element *scheme, element *h, element *q, element *f);

element *mk_str(const char *value);
element *mk_integer(const char *value);

extern const char *charbuf; /* Buffer of characters to be parsed. */
extern uri_t *parse_result; /* Results of parse. */

#endif