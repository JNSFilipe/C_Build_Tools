#ifndef BT_H_
#define BT_H_

#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define BT_ASSERT assert
#define BT_REALLOC realloc
#define BT_FREE free

typedef enum {
  BT_INFO,
  BT_WARNING,
  BT_ERROR,
} Bt_Log_Level;

void nob_log(Bt_Log_Level level, const char *fmt, ...) {
  switch (level) {
  case BT_INFO:
    fprintf(stderr, "[INFO] ");
    break;
  case BT_WARNING:
    fprintf(stderr, "[WARNING] ");
    break;
  case BT_ERROR:
    fprintf(stderr, "[ERROR] ");
    break;
  default:
    BT_ASSERT(0 && "unreachable");
  }

  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);
  fprintf(stderr, "\n");
}

#endif // BT_H_
