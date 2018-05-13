#include <QApplication>
#include <QDialog>
#include "ui_gotocelldialog.h"
#include "gotocelldialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

  //  Ui::GoToCellDialog ui;
    QDialog *dialog = new GoToCellDialog;// QDialog;
   // ui.setupUi(dialog);
    dialog->show();

    return app.exec();
}
