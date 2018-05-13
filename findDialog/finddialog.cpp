#include <QtGui>
#include "finddialog.h"

FindDialog::FindDialog(QWidget *parent)
    :QDialog(parent)
{
    label = new QLabel(tr("find &what:"));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    caseCheckBox = new QCheckBox(tr("Match &case"));
    backwardCheckBox = new QCheckBox(tr("Search &backward"));

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("close"));

    connect(lineEdit, SIGNAL(textChanged(const QString &)),
            this, SLOT(enableFindButton(const QString &)));
    connect(findButton, SIGNAL(clicked()),
            this, SLOT(findClicked()));
    connect(closeButton, SIGNAL(clicked()),
            this, SLOT(close()));

    QHBoxLayout *topLeftlayout = new QHBoxLayout;
    topLeftlayout->addWidget(label);
    topLeftlayout->addWidget(lineEdit);

    QVBoxLayout *leftlayout = new QVBoxLayout;
    leftlayout->addLayout(topLeftlayout);
    leftlayout->addWidget(caseCheckBox);
    leftlayout->addWidget(backwardCheckBox);

    QVBoxLayout *rightlayout = new QVBoxLayout;
    rightlayout->addWidget(findButton);
    rightlayout->addWidget(closeButton);
    rightlayout->addStretch();

    QHBoxLayout *mainlayout = new QHBoxLayout;
    mainlayout->addLayout(leftlayout);
    mainlayout->addLayout(rightlayout);
    setLayout(mainlayout);

    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());

}

void FindDialog::findClicked()
{
    QString text = lineEdit->text();
    Qt::CaseSensitivity cs = caseCheckBox->isChecked()?Qt::CaseSensitive:Qt::CaseInsensitive;

    if (backwardCheckBox->isChecked()){
        emit findPrevious(text, cs);

    }
    else
        emit findNext(text, cs);
}

void FindDialog::enableFindButton(const QString &text)
{
    findButton->setEnabled(!text.isEmpty());
}
