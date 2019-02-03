//
//Muzaffer Kadir YILMAZ  g++ -std=c++11 appointment.cpp 
//
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

#define lecturerLimitSize 100
#define studentLimitSize 100
#define appointmentLimitSize 300

using namespace std;

string ogrenci="ogrenci.txt";
string akademisyen="akademisyen.txt";
string randevu="randevu.txt";

class lecturer
{
    public:

        void setlRegistrationNumber(int lrn);
        int getlRegistrationNumber();
        void setlName(string ln);
        string getlName();
        void setlSurname(string lsn);
        string getlSurname();
        void setlMainDepartment(string lmd);
        string getlMainDepartment();
        void setlEmail(string le);
        string getlEmail();
        void setlPhoneNumber(string lpn);
        string getlPhoneNumber();
        void setlDegree(string lg);
        string getlDegree();

    protected:
        int lRegistrationNumber;
        string lName;
        string lSurname;
        string lMainDepartment;
        string lEmail;
        string lPhoneNumber;
        string lDegree;

    private:
};
void lecturer::setlRegistrationNumber(int lrn){
    lRegistrationNumber=lrn;
}
int lecturer::getlRegistrationNumber(){
    return lRegistrationNumber;
}
void lecturer::setlName(string ln){
    lName=ln;
}
string lecturer::getlName(){
    return lName;
}
void lecturer::setlSurname(string lsn){
    lSurname=lsn;
}
string lecturer::getlSurname(){
    return lSurname;
}
void lecturer::setlMainDepartment(string lmd){
    lMainDepartment=lmd;
}
string lecturer::getlMainDepartment(){
    return lMainDepartment;
}
void lecturer::setlEmail(string le){
    lEmail=le;
}
string lecturer::getlEmail(){
    return lEmail;
}
void lecturer::setlPhoneNumber(string lpn){
    lPhoneNumber=lpn;
}
string lecturer::getlPhoneNumber(){
    return lPhoneNumber;
}
void lecturer::setlDegree(string lg){
    lDegree=lg;
}
string lecturer::getlDegree(){
    return lDegree;
}

class student
{
    public:

        void setsNumber(int sn);
        int getsNumber();
        void setsName(string sn);
        string getsName();
        void setsSurname(string ssn);
        string getsSurname();
        void setsDepartment(string sd);
        string getsDepartment();
        void setsRegistrationYear(int sry);
        int getsRegistrationYear();
        void setsEmail(string se);
        string getsEmail();
        void setsPhoneNumber(string spn);
        string getsPhoneNumber();

    protected:
        int sNumber;
        string sName;
        string sSurname;
        string sDepartment;
        int sRegistrationYear;
        string sEmail;
        string sPhoneNumber;

    private:
};

void student::setsNumber(int sn){
    sNumber=sn;
}
int student::getsNumber(){
    return sNumber;
}
void student::setsName(string sn){
    sName=sn;
}
string student::getsName(){
    return sName;
}
void student::setsSurname(string ssn){
    sSurname=ssn;
}
string student::getsSurname(){
    return sSurname;
}
void student::setsDepartment(string sd){
    sDepartment=sd;
}
string student::getsDepartment(){
    return sDepartment;
}
void student::setsRegistrationYear(int sry){
    sRegistrationYear=sry;
}
int student::getsRegistrationYear(){
    return sRegistrationYear;
}
void student::setsEmail(string se){
    sEmail=se;
}
string student::getsEmail(){
    return sEmail;
}
void student::setsPhoneNumber(string spn){
    sPhoneNumber=spn;
}
string student::getsPhoneNumber(){
    return sPhoneNumber;
}

class appointment: public student, public lecturer
{
    public:
        void setAppointmentDate(string sad);
        string getAppointmentDate();
        void setStartTime(string sst);
        string getStartTime();
        void setFinishTime(string sft);
        string getFinishTime();
    protected:
        string appointmentDate;
        string startTime;
        string finishTime;
    private:
};
void appointment::setAppointmentDate(string sad)
{
    appointmentDate = sad;
}
string appointment::getAppointmentDate()
{
    return appointmentDate;
}
void appointment::setStartTime(string sst)
{
    startTime = sst;
}
string appointment::getStartTime()
{
    return startTime;
}
void appointment::setFinishTime(string sft)
{
    finishTime=sft;
}
string appointment::getFinishTime()
{
    return finishTime;
}

