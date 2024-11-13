#pragma once
#include <cstring>

int _id = 1;

class student;
class student_session1;
class student_session2;

student* students[100];
student_session1* students_session1[100];
student_session2* students_session2[100];

int num_student = 0;
int num_student1 = 0;
int num_student2 = 0;

class student{
public:
    void set_name(std::string _name){
        name[100] = {'\0'};
        strcpy(name, _name.c_str());
    }
    void set_course(int _course){
        course = _course;
    }
    void set_group(int _group){
        group = _group;
    }
    student(std::string _name, int _course, int _group, int _grade_book_num, const int current_session = 0){
        id = _id;
        _id += 1;
        name = new char[100];
        strcpy(name, _name.c_str());
        course = _course;
        group = _group;
        grade_book_num = _grade_book_num;
        if (current_session == 0){
            students[num_student] = this;
            num_student += 1;
        }
    }
    int get_id(){
        return id;
    }
    char* get_name(){
        return name;
    }
    int get_course(){
        return course;
    }
    int get_group(){
        return group;
    }
    int get_grade_book_num(){
        return grade_book_num;
    }
    student(student &other){
        id = _id;
        _id += 1;
        int i = 0;
        name = new char[100];
        name[100] = {'\0'};
        while(other.name[i] != '\0'){
            name[i] = other.name[i];
            i += 1;
        }
        name[i] = '\0';
        course = other.course;
        group = other.group;
        grade_book_num = other.grade_book_num;
    }
protected:
    int id;
    char* name;
    int course;
    int group;
    int grade_book_num;
private:

};
class student_session1 : public student{
public:
    void set_mark1(int number, int mark){
        marks1[number] = mark;
    }
    student_session1(std::string _name, int _course, int _group, int _grade_book_num, int* _marks1, const int current_session = 1) 
                    : student(_name, _course, _group, _grade_book_num, current_session){
        for (int i = 0; i < 4; i++){
            marks1[i] = _marks1[i];
        }
        if (current_session == 1){
            students_session1[num_student1] = this;
            num_student1 += 1;
        }
    }
    int get_mark1(int number){
        return marks1[number];
    }
    void get_marks1(){
        std::cout << marks1[0] << " " << marks1[1] << " " << marks1[2] << " " << marks1[3] << std::endl; 
    }
    student_session1(student_session1 &other) : student(other.name, other.course, other.group, other.grade_book_num){
        for (int i = 0; i < 4; i++){
            marks1[i] = other.marks1[i];
        }   
    }
    virtual double average_score(){
        return (marks1[0] + marks1[1] + marks1[2] + marks1[3]) / 4.0;
    }
protected:
    int marks1[4];
private:
};
class student_session2 : public student_session1{
public:
    void set_mark2(int number, int mark){
        marks2[number] = mark;
    }
    student_session2(std::string _name, int _course, int _group, int _grade_book_num, int* _marks1, int* _marks2)
                    : student_session1(_name, _course, _group, _grade_book_num, _marks1, 2){
        for (int i = 0; i < 5; i++){
            marks2[i] = _marks2[i];
        }
        students_session2[num_student2] = this;
        num_student2 += 1;
    }
    int get_mark2(int number){
        return marks2[number]; 
    }
    void get_marks2(){
        std::cout << marks2[0] << " " << marks2[1] << " " << marks2[2] << " " << marks2[3] << " " << marks2[4] << std::endl; 
    }
    student_session2(student_session2 &other) : student_session1(other.name, other.course, other.group, other.grade_book_num, other.marks2){
        for (int i = 0; i < 5; i++){
            marks2[i] = other.marks2[i];
        }
    }
    double average_score(){
        return (marks1[0] + marks1[1] + marks1[2] + marks1[3] + marks2[0] + marks2[1] + marks2[2] + marks2[3] + marks2[4]) / 9.0;
    }
private:
    int marks2[5];
};
double av_score_students_session1(){
    double sum = 0;
    for (int i = 0; i < num_student1; i++) sum += students_session1[i]->average_score();
    return sum / double(num_student1);
}
double av_score_students_2sessions(){
    double sum = 0;
    for (int i = 0; i < num_student2; i++) sum += students_session2[i]->average_score();
    return sum / double(num_student2);
}
double av_score_group_session1(int group){
    double sum = 0;
    int j = 0;
    for (int i = 0; i < num_student1; i++){
        if (students_session1[i]->get_group() == group){
            sum += students_session1[i]->average_score();
            j += 1;
        }
    }
    if (j == 0) return 0;
    return sum / double(j);
}
double av_score_group_2sessions(int group){
    double sum = 0;
    int j = 0;
    for (int i = 0; i < num_student2; i++){
        if (students_session2[i]->get_group() == group){
            sum += students_session2[i]->average_score();
            j += 1;
        }
    }
    if (j == 0) return 0;
    return sum / double(j);
}

std::ostream& operator<<(std::ostream &out, student &n) {
    out << "ID: " << n.get_id() << std::endl;
    out << "Name: " << n.get_name() << std::endl;
    out << "Course: " << n.get_course() << std::endl;
    out << "Group: " << n.get_group() << std::endl;
    out << "Grade_book_num: " << n.get_grade_book_num() << std::endl << std::endl;
    return out;
}
std::ostream& operator<<(std::ostream &out, student_session1 &n) {
    out << "ID: " << n.get_id() << std::endl;
    out << "Name: " << n.get_name() << std::endl;
    out << "Course: " << n.get_course() << std::endl;
    out << "Group: " << n.get_group() << std::endl;
    out << "Grade_book_num: " << n.get_grade_book_num() << std::endl;
    out << "Marks 1 session: " << n.get_mark1(0) << ", " << n.get_mark1(1) << ", " << n.get_mark1(2) << ", " << n.get_mark1(3) << std::endl << std::endl;
    return out;
}
std::ostream& operator<<(std::ostream &out, student_session2 &n) {
    out << "ID: " << n.get_id() << std::endl;
    out << "Name: " << n.get_name() << std::endl;
    out << "Course: " << n.get_course() << std::endl;
    out << "Group: " << n.get_group() << std::endl;
    out << "Grade_book_num: " << n.get_grade_book_num() << std::endl;
    out << "Marks 1 session: " << n.get_mark1(0) << ", " << n.get_mark1(1) << ", " << n.get_mark1(2) << ", " << n.get_mark1(3) << std::endl;
    out << "Marks 2 session: " << n.get_mark2(0) << ", " << n.get_mark2(1) << ", " << n.get_mark2(2) << ", " << n.get_mark2(3) << ", " << n.get_mark2(4)<< std::endl << std::endl;
    return out;
}
