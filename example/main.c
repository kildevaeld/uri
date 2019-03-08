#include <stdio.h>
#include <uri/uri.h>


int main() {

  /*uri_t *u = parse("http://user:test@hellop.com:80/world");

  if (u)
    print_url(u);*/
  // print_url(parse("http://user:test@hellop.com:80/world"));
  print_uri(parse_uri("http://test:password@127.0.0.1/test?helloworld#fra"));
  print_uri(parse_uri("file:/files?test=lapssdd%20test"));


  return 0;
}