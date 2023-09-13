#include <stdio.h>
#include <stdlib.h> //check online what use
#include <string.h>
#include <ctype.h> //check online what use
#include <math.h>
#include <time.h>
//#define MAXINPUT 100

// Declaring main structure for data of patients with sub structures.
struct data_of_patient
{
    char name[50], address[500], email[50], gender[10], b_group[5], disease[100], insurance[50];
    char ph_no[20], l_no[20], aadhar_no[20];
    int age;

    struct primary_details
    {
        float height, weight;
        int o2, pulse;
        // float bmi,age;
    } pd[20];

    struct emergency_contact
    {
        char e_name[50], e_address[500], e_email[150], e_relation[20];
        char e_ph_no[20], e_aadhar_no[20];
    } ec[20];

    struct date_of_birth
    {
        int dd, mm, yy;
    } dob[20];

    struct blood_pressure
    {
        int sys, dia;
    } bp[20];

    struct billing
    {
        int consult,report;
        float operation,medical,room_rent,other,total;
    } bill[7];
};

// initialized data
struct data_of_patient dp[20] =
    {
        {"Priya", "D-1,Valkeshwer Flat,Ghatlodiya,Ahmedabad.", "patelpriya@gmail.com", "female", "B+", "Typhoid", "No", "6783849398", "87658954", "674837483828", 18, {5.5, 55, 98, 75, 22.5}, {"Rohanbhai", "D-1,Valkeshwer Flat,Ghatlodiya,Ahmedabad.", "rohan76@gmail.com", "Father", "6785467989", "890967895489"}, {7, 6, 2004}, {122, 79}, {500, 600, 0.00, 2000, 15000, 2000, 20100}},
        {"Riya", "M-745279,Kadambari Society,Shastrinagar,Ahmedabad.", "riya21@gmail.com", "female", "A+", "Breast Cancer", "Aarogya Insurance", "8954667439", "67895489", "988462346721", 25, {5.8, 48, 99, 77, 25}, {"Kishorbhai", "M-765783,Kadambari Society,Shatstrinagar,Ghatlodiya", "kishor65@gmail.com", "Brother", "4864657278", "989485743893"}, {19, 10, 1997}, {130, 85}, {1000, 3000, 60000, 5000, 10000, 5000, 84000}},
        {"Vedant", "A-5,Sagar Row house,Ushmanpura,Ahmedabad.", "tgfvedant@yahoo.com", "male", "O+", "Accidental Injury", "Health Insurance", "9078656543", "87653490", "808734567812", 42, {6.0, 67, 97, 70, 30}, {"Rahul", "Shantigram society,Sarkhej,Ahmedabad.", "rahul56@gmail.com", "Friend", "8976543210", "897856434212"}, {25, 12, 1980}, {118, 82}, {200, 200, 2000, 1000, 1000, 700, 5100}},
        //{"Aayush","A-702,Shukan Society,Motavarachha,Surat.","aayush3214@gmail.com","male","A-","Tuberculosis","No",9765231467,78654390,876523419812,34,{5.2,50,98,74,24},{"Trisha","Shanti dham society,surat","trisha67@yahoo.com","Friend",8976743578,9878541234},{19,02,1989},{125,84},{}},
        {"Niti", "Shrikunj Society,Ranip,Ahmedabad", "nitipatel@gmail.com", "female", "O+", "Fracture hand", "Maa Card", "9876542092", "67895478", "909099345678", 28, {5.8, 65, 99, 80, 27}, {"Yuvraj", "Royal Bunglow,Vastral,Ahmedabad.", "yuvyt543@gmail.com", "Uncle", "9545632889", "876590923785"}, {31, 7, 1994}, {120, 81}, {500, 200, 300, 500, 0, 0, 1500}},
        {"Devam", "72-Dharmjivan society,Katardham,Rajkot", "devammohan@gmail.com", "Male", "AB-", "Coronary Artery Disease", "Mediclam", "9812234568", "78864984", "987645891234", 56, {5.4, 70, 90, 40, 28}, {"Manoj", "Eidden hills,Chunaravad,Rajkot", "manojyu54@gmail.com", "Father", "9876341234", "879025348752"}, {10, 11, 1966}, {126, 89}, {4000, 6000, 100000, 10000, 30000, 5000, 155000}},
        {"Geeta", "Kirti Apartment,Navrangpura,Ahmedabad", "gspatadiya@yahoo.com", "Female", "O+", "Sonography", "No", "8976542390", "89076589", "908765433298", 30, {5.3, 72, 98, 76, 28}, {"Vikki", "Kirti Apartment,Navrangpura,Ahmedabad.", "vikki34@gmail.com", "Husband", "9898907645", "987645972413"}, {28, 2, 1992}, {125, 83}, {1000, 4000, 0, 1500, 0, 0, 6500}}
    };

