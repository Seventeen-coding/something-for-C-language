/*
    C 标准库 - <stdio.h>
    简介
    stdio .h 头文件定义了三个变量类型、一些宏和各种函数来执行输入和输出。

 */
#include <stdio.h>

int main ( void )
{
    {
        FILE *fp;

        fp = fopen ( "file.txt", "w" );

        fprintf ( fp, "%s", "这里是 runoob.com" );
        fclose ( fp );
    }

    {
        FILE *fp;
        char c;

        fp = fopen ( "file.txt", "w" );

        c = fgetc ( fp );
        if ( ferror ( fp ) )
        {
            printf ( "读取文件：file.txt 时发生错误\n" );
        }
        clearerr ( fp );
        if ( ferror ( fp ) )
        {
            printf ( "读取文件：file.txt 时发生错误\n" );
        }
        fclose ( fp );
    }

    {

        FILE *fp;
        int c;

        fp = fopen ( "file.txt","r" );
        if ( fp == NULL )
        {
            perror ( "打开文件时发生错误" );
            return ( -1 );
        }
        while ( 1 )
        {
            c = fgetc ( fp );
            if ( feof ( fp ) )
            {
                break ;
            }
            printf ( "%c", c );
        }
        fclose ( fp );
    }
    {
        FILE *fp;
        char c;

        fp = fopen ( "file.txt", "w" );

        c = fgetc ( fp );
        if ( ferror ( fp ) )
        {
            printf ( "读取文件：file.txt 时发生错误\n" );
        }
        clearerr ( fp );
        if ( ferror ( fp ) )
        {
            printf ( "读取文件：file.txt 时发生错误\n" );
        }
        fclose ( fp );
    }

    {
        char buff[1024];

        memset ( buff, '\0', sizeof ( buff ) );

        fprintf ( stdout, "启用全缓冲\n" );
        setvbuf ( stdout, buff, _IOFBF, 1024 );

        fprintf ( stdout, "这里是 runoob.com\n" );
        fprintf ( stdout, "该输出将保存到 buff\n" );
        fflush ( stdout );

        fprintf ( stdout, "这将在编程时出现\n" );
        fprintf ( stdout, "最后休眠五秒钟\n" );

        sleep ( 5 );
    }
    {
        FILE *fp;
        fpos_t position;

        fp = fopen ( "file.txt","w+" );
        fgetpos ( fp, &position );
        fputs ( "Hello, World!", fp );

        fsetpos ( fp, &position );
        fputs ( "这将覆盖之前的内容", fp );
        fclose ( fp );

    }
    {
        FILE * fp;

        fp = fopen ( "file.txt", "w+" );
        fprintf ( fp, "%s %s %s %d", "We", "are", "in", 2014 );

        fclose ( fp );

    }
    {
#include <string.h>
        FILE *fp;
        char c[] = "This is runoob";
        char buffer[20];

        /* 打开文件用于读写 */
        fp = fopen ( "file.txt", "w+" );

        /* 写入数据到文件 */
        fwrite ( c, strlen ( c ) + 1, 1, fp );

        /* 查找文件的开头 */
        fseek ( fp, 0, SEEK_SET );

        /* 读取并显示数据 */
        fread ( buffer, strlen ( c )+1, 1, fp );
        printf ( "%s\n", buffer );
        fclose ( fp );

    }
    {
        FILE *fp;

        printf ( "该文本重定向到 stdout\n" );

        fp = freopen ( "file.txt", "w+", stdout );

        printf ( "该文本重定向到 file.txt\n" );

        fclose ( fp );

    }
    {
        FILE *fp;

        fp = fopen ( "file.txt","w+" );
        fputs ( "This is runoob.com", fp );

        fseek ( fp, 7, SEEK_SET );
        fputs ( " C Programming Langauge", fp );
        fclose ( fp );

    }
    {
        FILE *fp;
        fpos_t position;

        fp = fopen ( "file.txt","w+" );
        fgetpos ( fp, &position );
        fputs ( "Hello, World!", fp );

        fsetpos ( fp, &position );
        fputs ( "这将覆盖之前的内容", fp );
        fclose ( fp );


    }
    {
        FILE *fp;
        int len;

        fp = fopen ( "file.txt", "r" );
        if ( fp == NULL )
        {
            perror ( "打开文件错误" );
            return ( -1 );
        }
        fseek ( fp, 0, SEEK_END );

        len = ftell ( fp );
        fclose ( fp );

        printf ( "file.txt 的总大小 = %d 字节\n", len );


    }
    {
        FILE *fp;
        char str[] = "This is runoob.com";

        fp = fopen ( "file.txt", "w" );
        fwrite ( str, sizeof ( str ), 1, fp );

        fclose ( fp );
    }
    {
        int ret;
        FILE *fp;
        char filename[] = "file.txt";

        fp = fopen ( filename, "w" );

        fprintf ( fp, "%s", "这里是 runoob.com" );
        fclose ( fp );

        ret = remove ( filename );

        if ( ret == 0 )
        {
            printf ( "文件删除成功" );
        }
        else
        {
            printf ( "错误：不能删除该文件" );
        }
    }
    {
        char str[] = "This is runoob.com";
        FILE *fp;
        int ch;

        /* 首先让我们在文件中写入一些内容 */
        fp = fopen ( "file.txt", "w" );
        fwrite ( str, 1, sizeof ( str ), fp );
        fclose ( fp );

        fp = fopen ( "file.txt", "r" );
        while ( 1 )
        {
            ch = fgetc ( fp );
            if ( feof ( fp ) )
            {
                break ;
            }
            printf ( "%c", ch );
        }
        rewind ( fp );
        printf ( "\n" );
        while ( 1 )
        {
            ch = fgetc ( fp );
            if ( feof ( fp ) )
            {
                break ;
            }
            printf ( "%c", ch );

        }
        fclose ( fp );
    }
    {
        char buf[BUFSIZ];

        setbuf ( stdout, buf );
        puts ( "This is runoob" );

        fflush ( stdout );
    }
    {
        char buffer[L_tmpnam];
        char *ptr;


        tmpnam ( buffer );
        printf ( "临时名称 1: %s\n", buffer );

        ptr = tmpnam ( NULL );
        printf ( "临时名称 2: %s\n", ptr );

    }

    {
        FILE * fp;

        fp = fopen ( "file.txt", "w+" );
        fprintf ( fp, "%s %s %s %d", "We", "are", "in", 2014 );

        fclose ( fp );
    }
    {
        int ch;

        for ( ch = 75 ; ch <= 100; ch++ )
        {
            printf ( "ASCII 值 = %d, 字符 = %c\n", ch, ch );
        }
    }
    {
#include <math.h>
        char str[80];

        sprintf ( str, "Pi 的值 = %f", M_PI );
        puts ( str );

    }
    {
#include <stdarg.h>
        void WriteFrmtd ( FILE *stream, char *format, ... )
        {
            va_list args;

            va_start ( args, format );
            vfprintf ( stream, format, args );
            va_end ( args );
        }

        FILE *fp;

        fp = fopen ( "file.txt","w" );

        WriteFrmtd ( fp, "This is just one argument %d \n", 10 );

        fclose ( fp );
    }
    {
#include <stdarg.h>
        void WriteFrmtd ( char *format, ... )
        {
            va_list args;

            va_start ( args, format );
            vprintf ( format, args );
            va_end ( args );
        }
        WriteFrmtd ( "%d variable argument\n", 1 );
        WriteFrmtd ( "%d variable %s\n", 2, "arguments" );

    }
    {
#include <stdarg.h>
        char buffer[80];
        int vspfunc ( char *format, ... )
        {
            va_list aptr;
            int ret;

            va_start ( aptr, format );
            ret = vsprintf ( buffer, format, aptr );
            va_end ( aptr );

            return ( ret );
        }
        int i = 5;
        float f = 27.0;
        char str[50] = "runoob.com";

        vspfunc ( "%d %f %s", i, f, str );
        printf ( "%s\n", buffer );

    }

    {
        char str1[10], str2[10], str3[10];
        int year;
        FILE * fp;

        fp = fopen ( "file.txt", "w+" );
        fputs ( "We are in 2014", fp );

        rewind ( fp );
        fscanf ( fp, "%s %s %s %d", str1, str2, str3, &year );

        printf ( "Read String1 |%s|\n", str1 );
        printf ( "Read String2 |%s|\n", str2 );
        printf ( "Read String3 |%s|\n", str3 );
        printf ( "Read Integer |%d|\n", year );

        fclose ( fp );
    }
    {
        char str1[20], str2[30];

        printf ( "请输入用户名：" );
        scanf ( "%s", str1 );

        printf ( "请输入您的网站：" );
        scanf ( "%s", str2 );

        printf ( "输入的用户名：%s\n", str1 );
        printf ( "输入的网站：%s", str2 );

    }
    {
        int day, year;
        char weekday[20], month[20], dtm[100];

        strcpy ( dtm, "Saturday March 25 1989" );
        sscanf ( dtm, "%s %s %d  %d", weekday, month, &day, &year );

        printf ( "%s %d, %d = %s\n", month, day, year, weekday );


    }
    {
        FILE *fp;
        int c;
        int n = 0;

        fp = fopen ( "file.txt","r" );
        if ( fp == NULL )
        {
            perror ( "打开文件时发生错误" );
            return ( -1 );
        }
        do
        {
            c = fgetc ( fp );
            if ( feof ( fp ) )
            {
                break ;
            }
            printf ( "%c", c );
        }
        while ( 1 );

        fclose ( fp );

    }
    {
        FILE *fp;
        char str[60];

        /* 打开用于读取的文件 */
        fp = fopen ( "file.txt", "r" );
        if ( fp == NULL )
        {
            perror ( "打开文件时发生错误" );
            return ( -1 );
        }
        if ( fgets ( str, 60, fp ) !=NULL )
        {
            /* 向标准输出 stdout 写入内容 */
            puts ( str );
        }
        fclose ( fp );


    }
    {
        FILE *fp;
        int ch;

        fp = fopen ( "file.txt", "w+" );
        for ( ch = 33 ; ch <= 100; ch++ )
        {
            fputc ( ch, fp );
        }
        fclose ( fp );


    }
    {
        FILE *fp;

        fp = fopen ( "file.txt", "w+" );

        fputs ( "这是 C 语言。", fp );
        fputs ( "这是一种系统程序设计语言。", fp );

        fclose ( fp );

    }
    {
        char c;

        printf ( "请输入字符：" );
        c = getc ( stdin );
        printf ( "输入的字符：" );
        putc ( c, stdout );


    }
    {
        char c;

        printf ( "请输入字符：" );
        c = getchar();

        printf ( "输入的字符：" );
        putchar ( c );


    }
    {
        char str[50];

        printf ( "请输入一个字符串：" );
        gets ( str );

        printf ( "您输入的字符串是：%s", str );


    }
    {
        FILE *fp;
        int ch;

        fp = fopen ( "file.txt", "w" );
        for ( ch = 33 ; ch <= 100; ch++ )
        {
            putc ( ch, fp );
        }
        fclose ( fp );
    }
    {
        char ch;

        for ( ch = 'A' ; ch <= 'Z' ; ch++ )
        {
            putchar ( ch );
        }
    }
    {
        char str1[15];
        char str2[15];

        strcpy ( str1, "RUNOOB1" );
        strcpy ( str2, "RUNOOB2" );

        puts ( str1 );
        puts ( str2 );
    }
    {
        FILE *fp;
        int c;
        char buffer [256];

        fp = fopen ( "file.txt", "r" );
        if ( fp == NULL )
        {
            perror ( "打开文件时发生错误" );
            return ( -1 );
        }
        while ( !feof ( fp ) )
        {
            c = getc ( fp );
            /* 把 ! 替换为 + */
            if ( c == '!' )
            {
                ungetc ( '+', fp );
            }
            else
            {
                ungetc ( c, fp );
            }
            fgets ( buffer, 255, fp );
            fputs ( buffer, stdout );
        }
    }
    {
        FILE *fp;

        /* 首先重命名文件 */
        rename ( "file.txt", "newfile.txt" );

        /* 现在让我们尝试打开相同的文件 */
        fp = fopen ( "file.txt", "r" );
        if ( fp == NULL )
        {
            perror ( "Error: " );
            return ( -1 );
        }
        fclose ( fp );

    }
    {

        FILE *fp;

        fp = tmpfile();
        printf ( "临时文件被创建\n" );

        /* 您可以在这里使用临时文件 */

        fclose ( fp );
    }
    return 0;
}
