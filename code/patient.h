#include <algorithm>
#include <ctime> //used to get stream size
#include <iostream>
#include <iterator>
#include <list>
double n = 0;
int code = 0;
int d = 0;
// the next three struct is the  data of each stuff in the hospital****************************************************************************************
struct icu

{

    int icu_code;
    int icu_cap;  //no. of beds in icu (capacity)
    int icu_p_no; //no. of patients already in the icu

    std::QString ICU_name;
    std::QString icu_maneger;

    icu *back;
    icu *next;
};
icu *icu_front = new icu;

struct patient
{
    int p_id;
    std::QString p_name;
    std::QString p_address;
    std::QString p_phone;
    std::QString p_p_sex;
    std::QString p_BD; //birthday date

    std::time_t ICU_date; //intrance date and time
    struct tm *ti;        //function to get the excat date of new patient
    icu *P_icu;

    struct perscri_drugs
    {
        int period_dose;
        std::QString drug;
        std::QString dose;
        std::QString start_date;
        std::QString end_date;
        std::QString dr_id;
        std::QString dr_name;
    };

    std::list<patient::perscri_drugs> drugs;
    std::QString pat_dr_name;
    int pat_dr_no;
    std::QString Medic_Hist;
    struct MS
    {
        int temp = 0;        //tempuratue
        std::QString BP = 0; //blood pressure
        int HR = 0;          // heart rate
    };
    patient *next;
    patient *back;
};

patient *front = nullptr;