int i, j, k, l, n, m, s, flag = 0;
int ages, dd, mm, yy;
char uniq_id[20];

// Functions

void age();
void is_alpha(char name[20]);
void is_ph_no(char ph_no[20]);
void is_landline_no(char landline_no[20]);
void is_aadhar_no(char aadhar_no[20]);
void is_gender(char gender[10]);

void main()
{
    
    int wish, option, i, j, o;
    int a, b, c;
    int day, month, year;

    printf("\t\t\t\t\t\tWelcome to HEALTHCARE MANAGEMENT SYSTEM\n");

    time_t now;
    time(&now);

    struct tm *local = localtime(&now);

    day = local->tm_mday;         // get day of month (1 to 31)
    month = local->tm_mon + 1;    // get month of year (0 to 11)
    year = local->tm_year + 1900; // get year since 1900

    // prit the current date
    printf("\t\t\t\t\t\t\tDate is: %02d/%02d/%d\n", day, month, year);
start:
    printf("\n\t\t\t\t\t\t\tEnter 1 to PROCEED");
    printf("\n\t\t\t\t\t\t\tEnter 0 to EXIT\n\n");
    scanf("%d", &wish);

    switch (wish)
    {
    case 1:
    {

        printf("\n1 : Input Data"); // finish-panthee,diya
        printf("\n2 : Edit");       // nidhi
        printf("\n3 : Bill");       // nidhi
        printf("\n4 : Details");    // panthee,diya
        printf("\n5 : Help");
        printf("\n6 : Delete");
        printf("\n\nPress a number to proceed further : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1: // input data
        {

        printf("\nEnter number of patient Records ");
        scanf("%d", &n);
       
            for (i = 0, j = 0, k = 0, l = 0 , m=0 , o = 0; i < n; i++)
            {
                printf("\n**Enter the details of Patient : %d **\n", i + 1);

                printf("\nName : ");
                fflush(stdin);
                gets(dp[i].name);
                is_alpha(dp[i].name);
                //  printf("\nName : ");

                printf("\nAddress : ");
                fflush(stdin);
                gets(dp[i].address);
                // printf("Address : %s",dp[i].address);

                printf("\nPhone no. : ");
                fflush(stdin);
                gets(dp[i].ph_no);
                is_ph_no(dp[i].ph_no);
                // printf("Ph : +91 %.0lf",dp[i].ph_no);

                printf("\nLandline no. : ");
                fflush(stdin);
                gets(dp[i].l_no);
                is_landline_no(dp[i].l_no);
                // printf("\n Landline No. : 079 %.0lf",dp[i].l_no);
                //  NA if not there

                printf("\nEmail : ");
                fflush(stdin);
                gets(dp[i].email);
                // check @ and .com at the end of email
                // printf("Email : %s",dp[i].email);

                printf("\nAadhar no. : ");
                fflush(stdin);
                gets(dp[i].aadhar_no);
                is_aadhar_no(dp[i].aadhar_no);
                // printf("\n Aadhar Card No. : %.0lf",dp[i].aadhar_no);

                age();
                // day>0 || day<31

                printf("\nGender : ");
                fflush(stdin);
                gets(dp[i].gender);
                is_gender(dp[i].gender);
                // printf("Gender : %s ",dp[i].gender);

                printf("\nBlood Group : ");
                fflush(stdin);
                gets(dp[i].b_group);
                // restrict to 3 characters and alphabets
                // printf("\nBlood Group : %s",dp[i].b_group);

                // insurance
                // disease

                //**************************************Primary Details ******************************
                printf("\n\n\t\t\t\t\t\t Primary Details ");

                printf("\n\nHeight in cm: ");
                scanf("%f", &dp[i].pd[k].height);
                // printf("\nHeight : %f cm",dp[i].pd[k].height);

                printf("Weight in kg : ");
                scanf("%f", &dp[i].pd[k].weight);
                // printf("\nWeight : %f kg",dp[i].pd[k].weight);

                printf("Blood Pressure in sys/dia in mm Hg : ");
                scanf("%d%d", &dp[i].bp[o].sys, &dp[i].bp[o].dia);
                // printf("Blood Pressure : Sys : %d mm-Hg Dia : %d mm-Hg",dp[i].bp[i].sys,dp[i].bp[i].dia);

                printf("Oxygen Level : ");
                scanf("%d", &dp[i].pd[k].o2);
                // printf("\nOxygen Level : %d ",dp[i].pd[k].o2);

                printf("Pulse Rate in BPM : ");
                scanf("%d", &dp[i].pd[k].pulse);
                // printf("\nPulse Rate : %d BPM \n",dp[i].pd[k].pulse);

                //*****************************Emergency Contact Details******************************
                printf("\n\n\t\t\t\t\t Emergency Contact Details  ");

                printf("\n\nName : ");
                fflush(stdin);
                gets(dp[i].ec[l].e_name);
                is_alpha(dp[i].ec[l].e_name);
                // printf("Name : %s",dp[i].ec[l].e_name);

                printf("\nAddress : ");
                fflush(stdin);
                gets(dp[i].ec[l].e_address);
                // printf("Address : %s",dp[i].ec[l].e_address);

                printf("\nPhone No. : ");
                fflush(stdin);
                gets(dp[i].ec[l].e_ph_no);
                is_ph_no(dp[i].ec[l].e_ph_no);
                // check 10 digits**
                // printf("Ph : +91 %.0lf",dp[i].ec[l].e_ph_no);

                printf("\nEmail : ");
                fflush(stdin);
                gets(dp[i].ec[l].e_email);
                // check @ and .com at the end of email
                // printf("Email : %s",dp[i].ec[l].e_email);

                printf("\nAadhar Card No. : ");
                fflush(stdin);
                gets(dp[i].ec[l].e_aadhar_no);
                is_aadhar_no(dp[i].ec[l].e_aadhar_no);
                // check 14 digits
                // printf("\n Aadhar Card No. : %.0lf",dp[i].ec[l].e_aadhar_no);

                printf("\nRelation : ");
                fflush(stdin);
                gets(dp[i].ec[l].e_relation);
                is_alpha(dp[i].ec[l].e_relation);
                // printf("Relation : %s",dp[i].ec[l].e_relation);

                //*****************************Billing******************************
                printf("\n\n\t\t\t\t\t\t Billing Details ");

                printf("\nConsultation fees : ");
                scanf("%d",&dp[i].bill[m].consult);

                printf("\nReports & Diagnostic : ");
                scanf("%d",&dp[i].bill[m].report);

                printf("\nOperation and Surgery : ");
                scanf("%f",&dp[i].bill[m].operation);

                printf("\nMedicines : ");
                scanf("%f",&dp[i].bill[m].medical);

                printf("\nRoom Rent: ");
                scanf("%f",&dp[i].bill[m].room_rent);

                printf("\nFood and Other : ");
                scanf("%f",&dp[i].bill[m].other);

                dp[i].bill[m].total=dp[i].bill[m].consult+dp[i].bill[m].report+
                dp[i].bill[m].operation+dp[i].bill[m].medical+
                dp[i].bill[m].room_rent;
                printf("\nyour Total is : %.02f ",dp[i].bill[m].total);
            }
            goto start;
            break; // wish-option-case-1-end

        }
        
        
                  // input end

        case 2: // edit
        {
            int edit, pedit, eedit;
            char YN;
            printf("\nEnter Unique ID for patient details : ");
            fflush(stdin);
            gets(uniq_id);
            for (i = 0, j = 0, k = 0, l = 0, m = 0, flag = 0; i < 10; i++)
            {
                if (strcmp(dp[i].aadhar_no, uniq_id) == 0)
                {
                    flag = 1;
                    a = i;
                    break;

                } // if complete
            }     // for loop complete
            for (i = a, j = 0, k = 0; i < 20; i++)
            {
                if (flag == 1)
                {
                    edit:
                    printf("\nEnter a number to edit further :  ");
                    printf("\n1:Edit Name");
                    printf("\n2:Edit Address");
                    printf("\n3:Edit Phone no.");
                    printf("\n4:Edit Landline no.");
                    printf("\n5:Edit Email id");
                    printf("\n6:Edit Aadhar Card no.");
                    printf("\n7:Edit Gender");
                    printf("\n8:Edit Blood Group");
                    printf("\n9:Edit Primary Details");
                    printf("\n10:Edit Emergency Details\n\n");
                    scanf("%d", &edit);
                    switch (edit)
                    {
                    case 1:
                    {
                        printf("Previous Name :%s", dp[i].name);
                        printf("\nEnter New Name :");
                        fflush(stdin);
                        gets(dp[i].name);
                        break;
                    }
                    case 2:
                    {
                        printf("Current Address :%s", dp[i].address);
                        printf("\nEnter New Address : ");
                        fflush(stdin);
                        gets(dp[i].address);
                        break;
                    }
                    case 3:
                    {
                        printf("Current Phone no. :%s", dp[i].ph_no);
                        printf("\nEnter New Phone no. : ");
                        fflush(stdin);
                        gets(dp[i].ph_no);
                        break;
                    }
                    case 4:
                    {
                        printf("Current Landline no. :%s", dp[i].l_no);
                        printf("\nEnter New Landline no. : ");
                        fflush(stdin);
                        gets(dp[i].l_no);
                        break;
                    }
                    case 5:
                    {
                        printf("Current Email id :%s", dp[i].email);
                        printf("\nEnter New Email id : ");
                        fflush(stdin);
                        gets(dp[i].email);
                        break;
                    }
                    case 6:
                    {
                        printf("Current Aadhar card no. :%s", dp[i].aadhar_no);
                        printf("\nEnter New Aadhar card no. : ");
                        fflush(stdin);
                        gets(dp[i].aadhar_no);
                        break;
                    }
                    case 7:
                    {
                        printf("Previous input :%s", dp[i].gender);
                        printf("\nEnter Gender : ");
                        fflush(stdin);
                        gets(dp[i].gender);
                        break;
                    }
                    case 8:
                    {
                        printf("Previous input :%s", dp[i].b_group);
                        printf("\nEnter New Blood Group : ");
                        fflush(stdin);
                        gets(dp[i].b_group);
                        break;
                    }
                    
                    //*****************primary detail********************8//
                    case 9:
                    {
        
                        printf(" Enter a number to edit further : ");
                        printf("\n1:Height");
                        printf("\n2:Weight");
                        printf("\n3:Blood Pressure");
                        printf("\n4:Oxygen level");
                        printf("\n5:Pulse rate\n");
                        scanf("%d", &pedit);

                        switch (pedit)
                        {
                            case 1:
                            {
                                printf("Previous input :%f", dp[i].pd[j].height);
                                printf("\nEnter New Height : ");
                                scanf("%f", &dp[i].pd[i].height);
                                break;
                            }

                            case 2:
                            {
                                printf("Previous input :%f", dp[i].pd[j].weight);
                                printf("\nEnter New Weight : ");
                                scanf("%f", &dp[i].pd[j].weight);
                                break;
                            }
                            case 3:
                            {
                                printf("Current O2 level : ", dp[i].pd[j].o2);
                                printf("\nEnter New O2 level : ");
                                scanf("%d", &dp[i].pd[i].o2);
                                break;
                            }
                            case 4:
                            {
                                printf("Current Pulse Rate :%d", dp[i].pd[j].pulse);
                                printf("\nEnter New Pulse Rate :%d", dp[i].pd[j].pulse);
                                scanf("%d", &dp[i].pd[j].pulse);
                                break;
                            }
                        }//switch-pedit end here
                    } // case 9 end here
                //**************emergency detail*************//
                    case 10:
                    {

                            printf("Enter a number to edit furthur details: ");
                            printf("\n1:Name");
                            printf("\n2:Address");
                            printf("\n3:Phone no.");
                            printf("\n4:Email");
                            printf("\n5:Aadhar Card no.");
                            printf("\n6:Relation");
                            scanf("%d", &eedit);
                        switch (eedit)
                        {
                            case 1:
                            {
                                printf("Previous Name:%s", dp[i].ec[k].e_name);
                                printf("\nEnter New Name :");
                                fflush(stdin);
                                gets(dp[i].ec[k].e_name);
                                break;
                            }
                            case 2:
                            {
                                printf("Current Adress:%s", dp[i].ec[k].e_address);
                                printf("\nEnter New Address : ");
                                fflush(stdin);
                                gets(dp[i].ec[k].e_address);
                                break;
                            }
                            case 3:
                            {
                                printf("Current Phone no:%s ", dp[i].ec[k].e_ph_no);
                                printf("\nEnter New Phone no. : ");
                                fflush(stdin);
                                gets(dp[i].ec[k].e_ph_no);
                                break;
                            }
                            case 4:
                            {
                                printf("Current Email id:%s", dp[i].ec[k].e_email);
                                printf("\nEnter New Email id : ");
                                fflush(stdin);
                                gets(dp[i].ec[k].e_email);
                                break;
                            }
                            case 5:
                            {
                                printf("Current Aadhar Card no.:%s", dp[i].ec[k].e_aadhar_no);
                                printf("\nEnter New Aadhar Card no : ");
                                fflush(stdin);
                                gets(dp[i].ec[k].e_aadhar_no);
                                break;
                            }
                            case 6:
                            {
                                printf("Relation:%s", dp[i].ec[k].e_relation);
                                printf("\nEnter New Relation : ");
                                fflush(stdin);
                                gets(dp[i].ec[k].e_relation);
                                break;
                            }
                        }//switch-eedit end here
                    } // case 10 end here
                    

                }// switch-edit end here

                 printf("\nEnter Y to edit further else enter N : ");
                    scanf("%c",&YN);
                    if(YN=='Y'||YN=='y')
                    {
                        goto edit;
                    }
                    else
                    {
                        goto start;
                    }

                } // if end
                     else
                    {
                        printf("\nEntered Unique id is not found");
                    }//else end
                    i=100;
            }     // for loop end
            goto start;
            break;
        }         // case 2 end here

        case 3: // bill
        {
            int bill;
            char yn;
            printf("\nEnter Unique ID for patient details : ");
            fflush(stdin);
            gets(uniq_id);
        
            for (i = 0, j = 0, k = 0, l = 0, m = 0, flag = 0; i < 10; i++)
            {
                if (strcmp(dp[i].aadhar_no, uniq_id) == 0)
                {
                    flag = 1;
                    a = i;
                    break;
                } // if complete
            }     // for loop complete
            for (i = a, j = 0; i <= a; i++)
            {
                if (flag == 1)
                {
                    printf("1:Check bill\n");
                    printf("2:Edit bill\n");
                    printf("-> ");
                    scanf("%d",&bill);
                    printf("\n");
                    switch(bill)
                    {
                        case 1:
                        {
                             // initialized data of bill //
                             show_bill:
                              printf("\nName of Patient : %s",dp[i].name);
                              printf("\nExpenses name \t\t\t\tcharges(Rs.)");
                              printf("\nConsultation \t\t\t\t%d", dp[i].bill[j].consult);
                              printf("\nReport and Diagnostics \t\t\t%d", dp[i].bill[j].report);
                              printf("\nOperations and Surgeries \t\t%.0f", dp[i].bill[j].operation);
                              printf("\nMedicinal Expenses \t\t\t%.0f", dp[i].bill[j].medical);
                              printf("\nRoom Rent\t\t\t\t%.0f", dp[i].bill[j].room_rent);
                              printf("\nFood and Others\t\t\t\t%.0f", dp[i].bill[j].other);
                              printf("\n");
                              printf("\nTotal bill\t\t\t\t%.0f", dp[i].bill[j].total);
                              break;
                        }
                        case 2:
                        {
                            //edit bill//
                            int choice;
                            again_bill:
							
							printf("1:consultation charges\n");
							printf("2:report & dignostic charges\n");
							printf("3:opration (or) surgery charges\n");
							printf("4:medicines charges\n");
							printf("5:room_rent\n");
							printf("6:food & other expenses\n");
                            printf("***Enter a number to edit further : ");
							scanf("%d",&choice);
							switch(choice)
							{
								case 1:
									{
                                        ///////dp[i].bill[j].total=dp[i].bill[j].total-dp[i].bill[j].consult;
										printf("Consultation Charges:%d",dp[i].bill[j].consult);
										printf("\nEnter new charges: ");
										scanf("%d",&dp[i].bill[j].consult);
                                        ///////dp[i].bill[j].total=dp[i].bill[j].total+dp[i].bill[j].consult;
										break;
									}
								case 2:
									{
										printf("Report & Dignostic Charges:%d",dp[i].bill[j].report);
										printf("\nEnter new charges: ");
										scanf("%d",&dp[i].bill[j].report);
										break;
									}
								case 3:
								    {
								    	printf("Opration (or) Surgery Charges:%lf",dp[i].bill[j].operation);
								    	printf("\nEnter new charges: ");
								    	scanf("%lf",&dp[i].bill[j].operation);
								    	break;
									}
								case 4:
									{
										printf("Medicines Charges:%d",dp[i].bill[j].medical);
										printf("\nEnter new charges: ");
										scanf("%d",&dp[i].bill[j].medical);
										break;
									}
								case 5:
									{
										printf("Room_rent :%f",dp[i].bill[j].room_rent);
										printf("\nEnter New charges: ");
										scanf("%f",&dp[i].bill[j].room_rent);
										break;
									}
								case 6:
									{
										printf("\nFood & Other:%d",dp[i].bill[j].other);
										printf("\nEnter new charges: ");
										scanf("%d",&dp[i].bill[j].other);
										break;
									}
						         
                            }//switch choice end
                            dp[i].bill[j].total=dp[i].bill[j].consult+dp[i].bill[j].medical+
                                                     dp[i].bill[j].operation+dp[i].bill[j].other+
                                                     dp[i].bill[j].report+dp[i].bill[j].room_rent;
                                 printf("\nYour Total Bill is : %.02f ",dp[i].bill[m].total);
                        }//case 2 of bill end
                          printf("\nEnter Y to edit further else enter N: ");
                            scanf(" %c",&yn);
                            if(yn=='y'||yn=='Y')
                            {
                                goto again_bill;
                            }
                            if(yn=='n'||yn=='N')
                            {
                                goto show_bill;
                            }
                            break;
                    }//switch bill end
                }//if end
            }//for end
            goto start;
            break; // wish-option-case-3-end
        }          // bill end

        case 4: // details
        {
            //**********************************details******************************** 4th case

            printf("\nEnter Unique ID for patient details : ");
            fflush(stdin);
            gets(uniq_id);

            for (i = 0, j = 0, k = 0, l = 0, m = 0, flag = 0; i < 10; i++)
            {
                if (strcmp(dp[i].aadhar_no, uniq_id) == 0)
                {
                    flag = 1;
                    a = i;
                    break;
                } // if complete

            } // for loop complete
            for (i = a, j = 0, k = 0, l = 0, m = 0; i <= a; i++)
            {
                if (flag == 1)
                {
                    printf("\nName : %s \t\t\t\t\t\t Total : %.0f ", dp[i].name, dp[i].bill[m].total);
                    printf("\nAddress : %s", dp[i].address);
                    printf("\nPhone No. : +91 %s", dp[i].ph_no);
                    printf("\nLandline No. : 079 %s", dp[i].l_no);
                    printf("\nEmail id : %s", dp[i].email);
                    printf("\nAadhar Card No. : %s", dp[i].aadhar_no);
                    printf("\nAge : Years %d Months %d Days %d", dp[i].dob[j].yy, dp[i].dob[j].mm, dp[i].dob[j].dd);
                    printf("\nGender : %s", dp[i].gender);
                    printf("\nBlood Group : %s", dp[i].b_group);
                    printf("\n\n\t\t\t\t\t Primary Details ");
                    printf("\nHeight : %f cm", dp[i].pd[k].height);
                    printf("\nWeight : %f kg", dp[i].pd[k].weight);
                    printf("\nBlood Pressure : Sys : %d mm-Hg Dia : %d mm-Hg", dp[i].bp[i].sys, dp[i].bp[i].dia);
                    printf("\nOxygen Level : %d ", dp[i].pd[k].o2);
                    printf("\nPulse Rate : %d BPM \n", dp[i].pd[k].pulse);
                    printf("\n\n\t\t\t\t Emergency Contact Details : ");
                    printf("\nName : %s", dp[i].ec[l].e_name);
                    printf("\nAddress : %s", dp[i].ec[l].e_address);
                    printf("\nPhone No. : +91 %s", dp[i].ec[l].e_ph_no);
                    printf("\nEmail : %s", dp[i].ec[l].e_email);
                    printf("\nAadhar Card No. : %s", dp[i].ec[l].e_aadhar_no);
                    printf("\nRelation : %s", dp[i].ec[l].e_relation);
                    printf("\n\n\t\t\t\t Billing Details : ");
                    printf("\nExpenses name \t\t\t\tcharges(Rs.)");
                    printf("\nConsultation \t\t\t\t%d", dp[i].bill[j].consult);
                    printf("\nReport and Diagnostics \t\t\t%d", dp[i].bill[j].report);
                    printf("\nOperations and Surgeries \t\t\t%.0f", dp[i].bill[j].operation);
                    printf("\nMedicinal Expenses \t\t\t\t%.0f", dp[i].bill[j].medical);
                    printf("\nRoom Rent\t\t\t\t%.0f", dp[i].bill[j].room_rent);
                    printf("\nFood and Others\t\t\t\t%.0f", dp[i].bill[j].other);
                    printf("\n");
                    printf("\nTotal bill\t\t\t\t%.0f", dp[i].bill[j].total);
                }
                else
                {
                    printf("\nEntered Unique id not found \n");
                } // else complete
            }
            goto start;
            break; // wish-option-case-4-end
        }          // details end

        case 5: // help
        {
            printf("->> Please Enter Correct Details.\n");
            printf("->> Do not use space or special characters in Aadhar Card No.\n");
            printf("->> Compulsoriy enter 12 digits in Aadhar Card No.\n");
            printf("->> Do not use any special character while entering Name.\n");
            printf("->> Compulsoriy enter 10 digits in Mobile No.\n");
            printf("->> Compulsoriy enter 8 digits in Landline No.\n");
            printf("->> Compulsorily input Birth Date in DD/MM/YYYY format only.\n");
            printf("->> Enter Valid Blood Group.\n");
            goto start;
            break; // wish-option-case-5-end
        }          // help end

        case 6: // delete
        {
            printf("\nEnter Unique ID for patient details : ");
            fflush(stdin);
            gets(uniq_id);

            for (i = 0, flag = 0; i < 20; i++)
            {
                if (strcmp(uniq_id, dp[i].aadhar_no) == 0)
                {
                    flag++;
                    for(j=i;j<20;j++)
                    {
                        dp[j]=dp[j+1];
                    }
                }
            }
            if (flag == 0)
            {
                printf("User not found.");
            }

            for (i = 0; i < 6; i++)
            {
                printf("\n%s", dp[i].name);
            }
            break; // wish-option-case-6-end
        }          // delete end
        }
        // system("cls");
        goto start;
        break; // wish-case-1-end

    } // wish-case-1-end

    case 0:
    {

        printf("\n\n\t\t\t\t\t\t    Thank you for visiting :)\n");
        break; // wish-case-2-end
    }          // wish-case-2-end

    default:
    {
        printf("\nENTER ONLY (0) OR (1)");
        break; // wish-default-end
    }          // wish-default-end
    }
}

