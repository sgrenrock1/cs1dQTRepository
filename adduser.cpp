#include "adduser.h"
#include "ui_adduser.h"
#include "account.h"
#include "ui_account.h"
#include "mainwindow.h"
#include "adminmain.h"
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include <QFileInfo>

addUser::addUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addUser)
{
    ui->setupUi(this);
}

addUser::~addUser()
{
    delete ui;
}

void addUser::add()
{

}

void addUser::checkUsernameAvailability(){
    QMessageBox messageBox;
    bool available = true;
    unsigned int i = 0;

    while(available && i < accounts.size()){
        if(accounts[i].userName == info.userName){
            available = false;
        }
        i++;
    }

    if(!available){
        messageBox.setText("Username already taken. Please enter a new username.");
        messageBox.setFixedSize(500, 200);
        messageBox.exec();
    }
    else if(info.userName.length() > 16 || info.userName.length() < 4){
        messageBox.setText("Invalid username length - must be between 4 and 16 characters.");
        messageBox.setFixedSize(500, 200);
        messageBox.exec();
    }
    else if(info.password.length() > 20 || info.password.length() < 6){
        messageBox.setText("Invalid password length - must be between 6 and 20 characters.");
        messageBox.setFixedSize(500, 200);
        messageBox.exec();
    }
    else if(info.name.length() > 50){
        messageBox.setText("Name too long - must be 50 characters or shorter.");
        messageBox.setFixedSize(500, 200);
        messageBox.exec();
    }
    else{
        messageBox.setText("Account Added!");
        messageBox.setFixedSize(500, 200);
        messageBox.exec();
        addAccount();
        this->close();
    }
}

void addUser::addAccount(){
    accounts.push_back(info);
    printToFile();
}

void addUser::on_submit_clicked(){

    ReadFile();
    info.name = ui->RegisterFullNameBox->text();
    info.userName = ui->RegisterUsernameBox->text();
    info.password = ui->RegisterPasswordBox->text();
    if(ui->checkBox->isChecked())
    {
        info.adminStatus = "yes";
    }
    else
    {
        info.adminStatus = "no";
    }
    info.space = "\n";
    checkUsernameAvailability();
}

void addUser::ReadFile()
{
    QTextStream stream(stdin);
    QFileInfo info;


    QString user;
    QString pw;
    QString n;
    QString as;
    QString sp;
    QString filePath;

    // **** STEVEN ****
   // QFile file("C:\\Users\\Steve\\Documents\\GitHub\\cs1dQTRepository\\LoginInfo.txt");

    // **** DORI ****
       QFile file("C:\\Users\\Dori\\Desktop\\CS1DClassProject\\cs1dQTRepository\\LoginInfo.txt");

    //QFile file("//Users//austinrosario//Desktop//QT workspace//cs1dQTRepository//LoginInfo.txt");

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);

    in.setCodec("UTF-8");

    while(!in.atEnd())
    {
        AccountInfo nextAccount;
        //totalAccounts++;

        user = in.readLine();
        pw = in.readLine();
        n = in.readLine();
        as = in.readLine();
        sp = in.readLine();

        nextAccount.userName = user;
        nextAccount.password = pw;
        nextAccount.name = n;
        nextAccount.adminStatus = as;
        nextAccount.space = sp;

        accounts.push_back(nextAccount);
    }
}

void addUser::printToFile(){

    // **** AUSTIN ****
    //QFile file("//Users//austinrosario//Desktop//QT workspace//cs1dQTRepository//LoginInfo.txt");

    // **** DORI ****
    remove("C:\\Users\\Dori\\Desktop\\CS1DClassProject\\cs1dQTRepository\\LoginInfo.txt");
    QFile file("C:\\Users\\Dori\\Desktop\\CS1DClassProject\\cs1dQTRepository\\LoginInfo.txt");

    // **** STEVE ****
    //remove("C:\\Users\\Steve\\Documents\\GitHub\\cs1dQTRepository\\LoginInfo.txt");
    //QFile file("C:\\Users\\Steve\\Documents\\GitHub\\cs1dQTRepository\\LoginInfo.txt");

    file.open(QIODevice::WriteOnly|QIODevice::Text);

    QTextStream out(&file);

    unsigned int i = 0;

    while (i < accounts.size())
    {
        out << accounts[i].userName << endl;
        out << accounts[i].password << endl;
        out << accounts[i].name << endl;
        out << accounts[i].adminStatus << endl;
        out << " " << endl;
        qDebug () << "here";
        i++;
    }

    file.close();
    qDebug() << "Output to file complete!";
}

void addUser::on_cancel_clicked(){
    this->close();
}
