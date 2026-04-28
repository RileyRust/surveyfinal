#include <stdio.h>
int getAge();
double getfeet();
double getinch();
double getweight();
char getsex();
int getactivitylevel();
double calculate_bmr(double weightKg, double heightCm, int age, char sex);
double calculate_tdee(double bmr, int activity);
void run_tests();



int main() {



    #ifdef TEST
        run_tests();
        return 0;
    #endif



    int age;
    double heightinfeet;
    double heightininches;
    double weight;
    char sex; 
    double total_in;
    double heightCm;
    double weightKg;
    double BMI;
    double BMR;
    double multiplier;
    int activity;

    printf("Welcome to the Calorie Calculator!\n");

    age = getAge();
    heightinfeet = getfeet();
    heightininches = getinch();
    weight = getweight();
    sex = getsex();
    activity = getactivitylevel();


    // converting to cm and kilos because thats what the equation asked for 
    total_in = (heightinfeet * 12) + heightininches;
    heightCm = total_in * 2.54;
    weightKg = weight * 0.45359237;


    double heightMeters = heightCm / 100.0;
    BMI = weightKg / (heightMeters * heightMeters);

    BMR = calculate_bmr(weightKg, heightCm, age, sex);
    double TDEE = calculate_tdee(BMR, activity);




    //goal 
    int goal;

    printf("\nChoose your goal:\n");
    printf("1 = Lose weight\n");
    printf("2 = Maintain weight\n");
    printf("3 = Gain weight\n");
     // goal varification
    do {
        printf("Enter choice (1-3): ");
        if (scanf("%d", &goal) != 1 || goal < 1 || goal > 3) {
            printf("can you not count that high 1 2 or 3\n");
            while (getchar() != '\n');
            goal = -1;
        }
    } while (goal < 1 || goal > 3);

    // calorie goal calculation
    double tc;

    if (goal == 1) {
        tc = TDEE - 500;
    } else if (goal == 2) {
        tc = TDEE;
    } else {
        tc = TDEE + 500;
    }


    //explination so user understands
    if (goal == 1) {
    printf("\n you chose to lose weight tubby.\n");
    printf("This calorie target is about 500 calories below your maintenance level so basicaaly eat less.\n");
    printf("following it consistently should help you lose about 1 pound per week keyword following.\n");
    }
    else if (goal == 2) {
        printf("\n you chose to maintain your weight do you think that is a good idea?\n");
        printf("Eating around this number should keep your weight stable.\n");
    }
    else {
        printf("\n you chose to gain weight..... better hurry before the winds blows you away \n");
        printf("this calorie target is about 500 calories above your maintenance level eat baby eat.\n");
        printf("following it consistently should help you gain about 1 pound per week.\n");
    }


    //bmr tdee and calorie goal
    printf("\n");
    printf("BMR: %.2f calories per day\n", BMR);
     printf("\n");
    printf("TDEE: %.2f calories per day\n", TDEE);
     printf("\n");
    printf("Calorie Goal: %.0f calories per day\n", tc);
     printf("\n");




     //tells you if you fitness based on body mass index
     printf("BMI: %.1f\n", BMI);

    if (BMI < 18.5) {
    printf("BMI Category: Underweight\n");
    } else if (BMI < 25.0) {
    printf("BMI Category: Normal weight\n");
    } else if (BMI < 30.0) {
    printf("BMI Category: Overweight\n");
    } else {
    printf("BMI Category: Obese\n");
    }
    printf("\n");


    // which diet you are choosing 
    int macroChoice;

    printf("\nChoose your meal style\n");
    printf("1 = Balanced (30%% protein, 40%% carbs, 30%% fat)\n");
    printf("2 = High Protein (40%% protein, 30%% carbs, 30%% fat)\n");
    printf("3 = Low Carb (30%% protein, 20%% carbs, 50%% fat)\n");
    printf("4 = Keto (20%% protein, 5%% carbs, 75%% fat)\n");

    do {
    printf("Enter choice (1-4): ");
    if (scanf("%d", &macroChoice) != 1 || macroChoice < 1 || macroChoice > 4) {
        printf("Invalid choice. Enter 1–4.\n");
        while (getchar() != '\n');
        macroChoice = -1;
    }
    } while (macroChoice < 1 || macroChoice > 4);

    double pPercent, cPercent, fPercent;

    if (macroChoice == 1) {
    pPercent = 0.30;
    cPercent = 0.40;
    fPercent = 0.30;
    printf("\nBalanced\n");
    }
    else if (macroChoice == 2) {
    pPercent = 0.40;
    cPercent = 0.30;
    fPercent = 0.30;
    printf("\nHigh Protein\n");
    }
    else if (macroChoice == 3) {
    pPercent = 0.30;
    cPercent = 0.20;
    fPercent = 0.50;
    printf("\nLow Carb\n");
    }
    else {
    pPercent = 0.20;
    cPercent = 0.05;
    fPercent = 0.75;
    printf("\nKeto\n");
    }

    double b = tc * 0.25;
    double l = tc * 0.30;
    double d = tc * 0.30;
    double s = tc * 0.15;




    double bp;
    double bc; 
    double bf;
    double lp; 
    double lc;
    double lf;
    double dp; 
    double dc; 
    double df;
    double snp;
    double snc;
    double snf;


    // protein for each
    bp = (b * 0.30) / 4;
    lp = (l * 0.30) / 4;
    dp = (d * 0.30) / 4;
    snp = (s * 0.30) / 4;

    // carbs for each 
    bc = (b * 0.40) / 4;
    lc = (l * 0.40) / 4;
    dc = (d * 0.30) / 9;
    snc = (s * 0.40) / 4;

    // fats for each

    bf = (b * 0.30) / 9;
    lf = (l * 0.30) / 9;
    df = (d * 0.30) / 9;
    snf = (s * 0.30) / 9;


    // breakfast
    printf("\nBreakfast: %.0f calories\n", b);
    printf("Protein: %.0f g\n", bp);
    printf("Carbs:   %.0f g\n", bc);
    printf("Fat:     %.0f g\n", bf);

    // lunch
    printf("\nLunch: %.0f calories\n", l);
    printf("Protein: %.0f g\n", lp);
    printf("Carbs:   %.0f g\n", lc);
    printf("Fat:     %.0f g\n", lf);

    // dinner
    printf("\nDinner: %.0f calories\n", d);
    printf("Protein: %.0f g\n", dp);
    printf("Carbs:   %.0f g\n", dc );
    printf("Fat:     %.0f g\n", lf);

    // snacks
    printf("\nSnacks: %.0f calories:\n", s);
    printf("Protein: %.0f g\n", snp);
    printf("Carbs:   %.0f g\n", snc);
    printf("Fat:     %.0f g\n", snf);




    // save results
    char saveChoice;

    printf("\n save your results? y or n ");
        scanf(" %c", &saveChoice);

    if (saveChoice == 'Y' || saveChoice == 'y') {

        FILE *file = fopen("results.txt", "w");

    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
    } else {

        fprintf(file, "calorie calculator results \n\n");
        fprintf(file, "Age %d\n", age);
        fprintf(file, "Sex %c\n", sex);
        fprintf(file, "Height %.0f ft %.0f in\n", heightinfeet, heightininches);
        fprintf(file, "Weight %.1f lbs\n\n", weight);

        fprintf(file, "BMR %.2f calories/day\n", BMR);
        fprintf(file, "TDEE %.2f calories/day\n", TDEE);
        fprintf(file, "Calorie Goal %.0f calories/day\n\n", tc);

        fprintf(file, "BMI %.1f\n", BMI);
        if (BMI < 18.5) fprintf(file, "Underweight\n\n");
        else if (BMI < 25.0) fprintf(file, "Normal weight\n\n");
        else if (BMI < 30.0) fprintf(file, "Overweight\n\n");
        else fprintf(file, " Obese\n\n");

        fprintf(file, "meal breakdown\n");
        fprintf(file, "Breakfast %.0f calories P %.0f g C %.0f g F %.0f g\n", b, bp, bc, bf);
        fprintf(file, "Lunch: %.0f calories P %.0f g C %.0f g F %.0f g\n", l, lp, lc, lf);
        fprintf(file, "Dinner: %.0f calories P %.0f g C %.0f g F %.0f g\n", d, dp, dc, df);
        fprintf(file, "Snacks: %.0f calories P %.0f g C %.0f g F %.0f g\n", s, snp, snc, snf);

        fclose(file);
        printf("\nYour results have been saved to results.txt\n");
    }
}

    

    // end menu
    int choice;

    printf("\nWould you like to:\n");
    printf("1 = Run the calculator again\n");
    printf("2 = Exit the program\n");
    printf("Enter choice: ");

    scanf("%d", &choice);

    if (choice == 1) {
        
        printf("\nRestarting...\n\n");
        main();  
    }

    return 0;
}



