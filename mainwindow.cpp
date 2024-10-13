#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMenuBar>
#include <QFileDialog>
#include <fstream>
#include <QString>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), _ui(new Ui::MainWindow) {
    _ui->setupUi(this);
    configLayout();
    connectButtons();
    configTable();
    configMenu();
    this->setFixedSize(this->width(), this->height());
}

MainWindow::~MainWindow() {
    delete _ui;
}

void MainWindow::pushInsertButtonClicked() const {
    if(_table == nullptr) {
        addLogInDebug("Параметры хт не заданы");
        return;
    }

    const auto element = readLineEdits();
    if(element == nullptr){
        addLogInDebug("Не верные параметры");
        return;
    }

    insert(*element);
    print();
}

void MainWindow::pushDeleteButtonClicked() const {
    const auto element = readLineEdits();
    if(element == nullptr){
        addLogInDebug("Не верные параметры");
        return;
    }

    if(_table->remove(*element))
        addLogInDebug("Успешное удаление");
    else
        addLogInDebug("Поставка не удалена");
    print();
}

void MainWindow::pushFindButtonClicked() const {
    const auto element = readLineEdits();
    if(element == nullptr){
        addLogInDebug("Не верные параметры");
        return;
    }

    if(const auto cntSteps = _table->find(*element); cntSteps != -1)
        addLogInDebug("Поставка найдена. Кол-во шагов: " + QString::number(cntSteps));
    else
        addLogInDebug("Поставка не найдена");
}

void MainWindow::pushInputButtonClicked() const {
    const auto path = QFileDialog::getOpenFileName().toStdString();
    if(path == "")
        return;

    ifstream file(path);
    if(file.is_open()) {
        string buf;
        while(getline(file,buf)) {
            if (!buf.empty() && buf.back() == '\r') {
                buf.pop_back();  // Убираем \r в конце строки
            }
            QRegularExpression regex(R"(^(\d{4} \d{6}) ([A-Z][a-z]+ [A-Z][a-z]+ [A-Z][a-z]+) ([A-Z]\d{3}[A-Z]{2}) (\d{2}\.\d{2}\.\d{4})$)");
            QRegularExpressionMatch match = regex.match(QString::fromStdString(buf));
            if (match.hasMatch()) {
                QString passport = match.captured(1);
                QString fio = match.captured(2);
                QString number = match.captured(3);
                string strDate = match.captured(4).toStdString();
                Element el;
                QStringList list = fio.split(' ');
                QString symbols = QString("") + number[0] + number[4] + number[5];
                QString num = QString("") + number[1] + number[2] + number[3];
                el.setPassport(Passport(passport.mid(0,4).toShort(), passport.mid(5).toInt()));
                el.setFIO(FIO(list.at(0), list.at(1), list.at(2)));
                el.setStateNumber(StateNumber(symbols, num.toUInt()));
                el.setDate(Date(strDate));
                if(el.getDate().correctDate()) {
                    if(_table->insert(el))
                        addLogInDebug("Запись добавлена");
                    else
                        addLogInDebug("Ошибка добавления");
                }
                else
                    addLogInDebug("Ошибка добавления");
            }
            else {
                addLogInDebug("Ошибка добавления");
            }
        }
        file.close();
        print();
    }
    else
        addLogInDebug("Не удалось открыть файл");
}

void MainWindow::pushOutputButtonClicked() const {
    const auto path = QFileDialog::getSaveFileName();
    ofstream file(path.toStdString());
    if(file.is_open()) {
        _table->outputFile(file);
        file.close();
        addLogInDebug("Информация о поставках выведена в файл");
    }
    else
        addLogInDebug("Невозоможно открыть файл");
}

void MainWindow::pushSizeHashTableButtonClicked() {
    const auto size = _ui->spinBoxSize->value();
    if(size != 0) {
        _table = new HashTable(size);
        _ui->spinBoxSize->setVisible(false);
        _ui->pushSizeHashTableButton->setVisible(false);
    }
    else {
        addLogInDebug("Размер хт или коэффециент заданы некорректно");
    }
}

void MainWindow::showMainWindow() const {
    _layout->setCurrentIndex(0);
}

void MainWindow::showDebugWindow() const {
    _layout->setCurrentIndex(1);
}

void MainWindow::showAlterView() const {
    _layout->setCurrentIndex(2);
    alterPrint();
}

void MainWindow::connectButtons() {
    connect(_ui->pushInsertButton, &QPushButton::clicked,this, &MainWindow::pushInsertButtonClicked);
    connect(_ui->pushDeleteButton, &QPushButton::clicked,this, &MainWindow::pushDeleteButtonClicked);
    connect(_ui->pushFindButton, &QPushButton::clicked,this, &MainWindow::pushFindButtonClicked);
    connect(_ui->pushInputFileButton, &QPushButton::clicked, this, &MainWindow::pushInputButtonClicked);
    connect(_ui->pushOutputFileButton, &QPushButton::clicked, this, &MainWindow::pushOutputButtonClicked);
    connect(_ui->pushSizeHashTableButton, &QPushButton::clicked, this, &MainWindow::pushSizeHashTableButtonClicked);
}

