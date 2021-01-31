#include <cstdio>

struct Book {
    char name[256];
    int year;
    int pages;
    bool hardcover;
};

union Variant {
    char string[10];
    int integer;
    double floating_point;
};

struct ClockOfTheLongNow {
    void add_year() {
        year++;
    }

    bool set_year(int new_year) {
        if (new_year < 2021) {
            return false;
        }

        year = new_year;

        return true;
    }

    int get_year() {
        return year;
    }

private:
    int year;
};

class ClockOfTheLongNowClass {
public:
    ClockOfTheLongNowClass() {
        year = 2020;
    }

    explicit ClockOfTheLongNowClass(int year_in) {
        year = year_in;
    }

    void add_year() {
        year++;
    }

    bool set_year(int new_year) {
        if (new_year < 2020) {
            return false;
        }

        year = new_year;

        return true;
    }

    int get_year() {
        return year;
    }

private:
    int year;
};

struct Taxonomist {
    Taxonomist() {
        printf("No argument\n");
    }

    Taxonomist(char x) {
        printf("char: %c\n", x);
    }

    Taxonomist(int x) {
        printf("int: %d\n", x);
    }

    Taxonomist(float x) {
        printf("float: %f\n", x);
    }
};

enum class Operation {
    Add,
    Substract,
    Multiply,
    Divide
};

struct Calculator {
    Calculator(Operation t_operation) {
        operation = t_operation;
    }

    int calculate(int a, int b) {
        switch (operation) {
            case Operation::Add: {
                return a + b;
            }
            case Operation::Substract: {
                return a - b;
            }
            case Operation::Multiply: {
                return a * b;
            }
            case Operation::Divide: {
                if (b == 0) {
                    printf("You can't divide by zero!\n");
                    return -1;
                }

                return a / b;
            }
            default:
                return -1;
        }
    }

private:
    Operation operation;
};

int main() {
    // PODs
    Book neuromancer;
    neuromancer.pages = 271;

    printf("Neuromance has %d pages.\n", neuromancer.pages);

    // Unions
    Variant v;
    v.integer = 42;

    printf("The ultimate answer: %d\n", v.integer);

    v.floating_point = 2.7182818284;

    printf("Euler's number e: %f\n", v.floating_point);
    printf("A dumpster fire: %d\n", v.integer);

    // Classes
    ClockOfTheLongNow clock;
    clock.set_year(2050);
    clock.add_year();
    printf("Year: %d\n", clock.get_year());
    clock.add_year();
    printf("Year: %d\n", clock.get_year());
    if (!clock.set_year(2000)) {
        printf("Setting a year 2000 failed!\n");
    }

    ClockOfTheLongNowClass other_clock{2100};
    printf("Year: %d\n", other_clock.get_year());

    Book lord_of_the_rings{};
    Book harry_potter{"Harry Potter", 1998, 123, true};

    // Fully Featured Classes
    Taxonomist t1;
    Taxonomist t2{'c'};
    Taxonomist t3{65537};
    Taxonomist t4{6.02e23f};
    Taxonomist t5{'g'};
    Taxonomist t6 = {'1'};
    Taxonomist t7{};
    Taxonomist t8();

    Calculator calc{Operation::Divide};
    calc.calculate(123, 0);
    int result = calc.calculate(100, 50);
    printf("Result of calculation: %d\n", result);

    return 0;
}
