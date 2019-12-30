
#include "Composite_Pattern.h"
#include <stdio.h>

void run();

int main(void)
{
    run();
    return 0;
}

//test
//目的 分组管理
//可以继承person 实现headmaster teacher students 的类
//把teacher 和 student看作person类加入headmaster即可
void run()
{
    Person headmaster;
    CreatPerson(&headmaster,"seventeen",17,"headmaster");
    Person teacher1;
    CreatPerson(&teacher1,"teacher1",16,"class1");
    Person teacher2;
    CreatPerson(&teacher2,"teacher2",15,"class2");
    Person student1;
    CreatPerson(&student1,"student1",14,"class1");
    Person student2;
    CreatPerson(&student2,"student2",13,"class1");
    Person student3;
    CreatPerson(&student3,"student3",12,"class2");
    Person student4;
    CreatPerson(&student4,"student4",11,"class2");


    headmaster.add(&headmaster,&teacher1);
    headmaster.add(&headmaster,&teacher2);

    teacher1.add(&teacher1,&student1);
    teacher1.add(&teacher1,&student2);
    teacher2.add(&teacher2,&student3);
    teacher2.add(&teacher2,&student4);

    //验证 整个过程发只操作了headmaster
    Person **teacher_list;
    Person **student_list;
    Person *teacher;
    Person *student;
    headmaster.about(&headmaster);
    int i,j;
    teacher_list = headmaster.getSubordinates(&headmaster);
    for( i = 0 ; i < MAX_LEN ; i++)
    {
        teacher = teacher_list[i];
        if(teacher == NULL)
            break;
        teacher->about(teacher);
        student_list =  teacher->getSubordinates(teacher);
        for(j = 0; j < MAX_LEN ; j++)
        {
            student = student_list[j];
            if(student == NULL)
                break;
            student->about(student);
        }
    }
    return;
}