class aDate
{
    public:
        string getDate();
        string getStartTime();
        string getFinishTime();
        void setAppoinmentYear(int y);
        void setAppoinmentMonth(int m);
        void setAppoinmentDay(int d);
        void setAppoinmentHour(int h);
        void setAppoinmentMinute(int min);


    protected:
        string strDate;
        int year = 2019;
        int month = 1;
        int day = 1;
        int hour = 13;
        int minute = 0;
    private:
};
string aDate::getDate(){
    strDate="";
    strDate.append(to_string(day));
    strDate.append(".");
    strDate.append(to_string(month));
    strDate.append(".");
    strDate.append(to_string(year));
    
    return strDate;
}
string aDate::getStartTime()
{
    strDate="";
    strDate.append(to_string(hour));
    strDate.append(":");
    if(minute==0)
    strDate.append("00");
    else
    strDate.append(to_string(minute));
    return strDate;
}
string aDate::getFinishTime()
{    
    strDate="";
    if(minute == 30)
    {
    strDate.append(to_string(hour+1));
    strDate.append(":");
    strDate.append("00");
    }
    else{
    strDate.append(to_string(hour));
    strDate.append(":");
    strDate.append("30");
    }
    return strDate;

}
void aDate::setAppoinmentYear(int y){
    if(y<2018)
    {
        cout<<"Hata! Yıl yanlış girildi!"<<endl;
        cout<<"2019 Olarak Belirlendi."<<endl;
    }
    else {year=y;}
}
void aDate::setAppoinmentMonth(int m){
    if(m<1 || m>12)
    {
        cout<<"Hata Ay yanlış girildi!"<<endl;
        cout<<"01 Olarak Belirlendi."<<endl;
    }
    else{month=m;}
}
void aDate::setAppoinmentDay(int d){
    if((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)||(month==12))
    {
        if(d<1 || d>31){
            cout<<"Hata Gün yanlış girildi!"<<endl;
            cout<<"01 Olarak Belirlendi."<<endl;
        }
        else{day=d;}
    }
    else if ((month==4)||(month==6)||(month==9)||(month==11))
    {
        if(d<1 || d>30)
        {
            cout<<"Hata Gün yanlış girildi!"<<endl;
            cout<<"01 Olarak Belirlendi."<<endl;

        }
        else{day = d;}
    }
    else if (month==2)
    {
        if(year%4==0){
            if(d<1 || d>29)
            {
                cout<<"Hata Gün yanlış girildi!"<<endl;
                cout<<"01 Olarak Belirlendi."<<endl;

            }
            else{day = d;}
        }
        else{
            if(d<1 || d>28){
                cout<<"Hata Gün yanlış girildi!"<<endl;
                cout<<"01 Olarak Belirlendi."<<endl;

            }
            else{day = d;}
        }
    }
    else{cout<<"Hata Bilgileri Kontrol Edin!"<<endl;}
}
void aDate::setAppoinmentHour(int h){
    if(h<8 || h>17){
        cout<<"Hata Uygun Saat girilmedi! "<<endl;
        cout<<"13:00 Olarak Belirlendi."<<endl;
    }
    else if(h==12){
        cout<<"Hata Uygun Saat girilmedi! Öğlen arası!"<<endl;
        cout<<"13:00 Olarak Belirlendi."<<endl;    
    }
    else{
        hour=h;
    }
}
void aDate::setAppoinmentMinute(int min){
    minute=min;
}

class AppoinmentSystem
{   
    public:
    void menu();
    int getLecturers();
    int getStudents();
    int getAppointments();
    void addStudent(int num,string name,string sname,string dep,int year,string email,string phone);
    void addLecturer(int num,string name,string sname,string email,string phone,string degree);
    void addAppointment(int snum,int lnum, string date,string startDate,string finishDate);
    void appointmentControl();
    void studentControl();
    void lecturerControl();
    bool checkAppointments(int lnum,string date, string startDate);
    bool checkStudents(int studentNumber);
    bool checkLecturers(int lecturerNumber);
    void printStudents();
    void printLecturers();
    void printAppointments();
    void studentAppointments();
    void lecturerAppointments();
    protected:
    student students[studentLimitSize];
    lecturer lecturers[lecturerLimitSize];
    appointment appointments[appointmentLimitSize];
    int numberOfStudent;
    int numberOfLecturer;
    int numberOfAppointment;
    private:
};  

