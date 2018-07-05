#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H
#include "inputdialog.h"
#include <QDialog>
//to create a dialog box ... but not used ...
namespace Ui {
class inputDialog;
}

class inputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit inputDialog(QWidget *parent = 0);
    ~inputDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::inputDialog *ui;
};

#endif // INPUTDIALOG_H
