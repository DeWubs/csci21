#include "temperature.h"

// CLASS FUNCTION DEFINITIONS GO HERE
Temperature::Temperature()
{
    kelvin_ = 0;
}

Temperature::Temperature(double kelvin)
{
    kelvin_ = kelvin;
}

Temperature::Temperature(double temp, char unit)
{
    unit = toupper(unit);
    if (unit == 'C')
    {
        SetTempFromCelsius(temp);
    }
    else if(unit == 'F')
    {
        SetTempFromFahrenheit(temp);
    }
    else
        kelvin_ = temp;
}

void Temperature::SetTempFromKelvin(double kelvin)
{
    kelvin_ = kelvin;
}

void Temperature::SetTempFromCelsius(double celsius)
{
    kelvin_ =(celsius +273.15);
}

void Temperature::SetTempFromFahrenheit(double fahrenheit)
{
    kelvin_ = ((5.0* (fahrenheit - 32) / 9) + 273.15);
}

double Temperature::GetTempAsKelvin() const
{
    return kelvin_;
}

double Temperature::GetTempAsCelsius() const
{
    double cel;
    cel = (kelvin_ - 273.15);
    return cel;
}

double Temperature::GetTempAsFahrenheit() const
{
    double fah;
    fah = ((((kelvin_ - 273.15) *9) / 5) + 32);
    return fah;
}

string Temperature::ToString(char unit ) const
{
    unit = toupper(unit);
    stringstream sso;
    
    if(unit =='K')
    {
        sso << std::fixed << std::setprecision(2) << GetTempAsKelvin() << " Kelvin";
    }
    else if(unit == 'C')
    {
        sso << GetTempAsCelsius()<< " Celsius";
    }
    else if (unit == 'F')
    {
        sso << GetTempAsFahrenheit() << " Fahrenheit";
    }
    else
    {
        sso << "Invalid Unit";
    }
    return sso.str();
    
}