int AppoinmentSystem::getStudents()
{
    ifstream input;
    input.open(ogrenci);
    string inputString;
    int inputInt;
    numberOfStudent = 0;
    
    while(!input.eof())
    {
        input >> inputInt;
        students[numberOfStudent].setsNumber(inputInt);
        input >> inputString;
        students[numberOfStudent].setsName(inputString);
        input >> inputString;
        students[numberOfStudent].setsSurname(inputString);
        input >> inputString;
        students[numberOfStudent].setsDepartment(inputString);
        input >> inputInt;
        students[numberOfStudent].setsRegistrationYear(inputInt);
        input >> inputString;
        students[numberOfStudent].setsEmail(inputString);
        input >> inputString;
        students[numberOfStudent].setsPhoneNumber(inputString);

        numberOfStudent+=1;
    }
    numberOfStudent-=1;
    input.close();
    return numberOfStudent;
}
int AppoinmentSystem::getLecturers()
{
    ifstream input;
    input.open(akademisyen);
    string inputString;
    int inputInt;
    numberOfLecturer = 0;

    while(!input.eof())
    {
        input >> inputInt;
        lecturers[numberOfLecturer].setlRegistrationNumber(inputInt);
        input >> inputString;
        lecturers[numberOfLecturer].setlName(inputString);
        input >> inputString;
        lecturers[numberOfLecturer].setlSurname(inputString);
        input >> inputString;
        lecturers[numberOfLecturer].setlMainDepartment(inputString);
        input >> inputString;
        lecturers[numberOfLecturer].setlEmail(inputString);
        input >> inputString;
        lecturers[numberOfLecturer].setlPhoneNumber(inputString);
        input >> inputString;
        lecturers[numberOfLecturer].setlDegree(inputString);
        
        numberOfLecturer+=1;
    }
    numberOfLecturer-=1;
    input.close();
    return numberOfLecturer;
}
int AppoinmentSystem::getAppointments()
{
    ifstream input;
    input.open(randevu);
    string inputString;
    int inputInt;
    numberOfAppointment=0;
    
    while(!input.eof())
    {
        input >> inputInt;
        appointments[numberOfAppointment].setsNumber(inputInt);
        input >> inputInt;
        appointments[numberOfAppointment].setlRegistrationNumber(inputInt);
        input >> inputString;
        appointments[numberOfAppointment].setAppointmentDate(inputString);
        input >> inputString;
        appointments[numberOfAppointment].setStartTime(inputString);
        input >> inputString;
        appointments[numberOfAppointment].setFinishTime(inputString);
        numberOfAppointment+=1;
    }
    numberOfAppointment-=1;
    input.close();
    return numberOfAppointment;
}

