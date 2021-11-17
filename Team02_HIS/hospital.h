#ifndef HOSPITAL_H
#define HOSPITAL_H
#include <algorithm>
#include <ctime> //used to get stream size
#include <iostream>
#include <iterator>
#include <list>
#include <QMainWindow>
double n = 0;
int code = 0;
int d = 1;

// the next three struct is the  data of each stuff in the hospital and there front pointer ******************************
struct icu
{

    int icu_code;
    int icu_cap;  //no. of beds in icu (capacity)
    int icu_p_no; //no. of patients already in the icu

    QString ICU_name;
    QString icu_maneger;

    icu *back;
    icu *next;
};

icu *icu_front = new icu;


struct patient
{

    int p_id;
    QString p_name;
    QString p_address;
    QString p_phone;
    QString p_p_sex;
    QString p_BD; //birthday date
    QString p_HR;
    QString p_pressure;
    QString p_MH;

    std::time_t ICU_date; //intrance date and time
    struct tm *ti;        //function to get the excat date of new patient
    icu *P_icu;
    QString ICU_DATE;
    struct perscri_drugs
    {
        QString period_dose;
        QString drug;
        QString dose;
        QString start_date;
        QString end_date;
        int dr_id;
        QString dr_name;
    };

    std::list<patient::perscri_drugs> drugs;
    QString pat_dr_name;
    int pat_dr_no;
    QString Medic_Hist;

        QString temp = 0;       //tempuratue
        QString BP = 0; //blood pressure
        QString HR = 0;         // heart rate
        patient *next;
        patient *back;
};

patient *front = nullptr;


struct doctor
{
    //data
    QString dr_name;     //name
    QString dr_birth;    //birthdate
    int dr_security_No;      //social_security no.
    QString dr_degree;   //doctor's_degree
    QString dr_sci_area; //doctor scientific area
    QString dr_p_sex;
    struct dr_pat
    {
        int no_of_hours_spent;
        patient *pat_dr;
    };
    std::list<dr_pat> dr_p;

    doctor *next;
    doctor *back;
};

doctor *dr_front = nullptr;




// the next three struct is the  function that enter and display the  stuffs data

struct ICU
{ //an object called ICU which is connected by patient by the system ************


    icu *search_icu_code(int code)
    {
        icu *temp = icu_front;
        while (temp->icu_code != code)
        {
            if (temp->next == icu_front)
            {
                std::cout << "not found";
                return 0;
            }
            temp = temp->next;
        }

        return temp;
    }

    void *Newicu(icu *temp, QString icu_name, QString icu_man, QString icucap)
    {
        code++;
        int c=icucap.toInt();
       temp->icu_code = code;
       temp->ICU_name= icu_name;
       temp->icu_maneger = icu_man;
       temp->icu_cap = c;
       temp->icu_p_no=0;
    }

    int new_icu(QString icu_name,QString icu_man, QString icucap)

    {

            if (code == 0)

            {

                icu_front = new icu;

                icu_front->next = icu_front;

                icu_front->back = icu_front;

                Newicu(icu_front,icu_name,icu_man, icucap);
                return icu_front->icu_code;
            }

            else

            {

                icu *temp = new icu;

                temp->next = icu_front;

                temp->back = icu_front->back;

                icu_front->back = temp;

                temp->back->next = temp;

                Newicu(temp,icu_name,icu_man,icucap);
                return temp->icu_code;

                if (code == 1)

                {

                    icu_front->next = temp;
                }
            }

    }

    icu *checkin(int p_c)

    {
        switch (p_c)
        {
        case 1:

            icu_front->icu_p_no++;
            return icu_front;

        case 2:
            icu_front->next->icu_p_no++;
            return icu_front->next;
            break;

        case 3:
            icu_front->next->next->icu_p_no++;
            return icu_front->next->next;
            break;

        defualt:
            std::cout << "\nplease insert patient again but this time insert a right icu code :\n";
        }
    }
};

struct pat
{


    patient *pt_search_id(int ID)
    {
        patient *temp = front;
        while (temp->p_id != ID)
        {
            if (temp->next == front)
            {
                std::cout << "not found";
                return 0;
            }
            temp = temp->next;
        }

        return temp;
    }

