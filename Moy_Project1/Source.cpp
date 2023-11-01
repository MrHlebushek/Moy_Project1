#include <iostream>
#include <cmath>
#include <iomanip>

class Array
{
public:

    typedef double
        value_type;
    typedef double*
        iterator;
    typedef const double*
        const_iterator;
    typedef double&
        reference;
    typedef const double&
        const_reference;
    typedef std::size_t
        size_type;

    Array(const size_type n);
    //Array(const Array& array);
    Array(iterator first, iterator last);

    ~Array()
    {
        delete[]Str;
    }

    //Array& operator=(const Array&);

    iterator begin() { return Str; }
    const_iterator begin() const { return Str; }
    iterator end() { return Str + Numero; }
    const_iterator end() const { return Str + Numero; }

    size_type sizer() const
    {
        return Numero;
    }

    void new_size(size_type resize);

    size_type repository() const
    {
        return memory_size;
    }

    // текущий размер массива
    bool empty() const
    {
        if (Numero == 0)
            return true;
        else
            return false;
    }

    reference operator[](size_type index);
    const_reference operator[](size_type index) const;
    reference front() { return Str[0]; }
    const_reference front() const { return Str[0]; }

    reference back()
    {
        return Str[sizer() - 1];
    }

    const_reference back() const { return Str[sizer() - 1]; }

    //void swap(Array& other);

    //void assign(const value_type& v);

    void knock_back(const value_type& v);

    void help()
    {
        Str[Numero - 1] = 0;
        Numero--;
    }

    // очистить массив
    void annihilation()
    {
        Numero = 0;
    }

    void Display()
    {
        for (int i = 0; i < Numero; i++)
        {
            std::cout.precision(3);
            std::cout << std::fixed << Str[i] << " ";
        }
        std::cout << '\n';
    }

private:
    // указатель на данные
    value_type* Str;

    // количество элементов в массиве
    size_type Numero;

    // минимальный размер массива
    static const size_type min = 10;

    // выделено элементов в памяти
    size_type memory_size;

};

double Summ(const Array& massive)
{
    double sum = 0;

    for (int i = 0; i < massive.sizer(); i++)
        sum += massive[i];

    return sum;
}

double Del(const Array& massive)
{
    double aver = Summ(massive) / massive.sizer();

    return aver;
}

void Task(Array& mass)
{
    int c;

    float g, dj, half_summa;

    for (int i = 0; i < mass.sizer(); i++)
    {
        if (mass[i] < 0)
        {
            g = mass[i];

            break;
        }
    }

    for (int i = 0; i < mass.sizer(); i++)
    {
        if (i == 5)
        {
            dj = mass[i];

            break;
        }
    }

    half_summa = (g + dj) / 2;

    for (int i = 0; i < mass.sizer(); i++)
        (mass.begin())[i] = (mass.begin())[i] / half_summa;
}

void Array::knock_back(const value_type& N)
{
    if (Numero == memory_size)
        new_size(memory_size * 2);

    Str[Numero++] = N;
}

void Array::new_size(size_type new_size)
{
    value_type* s = new value_type[new_size];

    for (size_type i = 0; i < Numero; ++i)
        s[i] = Str[i];

    delete[] Str;

    Str = s;
    memory_size = new_size;
}

Array::Array(iterator first_one, iterator last_one)
{
    if (first_one < last_one)
    {
        memory_size = (first_one - last_one);
        Str = new value_type[memory_size];

        for (int i = 0; i < memory_size; ++i)
            Str[i] = *(first_one + i);

        Numero = memory_size;
    }
}

Array::Array(const size_type n)
{
    memory_size = n;
    Str = new value_type[n];
    Numero = 0;
}

double& Array::operator[](size_type index)
{
    if (index < Numero)
        return Str[index];
}

const double& Array::operator[](size_type index) const
{
    if (index < Numero)
        return Str[index];
}

int main()
{
    double number, summa = 0, del = 0;
    int razmer, count = 1;
    
    //Ввод размерности массива

    std::cin >> razmer;

    //Объявление массива

    Array arr(razmer);

    //Заполнение массива

    for (int i = 0; i < razmer; i++)
    {
        std::cin >> number;

        arr.knock_back(number);
    }

    std::cout << arr.sizer() << '\n';

    arr.Display();

    //Расчет суммы и деления 

    summa = Summ(arr);
    del = Del(arr);

    arr.knock_back(summa);
    arr.knock_back(del);

    arr.Display();

    Task(arr);

    arr.Display();

    //Действия согласно заданию

    while (true)
    {
        std::cin >> count;

        if (count == 0)
        {
            break;
        }

        else
        {
            switch (count)
            {
            case 1:
                std::cin >> number;

                arr.knock_back(number);

                std::cout << "+:" << arr.sizer() << '\n';

                arr.Display();

                summa = Summ(arr);
                del = Del(arr);

                arr.knock_back(summa);
                arr.knock_back(del);

                arr.Display();

                Task(arr);

                arr.Display();

                break;
            case 2:
                arr.help();

                std::cout << "-:" << arr.sizer() << '\n';

                arr.Display();

                summa = Summ(arr);
                del = Del(arr);

                arr.knock_back(summa);
                arr.knock_back(del);

                arr.Display();

                Task(arr);

                arr.Display();
                break;
            }
        }
    }
    return 0;
}