void AppoinmentSystem::addStudent(int num,string name,string sname,string dep,int year,string email,string phone)
{
    ofstream input;
    input.open(ogrenci,ios::app);
    input <<num<<" "<<name<<" "<<sname<<" "<<dep<<" "<<year<<" "<<email<<" "<<phone<<endl;
    input.close();
}
void AppoinmentSystem::addLecturer(int num,string name,string sname,string email,string phone,string degree)
{
    ofstream input;
    input.open(akademisyen, ios::app);
    input<<num<<" "<<name<<" "<<sname<<" "<<email<<" "<<phone<<" "<<degree<<endl;
    input.close();
}
void AppoinmentSystem::addAppointment(int snum,int lnum, string date,string startDate,string finishDate)
{
    ofstream input;
    input.open(randevu, ios::app);
    input<<snum<<" "<<lnum<<" "<<date<<" "<<startDate<<" "<<finishDate<<endl;
    input.close();
}
bool AppoinmentSystem::checkAppointments(int lnum, string date, string startDate)
{
    for(int i=0;i<numberOfAppointment ;i++)
    {
        if(appointments[i].getlRegistrationNumber()==lnum)
        {
            if(appointments[i].getAppointmentDate()==date)
            {
                if(appointments[i].getStartTime()==startDate)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
bool AppoinmentSystem::checkStudents(int studentNumber)
{
    getStudents();
    for(int i =0; i<numberOfStudent; i++)
    {
        if(students[i].getsNumber()==studentNumber)
        return true;
    }
    return false;
}
bool AppoinmentSystem::checkLecturers(int lecturerNumber)
{
    getLecturers();
    for(int i = 0; i<numberOfLecturer;i++)
    {
        if(lecturers[i].getlRegistrationNumber()==lecturerNumber)
        return true;
    }
    return false;
}
void AppoinmentSystem::printStudents()
{ 
    for(int i=0;i<numberOfStudent;i++)
    {
        cout<<students[i].getsNumber()<<endl;
    }
}
void AppoinmentSystem::printLecturers()
{
    for(int i=0; i<numberOfLecturer;i++)
    {
        cout<<lecturers[i].getlRegistrationNumber()<<endl;
    }
}
void AppoinmentSystem::printAppointments()
{
    system("clear");
    cout<<"RANDEVU LİSTESİ"<<endl;

    for(int i=0; i<numberOfAppointment; i++)
    {
        cout<< "["<<i+1<<"]" <<"  " <<appointments[i].getsNumber()<<" - "<<appointments[i].getlRegistrationNumber()
        <<" - "<<appointments[i].getAppointmentDate()<<" - "<< appointments[i].getStartTime()<<" - "<<
        appointments[i].getFinishTime()<<endl;
    }
    cout<<"GERİ DÖN[Y]"<<endl;

    string end;
    while(true){
        cin>>end;
        if((end=="y") || (end=="Y"))
                return menu();
    }
}
void AppoinmentSystem::appointmentControl()
{
    system("clear");
    aDate date;
    int inputSNumber;
    int inputLNumber;
    int d,m,y,h,min;

    cout<<"RANDEVU EKLE \n"<<endl;
    cout<<"ÖĞRENCİ NUMARASI:"<<endl;
    cin>>inputSNumber;
    cout<<"AKADEMİSYEN NUMARASI:"<<endl;
    cin>>inputLNumber;
    if(checkLecturers(inputLNumber) && checkStudents(inputSNumber))
    {
        cout<<"YIL:";
        cin>>y;
        cout<<"AY:";
        cin>>m;
        cout<<"GÜN:";
        cin>>d;
        cout<<"SAAT:";
        cin>>h;
        cout<<"RANDEVU ZAMANINI BELİRLEYİNİZ"<<endl;
        cout<<"[1]"<<h<<":00  "<< endl;
        cout<<"[2]"<<h<<":30" << endl;
        cin>>min;
        if(min==1)
        min=0;
        else if(min==2)
        min=30;
        else
        {
        cout<<"HATALI TUŞ! "<<h<<":00 OLARAK BELİRLENDİ." <<endl;
        min=0;
        }
        date.setAppoinmentYear(y);
        date.setAppoinmentMonth(m);
        date.setAppoinmentDay(d);
        date.setAppoinmentHour(h);
        date.setAppoinmentMinute(min);


        if(checkAppointments(inputLNumber,date.getDate(),date.getStartTime()))
        {
            cout<<"TARİH DOLU, RANDEVU ALINAMADI!"<<endl;
            
        }
        else
        {
            addAppointment(inputSNumber,inputLNumber,date.getDate(),date.getStartTime(),date.getFinishTime());
            cout<<"RANDEVU BAŞARI İLE ALINDI!"<<endl;
            cout<<inputSNumber<<" - "<<inputLNumber<<" - "<<date.getDate()<<" - "
            <<date.getStartTime()<<" - "<<date.getFinishTime()<<endl;
        }


    }
    else
    cout<<"HATALI KİŞİ BİLGİSİ GİRİLDİ! KİŞİ[LER] BULUNAMADI!"<<endl;
    
    cout<<"GERİ DÖN[Y]"<<endl;
    string end;
    while(true){
        cin>>end;
        if((end=="y") || (end=="Y"))
                return menu();
    }

}
void AppoinmentSystem::studentAppointments()
{
    system("clear");
    int number;
    int listNumber=1;
    cout<<"ÖĞRENCİ NUMARASI GİRİN:"<<endl;
    cin>>number;
    if(checkStudents(number))
    {
        for(int i=0; i<numberOfAppointment;i++)
        {
            if(appointments[i].getsNumber()==number)
            {
                
                cout<<"["<< listNumber<<"] "<<appointments[i].getsNumber()<<" - "
                <<appointments[i].getlRegistrationNumber()<<" - "<<appointments[i].getAppointmentDate()
                <<" - "<< appointments[i].getStartTime()<<" - "<<appointments[i].getFinishTime()<<endl;
                listNumber+=1;
            }
        }
    }
    else
    cout<<"ÖĞRENCİ BULUNAMADI!"<<endl;
    
    cout<<"GERİ DÖN[Y]"<<endl;
    string end;
    while(true){
        cin>>end;
        if((end=="y") || (end=="Y"))
                return menu();
    }
}
void AppoinmentSystem::lecturerAppointments()
{
    system("clear");
    int number;
    int listNumber=1;
    cout<<"AKADEMİSYEN NUMARASI GİRİN:"<<endl;
    cin>>number;
    if(checkLecturers(number))
    {
        for(int i=0;i<numberOfLecturer;i++)
        {
            if(appointments[i].getlRegistrationNumber()==number)
            {
                cout<<"["<< listNumber<<"] "<<appointments[i].getlRegistrationNumber()<<" - "
                <<appointments[i].getsNumber()<<" - "<<appointments[i].getAppointmentDate()
                <<" - "<< appointments[i].getStartTime()<<" - "<<appointments[i].getFinishTime()<<endl;
                listNumber+=1;
            }

        }
    }
    else
    cout<<"AKADEMİSYEN BULUNAMADI!"<<endl;

    cout<<"GERİ DÖN[Y]"<<endl;
    string end;
    while(true){
        cin>>end;
        if((end=="y") || (end=="Y"))
                return menu();
    }

}
void AppoinmentSystem::studentControl()
{
    system("clear");
    int num,year;
    string name,sname,dep,email,phone;
    cout<<"ÖĞRENCİ EKLE \n"<<endl;

    cout<<"ÖĞRENCİ NUMARASI:"<<endl;
    cin>>num;
    if(!checkStudents(num))
    {
        cout<<"ÖGRENCİ ADI:"<<endl;
        cin>>name;
        cout<<"ÖGRENCİ SOYADI:"<<endl;
        cin>>sname;
        cout<<"ÖGRENCİ BÖLÜMÜ:"<<endl;
        cin>>dep;
        cout<<"ÖGRENCİ EMAIL:(*****@***.**)"<<endl;
        cin>>email;
        cout<<"ÖGRENCİ TELEFON NUMARASI(+905*********):"<<endl;
        cin>>phone;
        cout<<"ÖGRENCİ GİRİŞ YILI(****):"<<endl;
        cin>>year;
        addStudent(num,name,sname,dep,year,email,phone);
        cout<<"BAŞARIYLA KAYDEDİLDİ!"<<endl;
    }
    else
    cout<<"HATA! KAYITLI ÖĞRENCİ!"<<endl;
    
    cout<<"GERİ DÖN[Y]"<<endl;
    string end;
    while(true){
        cin>>end;
        if((end=="y") || (end=="Y"))
                return menu();
    }

}
void AppoinmentSystem::lecturerControl()
{
    system("clear");
    int num;
    string name,sname,email,phone,degree;
    cout<<"AKADEMİSYEN EKLE \n"<<endl;

    cout<<"AKADEMİSYEN NUMARASI:"<<endl;
    cin>>num;
    if(!checkLecturers(num))
    {
        cout<<"AKADEMİSYEN ADI:"<<endl;
        cin>>name;
        cout<<"AKADEMİSYEN SOYADI:"<<endl;
        cin>>sname;
        cout<<"AKADEMİSYEN EMAIL:(*****@***.**)"<<endl;
        cin>>email;
        cout<<"AKADEMİSYEN TELEFON NUMARASI(+905*********):"<<endl;
        cin>>phone;
        cout<<"AKADEMİSYEN GİRİŞ YILI(****):"<<endl;
        cin>>degree;
        addLecturer(num,name,sname,email,phone,degree);
        cout<<"BAŞARIYLA KAYDEDİLDİ!"<<endl;
        
    }
    else
    cout<<"HATA! KAYITLI AKADEMİSYEN!"<<endl;
    

    cout<<"GERİ DÖN[Y]"<<endl;
    string end;
    while(true){
        cin>>end;
        if((end=="y") || (end=="Y"))
                return menu();
    }

}
void AppoinmentSystem::menu()
{
    system("clear");
    int input;
    cout<<"-------------------RANDEVU SİSTEMİ-------------------"<<endl;
    cout<<"\n"<<endl;
    cout<<"[1] RANDEVU LİSTELE "<<endl;
    cout<<"[2] RANDEVU EKLE"<<endl;
    cout<<"[3] ÖĞRENCİ RANDEVU LİSTELE"<<endl;
    cout<<"[4] ÖĞRENCİ EKLE"<<endl;
    cout<<"[5] AKADEMİSYEN RANDEVU LİSTELE "<<endl;
    cout<<"[6] AKADEMİSYEN EKLE"<<endl;
    cin>>input;
    getAppointments();
    switch(input)
    {
        case 1:
        printAppointments();
        break;
        case 2:
        appointmentControl();
        break;
        case 3:
        studentAppointments();
        break;
        case 4:
        studentControl();
        break;
        case 5:
        lecturerAppointments();
        break;
        case 6:
        lecturerControl();
        break;

        

    }
}

int main()
{
    AppoinmentSystem mky;
    mky.menu();

    return 0;
}
