#include "oop_concept_test.h"

/* Function to check the max power supply for WiredCharger*/
void WiredCharger::check_power_supply(string charger_t, string wire_type, string adaptor) 
{
    if (charger_t == "Wired") 
    {
        charger_type = "Wired";
        if ((wire_type == "Type-B") && (adaptor == "Android"))
            max_power_supply = 22.5;
        else if ((wire_type == "Type-C") && (adaptor == "Laptop"))
            max_power_supply = 60;
        else if ((wire_type == "Laptop") && (adaptor == "Laptop"))
            max_power_supply = 135;
        else
            max_power_supply = 18;
    } 
    else 
    {
        charger_type = "Wireless";
        cout << "Charger Type: " << charger_type << endl;
        max_power_supply = 10;
    }
}

/* Function to check the max power supply for WirelessCharger*/
void WirelessCharger::check_power_supply(string charger_t, string wire_type, string adaptor) 
{
    if (charger_t == "Wired") 
    {
        charger_type = "Wired";
        if ((wire_type == "Type-B") && (adaptor == "Android"))
            max_power_supply = 22.5;
        else if ((wire_type == "Type-C") && (adaptor == "Laptop"))
            max_power_supply = 60;
        else if ((wire_type == "Laptop") && (adaptor == "Laptop"))
            max_power_supply = 135;
        else
            max_power_supply = 18;
    } 
    else 
    {
        charger_type = "Wireless";
        //cout << "Charger Type: " << charger_type << endl;
        max_power_supply = 10;
    }
}

/* Function to set the names for the two Derived Classes*/
void Charger::setnames(string wire_type, string adaptor, string charger_color, float price) 
{
    wire_t = wire_type;
    adaptor_t = adaptor;
    chg_col = charger_color;
    this->price = price;
}

/* Function to get the names for the two Derived Classes*/
void Charger::getnames() 
{
    cout << "\nCharger Type: " << charger_type << "\nWire Type: " << wire_t << "\nAdaptor Type: " << adaptor_t << "\nMax Power Supply: " << max_power_supply << "\nCharger Color: " << chg_col << "\nPrice: " << price << endl;
}

/* Main Function */
int main() 
{
    float pr[SIZE] = {249.99, 599.99, 6499.99, 999.99};
    string wired = "Wired";
    string wireless = "Wireless";
    string wire_type[SIZE] = {"Type-B", "Type-C", "Laptop", "iOS"};
    string adaptor[SIZE] = {"Android", "Laptop", "Iphone"};
    string charger_color[SIZE] = {"Yellow", "Black", "White"};

    WiredCharger wc;
    WirelessCharger wlc;

    wc.setnames(wire_type[0], adaptor[0],  charger_color[0], pr[0]);
    
    wc.check_power_supply(wired,wire_type[0], adaptor[0]);
    wc.getnames();
    

    wlc.check_power_supply(wireless,wire_type[0], adaptor[0]);
    wlc.setnames( wire_type[1], adaptor[1], charger_color[2], pr[1]);
    wlc.getnames();

    return 0;
}



