#include<stdio.h>

#define FILE_NAME "C:\\Users\\HR\\Desktop\\School\\C\\Test\\Test.txt"
#define MAX_LINE 30
#define PEOPLE_COUNT 5

typedef struct {
    char first_name[MAX_LINE];
    char last_name[MAX_LINE];
    int age;
} Person;

void init_people(Person* people);
void print_people(Person* people);
void to_file(Person* people);
// Write definition of this function
// Make the user to enter the new names and age
void edit_person(Person* people, int index);

int main() {
    int index;

    Person people[PEOPLE_COUNT];

    init_people(people);
    print_people(people);

    printf("Who do you wish to edit? ");
    scanf("%d", &index);

    edit_person(people, index);
    to_file(people);

    init_people(people);
    print_people(people);

    return 0;
}

void init_people(Person* people) {
    FILE* fp;
    fp = fopen(FILE_NAME, "r");

    for(int i = 0; i < PEOPLE_COUNT; ++i) {
        fscanf(fp, "%s %s %d", people->first_name, people->last_name, &people->age);
        people++;
    }

    fclose(fp);
}

void print_people(Person* people) {
    for(int i = 0; i < PEOPLE_COUNT; ++i) {
        printf("First name: %s, Last name: %s, Age: %d\n",
               people->first_name, people->last_name, people->age);
        people++;
    }
}

void to_file(Person* people) {
    FILE* fp;
    fp = fopen(FILE_NAME, "w");

    for(int i = 0; i < PEOPLE_COUNT; ++i) {
        fprintf(fp, "%s %s %d\n",
                people->first_name, people->last_name, people->age + 1);
        people++;
    }

    fclose(fp);
}

void edit_person(Person* people, int index)
{
    printf("Enter a new first name: ");
    scanf("%s", (people + index - 1)->first_name);
    printf("Enter a new last name: ");
    scanf("%s", (people + index - 1)->last_name);
    printf("Enter a new age: ");
    scanf("%d", &(people + index - 1)->age);


//    printf("Enter a new first name: ");
//    scanf("%s", people[index - 1].first_name);
//    printf("Enter a new last name: ");
//    scanf("%s", people[index - 1].last_name);
//    printf("Enter a new age: ");
//    scanf("%d", &people[index - 1].age);
}
