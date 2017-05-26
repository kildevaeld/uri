## Uri
Uri parser in c

```c

uri_t *u = parse_uri("http://user:password@example.com/path?query=Hello%20World#afs2");
print_uri(u);
free_uri(u);

```