#pragma once

#include <iostream>
#include <map>
#include <string>

class Primitive {
 public:
  Primitive() {}
  virtual ~Primitive() {}
  virtual void create_prim() = 0;
  virtual void delete_prim(int) = 0;
  virtual void get() = 0;
};

class Dot : public Primitive {
 public:
  Dot() {}
  ~Dot() {}

  virtual void create_prim() override {
    m_a.first = rand();
    m_a.second = rand();
    coordinate.insert_or_assign(m_key, m_a);
    ++m_key;
  }
  virtual void get() override {
    for (auto coord : coordinate) {
      std::cout << "dot-" << coord.first << "---"
                << "(" << coord.second.first << ";" << coord.second.second
                << ")" << std::endl;
    }
  }

  virtual void delete_prim(int key) override {
    for (auto it = coordinate.begin(); it != coordinate.end();) {
      if (it->first == key)
        it = coordinate.erase(it);
      else
        ++it;
    }
  }

 private:
  std::pair<int, int> m_a;
  int m_key{1};
  std::map<int, std::pair<int, int>> coordinate;
};

class Line : public Primitive {
 public:
  Line() {}
  ~Line() {}

  virtual void create_prim() override {
    line_1.first = rand();
    line_1.second = rand();
    line_2.first = rand();
    line_2.second = rand();

    line_dots.first = line_1;
    line_dots.second = line_2;

    line_coord.insert_or_assign(m_key, line_dots);
    ++m_key;
  }

  virtual void get() override {
    for (auto line : line_coord) {
      std::cout << "line-" << line.first << "---"
                << "(" << line.second.first.first << ";"
                << line.second.first.second << ") & ("
                << line.second.second.first << ":" << line.second.second.second
                << ")" << std::endl;
    }
  }

  virtual void delete_prim(int key) override {
    for (auto it = line_coord.begin(); it != line_coord.end();) {
      if (it->first == key)
        it = line_coord.erase(it);
      else
        ++it;
    }
  }

 private:
  int m_key{1};
  std::pair<int, int> line_1, line_2;
  std::pair<std::pair<int, int>, std::pair<int, int>> line_dots;
  std::map<int, std::pair<std::pair<int, int>, std::pair<int, int>>> line_coord;
};

class Editor {
 public:
  Editor() {}
  virtual ~Editor() {}

  virtual void create() = 0;
  virtual void delete_f() = 0;
  virtual std::map<std::string, int> get_data() = 0;
};

class File : public Editor {
 public:
  File() {}
  ~File() {}

  virtual void create() override {
    // exampel logic
    ++m_create;
    m_file.insert_or_assign("created_files", m_create);
  }

  virtual void delete_f() override {
    // exampel logic
    --m_create;
    m_file.insert_or_assign("created_files", m_create);
  }

  void import() {
    // exampel logic
    ++m_imp;
    m_file["imported_files"] = m_imp;
  }

  void export_f() {
    // exampel logic
    ++m_exp;
    m_file["exported_files"] = m_exp;
  }

  virtual std::map<std::string, int> get_data() override { return m_file; }

 private:
  int m_create = 0;
  int m_imp = 0;
  int m_exp = 0;
  std::map<std::string, int> m_file{};
};

class Document {
 public:
  Document() {}
  ~Document() {}

  std::unique_ptr<Dot> dot = std::make_unique<Dot>();
  std::unique_ptr<Line> line = std::make_unique<Line>();
};

class View {
 public:
  View(){};
  ~View(){};

  void operations(const std::map<std::string, int>& data) {
    for (auto n : data) {
      std::cout << n.first << "-----" << n.second << std::endl;
    }
  }
};

class Controller {
 public:
  Controller() {}
  ~Controller() {}

  void create_file() { m_file->create(); }

  void create_dot() { m_document->dot->create_prim(); }
  void erase_dot(int kq) { m_document->dot->delete_prim(kq); }
  void get_dots_coord() { m_document->dot->get(); }

  void create_line() { m_document->line->create_prim(); }
  void erase_line(int kq) { m_document->line->delete_prim(kq); }
  void get_lines_coord() { m_document->line->get(); }

  void import_file() { m_file->import(); }
  void export_file() { m_file->export_f(); }
  void delete_file() { m_file->delete_f(); }

  void view_file_res() { m_view->operations(m_file->get_data()); }

 private:
  std::unique_ptr<View> m_view = std::make_unique<View>();
  std::unique_ptr<File> m_file = std::make_unique<File>();
  std::unique_ptr<Document> m_document = std::make_unique<Document>();
};
