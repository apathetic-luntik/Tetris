/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *scoreLabel;
    QLabel *scoreNum;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *zanovo;
    QPushButton *start;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QTableView *tableView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(226, 392);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setMinimumSize(QSize(226, 392));
        Widget->setMaximumSize(QSize(226, 392));
        Widget->setFocusPolicy(Qt::NoFocus);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        scoreLabel = new QLabel(Widget);
        scoreLabel->setObjectName("scoreLabel");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arimo")});
        font.setPointSize(14);
        font.setBold(true);
        scoreLabel->setFont(font);

        horizontalLayout->addWidget(scoreLabel);

        scoreNum = new QLabel(Widget);
        scoreNum->setObjectName("scoreNum");
        scoreNum->setFont(font);

        horizontalLayout->addWidget(scoreNum);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        zanovo = new QPushButton(Widget);
        zanovo->setObjectName("zanovo");
        zanovo->setMinimumSize(QSize(80, 26));
        zanovo->setMaximumSize(QSize(80, 26));
        zanovo->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(zanovo);

        start = new QPushButton(Widget);
        start->setObjectName("start");
        start->setMinimumSize(QSize(80, 26));
        start->setMaximumSize(QSize(80, 26));
        start->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(start);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_2);

        tableView = new QTableView(Widget);
        tableView->setObjectName("tableView");
        tableView->setFocusPolicy(Qt::NoFocus);
        tableView->setAutoScroll(false);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->horizontalHeader()->setVisible(false);
        tableView->horizontalHeader()->setCascadingSectionResizes(false);
        tableView->horizontalHeader()->setMinimumSectionSize(20);
        tableView->horizontalHeader()->setDefaultSectionSize(20);
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setCascadingSectionResizes(false);
        tableView->verticalHeader()->setMinimumSectionSize(20);
        tableView->verticalHeader()->setDefaultSectionSize(20);
        tableView->verticalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(tableView);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 6);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\320\242\320\265\321\202\321\200\320\270\321\201", nullptr));
        scoreLabel->setText(QCoreApplication::translate("Widget", "\320\241\321\207\321\221\321\202", nullptr));
        scoreNum->setText(QCoreApplication::translate("Widget", "0", nullptr));
        zanovo->setText(QCoreApplication::translate("Widget", "\320\227\320\260\320\275\320\276\320\262\320\276", nullptr));
        start->setText(QCoreApplication::translate("Widget", "\320\241\321\202\320\260\321\200\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