// all functions

// name function
void is_alpha(char name[20])
{
    int i, flag = 0;
    // char name[20];
    //  fflush(stdin);
    //  gets(dp[i].name);
    for (i = 0; name[i] != '\0'; i++)
    {
        if ((!isalpha(name[i])) && (!name[i] == ' '))
        {
            flag++;
        }
    }
    if (flag != 0)
    {
        printf("\nYour Input contains some special symbols.");
        printf("\nTry again : ");
        fflush(stdin);
        gets(name);
        is_alpha(name);
    }
    else
    {
    }
}

// ph_no. function
void is_ph_no(char ph_no[20])
{
    int i, flag = 0, length;
    // char ph_no[20];
    //  printf("\nPhone no. : ");
    //  fflush(stdin);
    //  gets(ph_no);
    length = strlen(ph_no);
    if (length == 10)
    {
        for (i = 0; ph_no[i] != '\0'; i++)
        {
            if (!isdigit(ph_no[i]))
            {
                flag++;
            }
        }
        if (flag != 0)
        {
            printf("\nYour Input contains some special symbols.");
            printf("\nTry again : ");
            fflush(stdin);
            gets(ph_no);
            is_ph_no(ph_no);
        }
        else
        {
        }
    }
    else
    {
        printf("\nPlease Enter 10 digits ");
        printf("\nTry again : ");
        fflush(stdin);
        gets(ph_no);
        is_ph_no(ph_no);
    }
}

