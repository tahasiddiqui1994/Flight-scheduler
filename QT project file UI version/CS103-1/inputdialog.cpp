#include "inputdialog.h"
#include "ui_inputdialog.h"

inputDialog::inputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputDialog)
{
    ui->setupUi(this);
}

inputDialog::~inputDialog()
{
    delete ui;
}

void inputDialog::on_buttonBox_accepted()
{

}
