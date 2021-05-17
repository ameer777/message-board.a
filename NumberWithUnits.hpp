#include <stdexcept>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class Units{
    double number;
    std::string unit_name;
public:
    
};

namespace ariel{
    

    static std::map<std::string, Units> m;
    static std::map<std::string, std::string> a;

    class NumberWithUnits{
        double num;
        std::string unit;   

    public:
        //Constructors
        NumberWithUnits(){
            num = 0;
            unit = "";
        }
        NumberWithUnits(double, const std::string&);
        ~NumberWithUnits() {}

        static void read_units(std::ifstream& file_name);

       
        //*
        NumberWithUnits operator*(double x);
        friend NumberWithUnits operator*(double x, const NumberWithUnits& other);

        //boolean {==, !=, <, >}
        friend bool operator==(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator!=(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator<(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator<=(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator>(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator>=(const NumberWithUnits& a, const NumberWithUnits& b);

        //input & output
        friend std::istream& operator>> (std::istream& in, NumberWithUnits& number_unit);//אופרטור קלט
        friend std::ostream& operator<< (std::ostream& out, const NumberWithUnits& number_unit);//אופרטור פלט    
    };
}

