#ifndef BOY_H
#define BOY_H

typedef void (*boy_func1)(void *this_boy);
typedef void (*boy_func2)(void *this_boy);

typedef struct _boy{
    int arg1;
    int arg2;
    boy_func1 func1;
    boy_func2 func2;
}Boy;

#endif // BOY_H