// landline-no function
void is_landline_no(char landline_no[20])
{
    int i, flag = 0, length;
    // char land_no[20];
    // printf("\nlandline no. : ");
    // fflush(stdin);
    // gets(land_no);
    length = strlen(landline_no);
    if (length == 8)
    {
        for (i = 0; landline_no[i] != '\0'; i++)
        {
            if (!isdigit(landline_no[i]))
            {
                flag++;
            }
        }
        if (flag != 0)
        {
            printf("\nYour Input contains some special symbols.");
            printf("\nTry again : ");
            fflush(stdin);
            gets(landline_no);
            is_landline_no(landline_no);
        }
        else
        {
        }
    }
    else
    {
        printf("\nPlease Enter 8 digits ");
        printf("\nTry again : ");
        fflush(stdin);
        gets(landline_no);
        is_landline_no(landline_no);
    }
}

// is_aadhar_no function
void is_aadhar_no(char aadhar_no[20])
{
    int i, flag = 0, length;
    // char aadhar_no[20];
    // printf("\nAadhar no. : ");
    // fflush(stdin);
    // gets(aadhar_no);
    length = strlen(aadhar_no);
    if (length == 12)
    {
        for (i = 0; aadhar_no[i] != '\0'; i++)
        {
            if (!isdigit(aadhar_no[i]))
            {
                flag++;
            }
        }
        if (flag != 0)
        {
            printf("\nYour Input contains some special symbols.");
            printf("\nTry again : ");
            fflush(stdin);
            gets(aadhar_no);
            is_aadhar_no(aadhar_no);
        }
        else
        {
        }
    }
    else
    {
        printf("\nPlease enter 12 digits ");
        printf("\nTry again : ");
        fflush(stdin);
        gets(aadhar_no);
        is_aadhar_no(aadhar_no);
    }
}

