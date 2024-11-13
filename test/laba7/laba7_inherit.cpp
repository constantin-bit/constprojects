#include <iostream>
#include "laba7_inherit.h"

using namespace std;

int main(){
    student a("Tobbie", 1, 3, 7);
    //cout << a.get_id() << endl;
    //cout << a.get_name() << endl;
    //cout << a.get_course() << endl;;
    //cout << a.get_group() << endl;;
    //cout << a.get_grade_book_num() << endl;
    int b_marks1[4] = {1,2,3,5};
    student_session1 b("Tom", 2, 6, 10, b_marks1);
    int c_marks1[4] = {1,3,5,7};
    int c_marks2[5] = {6,7,7,9,10};
    student_session2 c("Bobbie", 3, 7, 11, c_marks1, c_marks2);
    //cout << c.average_score() << endl;
    //cout << students_session2[0]->get_name() << endl;
    //cout << num_student << endl;
    //cout << num_student1 << endl;
    //cout << num_student2 << endl;
    //cout << b.get_id() << endl;
    //cout << c.get_id() << endl;
    int d_marks1[4] = {0,3,5,7};
    int d_marks2[5] = {6,6,7,9,10};
    student_session2 d("Bobbie", 3, 8, 11, d_marks1, d_marks2);
    //cout << av_score_students_2sessions();
    int e_marks1[4] = {10,2,3,5};
    student_session1 e("Tom", 2, 8, 10, e_marks1);
    //cout << av_score_group_session1(8);
    //cout << av_score_group_2sessions(8);
    //cout << a;
    //cout << b;
    //cout << c;
    return 0;
}