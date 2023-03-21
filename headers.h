#pragma once

#include <iostream>
#include <map>
#include <string>

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

class Document : public Editor {
 public:
  Document() {}
  ~Document() {}

  virtual void create() override {
    // exampel logic
    ++doc_num;
    m_doc["create_obj"] = doc_num;
  }

  virtual void delete_f() override {
    // exampel logic
    if (doc_num < 1) {
      std::cerr << "Error: no any objects" << std::endl;
    }
    --doc_num;
    m_doc.insert_or_assign("create_obj", doc_num);
  }

  virtual std::map<std::string, int> get_data() override { return m_doc; }

 private:
  int doc_num = 0;
  std::map<std::string, int> m_doc{};
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
  void import_file() { m_file->import(); }
  void export_file() { m_file->export_f(); }
  void delete_file() { m_file->delete_f(); }

  void create_obj() { m_document->create(); }
  void delete_obj() { m_document->delete_f(); }

  void view_file_res() { m_view->operations(m_file->get_data()); }
  void view_obj_res() { m_view->operations(m_document->get_data()); }

 private:
  std::unique_ptr<View> m_view = std::make_unique<View>();
  std::unique_ptr<File> m_file = std::make_unique<File>();
  std::unique_ptr<Document> m_document = std::make_unique<Document>();
};
