#include<stdio.h>
#include<string.h>

//check ct marks as student..
void check_marks(char u_name[50])
{
    struct marks
    {
        char roll[50];
        char course_code[50];
        char mark[50];
    };
    struct marks m;

    struct student
    {
        char name[50];
        char password[50];
        char roll[50];
        char dept[50];
        char email[50];
        char mobile[50];
    };
    struct student s;

    FILE *mf,*sf;
    mf=fopen("marks.txt","r");
    sf=fopen("student.txt","r");
    char r[10];
    int z=0;
    while(fread(&s,sizeof(s),1,sf))
    {
        if(strcmp(u_name,s.name)==0)
        {
            strcpy(r,s.roll);
            break;
        }
    }
    while(fread(&m,sizeof(m),1,mf))
    {
        if(strcmp(m.roll,r)==0)
        {
            z=1;
            printf("%s : %s\n",m.course_code,m.mark);
        }
    }
    if(z==0)
    {
        printf("\nNo marks provided!!!\n");
    }

    printf("\nEnter 0 to go back... ");
    int q;
    scanf("%d",&q);

    if(q==0)
    {
        student_panel(u_name);
    }
}
//student panel
void student_panel(char u_name[50])
{
    printf("\n\n\t\t---------- Student Panel ---------\n\n");
    printf("\t1.Check CT marks\n");
    printf("\t0.Go to home\n");
    int ch;
    scanf("%d",&ch);
    if(ch==1)
    {
        check_marks(u_name);
    }
    if(ch==0)
    {
        main();
    }
}
//student login
void s_login()
{
    printf("\n\n\t\t------- Log in to Your Account ----------\n\n");
    struct student
    {
        char name[50];
        char password[50];
        char roll[50];
        char dept[50];
        char email[50];
        char mobile[50];
    };
    struct student s;

    char u_name[50],pass[50];
    int p=0;

    printf("Enter name: ");
    fflush(stdin);
    gets(u_name);
    printf("Enter password: ");
    fflush(stdin);
    gets(pass);
    printf("\n");

    FILE *sf;
    sf=fopen("student.txt","r");
    if(sf==NULL)
    {
        printf("file not found");
    }

    while(fread(&s,sizeof(s),1,sf))
    {

        if(strcmp(u_name,s.name)==0)//user found
        {
            p=1;
            if(strcmp(pass,s.password)==0)// password matched
            {

                printf("Log in successful.");
                student_panel(u_name);
                break;
            }
            else
            {
                printf("Incorrect password!!!");
                break;
            }
        }
    }
    if(p==0)
    {
        printf("User not found!!!");
    }
    fclose(sf);
}
//complete teacher panel..
//total student
void s_count(char u_name[20])
{
    struct student
    {
        char name[50];
        char password[50];
        char roll[50];
        char dept[50];
        char email[50];
        char mobile[50];
    };
    struct student s;

    FILE *sf;
    sf=fopen("student.txt","r");

    int c=0;
    while(fread(&s,sizeof(s),1,sf))
    {
        c++;
    }
    printf("Total student: %d",c);

    fclose(sf);

    int q;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&q);

    if(q==0)
    {
        teachers_panel(u_name);
    }
}