#ifdef TEST
void run_tests() {
    printf("Running internal tests...\n\n");

    double bmr1 = calculate_bmr(70, 175, 25, 'M');
    printf("BMR Test 1 (Male): %.2f\n", bmr1);

    double bmr2 = calculate_bmr(60, 160, 30, 'F');
    printf("BMR Test 2 (Female): %.2f\n", bmr2);

    double tdee1 = calculate_tdee(bmr1, 3);
    printf("TDEE Test 1 (Activity 3): %.2f\n", tdee1);
}
#endif




int getAge() {
    int age;

    do {
        printf("Please enter your age: ");
        if (scanf("%d", &age) != 1 || age <= 0 || age > 120) {
            printf("Invalid age. Please enter a number between 1 and 120.\n");
            while (getchar() != '\n');
            age = -1;
        }
    } while (age <= 0 || age > 120);

    return age;
}

double getfeet(){
    double feet; 

    do {
        printf("Please enter your height feet: ");
        if (scanf("%lf", &feet) != 1 || feet <= 0 || feet > 8) {
            printf("Thats not even possible feet must be between 1 and 8.\n");
            while (getchar() != '\n');
            feet = -1;
        }
    } while (feet <= 0 || feet > 8);
    return feet; 
}

double getinch(){
    double inch;

     do {
        printf("Please enter your height inches: ");
        if (scanf("%lf", &inch) != 1 || inch < 0 || inch >= 12) {
            printf("You do realise inches must be between 0 and 11.\n");
            while (getchar() != '\n');
            inch = -1;
        }
    } while (inch < 0 || inch >= 12);

    return inch;
}

