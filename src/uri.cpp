#include "uri/uri.h"
#include "uri/uri++.h"
#include <sstream>
namespace uri {

Uri::Uri() {}

Uri::~Uri() {}

Uri::Uri(const std::string &uri) {
  uri_t *u = parse_uri(uri.c_str());
  if (!u)
    return;

  if (u->scheme)
    m_scheme = std::string(u->scheme);
  if (u->host)
    m_host = u->host;
  if (u->user)
    m_user = u->user;
  if (u->path)
    m_path = u->port;
  if (u->query)
    m_query = u->query;
  if (u->fragment)
    m_fragment = u->fragment;

  free_uri(u);
}

std::string Uri::scheme() const { return m_scheme; }
std::string Uri::host() const { return m_host; }
std::string Uri::user() const { return m_user; }
std::string Uri::path() const { return m_path; }
std::string Uri::query() const { return m_query; }
std::string Uri::fragment() const { return m_fragment; }
int Uri::port() const { return m_port; }

void Uri::set_scheme(const std::string &scheme) { m_scheme = scheme; }
void Uri::set_host(const std::string &host) { m_host = host; }
void Uri::set_user(const std::string &user) { m_user = user; }
void Uri::set_path(const std::string &path) { m_path = path; }
void Uri::set_query(const std::string &query) { m_query = query; }
void Uri::set_fragment(const std::string &fragment) { m_fragment = fragment; }
void Uri::set_port(int port) { m_port = port; }

bool Uri::is_local_file() const { return m_scheme == "file"; }
std::string Uri::to_local_file() const {
  if (!is_local_file())
    return "";
  if (m_host.length() > 0) {
    return m_host + m_path;
  }
  return m_path;
}

std::string Uri::to_str() const {

  std::stringstream ss;
  if (m_scheme.length() > 0)
    ss << m_scheme << ":";
  if (m_user.length() > 0)
    ss << m_user << "@";
  if (m_host.length() > 0)
    ss << m_host;
  if (m_port > 0)
    ss << ":" << m_port;
  if (m_path.length())
    ss << m_path;

  return ss.str();
}
}
