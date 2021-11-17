
#ifndef INFORMATIONS_H
#define INFORMATIONS_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Informations; }
QT_END_NAMESPACE

class Informations : public QMainWindow
{
    Q_OBJECT

public:
    Informations(QWidget *parent = nullptr);
    ~Informations();

private slots:

    void on_savepat_clicked();

    void on_showpat_clicked();

    void on_shopresc_clicked();

    void on_savepresc_clicked();

    void on_Savedoctor_clicked();

    void on_saveicu_clicked();

    void on_viewcode_currentIndexChanged(int index);

    void on_dr_pres_currentIndexChanged(int index);

    void on_showdoc_clicked();


private:
    Ui::Informations *ui;
};
#endif // INFORMATIONS_H

