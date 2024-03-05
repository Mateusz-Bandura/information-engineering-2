#include <iostream>
#include <vector>
#include <algorithm>

bool ispositive(int grade)
{
    return grade == 2;
}

class Student{

private:

    std::string name;
    std::string surname;
    std::string album_number;
    std::vector<int> grades;

public:

    void set_name(std::string name_){
        name = name_;
    }

    void set_surname(std::string surname_){
        surname = surname_;
    }

    bool set_album_number(std::string album_number_){
        if(album_number_.length() >= 5 && album_number_.length() <= 6){
            album_number =  album_number_;
            return true;
        }
        return false;
    }

    void summary(){
        std::cout<< "Name: " << name << std::endl;
        std::cout<< "Surname: " << surname << std::endl;
        std::cout<< "Album number: " << album_number << std::endl;
        std::cout<< "Grades: ";
        for(auto it : grades){
            std::cout << it << " ";
        }
    }

    bool add_grade(int grade){
        if(grade >= 2 && grade <= 5){
            grades.emplace_back(grade);
            return true;
        }
        return false;
    }

    float meangrade(){
        float m_grade;

        for(auto it : grades){
            m_grade += static_cast<float>(it);
        }

        return m_grade/static_cast<float>(grades.size());
    }

    bool ifpassed()
    {
        return std::count_if(grades.begin(), grades.end(), ispositive) <= 1;
    }

};


class Complex{

private:

    float real;
    float imaginary;

public:

    Complex(float real_, float imaginary_){
        real = real_;
        imaginary = imaginary_;
    }

    Complex(float real_){
        real = real_;
        imaginary = 0;
    }

    Complex(){
        real = 0;
        imaginary = 0;
    }

    void set_real(float real_){
        real = real_;
    }

    void set_imaginary(float imaginary_){
        imaginary = imaginary_;
    }

    float get_real(){
        return real;
    }

    float get_imaginary(){
        return imaginary;
    }

    void print(){
        if(real != 0 && imaginary != 0){
            if(imaginary > 0){
                std::cout<<real<<"+"<<imaginary<<"i";
            }
            else{
                std::cout<<real<<imaginary<<"i";
            }
        }
        else if(real == 0 && imaginary != 0){
            std::cout<<imaginary<<"i";
        }
        else if(real != 0 && imaginary == 0){
            std::cout<<real;
        }
        else{
            std::cout<<0;
        }
    }

    Complex add(const Complex& other){
            return Complex(real + other.real, imaginary + other.imaginary);
        }

    Complex add(double real_val){
            return Complex(real + real_val, imaginary);
        }
};

int main()
{

    Student student;

    student.set_name("Jan");
    student.set_surname("Nowak");
    student.set_album_number("213555");
    student.add_grade(5);
    student.add_grade(3);
    student.add_grade(1);
    student.add_grade(4);

    std::cout<<student.meangrade()<<std::endl;
    std::cout<<student.ifpassed()<<std::endl;

    student.summary();

    std::cout<<std::endl<<std::endl;

    Complex d(0, 6);
    Complex e(2);
    Complex f;

    Complex a(1.0, -2.0);
    Complex b(3.14);

    b.set_imaginary(-5);

    Complex c = a.add(b);

    a.print();
    std::cout<<std::endl;
    b.print();
    std::cout<<std::endl;
    c.print();
    std::cout<<std::endl;
    d.print();
    std::cout<<std::endl;
    e.print();
    std::cout<<std::endl;
    f.print();
    std::cout<<std::endl;

    return 0;
}
