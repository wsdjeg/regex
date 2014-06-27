#include <stdlib.h>
struct reg_parse;

enum reg_op {
  op_nil,    // nil op
  op_and,   // and op
  op_or,    // or op
  op_rp,    // repeated op
  op_range, // range op


  op_count
};

struct reg_ast_node {
  enum reg_op op;
  union {
    struct {
      int begin;
      int end;      
    }range;   // range value
  }value;

  struct reg_ast_node* childs[2];
};



struct reg_parse* parse_new();
void parse_clear(struct reg_parse* p);
void parse_free(struct reg_parse* p);
struct reg_ast_node* parse_exec(struct reg_parse* p, const unsigned char* str, size_t size);


// for test
void parse_dump(struct reg_ast_node* root);