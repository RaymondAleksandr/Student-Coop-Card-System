#include <stdio.h>
#include <stdlib.h>

struct student // Create Linked list
{
    long int accountNo;
    char name[100];
    int fund;
};


void input(struct student[], int); // Get into the system and decide how many student you want to manage
void displayData(struct student[], int); // Display the fund that you inputted students are taking
void addFund(struct student[], int, long int, int); // Add fund to a student
void removeFund(struct student[], int, long int, int); // Delete fund from a student
int search(struct student[], int, long int); // Search for records


int main() {
    struct student data[20]; // Initialize students' data
    long int accountNo; // Create a long integer for storing student number
    int n, choice, amount, index; // The parameters for traverse and search
    int _Pwd = 2019; // Login password for this program
    int yourPwd; // The user input for password
    int try = 1;

    printf("Welcome to the Student IC Card Management System!\n");
    printf("Please input your password: "); // Tells the user to input the admin password
    scanf("%d", &yourPwd); // User input
    while (yourPwd != _Pwd) { // If the user inputted the wrong password, asks user to try again
        if (try > 3) { // If the user entered the wrong password 3 times, kick them out of the system.
            printf("You have benn kicked out! \n");
            exit(1); // Exit with error
        }
        printf("Your input password was wrong, try again! \n");
        printf("Input your password: ");
        scanf("%d", &yourPwd);
        try++;
    }

    printf("Successfully Logged In!\n");
    printf("Number of students you want to manage?: ");

    scanf("%d", &n); // Asks the user the input the data for student(s)
    input(data, n); // Put the user inputted data into student

    do { // Asks the user to choose one of the following options
        printf("\nIC Card Management System Menu :\n");
        printf("Press 1 to display all records.\n");
        printf("Press 2 to add fund to a student.\n");
        printf("Press 3 to remove fund from a student.\n");
        printf("Press 4 to search for a student.\n");
        printf("Press 0 to exit\n");
        printf("\nEnter choice(0-4) : ");
        scanf("%d", &choice);

        switch (choice) { // Display
            case 1:
                displayData(data, n);
                break;

            case 2:
                printf("Enter student number : ");
                scanf("%ld", &accountNo);
                printf("Enter amount to add : ");
                scanf("%d", &amount);
                addFund(data, n, accountNo, amount);
                break;

            case 3:
                printf("Enter student number : ");
                scanf("%ld", &accountNo);
                printf("Enter amount to delete : ");
                scanf("%d", &amount);
                removeFund(data, n, accountNo, amount);
                break;

            case 4:
                printf("Enter account number to search : ");
                scanf("%ld", &accountNo);
                index = search(data, n, accountNo);
                if (index == -1) {
                    printf("Record not found : ");
                } else {
                    printf("StudentNo: \t\t\t%ld\nStudent Name: \t\t%s\nTotal Fund: \t\t%d\n",
                           data[index].accountNo, data[index].name, data[index].fund);
                }
                break;

            case 0:
                printf("See you soon!");
                exit(0);
        }
    } while (choice != 0);
    return 0;
}

void input(struct student list[100], int s) {
    char *iPtr;
    int i;
    for (i = 0; i < s; i++) {
        printf("\nEnter data for Record #%d", i + 1);
        printf("\nEnter Student Number : ");
        scanf("%ld", &list[i].accountNo);
        fflush(stdin);
        printf("Enter The Name of Student : ");
        gets(list[i].name);
        list[i].fund = 0;
    }
}

void displayData(struct student list[100], int s) {
    long int i;

    for (i = 0; i < s; i++) {
        printf("StudentNo[%ld]: \t\t%ld\nStudent Name: \t\t%s\nTotal Fund: \t\t%d\n", i + 1,
               list[i].accountNo, list[i].name, list[i].fund);
    }
}

void addFund(struct student list[], int s, long int number, int amt) {
    int i = search(list, s, number);
    if (i == -1) {
        printf("Record not found");
    } else {
        list[i].fund += amt;
    }
}

void removeFund(struct student list[], int s, long int number, int amount) {
    int i = search(list, s, number);
    if (i == -1) {
        printf("Record not found\n");
    } else if (list[i].fund < amount) {
        printf("Insufficient Fund!!\n");
    } else {
        list[i].fund -= amount;
    }
}

int search(struct student list[100], int s, long int number) {
    int i;

    for (i = 0; i < s; i++) {
        if (list[i].accountNo == number) {
            return i;
        }
    }
    return -1;
}