struct doctor
{
    //data
    std::QString dr_name;     //name
    std::QString dr_birth;    //birthdate
    int dr_security_No;       //social_security no.
    std::QString dr_degree;   //doctor's_degree
    std::QString dr_sci_area; //doctor scientific area
    std::QString dr_p_sex;
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
{ //an object called ICU which is connected by patient by the system ********************************
    void new_icu()

    {
        if (icu_front->icu_code == 0)
        {

            icu_front = new icu;

            icu_front->next = icu_front;

            icu_front->back = icu_front;

            addicu(icu_front);
        }

        else

        {

            icu *temp = new icu;

            temp->next = icu_front;

            temp->back = icu_front->back;

            icu_front->back = temp;

            temp->back->next = temp;

            addicu(temp);

            if (icu_front->icu_code == 1)

            {

                icu_front->next = temp;
            }
        }
    }
    /* for (int i = 0; i < 1; i++)
{  if (i == 0)
            {
                icu_front = new icu;
                icu_front->next = icu_front;
                icu_front->back = icu_front;
                addicu(icu_front);
            }
            else
            {icu *temp = new icu;
                temp->next = icu_front;
                temp->back = icu_front->back;
                icu_front->back = temp;
                temp->back->next = temp;
                addicu(temp);
                if (i == 1)
                {
                   icu_front->next = temp;
                }
            }
        }*/

    // function to insert new data for each ICU in hospital
    void *addicu(icu *temp)

    {
        code++;

        temp->icu_code = code;
        std::cout << "add the capaticy\n";
        std::cin >> temp->icu_cap;

        std::cout << "\nplease enter the " << code << "  ICU's name\n";
        std::cin.ignore();
        getline(std::cin, temp->ICU_name);

        std::cout << "\nplease enter the " << code << "  ICU's maneger\n";
        std::cin.ignore();
        getline(std::cin, temp->icu_maneger);
    }
    //function for check in of the new patient

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
// object patient ***************************************************
void pat_dr(patient *temp);
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

    void *Newp(patient *temp)
    {
        // add new patient
        n++;
        temp->p_id = n;
        
        std::cout << "please enter the patient name\n";
        std::cin.ignore();
        getline(std::cin, temp->p_name);

        std::cout << "please enter the patient birthdate\n";
        std::cin.ignore();
        getline(std::cin, temp->p_BD);

        std::cout << "please enter the patient address\n";
        std::cin.ignore();
        getline(std::cin, temp->p_address);

        std::cout << "please enter the patient phone\n";
        std::cin.ignore();
        getline(std::cin, temp->p_phone);

        std::cout << "please enter the patient`s p_sex\n";
        std::cin.ignore();
        getline(std::cin, temp->p_p_sex);

        std::cout << "please give a briefnote on his medical history\n";
        std::cin.ignore();
        getline(std::cin, temp->Medic_Hist);
        std::transform(temp->p_name.begin(), temp->p_name.end(), temp->p_name.begin(), ::tolower);
        //DOCTOR OF THIS PATIENT
        pat_dr(temp);
        //THE TIME OF INTRANCE HE ICU
        time(&temp->ICU_date);
        temp->ti = localtime(&temp->ICU_date);
        // CODE FOR THE icU HE WILL ENTER
        int intrance_code = 0;
        std::cout << "there is 3 ICU here in this hospital please give the code of the icu for this patient from 1 to 3 : \n\a";
        std::cin >> intrance_code;
        ICU icu;
        temp->P_icu = icu.checkin(intrance_code);
    }
    void *add_p()
    {
        if (front == nullptr)
        {
            front = new patient;
            front->next = front;
            front->back = front;
            Newp(front);
        }
        else
        {
            patient *temp = new patient;
            temp->next = front;
            temp->back = front->back;
            front->back = temp;
            temp->back->next = temp;
            Newp(temp);
            if (temp->p_id == 1)
            {
                front->next = temp;
            }
        }
    }

    void display_id(int ID)
    {
        patient *temp = pt_search_id(ID);
        if (temp == 0)
            return;
        std::cout << "\nthe patient name :\n";
        std::cout << temp->p_name;
        std::cout << "\nthe patient adress: \n";
        std::cout << temp->p_address;
        std::cout << "\nthe patient phone :\n";
        std::cout << temp->p_phone;
        std::cout << "\nthe patient medical history :\n";
        std::cout << temp->Medic_Hist;
        std::cout << "\nthe patient dr :\n";
        std::cout << temp->pat_dr_name;
        std::cout << "\nthe patient icu code is :\n ";
        std::cout << temp->P_icu->icu_code;
        std::cout << "\nand its capacity :\n";
        std::cout << temp->P_icu->icu_cap;
        std::cout << "\nNO. of the patient in it  (_) .\n ";
        std::cout << temp->P_icu->icu_p_no;
        std::cout << "\nand it manager name for any complaint MR/ ";
        std::cout << temp->P_icu->icu_maneger;
        std::cout << "\nthe date that he intered the icu name : " << temp->P_icu->ICU_name << "and its code is : " << temp->P_icu->icu_code << " is :\n";
        std::cout << std::asctime(std::localtime(&temp->ICU_date));
        if (temp->drugs.empty())
        {
            std::cout << "no dr has write any prescribtion yet";
        }
        else
        {
            for (std::list<patient::perscri_drugs>::iterator it = temp->drugs.begin(); it != temp->drugs.end(); it++)
            {

                std::cout << "\nthe  drug that the patient  take :\n";
                std::cout << (*it).drug;
                std::cout << "\nand the dose is : \n";
                std::cout << (*it).dose;
                std::cout << "\nand the period  in hour :\n";
                std::cout << (*it).period_dose;

                std::cout << "\nand the start date  :\n";
                std::cout << (*it).start_date;

                std::cout << "\nand the end date too (-) :\n";
                std::cout << (*it).end_date;

                std::cout << "\nand the dr id that wrote this prescription (-) : ";
                std::cout << (*it).dr_name;

                std::cout << "\nand his id is  (-) :";
                std::cout << (*it).dr_id;
            }
        }
        pat_dr(temp);
    }
    void pat_medical_status()
    {
        std::cout << "\nplease, we are afraid about the patient (_) please infrom us about his medical status\n\a :";
        patient::MS m_s;

        std::cout << "\n his tempurature is : \n";
        std::cin >> m_s.temp;

        std::cout << "\nand the heart rate too  :\n";
        std::cin >> m_s.HR;

        std::cout << "\nand the blood pressure in form of (120/80) please :\n";
        //p for period
        std::cin.ignore();
        getline(std::cin, m_s.BP);
    }
}; //(-)
    //doctor object *******************************************
struct dr
{
    doctor *dr_search_id(int dr_secuirty_no) //O(n)
    {
        doctor *current = dr_front;
        while (!(current->dr_security_No == dr_secuirty_no))
        {
            current = current->next;
            if ((current->next == dr_front) && (current == dr_front))
                return 0;
        }
        return current;
    }

