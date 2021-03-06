#ifndef ASSIGNMENT_UNZIP_H
#define ASSIGNMENT_UNZIP_H

#include <iostream>
#include <string>
#include <unzip.h>
#include <time.h>
#include <cstdio>



//------------ declare public area for data downloaded from canvas--------

#ifndef _COURSE_INFO                                // struct for course including three structs: student information, assignment information, file(assignment itself) information
typedef struct{

    #ifndef _STU_INFO

    typedef struct{
        int Stu_Index;                              // index for retrieving information of student
        int Stu_Assigment_Grade_Current;            // grade students will get from this assignment
        int Stu_Assigment_Grade_Min;                // the minimum grade that students can get
        int Stu_Assigment_Grade_Max;                // the maximum grade that students can get
        double Stu_ID;                              // the ID number of student
        const char *Stu_Name;                             // student's name which has to be english
        const char *Stu_Mail_Addr;                        // student's email address


    } Stu_info;                                     // stu_info stores student information

    #define _STU_INFO
    #endif

    #ifndef _FILE_INFO

    typedef struct {
        const char *File_Orname, *File_Extname;            // file's name and extra name; the Orname may be full name if download group do not tell
        const char  *Dir_file_Or, *Dir_file_N;             // position that file is located and the position where the copies of files and unzip files are?? we are going to store these new files under the same level where orignal files are sitting
        const char *File_Extname_N;
        int Q_flag;                                 // file name qualified flag, by this, we'll know whose file follows rule. it has more priority than C_flag;
        int C_flag;                                 // complie qualified flag that represents wether this file is able to complie
        int file_dir_err;                           // tell us whether certain file has vaild path
        int file_name_err;                          // tell us whether certain file has vaild name
    } File_info;                                     // stores file (download from canvas, actually they are assignments) information. There are some seats reserved for class unzip, for now, we are not sure.

    #define _FILE_INFO
    #endif

    #ifndef _ASSIGNMENT_INFO

    typedef struct {

        const char *Assigment_Comment;                // grader's comment to a assignment
        const char *Assignment_Graph_Title;
    } Assignment_info;                          // all the things about assignment
    #define _ASSIGNMENT_INFO
    #endif
    Stu_info S_info;
    File_info F_info;
    Assignment_info A_info;

} Course_info;                                   // Assigment_information is to store all information about assigment like

#define _COURSE_INFO
#endif

//---------------------------------------------------------------------------------

class Assignment_Unzip{
private:
    int m_Index, m_C_flag, m_Q_flag;
    const char *m_F_Orname, *m_F_Exname, *m_F_Dir_Old, *m_F_Dir_New;
public:                                         // there are two methods;
    Assignment_Unzip(int S_Index, const char *F_Orname, const char *F_Exname, const char *F_Dir_Old, const char *F_Dir_New);  // reload your weapon ready to shoot
    void A_Check_file(int &f_c_flag, int &f_q_flag, const char *F_Exname);                              // check the file to see whether its name follows the rule and can or not be complied if file name is qualified
    void A_Send_mail(int f_c_flag, int f_q_flag, char const *s_mailaddress);      // notify student whose submitted assigment is not qualified
};

#endif // ASSIGMENT_UNZIP_H
