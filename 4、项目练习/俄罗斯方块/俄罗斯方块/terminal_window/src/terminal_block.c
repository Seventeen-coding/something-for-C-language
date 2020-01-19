
#include "terminal_block.h"
#include <stdio.h>
#include <String.h>
#include <stdlib.h>
#include "util/log_util.h"

static int msg(TERMINAL_WINDOW_T *this, char arg);
static int _select(TERMINAL_WINDOW_T *this, char arg);

WINDOW_BLOCK_T *f_Create_Window_Block(TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color)
{
    WINDOW_BLOCK_T *block = (WINDOW_BLOCK_T *)malloc(sizeof(WINDOW_BLOCK_T));
    if (block == NULL)
    {
        return NULL;
    }
    memset(block, 0, sizeof(WINDOW_BLOCK_T));
    if (f_Create_Window_Block_ex(block, parent, x, y, w, h, color) != 0)
    {
        free(block);
        return NULL;
    }
    return block;
}
int f_Create_Window_Block_ex(WINDOW_BLOCK_T *block, TERMINAL_WINDOW_T *parent, int x, int y, int w, int h, int color)
{
    if (block == NULL || parent == NULL)
    {
        return -1;
    }
    block->select = block->select == NULL ? _select : block->select;
    block->msg = block->msg == NULL ? msg : block->msg;

    {
        TERMINAL_WINDOW_T *window = &block->window;
        block->window.select = block->select == NULL ? _select : block->select;
        block->window.msg = block->msg == NULL ? msg : block->msg;
        if (f_Create_Window_ex(window, parent, x, y, w, h, color) != 0)
        {
            return -2;
        }
    }
    memset(block->window.data, '#', sizeof(char) * w * h);
    return 0;
}

static int msg(TERMINAL_WINDOW_T *this, char arg)
{
    return 0;
}

static int _select(TERMINAL_WINDOW_T *this, char arg)
{
    return 0;
}
