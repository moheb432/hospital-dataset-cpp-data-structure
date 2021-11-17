#include "patient.h"

int main()
{
    ICU icu1;
    dr dr1;
    pat pat1;
    std::QString choice;
    while(1){
    std::cout << "what do you want to do (new icu, new dr, add p, doctror duty ,display id)\n";
    getline(std::cin, choice);
    if (choice == "new icu")
        icu1.new_icu();
    else if (choice == "new dr")
        dr1.new_dr();
    else if (choice == "add p")
        pat1.add_p();
    else if (choice == "display id")
        pat1.display_id(0);
    else if (choice== "doctor duty")
        dr1.doctor_duty();    
    else
        std::cout << "try again";
    }
}