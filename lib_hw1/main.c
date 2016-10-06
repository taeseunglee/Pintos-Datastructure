#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./list.h"
#include "./new_utils.h"
#include "./tokenizer.h"

#define MAX_COMMAND_BUFFER 100
#define MAX_NAME_LEN 20

struct list_item
  {
    struct list_elem list_sequence;
    int item;
  };

struct list_named
  {
    struct list real_list;
    struct list_named *next;
    char name[MAX_NAME_LEN];
  };

typedef struct _Environment
  {
    struct list_named* all_list;
    char ** argv;
    int argc;
    int command_num;
  } Environment;

int
get_command_num (const char* command_name);
int
command_handle (Environment* env);

int
main ()
{
  Environment env;
  while (true)
    {
      char command_line_buffer[MAX_COMMAND_BUFFER];
      int argc = 0;

      fgets(command_line_buffer, MAX_COMMAND_BUFFER, stdin);
      tokenizer(command_line_buffer, &env.argc, &env.argv); // argv[0] : command

      int res = 0;
      if (env.argv[0] != NULL)
        {
          env.command_num = get_command_num(env.argv[0]);
         
          res = command_handle(&env);
        }
      else
        {
          fprintf(stderr, "Enter argv[0]\n");
        }
      tokenizer_deallocate_argvs(&env.argv, argc);
      
      if (res == -1 || res == 0) { return res; } // if res == -1 : error occurs.
    }
}


int
get_command_num(const char* command_name)
{
  char * collect_command[ ] = 
    {
      // Create, Dump : start : 0~
      "create", "dumpdata"
       // List . count : 18, start : 2~
       , "list_insert", "list_splice", "list_push"
       , "list_remove", "list_pop_front", "list_pop_back"
       , "list_front", "list_back"
       , "list_size", "list_empty"
       , "list_reverse", "list_sort"
       , "list_insert_ordered", "list_unique"
       , "list_max", "list_min", "list_swap"
       , "list_shuffle"
       // Hashtable . count : 9, start : 20
       , "hash_insert", "hash_replace", "hash_find"
       , "hash_delete", "hash_clear", "hash_size"
       , "hash_empty", "hash_apply", "hash_int_2"
       // Bitmap . count : 17 , start : 29
       , "bitmap_size", "bitmap_set", "bitmap_mark"
       , "bitmap_reset", "bitmap_flip", "bitmap_test"
       , "bitmap_set_all", "bitmap_set_multiple"
       , "bitmap_count", "bitmap_contains"
       , "bitmap_any", "bitmap_none", "bitmap_all"
       , "bitmap_scan", "bitmap_scan_and_flip"
       , "bitmap_dump", "bitmap_expand"
       // Quit , start : 46
       , "quit"
    };

  int i = 0, cnt_command = 2 + 18 + 9 + 17 + 1;

  for (i = 0; i < cnt_command; i++)
    {
      if (!strcmp(collect_command[i], command_name)) return i;
    }

  return -1; // command not found
}

int
command_handle (Environment *env)
{
  int ret = 1;  // result : 1 - normal, 0 - exit, -1 - error
  switch (env->command_num)
    {
    case 0 : // Create
      if (env->argc < 3)
        {
          fprintf(stderr, "create <list|hashtable|bitmap> <list_name>\n");
          return -1;
        }
      if (!strcmp(env->argv[1], "list"))
        {
          struct list_named* new_list_named = calloc(1, sizeof(struct list_named));
          strcpy(new_list_named->name, env->argv[2]);
          
          struct list_name* temp = env->all_list;
          if (temp == NULL)
            {
              temp = new_list_named;
            }
          else
            {
              while ()
            }
        }
      else if (!strcmp(env->argv[1], "hashtable"))
        {
          
        }
      else if (!strcmp(env->argv[1], "bitmap"))
        {
        
        }
      else // error
        {
          fprintf(stderr, "create <list|hashtable|bitmap> <list_name>\n");
          return -1;
        }
      break;
    case 1 : // dumpdata
      break;


      // List
    case 2: // list_insert
      break;
    case 3: // list_splice
      break;
    case 4: // list_push
      break;
    case 5: // list_remove
      break;
    case 6: // list_pop_front
      break;
    case 7: // list_pop_back
      break;
    case 8: // list_front
      break;
    case 9: // list_back
      break;
    case 10: // list_size
      break;
    case 11: // list_empty
      break;
    case 12: // list_reverse
      break;
    case 13: // list_sort
      break;
    case 14: // list_insert_ordered
      break;
    case 15: // list unique
      break;
    case 16: // list_max
      break;
    case 17: // list_min
      break;
    case 18: // list_swap
      break;
    case 19: // list_shuffle
      break;




      // Hashtable
    case 20: // hash_insert
      break;
    case 21: // hash_replace
      break;
    case 22: // hash_find
      break;
    case 23: // hash_delete
      break;
    case 24: // hash_clear
      break;
    case 25: // hash_size
      break;
    case 26: // hash_empty
      break;
    case 27: // hash_apply
      break;
    case 28: // hash_int_2
      break;

      // Bitmap
    case 29: // bitmap_size
      break;
    case 30: // bitmap_set
      break;
    case 31: // bitmap_mark
      break;
    case 32: // bitmap_reset
      break;
    case 33: // bitmap_flip
      break;
    case 34: // bitmap_test
      break;
    case 35: // bitmap_set_all
      break;
    case 36: // bitmap_set_multiple
      break;
    case 37: // bitmap_count
      break;
    case 38: // bitmap_contains
      break;
    case 39: // bitmap_any
      break;
    case 40: // bitmap_none
      break;
    case 41: // bitmap_all
      break;
    case 42: // bitmap_scan
      break;
    case 43: // bitmap_scan_and_flip
      break;
    case 44: // bitmap_dump
      break;
    case 45: // bitmap_expand
      break;
    case 46: // Quit
      ret = 0;
      break;
  }


  return ret;
}
