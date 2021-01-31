#include <cstdio>

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

struct College {
    char name[256];
};

void print_name(College *college_ptr) {
    printf("%s College\n", college_ptr->name);
}

int main() {
    int gettysburg{};
    int *gettysburg_address = &gettysburg;
    printf("Value at gettysburg_address: %d\n", *gettysburg_address);
    printf("Gettysburg Address: %p\n", gettysburg_address);
    *gettysburg_address = 17325;
    printf("Value at gettysburg_address: %d\n", *gettysburg_address);
    printf("Gettysburg Address: %p\n", gettysburg_address);

    ClockOfTheLongNow clock{};
    ClockOfTheLongNow *clock_ptr = &clock;
    clock_ptr->set_year(2021);
    printf("Address of clock: %p\n", clock_ptr);
    printf("Value of clock's year: %d\n", clock_ptr->get_year());

    int key_to_the_universe[]{3, 6, 9};
    int *key_ptr = key_to_the_universe;
    printf("Address of key_ptr: %p\n", key_ptr);
    printf("Value at key_ptr: %d\n", *key_ptr);

    College best_colleges[] = { "Magdalen", "Duffield", "Kellogg" };
    print_name(best_colleges);

    return 0;
}