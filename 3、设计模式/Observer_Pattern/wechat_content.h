#ifndef WECHAT_CONTENT_H
#define WECHAT_CONTENT_H

typedef enum {
    UNDEFINE_CONTENT = 0,
    EDUCATION,  //教育
    MILITARY,   //军事
    RECREATION, //娱乐
    TOTAL_NUMBER
}Content_type;

typedef struct _wechat_content{
    Content_type type;
    char content[256];
}Wechat_content;

#endif // WECHAT_CONTENT_H
