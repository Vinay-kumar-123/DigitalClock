#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
void time_menu();
void current_date();
void clear_screen();
int main(){
  time_menu();
  while(1){
   int choice;
   scanf("%d" , &choice);
   time_t raw_time;
   struct tm *current_time;
   char name[100], date[100];

   time(&raw_time);
   current_time = localtime(&raw_time);
   if (choice ==1) {
    strftime(name, sizeof(name), "%H:%M:%S ", current_time);
   }else{
    strftime(name, sizeof(name), "%I:%M:%S %p", current_time);
   }

   strftime(date, sizeof(date), "%d %B %Y", current_time);

   clear_screen();
   printf("Current Time : %s\n", name);
   printf("Current Date : %s\n", date);
   sleep(1);
  }
  
  return 0;
} 

void time_menu(){
  printf("\n-------------------------------");
  printf("\nWelcome to My project");
  printf("\nChoose the time formate");
  printf("\n1. 24 Hour format");
  printf("\n2. 12 Hour format (default)");
  printf("\nMake a choice(1/2): ");
}

void clear_screen() {
  #ifdef  _WIN32
    system("cls");
  #else
   system("clear");
  #endif
}