//find student by  name
void find_by_name(char u_name[50])
{
    printf("\n\n\t\t------ Find Student by Name -----------\n\n");
    struct student
    {
        char name[50];
        char password[50];
        char roll[50];
        char dept[50];
        char email[50];
        char mobile[50];
    }s;

    FILE *sf;
    sf=fopen("student.txt","r");
    char n[50];
    printf("Enter student's name: ");
    fflush(stdin);
    gets(n);

    while(fread(&s,sizeof(s),1,sf))
    {
        if(strcmp(n,s.name)==0)
        {
            printf("\nName %7c %s\n",':',s.name);
            printf("Roll %7c %s\n",':',s.roll);
            printf("Department %1c %s\n",':',s.dept);
            printf("Email %6c %s\n",':',s.email);
            printf("Mobile no %2c %s\n\n",':',s.mobile);
            break;
        }
    }
    fclose(sf);

    int q;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&q);

    if(q==0)
    {
        teachers_panel(u_name);
    }
}
//find student by roll
void find_by_roll(char u_name[50])
{
    printf("\n\n\t\t--------Find Student by Roll ---------\n\n");
    struct student
    {
        char name[50];
        char password[50];
        char roll[50];
        char dept[50];
        char email[50];
        char mobile[50];
    } s;

    FILE *sf;
    sf=fopen("student.txt","r");
    char r[50];
    printf("Enter student's roll: ");
    scanf("%s",r);

    while(fread(&s,sizeof(s),1,sf))
    {
        if(strcmp(r,s.roll)==0)
        {
            printf("\nName %7c %s\n",':',s.name);
            printf("Roll %7c %s\n",':',s.roll);
            printf("Department %1c %s\n",':',s.dept);
            printf("Email %6c %s\n",':',s.email);
            printf("Mobile no %2c %s\n\n",':',s.mobile);
            break;
        }
    }
    fclose(sf);

    int q;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&q);

    if(q==0)
    {
        teachers_panel(u_name);
    }

}
//update student's ct marks........
//update ct marks
void u_ct_mark(char u_name[50])
{
    printf("\n\n\t\t------- Update CT Marks --------\n\n");
    struct course
    {
        char username[50];
        char course_1[50];
        char course_2[50];
    } c;

    struct marks
    {
        char roll[50];
        char course_code[50];
        char mark[50];
    } m;

    FILE *cf,*mf;
    cf=fopen("course.txt","r");
    mf=fopen("marks.txt","r+");

    char code[50];
    int z=0,y=0,x=0;
    while(fread(&c,sizeof(c),1,cf))
    {
        if(strcmp(u_name,c.username)==0)
        {
            z=1;
            printf("Enter course code: ");
            fflush(stdin);
            gets(code);
            if((strcmp(code,c.course_1)==0) || strcmp(code,c.course_2)==0)
            {
                char r[50];
                strcpy(m.course_code,code);
                y=1;
                printf("Enter roll: ");
                scanf("%s",r);

                while(fread(&m,sizeof(m),1,mf))
                {
                    if(strcmp(m.roll,r)==0)
                    {
                        x=1;
                        printf("Enter new CT mark: ");
                        scanf("%s",m.mark);

                        fseek(mf,-sizeof(m),1);
                        fwrite(&m,sizeof(m),1,mf);

                        printf("\nmarks updated successfully...\n");

                        break;
                    }
                }

            }
        }
    }

    if(z==0)
    {
        printf("\nNo course assigned to you!!!\n");
    }
    else if(y==0)
    {
        printf("\nThis course is not for you!!!\n");
    }
    else if(x==0)
    {
        printf("\nRoll not found !!!\n");
    }

    fclose(cf);
    fclose(mf);

    int a;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&a);

    if(a==0)
    {
        teachers_panel(u_name);
    }
}
void p_ct_mark(char u_name[50])
{
    printf("\n\n\t\t--------- Provide CT Marks ---------\n\n");
    struct course
    {
        char name[50];
        char course_1[50];
        char course_2[50];
    } c;

    struct student
    {
        char name[50];
        char password[50];
        char roll[50];
        char dept[50];
        char email[50];
        char mobile[50];
    } s;

    struct marks
    {
        char roll[50];
        char course_code[50];
        char mark[50];
    } m;

    FILE *cf,*sf,*mf;
    cf=fopen("course.txt","r");
    sf=fopen("student.txt","r");
    mf=fopen("marks.txt","a");

    char code[50];
    int z=0,y=0,x=0;
    while(fread(&c,sizeof(c),1,cf))
    {
        if(strcmp(u_name,c.name)==0)
        {
            z=1;
            printf("Enter course code: ");
            scanf("%s",code);

            if((strcmp(code,c.course_1)==0) || strcmp(code,c.course_2)==0)
            {
                strcpy(m.course_code,code);
                y=1;
                printf("Enter roll: ");
                scanf("%s",m.roll);

                while(fread(&s,sizeof(s),1,sf))
                {
                    if(strcmp(m.roll,s.roll)==0)
                    {
                        x=1;
                        printf("Enter CT mark: ");
                        scanf("%s",m.mark);

                        fwrite(&m,sizeof(m),1,mf);

                        printf("\nmarks provided successfully...\n");

                        break;
                    }
                }

            }
        }
    }

    if(z==0)
    {
        printf("\nNo course assigned to you!!!\n");
    }
    else if(y==0)
    {
        printf("\nThis course is not for you!!!\n");
    }
    else if(x==0)
    {
        printf("\nRoll not found !!!\n");
    }
    fclose(cf);
    fclose(sf);
    fclose(mf);

    int a;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&a);

    if(a==0)
    {
        teachers_panel(u_name);
    }
}
//teachers panel
void teachers_panel(char u_name[20])
{
    printf("\n\n\t\t---------Teacher's Panel -------------\n\n");
    printf("\t1.Provide CT marks\n");
    printf("\t2.Update CT marks\n");
    printf("\t3.Find student by roll\n");
    printf("\t4.Find student by name\n");
    printf("\t5.Total students\n");
    printf("\t0.Go to home\n");

    int ch;
    printf("\nEnter your choice(serial no): ");
    scanf("%d",&ch);

    if(ch==1)
    {
        p_ct_mark(u_name);
    }
    else if(ch==2)
    {
        u_ct_mark(u_name);
    }
    else if(ch==3)
    {
        find_by_roll(u_name);
    }
    else if(ch==4)
    {
        find_by_name(u_name);
    }
    else if(ch==5)
    {
        s_count(u_name);
    }
    else if(ch==0)
    {
        main();
    }
}

