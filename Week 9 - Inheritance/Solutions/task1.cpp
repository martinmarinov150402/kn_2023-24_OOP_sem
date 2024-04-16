#include <iostream>
#include <fstream>
#include <cstring>

class Person
{
    private:
        char name[21];
        int age;
        char email[51];
    public:
        Person()
        {
            Person("", 55, "");
        }
        Person(char *name, int age, char* email)
        {
            strcpy(this->name, name);
            this->age = age;
            strcpy(this->email, email);
        }
        void print();
        void send_mail(char *message);
        void view_inbox();
        char* getName() {return name;};
        char* getEmail() { return email;};
};

void Person::print()
{
    std::cout << "Name: "  << name  << std::endl
              << "Age: "   << age   << std::endl
              << "Email: " << email << std::endl;
}
void Person::send_mail(char *message)
{
    std::ofstream file;
    file.open(name, std::ios::app);
    if(file)
    {
        file << "To " << name <<": " << message << std::endl; 
    }
    file.close();
}
void Person::view_inbox()
{
    std::ifstream file(name);
    char mail[1001];
    if(file)
    {
        while(!file.eof())
        {

            file.getline(mail, 1000);
            std::cout << mail << std::endl;
        }
    }   
    file.close();
}

class Student : public Person
{
    private:
        char fN[11];
    
    public:
        void print();
        void send_mail(char* message);
        Student()
        {
            Student("", 88, "", "");
        }
        Student(char *name, int age, char* email, char* fn) : Person(name, age, email)
        {
            strcpy(this->fN, fn);
        }
};

void Student::print()
{
    Person::print();
    std::cout << "FN: " << fN << std::endl;
}
void Student::send_mail(char* message)
{

    std::ofstream file;
    file.open(getName(), std::ios::app);
    if(file)
    {
        file << "To " << getName() << ", " << fN <<": " << message << std::endl; 
    }
    file.close();
}

class Lecturer : public Person
{
    private:
        char department[21];
    
    public:
        void print();
        void send_mail(char* message);
        Lecturer()
        {
            Lecturer("", 55, "", "");
        }
        Lecturer(char *name, int age, char* email, char* department) : Person(name, age, email)
        {
            strcpy(this->department, department);
        }
};

void Lecturer::print()
{
    Person::print();
    std::cout << "Department: " << department << std::endl;
}
void Lecturer::send_mail(char* message)
{

    std::ofstream file;
    file.open(getName(), std::ios::app);
    if(file)
    {
        file << "To " << getName() << ", part of " << department <<" department: " << message << std::endl; 
    }
    file.close();
}

class University
{
    private:
        char name[51];
        Student students[2000];
        Lecturer lecturers[2000];
        int lastIndexOfStudents;
        int lastIndexOfLecturers;
    
    public:
        void add_lecturer(Lecturer);
        void add_student(Student);  
        void remove_lecturer(char* name);
        void remove_student(char* name);
        void print();
        void send_mail_to_all(char* message);
        void send_mail_to_students(char* message);
        void send_mail_to_lecturers(char *message);
        University(): lastIndexOfLecturers(0), lastIndexOfStudents(0) {};
        University(char *name): University()
        {
            strcpy(this->name, name);
        }
};

void University::add_lecturer(Lecturer lec)
{
    lecturers[lastIndexOfLecturers++] = lec;
}

void University::add_student(Student student)
{
    students[lastIndexOfStudents++] = student;
}

void University::remove_lecturer(char* name)
{
    int index = -1;
    for(int i = 0; i < lastIndexOfLecturers; i++)
    {
        if(strcmp(lecturers[i].getName(), name) == 0)
        {
            index = i;
            break;
        }
    }
    if(index != -1)
    {
        std::swap(lecturers[index], lecturers[lastIndexOfLecturers - 1]);
        lastIndexOfLecturers--;
    }
}

void University::print()
{
    std::cout << "University " << std::endl
              << "Name: "<< name << std::endl
              << "Lecturers: " << std::endl;
    for(int i = 0; i < lastIndexOfLecturers; i++)
    {
        lecturers[i].print();
    }
    std::cout << "Students: " << std::endl;
    for(int i = 0; i < lastIndexOfStudents; i++)
    {
        students[i].print();
    }
}

void University::send_mail_to_lecturers(char* message)
{
    for(int i = 0; i < lastIndexOfLecturers; i++)
    {
        lecturers[i].send_mail(message);
    }
}
void University::send_mail_to_students(char* message)
{
    for(int i = 0; i < lastIndexOfStudents; i++)
    {
        students[i].send_mail(message);
    }
}

void University::send_mail_to_all(char* message)
{
    send_mail_to_lecturers(message);
    send_mail_to_students(message);
}


int main()
{
    Person person("Ivan", 20, "ivan@abv.bg");
    /*person.send_mail("Mara ivaneeee!");
    person.view_inbox();*/

    Student pesho("Pesho", 20, "pesho@abv.bg", "0MI0800052");
   /*pesho.print();
    pesho.send_mail("Peshouuu");
    pesho.view_inbox();*/

    Lecturer marti("Martin", 22, "martinmarinov150402@gmail.com", "KI");
    /*marti.print();
    marti.send_mail("Asdd");
    marti.view_inbox();*/

    University uni("Sofia University");
    uni.add_student(pesho);
    uni.add_lecturer(marti);
    uni.print();
    uni.send_mail_to_all("To all");
    uni.send_mail_to_lecturers("To teachers");
    uni.send_mail_to_students("To students");
    std::cout << "Pesho inbox: " << std::endl;
    pesho.view_inbox();
    std::cout << "Marti inbox: " << std::endl;
    marti.view_inbox();


}