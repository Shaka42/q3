#include<stdio.h>
#include<string.h>

//declaring functions
int validate_checker(double grade);
void print_grades(double grades[],int size);//
int grade_class1(double GPA);//
double GPA_calculator(double [],int size);//

int main(){
    typedef struct {
        char name[30];
        int age;
        char religion[20];
        double grades[5];
        char grade_class[50];
    }Student;

    char name[30], grade_class[50], religion[20];
    int age,number_of_grades=5,n,i=0;
    double grade,GPA;

    Student Student1;
    printf("Enter the student's name:");
    fgets(name,sizeof(name),stdin);
    strcpy(Student1.name,name);

    printf("Enter student's age:");
    scanf("%d",&age);
    Student1.age=age;

    printf("Enter student's religion:");
    scanf("%s", religion);
    strcpy(Student1.religion,religion);
    

    printf("Enter the number of grades:\n");
    do{ 
        scanf("%lf",&grade);
        if(validate_checker(grade)==1){
            Student1.grades[i] = grade;
            i++;
        }
        else{
            printf("please re-enter the value, invalid!!\n");
            continue;
        }
    } while ( i < 5);
    //validate section
    GPA = GPA_calculator(Student1.grades,number_of_grades);



    //output
    printf("\nName: %s",Student1.name);
    printf("Age: %d\n",Student1.age);
    printf("Religion: %s\n",Student1.religion);
    printf("Grades: ");
    print_grades(Student1.grades,number_of_grades);
    printf("\nGPA: %.1lf\n", GPA);
    
    n = grade_class1(GPA);
     if( n == 0){
        strcpy(Student1.grade_class,"First Class");
    }
    else if ( n == 1)
    {
        strcpy(Student1.grade_class,"Second Upper");
    }
    else if (n == 2)
    {
        strcpy(Student1.grade_class,"Second Lower");
    }
    else if ( n == 3)
    {
        strcpy(Student1.grade_class,"Second Lower Pass");
    }
    
    else{
        strcpy(Student1.grade_class,"Pass Degree");
    }
    printf("Grade  Class: %s",Student1.grade_class);

    return 0;
}

//function for printing grades
void print_grades(double grades[],int number_of_grades){
 for (int i = 0; i < number_of_grades ; i++)
    {
        printf("%.1lf,",grades[i]);
    }
}

//function for calculating GPA
double GPA_calculator(double grades[],int number_of_grades){
    double  sum=0;
    for (int i = 0; i < number_of_grades ; i++)
    {
        sum += grades[i];
    }
    return (sum/number_of_grades);
}


// function for printing grade class
int grade_class1(double GPA){
    if(GPA >= (double)4.0){
        return 0;
    }
    else if ( (GPA >= (double)3.5)&&(GPA < (double)4.0))
    {
        return 1;
    }
    else if ((GPA >= (double)3.0) && (GPA < (double)3.5))
    {
        return 2;
    }
    else if ((GPA >= (double)2.0) && (GPA < (double)3.0))
    {
        return 3;
    }
    else{
        return 4;
    }
}

int validate_checker(double grade){
    if((grade == (double)2.0)||(grade == (double)(2.5))||(grade == (double)(3.0))||(grade == (double)(3.5))||(grade == (double)(4.0))){
       return 1; 
    }
    else{
        return 0;
    }
}