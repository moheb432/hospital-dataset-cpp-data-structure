#include "informations.h"
#include "./ui_informations.h"
#include<QFile>
#include<QTextStream>
#include <QMessageBox>
#include "hospital.h"
pat pat1;
dr doc1;
ICU icu1;
//add patient done
//add doctordone
//view dr done
//add icu lsa
//show icu not completed
//add prescription done
//show presctiption done
Informations::Informations(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Informations)
{
    ui->setupUi(this);
}


void Informations::on_savepat_clicked()
{

    QString p_name= ui->patname->toPlainText();
    QString p_add= ui->patadd->toPlainText();
    QString p_num= ui->patnum->toPlainText();
    QString p_temp= ui->pattemp->toPlainText();
    QString p_birth= ui->patdate->toPlainText();
    QString p_gender= ui-> patgender->toPlainText();
    QString dr_no =ui->patdoc->toPlainText();
    QString ICU_code= ui->ICU_code->currentText();
    QString p_Pressure =ui->patsyspress->toPlainText();
    QString p_rate= ui->patrate->toPlainText();
    QString MH= ui->patnotes_2->toPlainText();

    int dr_id=dr_no.toInt();
    int ICU_COD=ICU_code.toInt();

     int x= pat1.add_p(p_name,p_temp,p_birth,p_add,p_num,p_gender,p_rate,dr_id,ICU_COD, p_Pressure, MH);


     ui->label_57->setNum(x);
     ui->patname->clear();
     ui->patadd->clear();
     ui->patnum->clear();
     ui->pattemp->clear();
     ui->patdate->clear();
     ui->patgender->clear();
     ui->patdoc->clear();
     ui->patsyspress->clear();
     ui->patrate->clear();
     ui->patnotes_2->clear();


}
void Informations::on_showpat_clicked()
{

    QString patient_id= ui->patient_view_id->toPlainText();

    int pat_ID=patient_id.toInt();
    patient *temp=pat1.pt_search_id(pat_ID);

    ui->vpname->setText(temp->p_name);
    ui->vpicu->setNum(temp->P_icu->icu_code);
    ui->vpbdate->setText(temp->p_BD);
    ui->vpgender->setText(temp->p_p_sex);
    ui->vpms->setText(temp-> p_MH);
    ui->vpdate->setText(temp->ICU_DATE);
    ui->vpadd->setText(temp->p_address);
    ui->patient_view_id->clear();
}
void Informations::on_Savedoctor_clicked()
  {
      QString Dr_name= ui->docname->toPlainText();
      QString Dr_BD= ui->docdate->toPlainText();
      QString Dr_degree= ui->docdegree->toPlainText();
      QString Dr_area= ui->docarea->toPlainText();
      int x =doc1.new_dr(Dr_name,Dr_BD,Dr_degree,Dr_area);
      ui->label_12->setNum(x);
      ui->docname->clear();
      ui->docdate->clear();
      ui->docdegree->clear();
      ui->docarea->clear();

  }

void Informations::on_saveicu_clicked()
{
    QString icu_name= ui->addicuname->toPlainText();
    QString icu_man= ui->addicuman->toPlainText();
    QString icucap= ui->addicucap->toPlainText();

    int c=icu1.new_icu(icu_name,icu_man,icucap);
    ui->icucode->setNum(c);
    ui->viewcode->addItem("c"+QString::number(c));
    ui->ICU_code->addItem(QString::number(c));
    ui->addicuname->clear();
    ui->addicuman->clear();
    ui->addicucap->clear();
}

void Informations::on_viewcode_currentIndexChanged(int index)
{
    int code=index+1;
    icu *temp=icu1.search_icu_code(code);
    ui->viewicuname->setText(temp->ICU_name);
    ui->viewicuman->setText(temp->icu_maneger);
    ui->icu_cap->setNum(temp->icu_cap);
    ui->no_of_patient->setNum(temp->icu_p_no);
}
void Informations::on_savepresc_clicked()
  {
      QString dr_id= ui->doctorid->toPlainText();
      QString p_id= ui->patidpresc->toPlainText();
      QString drug= ui->docdrug->toPlainText();
      QString dose= ui->drugdose ->toPlainText();
      QString period= ui->drugperiod->toPlainText();
      QString from= ui->drugfrom_2->toPlainText();
      QString to= ui->drugto_2->toPlainText();
      int dr_no=dr_id.toInt();
      int p_no=p_id.toInt();
      patient *temp_pat=pat1.pt_search_id(p_no);
      doctor *temp_dr=doc1.dr_search_id(dr_no);
      doc1.doctor_duty(temp_dr,temp_pat,drug,dose,from,to,period);
      ui->doctorid->clear();
      ui->patidpresc->clear();
      ui->docdrug->clear();
      ui->drugdose->clear();
      ui->drugfrom_2->clear();
      ui->drugto_2->clear();
      ui->drugperiod->clear();


  }
void Informations::on_shopresc_clicked()
{
    QString patient_id= ui->textEdit->toPlainText();
    int pat_ID=patient_id.toInt();
    patient *temp=pat1.pt_search_id(pat_ID);
    ui->dr_pres->clear();
    ui->dr_pres->addItem(" ");
   if (temp->drugs.empty())
    {
        ui->dr_name->clear();
        ui->dr_name ->setText( "no dr has written any prescribtion yet ");
    }
    else
    {
        for (std::list<patient::perscri_drugs>::iterator it = temp->drugs.begin(); it != temp->drugs.end(); ++it)
        {
            ui->dr_pres->addItem(QString::number((*it).dr_id));


        }
    }
}

void Informations::on_dr_pres_currentIndexChanged(int index)
{
    QString patient_id= ui->textEdit->toPlainText();
    int pat_ID=patient_id.toInt();
    patient *temp=pat1.pt_search_id(pat_ID);
    QString dr_id=ui->dr_pres->currentText();
    int dr_Id=dr_id.toInt();
    ui->patient_view_id->clear();
    for (std::list<patient::perscri_drugs>::iterator it = temp->drugs.begin(); it != temp->drugs.end(); ++it)
    {

        if((*it).dr_id==dr_Id)
        {

        ui->drug->setText((*it).drug);
        ui->dose->setText((*it).dose);
        ui->period->setText((*it).period_dose);
        ui->drugfrom->setText((*it).start_date);
        ui->drugto->setText((*it).end_date);
        ui->dr_name->setText((*it).dr_name);
        }
     }
}


        Informations::~Informations()
{
    delete ui;
}


void Informations::on_showdoc_clicked()
{

    QString view_dr_id= ui->vdrid->toPlainText();

    int doc_id=view_dr_id.toInt();
    doctor *temp=doc1.dr_search_id(doc_id);
    ui->vdrname->setText(temp->dr_name);
    ui->vdrBD->setText(temp->dr_birth);
    ui->vdrarea->setText(temp->dr_sci_area);
    ui->vdrdegree->setText(temp->dr_degree);
}

