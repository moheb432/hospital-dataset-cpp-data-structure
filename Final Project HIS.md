

SBE201 Data structure and Algorithms

Spring 2020

Hospital Information System (HIS)

Final Assessment Project

**Hospital Information System (HIS)**

Moheb Ashraf Shaker

Moheb.yani97@eng-st.cu.edu.eg

Dalia Lotfy Abdulhay

Dalia.momen99@eng-st.cu.edu.eg

Karin Amir Erian

Karin.zaky99@eng-st.cu.edu.eg

Fatma Osama Saad

Fatma Hussein wageh

Fatma.abdelrahim99@eng-st.cu.edu.eg

Fatma.hussain99@eng-st.cu.edu.eg

\*Key words: HIS: Hospital Information System.

**1.Introduction**

Hospital Information System (HIS) is a part of health

informatics related to medical needs in hospitals. An HIS is a

system for controlling all information about healthcare of the

hospital in fast , accurate and efficient way.The beginning of

this system was in 1960s, but as the computers are

developed, this system is developed too to be more and more

effective[1]. This system incorporates all data required by

clinicians and health service users to manage health care

srevice and operations efficiently. This help to reduce errors

ad simplify the work.Our Hospital Information System in

this project provides a big and integrated source of

informaton about patients’ personal information , patients’

health history and suitable treatment (drugs) attaching with

perscription, doctors’ personal information and number of

patients treated by them and ICU’s capacities and numbers of

them. This data are programmed by a lot of data strucutures

that make it easy to insert , edit and update easily. So,

clinicians can use this history at time that is needed[2].

**3.Resources**

**We used tools and libraries in our project to help us to**

**perform the required purpose:**

• iostream : firstly; we used this library to get std

namespace for cin and cout and lists, too.

• algorithm: we used this library because we were afraid

that the hospital stuff would use a capital letters in adding

new patient or doctor so we used it to lower litter names.

**2.Motivation**

Hospital Information System (HIS) has many impacts in

developing nessecary information in hospitals. It helps to

• ctime: we used this library in the patient struct because

display a picture of growth of hospital. It can improve the we need every time we call this struct or add new patient to

control of drug usage. It can reduce transcription errors and determine the local date of the patient entrance . so, we made

repeating of information inputs that been caused by compiler automatic to add the date of patient entrance icu

handwriting. Our team are excited to learn programming of from date in the computer .

Hospital Information System (HIS) as an important field in

our department and will help us a lot later. We benefit a lot

from this project as a good chance to build whole program.

• list: we need this library as we used a list of

prescriptions for patient and list of patients for doctor.

·

iterator: It is obvious that we needed this library to

print or cout data in special place in list.

6/6/2020

1





SBE201 Data Structures and Algorithms

Hospital Information System (HIS)

**4. Challenges and problems**

**6. Block diagram of the hospital information system**

**(HIS)**

We have faced a lot of errors while coding. We try to fix

them all. We have faced problem in connecting all data

together to be avaliable everywhere in code. So we can

search in patient to reach to information about patient and

doctor responsible for this patient’s case ,too and also search

in doctor to recieve all the data about doctor and patient

treated by this doctor. In addition to connecting ICUs with

doctors and patients ,too. This was a big challenge and effort

, too. We also have some problems in dealing with GUI as it

is a first time to make codes in GUI and connecying this with

the header file of tha main code. Also there was a problem

with us to convert Qstring to integer while using GUI.

We are trying to summarize the data we used in our project

in a block diagram consisting mainly from :

Patients , doctors and ICU’s and all information that was

provided in our project as a try to make an integrated and

accurate system as possible.

**5.User manual for the system**

\1. first we made the code ask for how many ICU in

the hospital and we give them code from 0 to n of their

numbers . If there are 3 then there code is 1,2,3….

\2. second we asked for how many doctors in this

hospital and we made their ID’s as the ICU from 0 to n

of their numbers

\3. same for patient of the clerk wrote add\_p(), this

function adds patient by asking him for the personal

information and the doctor that will care for this patient.

\4. in function add\_p() there is another function is

pat\_dr(), which links between doctor and patient and

function called checkin(code of ICU) :. this function just

increases number of patients in this ICU by”1”

\5. pat\_medical\_status () :this function used to display

medical status of each patient.

\6. new\_dr :function with same role as add\_p().

\7. doctor\_duty(): this function takes two arguments

patients’ IDs and doctors too and make push forward

in a list the number of hours spend in week and the

pointer to this patient, and push forward in a list of struct

called presc\_drug(), in patient both data on this drug the

doctor will write his name and his ID, so we have a list

in each patient of struct which contain drug data and

doctor who wrote this data .

**All of this data saved in circular linked list of**

**complexity**

◦ insert add\_p : O(1).

Block diagram of the whole system

◦ search\_ID for all stuff (patient or dr) O(n):

◦ display\_id(), O(n) in only searching of which prescription

we will need.

2





SBE201 Data Structures and Algorithms

Hospital Information System (HIS)

**7.Results:**

Screen shots of running programme( with GUI ).

3





SBE201 Data Structures and Algorithms

Hospital Information System (HIS)

4





SBE201 Data Structures and Algorithms

Hospital Information System (HIS)

**8.Contributions**

We are all sharing our experience and efforts in writting

reports , codes and learning dealing with GUI and then try to

divide tasks with us:

Moheb Ashraf : patient codes

Dalia lotfy : doctor codes.

Fatma Osama : ICU codes.

Fatma hussain , Karin Amir : GUI implementation.

We all sharing tha task of the connection between GUI and

the main code.

**9.References**

[1].Quoted from [http://www.emrconsultant.com/emr-](http://www.emrconsultant.com/emr-education-%20%20center/emr-selection-and-implementation/hospital-%20%20%20information-systems-his/)

[education-](http://www.emrconsultant.com/emr-education-%20%20center/emr-selection-and-implementation/hospital-%20%20%20information-systems-his/)[ ](http://www.emrconsultant.com/emr-education-%20%20center/emr-selection-and-implementation/hospital-%20%20%20information-systems-his/)[center/emr-selection-and-](http://www.emrconsultant.com/emr-education-%20%20center/emr-selection-and-implementation/hospital-%20%20%20information-systems-his/)

[implementation/hospital-](http://www.emrconsultant.com/emr-education-%20%20center/emr-selection-and-implementation/hospital-%20%20%20information-systems-his/)[ ](http://www.emrconsultant.com/emr-education-%20%20center/emr-selection-and-implementation/hospital-%20%20%20information-systems-his/)[information-systems-his/](http://www.emrconsultant.com/emr-education-%20%20center/emr-selection-and-implementation/hospital-%20%20%20information-systems-his/)

[2] "Meaning of Patients Health History". Miller Keane.

2019-11-11. Retrieved 2019-11-11.

[3] Robert Lafore(2002) “object oriented programming

C++”Fourth Edition.

[4] johannes j.Martin, Data types and Data Structures,

prentice-Hall International Series in computer science, C.A.R

Hoare, Series Editor, prentice-Hall International =,

(UK),LTD, 1986.

**TEAM 02:**

Dalia Lotfy Abdulhay

Fatma Osama Saad

Fatma Hussein Wageh

Karin Amir Erian

Sec:1 BN:30

Sec:2 BN:2

Sec:2 BN: 3

Sec:2 BN:6

Sec:2 BN:10

Moheb Ashraf Shaker

5

