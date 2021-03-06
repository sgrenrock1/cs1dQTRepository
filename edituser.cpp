#include "edituser.h"
#include "ui_edituser.h"
#include "editadminstatus.h"
#include "adminmain.h"
#include "deleteuser.h"
#include <QDebug>
#include "adduser.h"

editUser::editUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editUser)
{
    ui->setupUi(this);
}

editUser::~editUser()
{
    delete ui;
}

void editUser::on_addUserButton_clicked()
{
    addUser window;
    window.setModal(true);
    window.exec();

    window.add();
}

void editUser::on_deleteUserButton_clicked()
{
    deleteUser window;

    window.setModal(true);
    window.exec();

    window.DeleteUser();

}

void editUser::on_editAdminStatusButton_clicked()
{
    editAdminStatus window;

    window.setModal(true);
    window.exec();

    window.adminStatus();

}
