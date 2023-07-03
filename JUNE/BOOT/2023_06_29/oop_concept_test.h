#ifndef _OOP_CONCEPT_TEST_H_
#define _OOP_CONCEPT_TEST_H_

#include <iostream>
#include <cstring>

#define SIZE 5


using namespace std;

class Charger 
{
public:
    float max_power_supply = 0;
    float price;
    string charger_type, wire_type[SIZE], charger_color, adaptor[SIZE];

public:
    string wire_t, adaptor_t, chg_col;
    
    void setnames(string wire_type, string adaptor, string charger_color, float price); 
    void getnames(); 
    //virtual void check_power_supply(string charger_type, string wire_type, string adaptor);
};

class WiredCharger : public Charger 
{
public:
    void check_power_supply(string charger_t, string wire_type, string adaptor);
    /*void setnames(string wire_type, string adaptor, string charger_color, float price);
    void getnames();*/
};

class WirelessCharger : public Charger 
{
public:
    void check_power_supply(string charger_t, string wire_type, string adaptor);
    /*void setnames(string wire_type, string adaptor, string charger_color, float price);
    void getnames();*/
};

#endif

