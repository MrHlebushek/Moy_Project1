#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <sstream>

class Integral {
public:
    Integral(const std::vector<double>& Value_function, const std::vector<double>& El_arr)
        : Value_function(Value_function), El_arr(El_arr) {
        n = Value_function.size() - 1; 
        h = El_arr[n] - El_arr[0]; 
    }

    double MethodLeftRectangle() {
        double integr = 0;
        int i;
        for (i = 0; i < n; ++i) {
            integr += Value_function[i] * (El_arr[i + 1] - El_arr[i]);
        }
        return integr;
    }

    double MethodMiddleRectangle() {
        double integr = 0;
        int i;
        for (i = 0; i < n; ++i) {
            double ValueMid_function = (Value_function[i] + Value_function[i + 1]) / 2.0;
            integr += ValueMid_function * (El_arr[i + 1] - El_arr[i]);
        }
        return integr;
    }

    double MethodRightRectangle() {
        double integr = 0;
        int i;
        for (i = 0; i < n; ++i) {
            integr += Value_function[i + 1] * (El_arr[i + 1] - El_arr[i]);
        }
        return integr;
    }

    double MethodTrapezoidal() {
        double integr = 0;
        int i;
        for (i = 0; i < n; ++i) {
            integr += (Value_function[i] + Value_function[i + 1]) * (El_arr[i + 1] - El_arr[i]) / 2;
        }
        return integr;
    }

    double MethodSimpson() {
        double integr = 0;
        int i;
        for (i = 0; i < n; i += 2) {
            double h_i = El_arr[i + 2] - El_arr[i];
            integr += (Value_function[i] + 4 * Value_function[i + 1] + Value_function[i + 2]) * h_i / 6;
        }
        return integr;
    }

    double newtonCotes38Method() {
        double integr = 0;
        if (n % 3 == 0) {
            int i;
            for (i = 0; i < n; i += 3) {
                integr += (Value_function[i] + 3 * Value_function[i + 1] + 3 * Value_function[i + 2] +
                    Value_function[i + 3]) *
                    (El_arr[i + 3] - El_arr[i]) / 8;
            }
        }
        else {
            std::cerr << "The Newton-Cotes 3/8 method requires the number of subintervals to be a multiple of 3." << std::endl;
        }
        return integr;
    }

    void displayInputData() {
        std::cout << "input= argument ";
        int i;
        for (i = 0; i < El_arr.size(); ++i) {
            std::cout << El_arr[i] << " ";
        }

        std::cout << '\n';

        std::cout << "function ";
        for (i = 0; i < Value_function.size(); ++i) {
            std::cout << Value_function[i] << " ";
        }

        std::cout << '\n';
    }



private:
    std::vector<double> Value_function;
    std::vector<double> El_arr;
    int n;
    double h;

    double eval_function(double y) {
        return y * y;
    }
};

std::string formatNumber(double valuetion) {
    double savior = std::numeric_limits<double>::epsilon() * 1000.0;

    std::ostringstream oss;
    if (std::abs(valuetion - std::round(valuetion)) < savior) {
        oss << static_cast<int>(valuetion);
    }
    else {
        oss << std::fixed << std::setprecision(1) << valuetion;
    }
    return oss.str();
}

int main() {
    int Dimen_array;

    std::cin >> Dimen_array;

    std::vector<double> El_arr(Dimen_array);
    std::vector<double> Value_function(Dimen_array);

    int i;

    for (i = 0; i < Dimen_array; ++i) {
        std::cin >> El_arr[i];
    }

    for (i = 0; i < Dimen_array; ++i) {
        std::cin >> Value_function[i];
    }

    Integral Calculate_integr(Value_function, El_arr);

    Calculate_integr.displayInputData();

    double Integral_LeftRectangle = Calculate_integr.MethodLeftRectangle();

    if (Integral_LeftRectangle == static_cast<int>(Integral_LeftRectangle)) {
        std::cout << "lev priam= " << static_cast<int>(Integral_LeftRectangle) << std::endl;
    }
    else {
        std::cout << "lev priam=  " << Integral_LeftRectangle << std::endl;
    }

    double Integral_MiddleRectangle = Calculate_integr.MethodMiddleRectangle();

    std::cout << "sr priam= " << Integral_MiddleRectangle << std::endl;

    double Integral_RightRectangle = Calculate_integr.MethodRightRectangle();

    if (Integral_RightRectangle == static_cast<int>(Integral_RightRectangle)) {
        std::cout << "prav priam= " << static_cast<int>(Integral_RightRectangle) << std::endl;
    }
    else {
        std::cout << "prav priam=  " << Integral_RightRectangle << std::endl;
    }

    double Integral_Trapezoidal = Calculate_integr.MethodTrapezoidal();

    if (Integral_Trapezoidal == static_cast<int>(Integral_Trapezoidal)) {
        std::cout << "trapeciy= " << static_cast<int>(Integral_Trapezoidal) << std::endl;
    }
    else {
        std::cout << "trapeciy=  " << Integral_Trapezoidal << std::endl;
    }

    std::cout << std::fixed << std::setprecision(1);

    double Integral_Simpson = Calculate_integr.MethodSimpson();

    std::string Simpson_format = formatNumber(Integral_Simpson);
    std::cout << "Simpson= " << Simpson_format << std::endl;

    double Newton = Calculate_integr.newtonCotes38Method();

    std::string Newton_format = formatNumber(Newton);

    std::cout << "Newton " << Newton_format << std::endl;

    return 0;
}