//teacher login.....
void t_login()
{
    printf("\n\n\t\t-------- Log in to Your Account ----------\n\n");
    struct teacher
    {
        char name[50];
        char password[50];
        char dept[50];
        char status[50];
        char email[50];
        char mobile[50];
    };
    struct teacher t;

    char u_name[50],pass[50];
    int p=0;

    printf("Enter name: ");
    fflush(stdin);
    gets(u_name);
    printf("Enter password: ");
    fflush(stdin);
    gets(pass);
    printf("\n");

    FILE *tf;
    tf=fopen("teacher.txt","r");
    if(tf==NULL)
    {
        printf("file not found");
    }

    while(fread(&t,sizeof(t),1,tf))
    {

        if(strcmp(u_name,t.name)==0)//user found
        {
            p=1;
            if(strcmp(pass,t.password)==0)// password matched
            {

                printf("Log in successful.");
                teachers_panel(u_name);
                break;
            }
            else
            {
                printf("Incorrect password!!!");
                break;
            }
        }
    }
    if(p==0)
    {
        printf("User not found!!!");
    }
    fclose(tf);
}
//complete admin panel's job...
//update course.....
//1  teacer 2  course........
void c_update()
{
    printf("\n\n\t\t---------Course Update---------\n\n");
    struct course
    {
        char name[50];
        char course_1[50];
        char course_2[50];
    };
    struct course c;

    char u[50];
    printf("Enter Teacher's name: ");
    fflush(stdin);
    gets(u);

    FILE *crs;
    crs=fopen("course.txt","r+");
    int p=0;

    while(fread(&c,sizeof(c),1,crs))
    {
        if(strcmp(c.name,u)==0)
        {
            p=1;
            printf("Enter new course code-1: ");
            fflush(stdin);
            gets(c.course_1);
            printf("Enter new course code-2: ");
            fflush(stdin);
            gets(c.course_2);

            fseek(crs,-sizeof(c),1);//pointig the required data.....
            fwrite(&c,sizeof(c),1,crs);

            printf("\nCourse updated successfully...\n");
            break;
        }
    }
    fclose(crs);

    if(p==0)
    {
        printf("\nUser not found!!!\n");
    }

    int q;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&q);

    if(q==0)
    {
        admin_panel();
    }
}
//assigning courses.....
//1 teacher 2 ta course ...!!!
void course_assign()
{
    printf("\n\n\t\t-------Course Assignment --------\n\n");
    struct course
    {
        char name[50];
        char course_1[50];
        char course_2[50];
    };
    struct course c;

    struct teacher
    {
        char name[50];
        char password[50];
        char dept[50];
        char status[50];
        char email[50];
        char mobile[50];
    };
    struct teacher td;

    char u[50];
    printf("Enter Teacher's name: ");
    fflush(stdin);
    gets(u);

    FILE *t,*crs;
    t=fopen("teacher.txt","r");
    crs=fopen("course.txt","r");
    int z=0,y=0;

    while(fread(&c,sizeof(c),1,crs))
    {
        if(strcmp(c.name,u)==0)
        {
            y=1;
            printf("\nCourse already assigned to %s\n",u);
            break;
        }
    }
    fclose(crs);

    if(y==0)
    {
        strcpy(c.name,u);
        crs=fopen("course.txt","a");

        while(fread(&td,sizeof(td),1,t))
        {
            if(strcmp(c.name,td.name)==0)
            {
                z=1;
                printf("Enter course code-1: ");
                fflush(stdin);
                gets(c.course_1);
                printf("Enter course code-2: ");
                fflush(stdin);
                gets(c.course_2);
                fwrite(&c,sizeof(c),1,crs);

                printf("\nCourse added successfully...\n");
                break;
            }
        }
        fclose(crs);
    }

    fclose(t);


    if(z==0 && y==0)
    {
        printf("\nUser not found!!!\n");
    }

    int q;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&q);

    if(q==0)
    {
        admin_panel();
    }
}
//update student's info.....
void s_update()
{
    printf("\n\n\t\t-------Update Student's Information--------\n\n");

    struct student
    {
        char name[50];
        char password[50];
        char roll[50];
        char dept[50];
        char email[50];
        char mobile[50];
    };
    struct student s_u;

    //enter the student's name whose info u what to update.....
    char u[50];
    printf("Enter student's name: ");
    fflush(stdin);
    gets(u);

    FILE *f;
    f=fopen("student.txt","r+");

    int z=0;
    while(fread(&s_u,sizeof(s_u),1,f))
    {
        if(strcmp(u,s_u.name)==0)
        {
            z=1;
            printf("\nIf you want to update whole info,than press 0 ortherwise 1:");
            int b;
            scanf("%d",&b);
            if(b==0)
            {printf("Full name: ");
            fflush(stdin);
            gets(s_u.name);
            printf("Password: ");
            fflush(stdin);
            gets(s_u.password);
            printf("Roll: ");
            fflush(stdin);
            gets(s_u.roll);
            printf("Department: ");
            fflush(stdin);
            gets(s_u.dept);
            printf("E-mail: ");
            fflush(stdin);
            gets(s_u.email);
            printf("Mobile no.: ");
            fflush(stdin);
            gets(s_u.mobile);}

            else if(b==1)
            {
                printf("\n\nGive your choice what you want to update: \n");
                printf("\n\t\t1.Full name");
                printf("\n\t\t2.Password");
                printf("\n\t\t3.Roll");
                printf("\n\t\t4.Dept");
                printf("\n\t\t5.E-mail");
                printf("\n\t\t6.Mobile-no");

                printf("\n\nEnter your choice: ");
                int c;
                scanf("%d",&c);

                switch(c)
                {
                case 1:
                    printf("New full name: ");
                    fflush(stdin);
                    gets(s_u.name);
                    break;
                case 2:
                    printf("New password: ");
                    fflush(stdin);
                    gets(s_u.password);
                    break;
                case 3:
                    printf("New roll: ");
                    fflush(stdin);
                    gets(s_u.roll);
                    break;
                case 4:
                    printf("New department: ");
                    fflush(stdin);
                    gets(s_u.dept);
                    break;
                case 5:
                    printf("New e-mail: ");
                    fflush(stdin);
                    gets(s_u.email);
                    break;
                case 6:
                    printf("New mobile no.: ");
                    fflush(stdin);
                    gets(s_u.mobile);
                    break;
                }
            }
            fseek(f,-sizeof(s_u),1);//pointing to the required data
            fwrite(&s_u,sizeof(s_u),1,f);
            break;
        }
    }
    fclose(f);

    if(z==0)
    {
        printf("\n\nName not found!!!\n");
    }
    else
    {
        printf("\n\nInformation updated successfully!!!\n");
    }
    printf("\nEnter 0 to go back... ");
    int q;
    scanf("%d",&q);

    if(q==0)
    {
        admin_panel();
    }
}
//update teacher's info......
void t_update()
{
    printf("\n\n\t\t-----------Update Teacher's Information-----------\n\n");

    struct teacher
    {
        char name[50];
        char password[50];
        char dept[50];
        char status[50];
        char email[50];
        char mobile[50];
    };
    struct teacher t_u;

    //enter teacher's name whose info user wants to update.....
    char u[50];
    printf("Enter teacher's name: ");
    fflush(stdin);
    gets(u);

    FILE *f;
    f=fopen("teacher.txt","r+");
    //open the teacher's file and check if the given name is in that file?

    int z=0;
    while(fread(&t_u,sizeof(t_u),1,f))
    {
        if(strcmp(u,t_u.name)==0)
        {
            z=1;
            printf("\nIf you want to update whole info,than press 0 ortherwise 1:");
            int b;
            scanf("%d",&b);
            if(b==0)
            {printf("Full name: ");
            fflush(stdin);
            gets(t_u.name);
            printf("Password: ");
            fflush(stdin);
            gets(t_u.password);
            printf("Department: ");
            fflush(stdin);
            gets(t_u.dept);
            printf("Status: ");
            fflush(stdin);
            gets(t_u.status);
            printf("E-mail: ");
            fflush(stdin);
            gets(t_u.email);
            printf("Mobile no.: ");
            fflush(stdin);
            gets(t_u.mobile);}

            else if(b==1)
            {
                printf("\n\nGive your choice what you want to update: \n");
                printf("\n\t\t1.Full name");
                printf("\n\t\t2.Password");
                printf("\n\t\t3.Department");
                printf("\n\t\t4.Status");
                printf("\n\t\t5.E-mail");
                printf("\n\t\t6.Mobile-no");

                printf("\n\nEnter your choice: ");
                int c;
                scanf("%d",&c);
                switch(c)
                {
                case 1:
                    printf("New full name: ");
                    fflush(stdin);
                    gets(t_u.name);
                    break;
                case 2:
                    printf("New password: ");
                    fflush(stdin);
                    gets(t_u.password);
                    break;
                case 3:
                    printf("New department: ");
                    fflush(stdin);
                    gets(t_u.dept);
                    break;
                case 4:
                    printf("Status: ");
                    fflush(stdin);
                    gets(t_u.status);
                    break;
                case 5:
                    printf("New e-mail: ");
                    fflush(stdin);
                    gets(t_u.email);
                    break;
                case 6:
                    printf("New mobile no.: ");
                    fflush(stdin);
                    gets(t_u.mobile);
                    break;
                }
            }
            fseek(f,-sizeof(t_u),1);//pointing to the required data
            fwrite(&t_u,sizeof(t_u),1,f);
            break;
        }
    }
    fclose(f);

    if(z==0)
    {
        printf("\n\nname not found!!!\n\n");
    }
    else
    {
        printf("\n\nInformation updated successfully!!!\n");
    }

    printf("\n\nEnter 0 to go back... ");
    int q;
    scanf("%d",&q);

    if(q==0)
    {
        admin_panel();
    }
}
//show student info....
void s_info()
{
    printf("\n\n\t\t-------Student information-------\n\n");
    struct student
    {
        char name[50];
        char password[50];
        char roll[50];
        char dept[50];
        char email[50];
        char mobile[50];
    };
    struct student s;

    FILE *sf;
    sf=fopen("student.txt","r");

    while(fread(&s,sizeof(s),1,sf))
    {
        printf("name %7c %s\n",':',s.name);
        printf("Password %3c %s\n",':',s.password);
        printf("Roll %7c %s\n",':',s.roll);
        printf("Department %1c %s\n",':',s.dept);
        printf("Email %6c %s\n",':',s.email);
        printf("Mobile no %2c %s\n\n",':',s.mobile);
        printf("\n\n");
    }
    fclose(sf);

    printf("\nEnter 0 to go back... ");
    int q;
    scanf("%d",&q);

    if(q==0)
    {
        admin_panel();
    }
}
//show teacher info....
void t_info()
{
    printf("\n\n\t\t-----------Teacher's Information----------\n\n");
    struct teacher
    {
        char name[50];
        char password[50];
        char dept[50];
        char status[50];
        char email[50];
        char mobile[50];
    };
    struct teacher t;

    FILE *tf;
    tf=fopen("teacher.txt","r");

    while(fread(&t,sizeof(t),1,tf))
    {
        printf("Name %7c %s\n",':',t.name);
        printf("Password %3c %s\n",':',t.password);
        printf("Department %1c %s\n",':',t.dept);
        printf("Status %5c %s\n",':',t.status);
        printf("Email %6c %s\n",':',t.email);
        printf("Mobile no %2c %s\n",':',t.mobile);
        printf("\n\n");
    }
    fclose(tf);

    printf("\n\nEnter 0 to go back... ");
    int q;
    scanf("%d",&q);

    if(q==0)
    {
        admin_panel();
    }
}
//create student account.......
void s_account()
{
    struct student
    {
        char name[50];
        char password[50];
        char roll[50];
        char dept[50];
        char email[50];
        char mobile[50];
    };
    struct student st;

    printf("\n\n\t\t---------- Create Student's Account-----------\n\n");

    printf("Full name: ");
    fflush(stdin);
    gets(st.name);
    printf("Password: ");
    fflush(stdin);
    gets(st.password);
    printf("Roll: ");
    fflush(stdin);
    gets(st.roll);
    printf("Department: ");
    fflush(stdin);
    gets(st.dept);
    printf("E-mail: ");
    fflush(stdin);
    gets(st.email);
    printf("Mobile no.: ");
    fflush(stdin);
    gets(st.mobile);

    FILE *sd;
    sd=fopen("student.txt","a");
    fwrite(&st,sizeof(st),1,sd);
    fclose(sd);

    printf("\nAccount created successfully!!!\n\n");
    printf("Enter 0 to go back... ");
    int q;
    scanf("%d",&q);

    if(q==0)
    {
        admin_panel();
    }
}
//create teacher account as an admin........
void t_account()
{
    struct teacher
    {
        char name[50];
        char password[50];
        char dept[50];
        char status[50];
        char email[50];
        char mobile[50];
    };
    struct teacher tch;

    printf("\n\n\t\t--------- Create Teacher's Account ----------\n\n");

    printf("Full name: ");
    fflush(stdin);
    gets(tch.name);
    printf("Password: ");
    fflush(stdin);
    gets(tch.password);
    printf("Department: ");
    fflush(stdin);
    gets(tch.dept);
    printf("Status: ");
    fflush(stdin);
    gets(tch.status);
    printf("E-mail: ");
    fflush(stdin);
    gets(tch.email);
    printf("Mobile no.: ");
    fflush(stdin);
    gets(tch.mobile);

    FILE *td;
    td=fopen("teacher.txt","a");//append mode for store all data,past and present input data....
    fwrite(&tch,sizeof(tch),1,td);
    fclose(td);

    printf("\nAccount created successfully!!!\n\n");
    printf("Enter 0 to go back...");
    int q;
    scanf("%d",&q);

    if(q==0)
    {
        admin_panel();
    }
}
//as an admin...
void admin_panel()
{
    printf("\n\n\t\t----------This is Admin Panel ----------\n\n");
    printf("Select what you want to do:\n");

    printf("\t1.Create teacher's account\n");
    printf("\t2.Create student's account\n");
    printf("\t3.Show teacher's information\n");
    printf("\t4.Show student's information\n");
    printf("\t5.Update teacher's information\n");
    printf("\t6.Update student's information\n");
    printf("\t7.Assign courses to teacher\n");
    printf("\t8.Update courses of teacher\n");
    printf("\t0.Go to home\n");

    printf("Enter your choice(serial no): ");
    int cs;
    scanf("%d",&cs);

    if(cs==1)
    {
        t_account();
    }
    else if(cs==2)
    {
        s_account();
    }
    else if(cs==3)
    {
        t_info();
    }
    else if(cs==4)
    {
        s_info();
    }
    else if(cs==5)
    {
        t_update();
    }
    else if(cs==6)
    {
        s_update();
    }
    else if(cs==7)
    {
        course_assign();
    }
    else if(cs==8)
    {
        c_update();
    }
    else if(cs==0)
    {
        main();
    }
}
//1stly u have to create admin account by previous code....
//if choice=1
void admin_login()
{
    struct admin_login
    {
        char username[50];
        char password[50];
    };
    struct admin_login ad;

    printf("\n\n\t\t---------Log in to Your Account--------\n\n");
    char username[50],pass[50];
    int p=0;

    printf("Enter username: ");
    scanf("%s",username);
    printf("Enter password: ");
    scanf("%s",pass);
    printf("\n");

    FILE *admn;
    admn=fopen("myadmin.txt","r");
    if(admn==NULL)
    {
        printf("file not found");
    }

    while(fread(&ad,sizeof(ad),1,admn))
    {

        if(strcmp(username,ad.username)==0)
        {
            p=1;//user found...
            if(strcmp(pass,ad.password)==0)
            {

                printf("Log in successful.....!");// password matched....
                admin_panel();
                break;
            }
            else
            {
                printf("Incorrect password......!");//if did not match....
                break;
            }
        }
    }
    if(p==0)
    {
        printf("User not found!!!");
    }
fclose(admn);
}
int main()
{
        printf("\t\t\t\t---------Welcome to my project of CSE-1202----------\n\n");
        printf("\n\nThis is management system.\n");
        printf("Choose an option from below what you want to enroll:\n");
        printf("\t1.Admin\n");
        printf("\t2.Teacher\n");
        printf("\t3.Student\n");
        printf("\t4.Exit\n");

        printf("\nEnter your choice: ");
        int cs;
        scanf("%d",&cs);
        switch(cs)
        {
            case 1:
                admin_login();
                break;
            case 2:
                t_login();
                break;
            case 3:
                s_login();
                break;
            case 4:
                exit(0) ;
        }
    return 0;
}

