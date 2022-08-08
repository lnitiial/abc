
未曾登陆过的初始化学生密码：123
未曾登陆过的初始化教师密码：1234
未曾登陆过的初始化校长密码：12345

文件：
    teacher.txt//教师信息
    student.txt//学生信息
    pricipal.txt//校长信息
    stu_inf.txt//学生姓名性别导入（格式：姓名 性别）
    score.txt//学生成绩导入（格式：学号 语文 数学 英语）

文件读取：fread（二进制读取）
文件写入：fwrite（二进制写入）


全局变量：
        extern Student *Stu;//储存学生的数组

        extern int Sum_stu; //总学生数量

        extern Teacher *Tea;//储存教师的数组

        extern int Sum_tea;//总教师数量

        extern Principal *Pri;//储存校长的结构性指针
      

        #define MAX_STU 500  //在校和离校的最大学生人数
        #define MAX_TEA 50  //在校和离校的最大教师人数

三个结构体：
***********************************************************************************
    typedef struct Student//学生结构体
    {
        char name[20];//名字
        char id[10];//学号
        char password[20];//密码 初始化为123
        int chinese;//语文成绩
        int math;//数学成绩
        int english;//英语成绩
        bool in_school;//是否在校
        bool cur_state;//当前状态是不是被锁定 false为锁定 true为自由状态
        bool is_first;//是否是第一次登录 ture为第一次登录
        char sex;//性别
    }Student;
*************************************************************************************
    typedef struct Teacher//教师结构体
    {
        char name[20];//名字
        char id[10];//工号
        char passward[20];//密码 初始化为1234
        char sex;//性别
        bool in_school;//是否在校
        bool cur_state;//当前状态 false为锁定 true为自由状态
        bool is_first;//是否是第一次登录  ture为第一次登录
    }Teacher;
************************************************************************************
    typedef struct Pricipal//校长专属结构体
    {
        char passward[20]=;//密码 初始化为12345
        bool is_first;//是否是第一次登录  ture为第一次登录
    }Pricipal;
           
                        

  
    判断是否顺利登陆函数：
        1、先要判断有没有这个学生的学号 如果没有 显示提示信息
        2、查看当前学生信息的状态（可以再结构体中添加一个储存状态的成员名bool cur_state初始化为true为自用状态，false为锁定状态），
            如果是被锁定则提示  “找老师解锁” 
        3、如果有该学号状态为true，则让用户输入密码 如果不对 显示重新输入的提示 且重复输入次数（可以定义一个全局变量）+1
        4、如果密码正确，则会判断是否是第一次登陆（可以在结构体中再设置一个bool类型的成员名is_first且初始化为true)如果是，则强制用户重新修改密码(可以在结构体中再设置一个char类型的成员名password且初始化为123)
        5、如果不是第一次登陆，则显示界面：1查询成绩
                                        2修改密码
                                        3查看个人信息
                                        4退出，返回主界面
   





