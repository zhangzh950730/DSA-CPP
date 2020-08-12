//
// Created by zhang on 2020/8/12.
//


struct studentInfo {
    int id;
    char gender;
    char name[20];
    studentInfo *next;

    studentInfo() {}

    studentInfo(int id, char gender) : id(id), gender(gender) {}

} stu, *p;

struct node {
    node *next;
};

int main() {
    stu.id = 16;
    stu.name;
    stu.next;

    int id = stu.id;

    (*p).id;
    (*p).name;
    (*p).next;

    studentInfo stu1 = studentInfo();
    studentInfo stu2 = studentInfo(1, 'M');
}