double getweight(){
    double weight;
    do {
        printf("Please enter your weight in pounds round if needed: ");
        if (scanf("%lf", &weight) != 1 || weight <= 0) {
            printf("you cant weigh 0 or negative pounds dude\n");
            while (getchar() != '\n');
            weight = -1;
        }
    } while (weight <= 0);

    return weight; 
}


char getsex(){
    char sex; 
 do {
        printf("Please enter your biological sex M or F: ");
        scanf(" %c", &sex);

        if (sex != 'M' && sex != 'F' && sex != 'm' && sex != 'f') {
            printf("i want to say something funny but i dont want to get in trouble M or F please\n");
        }
    } while (sex != 'M' && sex != 'F' && sex != 'm' && sex != 'f');

    return sex; 
}

int getactivitylevel(){

    int activity; 

    do {
        printf("\nSelect your activity level:\n");
        printf("1 = soooo lazy \n");
        printf("2 = kinda lazyyyy \n");
        printf("3 = uhhhh i run.... sometimes\n");
        printf("4 =  yeah I jog on the beach\n");
        printf("5 =  i was born in the running (bane voice) \n");
        printf("Enter choice 1-5: ");

        if (scanf("%d", &activity) != 1 || activity < 1 || activity > 5) {
            printf("heyyyy stupid i said enter a number between 1 and 5..... stupid\n");
            while (getchar() != '\n');
            activity = -1;
        }
    } while (activity < 1 || activity > 5);

    return activity; 

}


double calculate_bmr(double weightKg, double heightCm, int age, char sex) {
    if (sex == 'M' || sex == 'm') {
        return (10 * weightKg) + (6.25 * heightCm) - (5 * age) + 5;
    } else {
        return (10 * weightKg) + (6.25 * heightCm) - (5 * age) - 161;
    }
}

double calculate_tdee(double bmr, int activity) {
    double multiplier;

    if (activity == 1) multiplier = 1.2;
    else if (activity == 2) multiplier = 1.375;
    else if (activity == 3) multiplier = 1.55;
    else if (activity == 4) multiplier = 1.725;
    else multiplier = 1.9;

    return bmr * multiplier;
}