    void *Newp(patient *temp,QString name,QString tempurature,QString birth,QString add,QString pho,QString gender,QString HR, int dr_id,int ICU_code, QString BP,QString p_MH )
    {
        // add new patient
        temp->p_id = n;
        n++;

        temp->p_name=name;
        temp->p_BD=birth;
        temp->p_address=add;
        temp->p_p_sex=gender;
        temp->pat_dr_no=dr_id;
        temp->p_phone=pho;
        temp->p_HR=HR;
        temp->temp =tempurature;
        temp->p_pressure= BP;
        temp->p_MH= p_MH;


        ICU icu;
        temp->P_icu = icu.search_icu_code(ICU_code);
        temp->P_icu->icu_p_no++;
        //pat_dr(temp);
        time(&temp->ICU_date);
        temp->ti = localtime(&temp->ICU_date);
        char buffer[80];
        strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",temp->ti);
        std::string s(buffer);
        temp->ICU_DATE = QString::fromLocal8Bit(s. c_str());

       }
    int add_p(QString name,QString tempurature,QString birth,QString add,QString pho,QString gender,QString HR, int dr_id,int ICU_code, QString BP , QString p_MH)
    {
        if (front==nullptr)
        {
            front = new patient;
            front->next = front;
            front->back = front;
            Newp(front,name,tempurature,birth,add,pho,gender,HR, dr_id,ICU_code,BP, p_MH);
            return front->p_id;
        }
        else
        {
            patient *temp = new patient;
            temp->next = front;
            temp->back = front->back;
            front->back = temp;
            temp->back->next = temp;
            Newp(temp,name,tempurature,birth,add,pho,gender,HR, dr_id,ICU_code,BP, p_MH);
          /*  if (temp->p_id == 1)
            {
                front->next = temp;
            }*/
            return temp->p_id;
        }
    }

};

struct dr
{
    doctor *dr_search_id(int dr_secuirty_no) //O(n)
    {
        doctor *current = dr_front;
        while (!(current->dr_security_No == dr_secuirty_no))
        {
            current = current->next;
               if ((current->next == dr_front) &&(current ==dr_front))
                return 0;
        }
        return current;
    }

    void *New_dr(doctor *current,QString Dr_name,QString Dr_BD,QString Dr_degree, QString Dr_area)
    {
        // add new doctor

        current->dr_security_No = d;
        d++;
        current->dr_name=Dr_name;
        current->dr_birth=Dr_BD;
        current->dr_sci_area=Dr_area;
        current->dr_degree =Dr_degree;
        //current->dr_p_sex=Dr_gender;

    }

    int new_dr(QString Dr_name,QString Dr_BD,QString Dr_degree, QString Dr_area)
    {

        if (dr_front == nullptr)
        {
            dr_front = new doctor;
            dr_front->next = dr_front;
            dr_front->back = dr_front;
            New_dr(dr_front,Dr_name,Dr_BD,Dr_degree,Dr_area);
            return dr_front->dr_security_No;
        }
        else
        {
            doctor *current = new doctor;
            current->next = dr_front;
            current->back = dr_front->back;
            dr_front->back->next = current;
            dr_front->back = current;
            New_dr(current,Dr_name,Dr_BD,Dr_degree,Dr_area);
            //if(current->dr_security_No==2)
            //
            //{dr_front->next=current;}
            return current->dr_security_No;
        }
    }

    void doctor_duty(doctor *temp_dr,patient *temp_pat,QString drug,QString dose,QString start_date,QString end_date,QString period) //this code can be only called by doctors
    {
                 patient::perscri_drugs pers;
                 pers.drug=drug;
                 pers.dose=dose;
                 pers.end_date =end_date;
                 pers.start_date=start_date;
                 pers.period_dose=period;
                 pers.dr_id=temp_dr->dr_security_No;
                 pers.dr_name=temp_dr->dr_name;
                 temp_pat->drugs.push_back(pers);
                 return;

    }
};

#endif // HOSPITAL_H
