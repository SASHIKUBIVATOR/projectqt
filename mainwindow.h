#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedLayout>
#include <QTableWidget>
#include "HashTable.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void pushInsertButtonClicked() const;
    void pushDeleteButtonClicked() const;
    void pushFindButtonClicked() const;
    void pushInputButtonClicked() const;
    void pushOutputButtonClicked() const;
    void pushSizeHashTableButtonClicked();
    void showMainWindow() const;
    void showDebugWindow() const;
    void showAlterView() const;

private:
    Element* readLineEdits() const;
    void connectButtons();
    void configTable() const;
    void configMenu();
    void configLayout();
    void alterPrint() const;
    void print() const;
    void insert(const Element &element) const;
    void addLogInDebug(const QString &log) const;

    Ui::MainWindow *_ui;
    HashTable *_table{};
    QStackedLayout *_layout{};
    QWidget *_debugWidget{};
    QTableWidget *_debugTable{};
    QWidget *_alterViewWidget{};
    QPlainTextEdit *_plainTextEdit{};
};
#endif // MAINWINDOW_H
