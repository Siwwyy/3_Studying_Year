#include "calculator.h"
#include "ui_calculator.h"


double calc_value = 0.0;
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calc_value));
    QPushButton * numButtons[10]{};

    for(size_t i = 0; i < 10; ++i)
    {
        QString button_name = "Button" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(button_name);
        connect(numButtons[i], SIGNAL(released()),this, SLOT(NumPressed()));
    }


    // Connect signals and slots for math buttons
    connect(ui->Adding, SIGNAL(released()), this, SLOT(MathButtonPressed()));;
    connect(ui->Subtraction, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Multiplication, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Division, SIGNAL(released()), this, SLOT(MathButtonPressed()));

    // Connect equals button
    connect(ui->Equals, SIGNAL(released()), this, SLOT(EqualButtonPressed()));

    // Connect change sign
    connect(ui->ChangeSign, SIGNAL(released()), this, SLOT(ChangeNumberSign()));

}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::NumPressed()
{
    QPushButton *button = (QPushButton*)sender();
    QString butVal = button->text();
    QString displayVal = ui->Display->text();
    if((displayVal.toDouble()) == 0 || (displayVal.toDouble()) == 0.0)
    {
        ui->Display->setText(butVal);
    }
    else
    {
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        ui->Display->setText(QString::number(dblNewVal, 'g',16));
    }
}

void Calculator::MathButtonPressed()
{
    // Cancel out previous math button clicks
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;

    // Store current value in Display
    QString displayVal = ui->Display->text();
    calc_value = displayVal.toDouble();

    // Sender returns a pointer to the button pressed
    QPushButton *button = (QPushButton *)sender();

    // Get math symbol on the button
    QString butVal = button->text();

    if(QString::compare(butVal, "/", Qt::CaseInsensitive) == 0)
    {
        divTrigger = true;
    }
    else if(QString::compare(butVal, "*", Qt::CaseInsensitive) == 0)
    {
        multTrigger = true;
    }
    else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0)
    {
        addTrigger = true;
    }
    else
    {
        subTrigger = true;
    }

    // Clear display
    ui->Display->setText("");
}

void Calculator::EqualButtonPressed()
{
    // Holds new calculation
    double solution = 0.0;

    // Get value in display
    QString displayVal = ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();

    // Make sure a math button was pressed
    if(addTrigger || subTrigger || multTrigger || divTrigger )
    {
        if(addTrigger)
        {
            solution = calc_value + dblDisplayVal;
        }
        else if(subTrigger)
        {
            solution = calc_value - dblDisplayVal;
        }
        else if(multTrigger)
        {
            solution = calc_value * dblDisplayVal;
        }
        else
        {
            solution = calc_value / dblDisplayVal;
        }
    }

    // Put solution in display
    ui->Display->setText(QString::number(solution));
}

void Calculator::ChangeNumberSign()
{
    // Get the value in the display
   QString displayVal = ui->Display->text();

   // Regular expression checks if it is a number
   // plus sign
   QRegExp reg("[-+]?[0-9.]*");

   // If it is a number change the sign
   if(reg.exactMatch(displayVal))
   {
       double dblDisplayVal = displayVal.toDouble();
       double dblDisplayValSign = -1 * dblDisplayVal;

       // Put solution in display
       ui->Display->setText(QString::number(dblDisplayValSign));
   }
}

