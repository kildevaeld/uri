#pragma once
#include <string>

namespace uri {

class Uri {

public:
  Uri();
  Uri(const std::string &uri);
  ~Uri();

  std::string scheme() const;
  std::string host() const;
  std::string user() const;
  std::string path() const;
  std::string query() const;
  std::string fragment() const;
  int port() const;

  void set_scheme(const std::string &scheme);
  void set_host(const std::string &host);
  void set_user(const std::string &user);
  void set_path(const std::string &path);
  void set_query(const std::string &query);
  void set_fragment(const std::string &fragment);
  void set_port(int port);

  bool is_local_file() const;
  std::string to_local_file() const;

  std::string str() const;

private:
  bool m_valid = false;
  std::string m_scheme;
  std::string m_host;
  std::string m_user;
  std::string m_path;
  std::string m_query;
  std::string m_fragment;
  int m_port;
};
}