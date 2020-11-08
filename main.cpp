#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "person.hpp"
using std::cout;
using std::endl;
using std::cin; 

person question(person p, int &smart, int &happiness, int &responsibility, int &wise, int parameter);
string u = "unemployed";

int main(){
int  wise = 0 , smart = 0, responsibility = 1, happiness = 10;
char decision; 
person user; 
birthday birth;
srand( (unsigned)time(NULL) );

int rFirst = rand()%20;
int rLast = rand()%20;
int rGender = rand()%3;
int rHair = rand()%5;
int rMajor = rand()%15;
int rCareer = rand()%15;

//initializing user atrributes
user.age = 0;
birth = set_birthday();
user.name = firstNames[rFirst] + lastNames[rLast];
user.g = gender[rGender];
user.hair = haircolor[rHair];
user.currency = 0;
user.job = "unemployed";
user.career = "unemployed";
user.major = "unemployed";
user.rstatus = "single";
user.agemajor = 0;
user.alive = 1;


//////////////////////////////////////MENU/////////////////////////////////////////////////
cout << "=====================================" 
     << "\nWelcome to the Grow Old (GO) Program!\n"   
     << "=====================================\n\n"
     << "Your birthday is " << birth.day << "/" << birth.month << "/" << birth.year 
     << "\nand your astrology sign is " << birth.astrology << "\n"
     <<"\nYou are " << user.age << " years old."
     <<"\nYour name is " << user.name <<"\nYour gender: " << user.g 
     <<"\nRelationship Status: " << user.rstatus 
     <<"\nThis is how much money you have $" << user.currency
     <<"\nEnter 'Y' to start your life\n"; 
     
cin >> decision;
if(decision == 'y' || decision == 'Y'){
  while((happiness > 0 && wise < 50 && responsibility > 0) && user.alive == 1 && user.age < 100 && user.currency >= -100000){
  user = question(user, smart, happiness, responsibility, wise, 0);
  user.age++;
  }  
}

 
if (user.alive == 1){
  cout << "\nYou are dead due to " << deaths[rand()%10] 
       << "\n--STATUS--"
       << "\nAge: " << user.age 
       << "\nMoney: " << user.currency << "\n"; 
}
else{
  cout << "\n--STATUS--"
       << "\nAge: " << user.age 
       << "\nMoney: " << user.currency << "\n";   
}

       
return 0; 
}