// is_gender function
void is_gender(char gender[10])
{
    int i, flag = 0, length;
    // char gender[10];
    //  printf("\nGender : ");
    //  fflush(stdin);
    //  gets(gender);
    if (
        flag == strcmp(gender, "male") || flag == strcmp(gender, "female") || flag == strcmp(gender, "other") ||
        flag == strcmp(gender, "Male") || flag == strcmp(gender, "Female") || flag == strcmp(gender, "Other") ||
        flag == strcmp(gender, "MALE") || flag == strcmp(gender, "FEMALE") || flag == strcmp(gender, "OTHER"))
    {
    }
    else
    {
        printf("\nInvalid input.");
        printf("\nTry again :");
        fflush(stdin);
        gets(gender);
        is_gender(gender);
    }
}

// age function
void age()
{
    int day, month, year;
    time_t now;
    time(&now);

    struct tm *local = localtime(&now);

    day = local->tm_mday;         // get day of month (1 to 31)
    month = local->tm_mon + 1;    // get month of year (0 to 11)
    year = local->tm_year + 1900; // get year since 1900

    // print the current date
    // printf("Date is: %02d/%02d/%d\n", day, month, year);
    printf("\nDate Of Birth in dd-mm-yyyy : ");
    scanf("%d %d %d", &dp[i].dob[j].dd, &dp[i].dob[j].mm, &dp[i].dob[j].yy);
    flag=0;
    if(dp[i].dob[j].yy > 1900  && dp[i].dob[j].yy < 2023)
    {
        if(dp[i].dob[j].mm < 13 && dp[i].dob[j].mm > 0)
        {
            if(dp[i].dob[j].mm == 1 || dp[i].dob[j].mm == 3 || dp[i].dob[j].mm == 5 || dp[i].dob[j].mm == 7 || dp[i].dob[j].mm == 8 || dp[i].dob[j].mm == 10 || dp[i].dob[j].mm == 12)
            {
                if(dp[i].dob[j].dd > 0 && dp[i].dob[j].dd < 32)
                {
                    flag=1;
                }
            }
            if(dp[i].dob[j].mm == 4 || dp[i].dob[j].mm == 6 || dp[i].dob[j].mm == 9 || dp[i].dob[j].mm == 11)
            {
                if(dp[i].dob[j].dd > 0 && dp[i].dob[j].dd < 31)
                {
                    flag=1;
                }
            }
            if(dp[i].dob[j].mm == 2)
            {
                if(dp[i].dob[j].dd > 0 && dp[i].dob[j].dd < 30)
                {
                    flag=1;
                }
            }

        }
    }



    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(flag == 1)
    {
         if (dp[i].dob[j].dd > day)
         {
             day = day + months[dp[i].dob[j].mm - 1];
             month = month - 1;
         }
         if (dp[i].dob[j].mm > month)
         {
             year = year - 1;
             month = month + 12;
         }
         dp[i].dob[j].dd = day - dp[i].dob[j].dd;
         dp[i].dob[j].mm = month - dp[i].dob[j].mm;
         dp[i].dob[j].yy = year - dp[i].dob[j].yy;
         printf("Age : %d Years %d Months %d Days \n", dp[i].dob[j].yy, dp[i].dob[j].mm, dp[i].dob[j].dd);
    }

    if(flag == 0)
    {
        printf("Invalid Birth date! ");
        age();
    }
}