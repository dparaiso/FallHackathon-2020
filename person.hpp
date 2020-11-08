#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

struct person {
  long long int currency;
  std::string name;
  std::string hair; 
  std::string g;
  unsigned int age;
  std::string career; 
  std::string job; 
  std::string major; 
  std::string rstatus;
  int agemajor;
  bool alive;
};

struct birthday{
  long unsigned int year;
  unsigned int month; 
  unsigned int day; 
  std::string astrology;
};

birthday set_birthday();

const string haircolor[5] = { "Black", "Blonde", "Brown", "Red", "Dirty Blonde"};

const string gender[3] = {"Male", "Female", "Other"};

const string firstNames[20] = {"Greg", "Joe", "Bo", "Jesus", "Justin", "Victor","Danieva","Sina","Francis", "Osama", "Theresa", "Meredith", "Steve", "Bill", "Julie", "Sharon", "Mary", "Anna", "Justine", "Karen"};

const string lastNames[20] = {" Fang", " Lee", " Mateo", " Paraiso", " Haghighi", " Brown", " Parker"," Glottenmeyre", " McLeod", " Jackson", " Bin Laden", " Garcia", " Davis", " Martinez", " Nelson", " Olajuwon", " Jordan", " Robertson", " Horvat", " Cosby"};

const string major[15] = {"Computer Science", "Engineering", "Health Science", "Psychology", "Art", "Theatre", "Mathematics", "Physics", "Business", "Education", "Architecture", "Criminology", "Accounting", "IT"};

const string job[15] = {"Tim Hortons", "McDonalds", "Walmart", "Save-on-Foods", "Burger King", "Starbucks", "Togo Sushi", "Marble Slab", "Cold Stone", "Extreme Air Park", "Apex", "PNE", "Host", "Stripper In Training", "Wendy's"};

const string career[30] = {"Computer Engineer", "Software Engineer", "Electronics Engineer", "Politician", "Mechanical Engineer", "Civil Engineer", "Thug", "Biomedical Engineer", "Stripper", "Prostitute", "Hooters Server", "Chemical Engineer", "Electrician", "Depressed Computer Scientist", "Doctor", "Lawyer", "Physicist", "Hippie", "Bezos", "Musician", "Actor", "Chef", "Rapist Therapist", "IT Developer", "Influencer", "Banker", "Astronaut", "Builder", "Technical Support", "Nurse"};

const string deaths[10] = {"getting hit by battle bus", "getting hit by a submarine"  "getting struck by lighting that einstein caused", "getting executed", "smelling someone's fart", "eating too many samosas", "sharting too much", "giving it to your cousin", "supporting Trump and Melania", "catching COVID"};

birthday set_birthday(){
  birthday theBirth;
  srand( (unsigned)time(NULL) );
  int rmonth = rand() % 11 + 1;
  int ryear = rand() % 100 + 1950; 
  int rday; 

  //calculates birthday
  if (rmonth == 2)
    rday = rand() % 27 + 1;
  else if(rmonth % 2 == 1)
    rday = rand() % 30 + 1;
  else 
    rday = rand() % 29 + 1;

  //sets the birthday 
  theBirth.day = rday; 
  theBirth.year = ryear; 
  theBirth.month = rmonth;

  //calculates astrological sign
  string zodiac;
  if (rmonth == 1){
    if(rday <= 19)
      zodiac = "Capricorn";
    else
      zodiac = "Aquarius";
  }
  if (rmonth == 2){
    if(rday <= 18)
      zodiac = "Aquarius";
    else
      zodiac = "Pisces";
  }
  if (rmonth == 3){
    if(rday <= 20)
      zodiac = "Pisces";
    else
      zodiac = "Aries";
  }
  if (rmonth == 4){
    if(rday <= 19)
      zodiac = "Aries";
    else
      zodiac = "Taurus";
  }
  if (rmonth == 5){
    if(rday <= 20)
      zodiac = "Taurus";
    else
      zodiac = "Gemini";
  }
  if (rmonth == 6){
    if(rday <= 20)
      zodiac = "Gemini";
    else
      zodiac = "Cancer";
  }
  if (rmonth == 7){
    if(rday <= 22)
      zodiac = "Cancer";
    else
      zodiac = "Leo";
  }
  if (rmonth == 8){
    if(rday <= 22)
      zodiac = "Leo";
    else
      zodiac = "Virgo";
  }
  if (rmonth == 9){
    if(rday <= 22)
      zodiac = "Virgo";
    else
      zodiac = "Libra";
  }
  if (rmonth == 10){
    if(rday <= 22)
      zodiac = "Libra";
    else
      zodiac = "Scorpio";
  }
  if (rmonth == 11){
    if(rday <= 21)
      zodiac = "Scorpio";
    else
      zodiac = "Sagittarius";
  }
  if (rmonth == 12){
    if(rday <= 21)
      zodiac = "Sagittarius";
    else
      zodiac = "Capricorn";
  }

  theBirth.astrology = zodiac;
  return theBirth;
}
