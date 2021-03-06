#ifndef EDITWINERIES_H
#define EDITWINERIES_H

#include <QDialog>

namespace Ui {
class EditWineries;
}

class EditWineries : public QDialog
{
    Q_OBJECT

public:
    explicit EditWineries(QWidget *parent = 0);
    ~EditWineries();

private:
    Ui::EditWineries *ui;

private slots:
    void on_add_new_winery_clicked();
    void on_edit_winery_clicked();
    void on_close_edit_wineries_clicked();
};

#endif // EDITWINERIES_H
