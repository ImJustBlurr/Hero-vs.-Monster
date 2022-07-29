#include <stdio.h>
#include <stdlib.h>

//Defining Prototypes
void printYouWin();
void printYouLose();
int monsterAttacks();
int heroAttacks(int weaponCode);

int main(void) {
  //Defining Variables
  int heroHealth = 30;
  int monsterHealth = 30;
  int code;
  int heroDmg;
  int monsterDmg;
  int rounds = 1;

  //The games main iteration
  while(heroHealth != 0 || monsterHealth != 0){

    //Computation of attacks and health
    code = rand() % 3;
    
    heroDmg = heroAttacks(code);
    monsterHealth -= heroDmg;

    
    
    monsterDmg = monsterAttacks();
    heroHealth -= monsterDmg;

    //Output to user
    printf("-------------------------------------------------------------------------------\n");
    printf("ROUND %d\n", rounds);
    printf("The hero is fighting with a ");
    
    switch(code){ //Displays correct weapon
      case 0:
        printf("Fist!\n");
        break;
    
      case 1:
        printf("Sword!\n");
        break;
    
      case 2:
        printf("Gun!\n");
        break;
    }

    printf("Hero attacks with %d damage; %45s %d HP\n", heroDmg, "Monster's health is ", monsterHealth);
    
    if(monsterHealth <= 0){
      break;
    }

    printf("Monster attacks with %d damage; %39s %d HP\n", monsterDmg, "Hero's health is ", heroHealth);

    rounds++;
  }
  
}

void printYouWin(){
  
}

void printYouLose(){
  
}

int monsterAttacks(){
  int dmg = (rand() % 6) + 1;
  
  if(dmg == 6){
    dmg += 2;
  }
  
  if(dmg == 1){
    dmg -= 1;
  }
  
  return dmg;
}

int heroAttacks(int weaponCode){
  int dmg = (rand() % 5) + 1;
  
  switch(weaponCode){
    case 0:
      dmg -= 1;
      break;
    
    case 1:
      dmg += 1;
      break;
    
    case 2:
      dmg += 3;
      break;
  }

  return dmg;
}