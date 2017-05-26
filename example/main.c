#include <stdio.h>
#include <uri/uri.h>

void print_url(uri_t *u) {
  if (!u) {
    return;
  }
  printf("Scheme: %s, ", u->scheme);
  printf("Path: %s, Host: %s, User: %s, Query %s\n", u->path, u->host, u->user,
         u->query);

  free_uri(u);
}

int main() {

  /*uri_t *u = parse("http://user:test@hellop.com:80/world");

  if (u)
    print_url(u);*/
  // print_url(parse("http://user:test@hellop.com:80/world"));
  print_uri(parse_uri("http://test:password@127.0.0.1/test?helloworld#fra"));
  print_url(parse_uri("file:///files?test=lapssdd%20test"));
  return 0;
}