person question(person p, int &smart, int &happiness, int &responsibility, int &wise, int parameter){
  int rando = rand() % 5;
/*   cout << "This is how much money you have: " << p.currency << endl;  */
  char decision = 0, decision2 = 0;
  if (parameter == 0){ //0 means age
    if(p.age == 5){
      cout << "You are " << p.age << " years old\n"; 
      cout << "Do you want to go to school?\nEnter your decision here (y/n): \n" ;
      cin >> decision;
      if(decision == 'y' || decision == 'Y'){
        cout << "Great!\n\n";
        smart++;
        responsibility++;
      }
      else{
        cout << "You are forced to go to school anyways :P\n";
        smart--; 
      } 
    }
    if(p.age == 5 || p.age == 16){
      cout << "You are " << p.age << " years old\n";
      cout << "Do you want to make some good friends? (y/n)\n";
      cin >> decision;
      if (decision == 'y' || decision == 'Y'){
        cout << "You have made great friends!\n\n";
        happiness++;
      }
      else{
        decision = 0;
        cout << "Do you want to make some bad friends? (y/n)\n";
        cin >> decision;
        if (decision == 'y' || decision == 'Y'){
          wise--;
          if (p.age == 16){
            cout << "Your friends have asked you to do drugs with them\nWill you use join them?(y/n)\n";
            cin >> decision2; 
            if(decision2 == 'y' || decision2 == 'Y'){
              responsibility--;
              wise--; 
              happiness++; 
              cout << "You have smoked weed\n\n";
            }
            else
              cout << "Wise choice\n\n";
          }
        }
        else{  
        cout << "Alright loner...\n\n";
        happiness--;
        }
      }
    }
    if(p.age >= 12 && p.age <= 20 && p.age %3 == 0 && p.job.compare(u) == 0){
      decision = 0;
      cout << "You are " << p.age << " years old\n";
      cout << "You want to buy some new clothes. \nWill you want to get a part-time job? (y/n)\n";
      cin >> decision;
      if (decision == 'y' || decision == 'Y'){
        p.job = job[rand() % 15];
        responsibility++;
        wise++;
        happiness--;
        p.job = job[rand()%15];
        cout << "Your job is: " << p.job << "\n\n";
      }
      else{
        wise--;
      }

    }

    if (p.age >= 12 && p.job.compare(u) != 0)
      p.currency += 500; 

    if (p.age == 13){
      cout << "You are " << p.age << " years old\n";
      cout<< "You are now in Highschool!\n";
    }
    if (p.age >= 13 && p.age <= 18){ //highschool phase
      decision = 0;
      if (p.age == 13){
        cout << "Do you want to join any clubs? (y/n)\n";
        cin >> decision;
        if (decision == 'y' || decision == 'Y'){
          responsibility++;
          smart++;
          wise++;
          happiness++;
        }
        decision = 0;
        cout << "Do you want to join any sport teams? (y/n)\n";
        cin >> decision;
        if (decision == 'y' || decision == 'Y'){
          responsibility++;
          wise++;
        }
      }
      if (p.age >= 13 && p.age <= 18){
        int rando2 = rand() % 10;
        if (rando2 == 0){
          cout << "You just failed your geography quiz, do you want to study more? (y/n)\n";
          cin >> decision;
          if (decision == 'y' || decision == 'Y'){
            wise++;
            smart++;
          }
          else{
            smart--;
          }
        }
        else if (rando2 == 1){
          cout << "You forgot to memorize your lines in the musical, will you cram it last minute? (y/n)\n";
          cin >> decision;
          if (decision == 'y' || decision == 'Y'){
            responsibility++;
            wise++;
          }
          else{
            responsibility--;
            happiness--;
          }
        }
        else if (rando2 == 2){
          cout << "Your principal accuses you of doing drugs in the washroom, did you do it? (y/n)\n";
          cin >> decision;
          if (decision == 'y' || decision == 'Y'){
            wise -= 2;
            happiness--;
            responsibility--;
          }
          else{
            wise++;
            happiness++;
            responsibility++;
          }
        }
        else if (rando2 == 3){
          cout << "Your band teacher says you stole some guitar picks, did you do it? (y/n)\n";
          cin >> decision;
          cout << "\nThey don't believe you, too bad.\n";
          happiness--;
          wise++;
        }
        else if (rando2 == 4){
          cout << "Your significant other says they saw you cheating, did you do it? (y/n)\n";
          cin >> decision;
          if (decision == 'y' || decision == 'Y'){
            happiness++;
            wise--;
            responsibility--;
          }
          else{
            responsibility++;
          }
        }
        else if (rando2 == 5){
          cout << "Your chemistry teacher is away on vacation and\n"
               << "the substitute only teaches P.E. and has \n"
               << "no experience with this. Your friends are \n"
               << "horseplayers and knock acid onto you. Do you\n"
               << "tell the teacher? (y/n)\n";
          cin >> decision;
          if (decision == 'y' || decision == 'Y'){
            cout << "The sub tried to make you run it off. You died.\n";
            p.alive = 0;
          }
          else{
            cout << "You used baking soda to reduce the pH level of the solution!\n";
            smart += 3;
            responsibility += 3;
            wise += 2;
          }
        }
        else if (rando2 == 6){
          cout << "You're behind in all of your classes, do you\n"
               << "want to quit your job? (y/n)\n";
          cin >> decision;
          if (decision == 'y' || decision == 'Y'){
            p.job = u;
            responsibility--;
            p.currency -= 200;
            wise++;
            happiness++;
            smart++;
          }
          else{
            wise--;
            smart--;
            happiness--;
            responsibility++;
          }
        }
        else if (rando2 == 7){
          cout << "Your teacher is looking at you seductively\n"
               << "do you follow? (y/n)\n";
          cin >> decision;    
          if (decision == 'y' || decision == 'Y'){
            cout << "You two are hooked!\n";
            p.rstatus = "taken";
            happiness += 2;
            responsibility--;
            wise--;
            smart++;
          }
          else{
            cout << "You missed out, good choice.\n";
            responsibility += 3;
            wise += 2;
          }
        }
        else if (rando2 == 8){
          cout << "Someone broke into your house and stole your PS4,\n"
               << "there are DNA traces on your bed and you can take\n"
               << "this to court, do you? (y/n)\n";
          cin >> decision; 
          if (decision == 'y' || decision == 'Y'){
            cout << "That cost 3000 dollars, you got your PS4 back though!\n";
            p.currency -= 3000;
            smart--;
            responsibility++;
            wise++;
            happiness++;
          }
          else{
            cout << "You lost a PS4 but that might have been for the best!\n";
            smart++;
            responsibility--;
            wise--;
            happiness--;
          }
        }
        else{
          cout << "Your friends got some sick new sneakers, do you\n"
               << "want to get some Obsidian 11s to outplay them? (y/n)\n";
          cin >> decision;
          if (decision == 'y' || decision == 'Y'){
            cout << "That was $255 wow! They think they're sick!\n";
            smart--;
            responsibility--;
            wise--;
            happiness += 2;
          }
          else{
            cout << "You definitely didn't impress them, you still\n"
                 << "got lunch money though! (hopefully)\n";
            smart++;
            responsibility++;
            wise++;
          }
        }

      }
    }
    
    if(p.age == 18){
      cout << "You are graduating highschool!\n";
    }

    if(p.age >= 18 && p.major.compare(u) == 0 && p.age % 5 == 0){
      decision = 0;
      cout << "Will you be going to post-secondary? (y/n)\n";
      cin >> decision; 
      if (decision == 'y' || decision == 'Y'){
        if (smart < 3 || responsibility < 5 ){
        cout << "You do not meet the qualifications for post-secondary :(\n"
             <<"You will have to find a job\n\n";
        happiness--; 
        } 
        else{
          cout << "You are set to start post-secondary in the fall\n\n";    
          p.major = major[rand()%15];
          cout << "You will will be majoring in " << p.major << "\n\n";
          p.currency -= 35000;
          happiness -= 5;
          smart += 3; 
          p.job = "unemployed";
          p.agemajor = p.age;
        }
      }
      else{
        happiness++;
        }
      }      

    if(p.age > 18 && p.age % 4 == 0 && p.major.compare(u) == 0){
      int rando3 = rand() % 6;
      decision = 0; 
      if(rando3 == 0){
        cout << "Your cousin is selling stocks.\nWould you like to learn about the stock market?(y/n)\n";
        cin >> decision; 
        if (decision == 'y' || decision =='Y'){
          smart++; 
          p.currency += 50; 
        }
      }
        
      else if(rando3 == 1){
        cout << "You get mugged in the street, do you fight them?(y/n)\n";
        cin >> decision;
        if (decision == 'y' || decision == 'Y'){
          if (rand() % 40 == 8){
            cout << "You got killed.\n";
          }
          else{
            cout << "You fought them off, and got your money back!\n";
            wise++;
            responsibility++;
            happiness++;
            smart++;
          }
        }
        else{
          cout << "You just lost $100\n";
          p.currency -= 100;
          happiness--;
          wise++;
          responsibility--;
        }
      }
      else if(rando3 == 2){
        cout << "You are invited to a party during a pandemic.\nDo you attend the party?(y/n)\n";
        cin >> decision; 
        if (decision == 'y' || decision == 'Y'){
          wise--; 
          responsibility--;
          happiness++; 
        }
        else 
          smart++;
      }
      else if(rando3 == 3){
        cout << "Jehovah's witness has come to your door for the\nfourth time "
             << "this week, do you file a restraining order?(y/n)\n";
        cin >> decision;
        if (decision == 'y' || decision == 'Y'){
          smart++;
          happiness++;
          wise++;
          responsibility++;
          p.currency -= 500; 
        }
        else{
          smart--;
          happiness--;
          wise--;
          responsibility--;
        }
      }
      else if(rando3 == 4){
        cout << "You go on vacation and the pilot is losing control, do you\n"
             << "help the pilot out?(y/n)\n";
        cin >> decision;
        if (decision == 'y' || decision == 'Y'){
          
        }
        else{
          cout << "You fell into the Mariana's Trench, goodbye.\n";
          p.alive = 0;
        }
      }
      else if(rando3 == 5){
        cout << "You go to the casino, do you go to the slot machines? (y/n)\n";
        cin >> decision;
        if (decision == 'y' || decision == 'Y'){
          if (rand() % 5 == 2){
            cout << "You won $3000!\n";
            p.currency += 3000;
            happiness += 3;
            responsibility -= 2;
            wise -= 2;
          }
          else{
            cout << "You went to the buffet and ate A LOT\n";
            p.currency -= 200;
            happiness++;
            responsibility--;
          }
        }
      }
    }
    
    if (p.age > 20)
      wise++; 

    if(p.agemajor != 0 && p.age >= p.agemajor + 5 && p.major.compare(u) == 0){
      p.job = u; 
      cout << "You have finished your degree!\n";
    }

    if(p.age >= 23 && p.career.compare(u) == 0 && p.agemajor != 0 && p.age >= p.agemajor + 5){
      decision = 0;
      cout <<"Would you like to find a full time job? (y/n)\n";
      cin >> decision;
      smart += 4;
      if (decision == 'y' || decision == 'Y'){
        p.career = career[rand()%30];
        p.currency += 50000;
      }
    }
    
    if (p.age == 27){
      decision = 0;
      cout <<"Do you want to marry someone? (y/n)\n";
      cin >> decision;
      if (decision == 'y' || decision == 'Y'){
        p.currency -= 3000;
        responsibility++;
        happiness++;
        p.rstatus = "Taken";
      }
    } 
    
    if (p.age > 18 && p.rstatus.compare("Taken") == 0 && rand()% 10 == 7){
      decision = 0;
      cout << "You are expecting! Do you choose to keep the child? (y/n)\n";
      cin >> decision;
        if (decision == 'y' || decision == 'Y')
          p.currency -= 25000;
          responsibility++; 
          happiness+=10; 
          wise++; 
    }
  }
  return p; 
}