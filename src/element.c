#include "uri/element.h"
#include "uri/defines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *charbuf = "";
uri_t *parse_result; /* Results of parse. */

static element *mk_element(Token token) {
  element *e = malloc(sizeof(element));
  if (!e)
    return NULL;
  e->token = token;
  return e;
}

element *mk_str(const char *value) {
  element *e = mk_element(String);
  e->value.string = strdup(value);

  return e;
}

element *mk_integer(const char *value) {
  element *e = mk_element(Integer);
  e->value.integer = atoi(value);
  return e;
}

uri_t *mk_uri(element *scheme, element *hir, element *q, element *f) {
  uri_t *uri = malloc(sizeof(uri_t));
  *uri = (uri_t){0};
  if (scheme) {
    uri->scheme = scheme->value.string;
    free(scheme);
  }

  if (hir) {

    uri->path = hir->value.part->path;
    if (hir->value.part->authority) {
      authority_t *auth = hir->value.part->authority;
      uri->host = auth->host;
      uri->port = auth->port;
      uri->user = auth->user;
      free(auth);
    }
    free(hir->value.part);
    free(hir);
  }

  if (q) {
    uri->query = q->value.string;
    free(q);
  }

  if (f) {
    uri->fragment = f->value.string;
    free(f);
  }

  return uri;
}

element *mk_hirhierarchical_part(element *path, element *auth) {

  element *e = mk_element(HirhierarchicalPart);
  if (!e)
    return NULL;

  hirhierarchical_part_t *part = malloc(sizeof(hirhierarchical_part_t));
  if (!part) {
    free(e);
    return NULL;
  }

  *part = (hirhierarchical_part_t){0};

  if (path) {
    part->path = path->value.string;
    free(path);
  }

  if (auth) {
    part->authority = auth->value.authority;
    free(auth);
  }

  e->value.part = part;

  return e;
}

element *mk_authority(element *u, element *h, element *p) {

  element *e = mk_element(Authority);
  authority_t *auth = malloc(sizeof(authority_t));
  *auth = (authority_t){0};

  if (!auth)
    return NULL;

  if (u) {
    auth->user = u->value.string;
    free(u);
  }
  if (h) {
    auth->host = h->value.string;
    free(h);
  }
  if (p) {
    auth->port = p->value.integer;
    free(p);
  }

  e->value.authority = auth;

  return e;
}