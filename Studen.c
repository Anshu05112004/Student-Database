#include <stdio.h>

#define SUB 5
#define PS_MRK 100

struct Student {
    int rlno; // Roll No ke liye use kiya hua hai variable
    char name[50]; // Name ke liye use kiya hua hai variable
    char gender; // gender ke liye 
    int marks[SUB]; // uper se no of subject le ke utna bada array banayega jitne subject hai
};

void Out(struct Student students[], int nuStu)//out wala function sab students ka data aek sath print karega
 {
    for (int i = 0; i < nuStu; i++) {
        struct Student student = students[i];
        int totalMarks = 0;

        printf("Roll No: %d\n", student.rlno);
        printf("Name: %s\n", student.name);
        printf("Gender: %c\n", student.gender);

        for (int j = 0; j < SUB; j++) {
            totalMarks += student.marks[j];
        }

        printf("Total Marks: %d\n\n", totalMarks);
    }
}

void displayFailedStudents(struct Student students[], int nuStu, int subjectIndex) {
    printf("List of students failed in Subject %d:\n", subjectIndex + 1);

    for (int i = 0; i < nuStu; i++) {
        struct Student student = students[i];

        if (student.marks[subjectIndex] < PS_MRK) {
            printf("Roll No: %d\n", student.rlno);
            printf("Name: %s\n", student.name);
            printf("Gender: %c\n\n", student.gender);
        }
    }
}

int main() {
    int nuStu; // Number of students ke liye use kiya hua hai variable

    printf("Enter the number of students: ");
    scanf("%d", &nuStu);

    struct Student students[nuStu];
    getchar();
    for (int i = 0; i < nuStu; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Enter Roll No: ");
        scanf("%d", &students[i].rlno);

        printf("Enter Name: ");
        scanf("%s", students[i].name);

        printf("Enter Gender: ");
        scanf(" %c", &students[i].gender);
         getchar();

        for (int j = 0; j < SUB; j++) 
        {
             getchar();
            printf("Enter marks for Subject %d: ", j + 1);
            getchar();
            scanf("%d", &students[i].marks[j]);
        }
    }

    printf("\n--- Student Data ---\n\n");
    Out(students, nuStu);

    int subjectIndex;
    printf("\nEnter the subject index to check failed students: ");
    scanf("%d", &subjectIndex);
    displayFailedStudents(students, nuStu, subjectIndex - 1);

    return 0;
}