    void *New_dr(doctor *current)
    {
        // add new doctor
        d++;
        current->dr_security_No = d;

        std::cout << "\nplease enter the doctor name\n";
        std::cin.ignore();
        getline(std::cin, current->dr_name);

        std::cout << "\nplease enter the doctor birthdate\n";
        std::cin.ignore();
        getline(std::cin, current->dr_birth);

        std::cout << "\nplease enter the doctor scientific area\n";
        std::cin.ignore();
        getline(std::cin, current->dr_sci_area);

        std::cout << "\nplease enter the doctor degree\n";
        std::cin.ignore();
        getline(std::cin, current->dr_degree);

        std::cout << "\nthe doctor gender\n";
        std::cin.ignore();
        getline(std::cin, current->dr_p_sex);
        std::transform(current->dr_name.begin(), current->dr_name.end(), current->dr_name.begin(), ::tolower);
    }

    void *new_dr()
    {

        if (dr_front == nullptr)
        {
            dr_front = new doctor;
            dr_front->next = dr_front;
            dr_front->back = dr_front;
            New_dr(dr_front);
        }
        else
        {
            doctor *current = new doctor;
            current = dr_front->next;
            current->back = dr_front;
            dr_front->next = current->next;
            dr_front->next->back = current;
            New_dr(current);
        }
    }

    void doctor_duty() //this code can be only called by doctors
    {
        int dr_id = 0;
        int patient_id = 0;
        std::cout << "\nplease doctor give me your id to access your data :\n";
        std::cin >> dr_id;
        std::cout << "\nplease doctor give me now the patient id you want to write his prescription for of the necessary medication : \n";
        std::cin >> patient_id;
        doctor *temp = dr_search_id(dr_id);
        patient::perscri_drugs pers;
        for (std::list<doctor::dr_pat>::iterator it = temp->dr_p.begin(); it != temp->dr_p.end(); it++)
        {

            if ((*it).pat_dr->p_id == patient_id)
            {
                patient *temp1 = (*it).pat_dr;
                std::cout << "\nwhich drug does the patient  need :\n";
                std::cin.ignore();
                getline(std::cin, pers.drug);

                std::cout << "\nand the dose please    :\n";
                std::cin.ignore();
                getline(std::cin, pers.dose);

                std::cout << "\n the period  in hour please please :\n";
                std::cin.ignore();
                std::cin >> pers.period_dose;

                std::cout << "\nthe start date please :\n";
                std::cin.ignore();
                getline(std::cin, pers.start_date);

                std::cout << "\n the end date too (*-*) :\n";
                std::cin.ignore();
                getline(std::cin, pers.end_date);
                pers.dr_name = temp->dr_name;
                pers.dr_id = temp->dr_security_No;
                temp1->drugs.push_back(pers);
                return;
            }
        }
        std::cout << "the patient id" << patient_id << "is not found have another shot ";
        doctor_duty();
    }
};

void pat_dr(patient *temp)
{
    std::cout << "\nthe dr in this hospital are \n"
              << d << " doctors where they are coded in the normal counting NO. so please give me the doctor id for this patient\n";
    int s = 0;
    std::cin >> s;
    dr dr1;
    doctor *dr_temp = dr1.dr_search_id(s);

    temp->pat_dr_name = dr_temp->dr_name;
    temp->pat_dr_no = dr_temp->dr_security_No;

    doctor::dr_pat z;
    std::cout << "\nplease tell me the no of hours needed to be spent on this patient by dr" << dr_temp->dr_name << "in one week to tell him \n";
    std::cin >> z.no_of_hours_spent;
    z.pat_dr = temp;
    dr_temp->dr_p.push_front(z);
}