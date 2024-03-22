#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<fstream>
#include<windows.h>
using namespace std;
class emp
{
    private:
        int emp_id,sal,group_id;
        string name,address;
    public:
        void menu();
        void insert();
        void display();
        void search();
        void modify();
        void del();
        void group();
        void search_group();
        void show_group();
};

    void login(){
        p:
        system("cls");
        char ch;
        string user,pass;
        cout<<"\n\n\n\n\n";
        cout<<"\t\t\t\t\t===========================";
        cout<<"\n\n\t\t\t\t\t\t Login Process";
        cout<<"\n\n\t\t\t\t\t===========================";
        cout<<"\n\n\n Enter User Name:";
        cin>>user;
        cout<<"\n\nEnter Password: ";
        for(int i=1;i<=6;i++){
            ch = getch();
            pass += ch;
            cout<<"*";
        }
        if(user == "abc@test.com" && pass=="123456"){
            cout<<"\n\n\n\n\t\t\t Congratulation Login Successful";
            cout<<"\n\n\n\t\t\t\t\tLoading";
            for(int i=1;i<=6;i++){
            Sleep(500);
            cout<<".";
            }
        }
        else if(user != "abc@test.com" && pass=="123456"){
            cout<<"\n\n\n Your User Name is Incorrect";
            getch();
            goto p;
        }
        else if(user == "abc@test.com" && pass!="123456"){
            cout<<"\n\n\n Your Password is Incorrect";
            getch();
            goto p;
        }
        else{
            cout<<"\n\n\n User Name & Password both are wrong";
            getch();
            exit(0);
        }
    }

    void emp::menu()
    {
        k:
        system("cls");
        int x;
        cout<<"\n\n\t\t\tControl Panel";
        cout<<"\n\n\n 1. Insert Record";
        cout<<"\n 2. Display Record";
        cout<<"\n 3. Search Record";
        cout<<"\n 4. Modify Record";
        cout<<"\n 5. Delete Record";
        cout<<"\n 6. Group Record";
        cout<<"\n 7. Search Group";
        cout<<"\n 8. Show All Groups";
        cout<<"\n 9. Exit";
        cout<<"\n\n Your Choice: ";
        cin>>x;

        switch (x)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            modify();
            break;
        case 5:
            del();
            break;
        case 6:
            group();
            break;
        case 7:
            search_group();
            break;
        case 8:
            show_group();
            break;
        case 9:
            /* code */
            exit(0);                            
        default:
            cout<<"\n\n Invalid Value..please try Again..";
            break;
        }
        getch();
        goto k;
    }
    void emp::insert(){
        system("cls");
        int test_id,found=0;
        fstream file,file1;
        cout<<"\n\n\t\t\t\tInsert Record";
        cout<<"\n\n Employee ID:";
        cin>>emp_id;
        cout<<"\n Employee Name:";
        cin>>name;
        cout<<"\n Employee Salary: ";
        cin>>sal;
        cout<<"\n Employee Address: ";
        cin>>address;
        cout<<"\n Employee Group ID: ";
        cin>>group_id;
        file.open("emp.txt",ios::out|ios::app);
        file<<" "<<emp_id<<" "<<name<<" "<<sal<<" "<<address<<" "<<group_id<<"\n";
        file.close();
        file1.open("group.txt",ios::out|ios::app);
        file1<<" "<<group_id<<" "<<emp_id<<" "<<sal<<"\n";
        file1.close();
        file.open("groupid.txt",ios::in);
        if(!file){
            file1.open("groupid.txt",ios::app|ios::out);
            file1<<" "<<group_id<<"\n";
            file1.close();
        }
        else{
            file>>test_id;
            while (!file.eof())
            {
                if(test_id == group_id){
                    found++;
                    file>>test_id;
                }
            }
            file.close();
            if(found == 0){
                file1.open("groupid.txt",ios::app|ios::out);
                file1<<" "<<group_id<<"\n";
                file1.close();
            }
            
        }
        cout<<"\n\n\n\t\t\tNew Record Inserted Successfully..";
    }
    void emp::display(){
        system("cls");
        fstream file;
        cout<<"\n\n\t\t\t\tDisplay Record";
        file.open("emp.txt",ios::in);
        if (!file)
        {
            cout<<"\n\n File Opening Error..";
            getch();
            menu();
        }
        
        file>>emp_id>>name>>sal>>address>>group_id;
        while (!file.eof())
        {
            cout<<"\n\n\n Employee ID : "<<emp_id;
            cout<<"\nEmployee Name : "<<name;
            cout<<"\nEmployee Salary : "<<sal;
            cout<<"\nEmployee Address : "<<address;
            cout<<"\nEmployee groupID : "<<group_id;
            file>>emp_id>>name>>sal>>address>>group_id;
        }
        getch();
        file.close();
        

    }
    void emp::search(){
        system("cls");
        fstream file;
        int emp_id_Search,found=0;
        cout<<"\n\n\t\t\t Search Record";
        file.open("emp.txt",ios::in);
        if(!file){
            cout<<"\n\n File Openning Error...";
            getch();
            menu();
        }
        cout<<"\n\n Employee ID for Search";
        cin>>emp_id_Search;
        file>>emp_id>>name>>sal>>address>>group_id;
        while (!file.eof())
        {
            if(emp_id_Search == emp_id){
                system("cls");
                cout<<"\n\n\t\t\tSearch Record";
                cout<<"\n\n\n Employee ID : "<<emp_id;
                cout<<"\nEmployee Name : "<<name;
                cout<<"\nEmployee Salary : "<<sal;
                cout<<"\nEmployee Address : "<<address;
                cout<<"\nEmployee groupID : "<<group_id;
                found++;
            }
            
            file>>emp_id>>name>>sal>>address>>group_id;
        }
        if(found == 0){
            cout<<"\n \n Employee ID Can't Found...";
        }
        getch();
        file.close();
    }
    void emp::modify(){
        system("cls");
        int sal1,test_id,found=0;
        string name1,address1;
        fstream file,file1,file2,file3;
        cout<<"\n\n\t\t\tModify Record";
        file.open("emp.txt",ios::in);
        file1.open("group.txt",ios::in);
        if(!file || !file1){
            cout<<"\n\n File Opening Error...";
            getch();
            menu();
        }
        cout<<"\n\n Employee ID For Modify :";
        cin>>test_id;
        file2.open("emp1.txt",ios::out|ios::app);
        file>>emp_id>>name>>sal>>address>>group_id;
        while (!file.eof())
        {
            if(test_id == emp_id){
                system("cls");
                cout<<"\n\n\t\t\t Modify Record";
                cout<<"\n\n Employee Name:";
                cin>>name1;
                cout<<"\n Employee Salary:";
                cin>>sal1;
                cout<<"\n Employee Address: ";
                cin>>address1;
                file2<<" "<<emp_id<<" "<<name1<<" "<<sal1<<" "<<address1<<" "<<group_id<<"\n";
                found++;
            }
            else{
                file2<<" "<<emp_id<<" "<<name<<" "<<sal<<" "<<address<<" "<<group_id<<"\n";
            }
            file>>emp_id>>name>>sal>>address>>group_id;
        }
        file.close();
        file2.close();
        remove("emp.txt");
        rename("emp1.txt","emp.txt");
        file3.open("group1.txt",ios::app|ios::out);
        file1>>group_id>>emp_id>>sal;
        while (!file1.eof())
        {
            if(test_id == emp_id){
                file3<<" "<<group_id<<" "<<emp_id<<" "<<sal1<<"\n";
            }
            else{
                file3<<" "<<group_id<<" "<<emp_id<<" "<<sal<<"\n";
            }
            file1>>group_id>>emp_id>>sal;
        }
        file1.close();
        file3.close();
        remove("group.txt");
        rename("group1.txt","group.txt");  
        if(found == 0){
            cout<<"\n \n Employee ID Can't Found...";
        }
        else{
            cout<<"\n\n\t\t\t Record Modify Succussfully...";
        }
        
        
    }

    void emp::del(){
        system("cls");
        int test_id,found=0;
        fstream file,file1,file2,file3;
        cout<<"\n\n\t\t\tDelete Record";
        file.open("emp.txt",ios::in);
        file1.open("group.txt",ios::in);
        if(!file || !file1){
            cout<<"\n\n File Opening Error...";
            getch();
            menu();
        }
        cout<<"\n\n Employee ID For Delete :";
        cin>>test_id;
        file2.open("emp1.txt",ios::out|ios::app);
        file>>emp_id>>name>>sal>>address>>group_id;
        while (!file.eof())
        {
            if(test_id == emp_id){
                found++;
            }
            else{
                file2<<" "<<emp_id<<" "<<name<<" "<<sal<<" "<<address<<" "<<group_id<<"\n";
            }
            file>>emp_id>>name>>sal>>address>>group_id;
        }
        file.close();
        file2.close();
        remove("emp.txt");
        rename("emp1.txt","emp.txt");
        file3.open("group1.txt",ios::app|ios::out);
        file1>>group_id>>emp_id>>sal;
        while (!file1.eof())
        {
            if(test_id == emp_id){

            }
            else{
                file3<<" "<<group_id<<" "<<emp_id<<" "<<sal<<"\n";
            }
            file1>>group_id>>emp_id>>sal;
        }
        file1.close();
        file3.close();
        remove("group.txt");
        rename("group1.txt","group.txt");  
        if(found == 0){
            cout<<"\n \n Employee ID Can't Found...";
        }
        else{
            cout<<"\n\n\t\t\t Record Deleted Succussfully...";
        }
    }

    void emp::group(){

        system("cls");
        fstream file;
        cout<<"\n\n\t\t\t\tGroup Record";
        file.open("group.txt",ios::in);
        if (!file)
        {
            cout<<"\n\n File Opening Error..";
            getch();
            menu();
        }
        
        file>>group_id>>emp_id>>sal;
        while (!file.eof())
        {
            cout<<"\n\n\n Group ID : "<<group_id;
            cout<<"\nEmployee ID : "<<emp_id;
            cout<<"\nEmployee Salary : "<<sal;
            file>>group_id>>emp_id>>sal;
        }
        getch();
        file.close();
    }

    void emp::search_group(){
        system("cls");
        int test_id,found=0,emp_count=0,sal_count=0;
        fstream file;
        cout<<"\n\n\t\t\tSearch Group Record";
        file.open("group.txt",ios::in);
        if (!file)
        {
            cout<<"\n\n File Opening Error..";
            getch();
            menu();
        }
        cout<<"\n\n Group ID For Search:";
        cin>>test_id;
        system("cls");
        cout<<"\n\n\n\t\t\tSearch Group Record";
        file>>group_id>>emp_id>>sal;
        while (!file.eof())
        {
            if(test_id == group_id){
                cout<<"\n\n\n Group ID : "<<group_id;
                cout<<"\nEmployee ID : "<<emp_id;
                cout<<"\nEmployee Salary : "<<sal;
                found++;
                emp_count++;
                sal_count = sal_count + sal;
            }
            file>>group_id>>emp_id>>sal; 
        }
        file.close();
        if(found != 0){
            cout<<"\n\n\n Group ID :"<<test_id;
            cout<<"\n\nTotal Employee :"<<emp_count;
            cout<<"\n\n Total Salary: "<<sal_count;
        }
        else{
            cout<<"\n\n Group ID can't found";
        }   
    }
    void emp::show_group(){
        system("cls");
        int test_id,emp_count=0,sal_count=0,emp_total=0,sal_total=0;
        fstream file,file1;
        cout<<"\n\n\t\t\t Show All Groups";
        file.open("groupid.txt",ios::in);
        if (!file)
        {
            cout<<"\n\n File Opening Error..";
            getch();
            menu();
        }
        file>>test_id;
        while (!file.eof())
        {
            file1.open("group.txt",ios::in);
            file1>>group_id>>emp_id>>sal;
            while (!file1.eof())
            {
                if(test_id == group_id){
                    emp_count++;
                    sal_count += sal;
                    emp_total++;
                    sal_total += sal;
                }
                file1>>group_id>>emp_id>>sal;
            }
            file1.close();
            cout<<"\n\n\n\t\tGroup ID: "<<test_id;
            cout<<"\n\n\n\t\tTotal Employee: "<<emp_count;
            cout<<"\n\n\n\t\tTotal Salary: "<<sal_count;
            emp_count=0;
            sal_count=0;
            file>>test_id;
        }

        

        file.close();
        cout<<"\n\n\n Over All Employee: "<<emp_total;
        cout<<"\n\n\n Over All Salary: "<<sal_total;
    }
   

main(){
    emp e;
    login();
    e.menu();
}