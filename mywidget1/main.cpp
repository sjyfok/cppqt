#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *widget = new QWidget();
    widget->setWindowTitle(QObject::tr("我是 widget"));
    QLabel *label = new QLabel();
    label->setWindowTitle(QObject::tr("我是lable"));
    label->setText(QObject::tr("label：我是窗口"));
    label->resize(180, 20);
    QLabel *label2 = new QLabel(widget);
    label2->setText(QObject::tr("Label2:我是不是独立窗口，只是widget的子部件"));
    label2->resize(250, 20);
    label->show();
    widget->show();
    int ret = a.exec();
    delete label;
    delete widget;
    return ret;
}