void MainWindow::configTable() const {
    _ui->tableWidget->setColumnCount(4);
    _ui->tableWidget->setHorizontalHeaderLabels({"Паспорт", "ФИО", "Гос. номер", "Дата"});
    _ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    _debugTable->setColumnCount(2);
    _debugTable->setHorizontalHeaderLabels({"№","Log"});
    _debugTable->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::configMenu() {
    const auto menu = this->menuBar();

    const auto mainWindow = new QAction("основное окно", this);
    menu->addAction(mainWindow);
    connect(mainWindow, &QAction::triggered, this, &MainWindow::showMainWindow);

    const auto debugWindow = new QAction("отладка", this);
    menu->addAction(debugWindow);
    connect(debugWindow, &QAction::triggered, this, &MainWindow::showDebugWindow);

    const auto alterViewData = new QAction("альтернативное отображение", this);
    menu->addAction(alterViewData);
    connect(alterViewData, &QAction::triggered, this, &MainWindow::showAlterView);
}

void MainWindow::configLayout() {
    _debugWidget = new QWidget();
    _debugTable = new QTableWidget();
    const auto debugLayout = new QVBoxLayout();
    debugLayout->addWidget(_debugTable);
    _debugWidget->setLayout(debugLayout);

    _alterViewWidget = new QWidget();
    _plainTextEdit = new QPlainTextEdit();
    _plainTextEdit->setReadOnly(true);
    const auto alterLayout = new QVBoxLayout();
    alterLayout->addWidget(_plainTextEdit);
    _alterViewWidget->setLayout(alterLayout);

    const auto mainWidget = new QWidget(this);
    _layout = new QStackedLayout(mainWidget);
    _layout->addWidget(_ui->centralWidget);
    _layout->addWidget(_debugWidget);
    _layout->addWidget(_alterViewWidget);
    setCentralWidget(mainWidget);
}

void MainWindow::alterPrint() const { // вывод в виде дерева на бок
    if(_table != nullptr) {
        _plainTextEdit->clear();
        _table->print(_plainTextEdit);
    }
}

void MainWindow::print() const {
    if(_table == nullptr)
        return;
    const auto elements = _table->print();
    _ui->tableWidget->setRowCount(0);
    for(const auto &i : elements) {
        const auto table = _ui->tableWidget;
        const auto row = table->rowCount();
        table->insertRow(row);
        table->setItem(row, 0, new QTableWidgetItem(i.getPassport().getString()));
        table->setItem(row, 1, new QTableWidgetItem(i.getFIO().getFIO()));
        table->setItem(row, 2, new QTableWidgetItem(i.getStateNumber().getString()));
        table->setItem(row, 3, new QTableWidgetItem(QString::number(i.getDate().getDay()) + "."
                                                    + QString::number(i.getDate().getMonth()) + "." + QString::number(i.getDate().getYear())));
    }
}

void MainWindow::insert(const Element &element) const {
    if(_table->insert(element))
        addLogInDebug("Поставка успешно добавлена");
    else
        addLogInDebug("Поставку не удалось добавить");
}

void MainWindow::addLogInDebug(const QString &log) const {
    const auto row = _debugTable->rowCount();
    _debugTable->insertRow(row);
    _debugTable->setItem(row, 0, new QTableWidgetItem(QString::number(row)));
    _debugTable->setItem(row, 1, new QTableWidgetItem(log));
}

Element* MainWindow::readLineEdits() const {
    QString buf = _ui->passportLine->text();
    if(buf.length() != 11)
        return nullptr;
    auto list = buf.split(" ");
    const auto seria = list.first().toUInt();
    const auto number = list.last().toUInt();
    const Passport passport(seria, number);
    buf = _ui->stateNumberLine->text();

    const auto symb = QString() + buf[0] + buf[4] + buf[5];
    const auto numbers = QString() + buf[1] + buf[2] + buf[3];

    const StateNumber num(symb, numbers.toUShort());

    buf = _ui->fioLine->text();
    list = buf.split(" ");
    if(list.size() != 3)
        return nullptr;

    QString lastname;
    QString firstname;
    QString patronymic;
    ushort j = 0;
    for(const auto &i : list) {
        switch (j) {
        case 0: {
            lastname = i;
            break;
        }
        case 1: {
            firstname = i;
            break;
        }
        case 2: {
            patronymic = i;
            break;
        }
        default:
            break;
        }
        j++;
    }
    const FIO fio(lastname, firstname, patronymic);
    const Date date(_ui->dateLine->text().toStdString());
    if(!date.correctDate())
        return nullptr;
    return new Element(date, fio, passport, num);
}

