#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include "item.h"
#include "property.h"

class monster;
class smallmonster;


class monster{
    private:
        int property;
        int HP,attack,defence;
    public:
        void setattack(int attack){
            this->attack=attack;
        }
        int showattack(){
            return attack;
        }
        void setdefence(int defence){
            this->defence=defence;
        }
        int showdefence(){
            return defence;
        }
        void setHP(int HP){
            this->HP=HP;
        }
        void changeHP(int change){
            this->HP-=change;
        }
        int showHP(){
            return HP;
        }
        void setproperty(int property){
            this->property=property;
        }
        string showproperty(){
            if(this->property==1){
                return "water";
            }
            else if(this->property==2){
                return "fire";
            }
            else if(this->property==3){
                return "grass";
            }
            else if(this->property==0){
                return "normal";
            }

    }
};


class smallmonster:public monster{
    public:
    smallmonster(int attack=10,int defence=30,int HP=50,int property=0){
        setattack(attack);
        setdefence(defence);
        setHP(HP);
        setproperty(property);
    }
    void fight(int &p_attack,int &p_defence,int &p_HP,int &result,int defeat_times){
        cout<<"Battle start"<<endl;
        bool battle=1;
        result=0;
        setattack(10+defeat_times*30);
        setdefence(30+defeat_times*40);
        setHP(50+defeat_times*70);
        string choice;
        int monster_choice;
        int accumulation=0;
        int cause_attack;
        srand(time(NULL));
        while(battle){
                bool monsterattack=false;
                bool monsterdefence=false;
                monster_choice=(rand()%3+1);
                if(monster_choice==1){
                    monsterattack=true;
                }
                else if(monster_choice==2){
                    monsterdefence=true;
                }
                else{
                    monsterattack=false;
                    monsterdefence=false;
                }
                cout<<"--------You---Monster---"<<endl;
                cout<<" Attack "<<p_attack<<"     "<<showattack()<<endl;
                cout<<"Defence "<<p_defence<<"     "<<showdefence()<<endl;
                cout<<"   HP   "<<p_HP<<"    "<<showHP()<<endl;
                cout<<"I have "<<accumulation<<" energy (you can't attack your opponent if your energy is 0)"<<endl;
                cout<<"------------------------------"<<endl;
                cout<<"What do you want to do?"<<endl;
                cout<<"1.Attack"<<endl;
                cout<<"2.Defence"<<endl;
                cout<<"3.Accumulate energy"<<endl;
                cout<<"4.Run away"<<endl;
                cin>>choice;
                if(choice=="1"||choice=="A"||choice=="a"){
                    if(accumulation==0){
                        cout<<"Sorry, you don't have enough energy"<<endl;
                        continue;
                    }
                    else if(monsterdefence){
                        cout<<"Small monster use defence."<<endl;
                        if(showdefence()>=accumulation*(p_attack)){
                            cout<<"Your attack deals 0 point of damage to the small monster."<<endl;
                        }
                        else{
                            changeHP(accumulation*(p_attack)-showdefence());
                            cout<<"Your attack deals "<<accumulation*(p_attack)-showdefence()<<" points of damage to the small monster."<<endl;
                        }
                        accumulation=0;
                        if(showHP()<=0){
                            cout<<"The small monster has died"<<endl;
                            cout<<"You win!!!!!!"<<endl;
                            cout<<"Your attack,defence +20,HP and HP limit+50"<<endl;
                            result=1;
                            battle=false;
                            return;
                        }
                        continue;

                    }
                    else if(monsterattack){
                        cout<<"Your attack deals "<<accumulation*(p_attack)<<" points of damage to the small monster"<<endl;
                        cout<<endl;
                        changeHP(accumulation*(p_attack));
                        accumulation=0;
                        if(showHP()<=0){
                            cout<<"The small monster has died"<<endl;
                            cout<<"You win!!!!!!"<<endl;
                            cout<<"Your attack,defence +20,HP and HP limit+50"<<endl;
                            result=1;
                            battle=false;
                            return;
                        }
                        if(monsterattack){
                            cout<<"You are attacked by the small monster"<<endl;
                            p_HP-=showattack();
                            if(p_HP<=0){
                                p_HP=0;
                                cout<<"Your are dead"<<endl;
                                return;
                            }
                        }
                    }
                    else{
                        cout<<"Your attack deals "<<accumulation*(p_attack)<<" points of damage to the small monster"<<endl;
                        changeHP(accumulation*(p_attack));
                        accumulation=0;
                        if(showHP()<=0){
                            cout<<"The small monster has died"<<endl;
                            cout<<"You win!!!!!!"<<endl;
                            cout<<"Your attack,defence +20,HP and HP limit+50"<<endl;
                            result=1;
                            battle=false;
                            return;
                        }
                    }
                }
                else if(choice=="2"||choice=="B"||choice=="b"){
                    if(monsterattack){
                        if(p_defence>=showattack()){
                            cout<<"You successfully defend against its attack"<<endl;
                        }
                        else if(p_defence<showattack()){
                            cout<<"You still receive some damage"<<endl;
                            p_HP-=(showattack()-p_defence);
                        }
                    }
                    else if(monsterdefence){
                        cout<<"Both of you and small monster use defence"<<endl;
                    }
                    else if(!monsterattack&&!monsterdefence){
                        cout<<"The small monster do nothing"<<endl;
                    }
                }
                else if(choice=="3"||choice=="C"||choice=="c"){
                    accumulation+=1;
                    if(monsterattack){
                        cout<<"You are attacked by the small monster"<<endl;
                        p_HP-=showattack();
                        if(p_HP<=0){
                            p_HP=0;
                            cout<<"Your are dead"<<endl;
                            return;
                        }
                    }
                    else if(monsterdefence){
                        cout<<"The small monster use defence"<<endl;
                    }
                    else if(!monsterattack&&!monsterdefence){
                        cout<<"The small monster do nothing"<<endl;
                    }
                }
                else if(choice=="4"||choice=="D"||choice=="d"){
                    cout<<"You have run away"<<endl;
                    battle=false;
                }
                else{
                    cout<<"Invalid input"<<endl;
                }
        }
    }

};


class NPC{
    private:
        string name;
    public:
        void setname(string name){
            this->name=name;
        }
        string showname(){
            return name;
        }
        virtual void say_lines()=0;
};

class Brock:public NPC{
    public:
        void say_lines()override{
            cout<<"Hello I'm Brock,do you want to trade with me?"<<endl;
        }
        void _do(int &money,int &attack,int &defence){
            cout<<"1.spend 5 dollars:attack+20"<<endl;
            cout<<"2.gamble(benefit or harm),guess 1 or 2"<<endl;
            cout<<"3.left"<<endl;
            while(1){
            string choice;
            string choice2;
            cin>>choice;
                if(choice=="1"||choice=="A"||choice=="a"){
                    cout<<"Your attack +20"<<endl;
                    money-=5;
                    attack+=20;
                    break;
                }
                else if(choice=="2"||choice=="B"||choice=="b"){
                    while(1){
                        cout<<"Enter your choice(1 or 2):";
                        cin>>choice2;
                        if(choice2=="1"||choice2=="A"||choice2=="a"){
                            cout<<"Your defence -10"<<endl;
                            defence-=10;
                            break;
                        }
                        else if(choice2=="2"||choice2=="B"||choice2=="b"){
                            cout<<"Your defence +10"<<endl;
                            defence+=10;
                            break;
                        }
                        else{
                            cout<<"Invalid input"<<endl;
                        }
                    }
                    break;
                }
                else if(choice=="3"||choice=="C"||choice=="c"){
                    return;
                }
                else{
                    cout<<"Invalid input"<<endl;
                }
            }
        }

};

class Team_Rocket_member:public NPC{
    public:
        void say_lines()override{
            cout<<"I am a Team Rocket member, and I will steal something from you."<<endl;
            cout<<"(You have no other choice but give him/her your food or water)"<<endl;
        }
        void _do(int &food,int &water){
            string choice;
            while(1){
                cout<<"1.food-20"<<endl;
                cout<<"2.water-20"<<endl;
                cout<<"My choice is: ";
                cin>>choice;
                if(choice=="1"||choice=="A"||choice=="a"){
                    cout<<"Your food -20"<<endl;
                    food-=20;
                    return;
                }
                else if(choice=="2"||choice=="B"||choice=="b"){
                    cout<<"Your water -20"<<endl;
                    water-=20;
                    return;
                }
                else{
                    cout<<"Invalid input"<<endl;
                }
            }
        }
};

class Esther:public NPC{
    public:
        void say_lines()override{
            cout<<"Hello, my name is Esther.Do you want to trade or fight with me?"<<endl;
        }
        void _do(int &attack,int &defence,int &HP,int &money){
            string choice;
            cout<<"1.fight(you will get 60$ if you win)"<<endl;
            cout<<"2.trade with me"<<endl;
            cout<<"3.left"<<endl;
            srand(time(NULL));
            bool battle=true;
            while(battle){
                cout<<"My choice is :";
                cin>>choice;
                if(choice=="1"||choice=="A"||choice=="a"){
                    int Esther_attack=50;
                    int Esther_defence=120;
                    int Esther_HP=400;
                    cout<<"Battle start"<<endl;
                    battle=true;
                    string choice1;
                    int monster_choice;
                    int accumulation=0;
                    int cause_attack;
                    while(battle){
                        bool monsterattack=false;
                        bool monsterdefence=false;
                        monster_choice=(rand()%2+1);
                        if(monster_choice==1){
                            monsterattack=true;
                            monsterdefence=false;
                        }
                        else if(monster_choice==2){
                            monsterattack=false;
                            monsterdefence=true;
                        }
                    cout<<"--------You---Esther---"<<endl;
                    cout<<" Attack "<<attack<<"     "<<Esther_attack<<endl;
                    cout<<"Defence "<<defence<<"     "<<Esther_defence<<endl;
                    cout<<"   HP   "<<HP<<"    "<<Esther_HP<<endl;
                    cout<<"My energy :"<<accumulation<<"(you can't attack your opponent if your energy is 0)"<<endl;
                    cout<<"------------------------------"<<endl;
                    cout<<"What do you want to do?"<<endl;
                    cout<<"1.Attack"<<endl;
                    cout<<"2.Defence"<<endl;
                    cout<<"3.Accumulate energy"<<endl;
                    cout<<"4.Run away"<<endl;
                cin>>choice1;
                if(choice1=="1"||choice1=="A"||choice1=="a"){
                    if(accumulation==0){
                        cout<<"Sorry, you don't have enough energy"<<endl;
                        continue;
                    }
                    else if(monsterdefence){
                        cout<<"Esther use defence."<<endl;
                        if(Esther_defence>=accumulation*(attack)){
                            cout<<"Your attack deals 0 point of damage to Esther."<<endl;
                        }
                        else{
                            Esther_HP-=(accumulation*(attack)-Esther_defence);
                            cout<<"Your attack deals "<<accumulation*(attack)-Esther_defence<<" points of damage to Esther."<<endl;
                        }
                        accumulation=0;
                        if(Esther_HP<=0){
                            cout<<"Esther has died"<<endl;
                            cout<<"You win!!!!!!"<<endl;
                            cout<<"You get 60$"<<endl;
                            money+=60;
                            battle=false;
                            return;
                        }
                        continue;

                    }
                    else if(monsterattack){
                        cout<<"Your attack deals "<<accumulation*(attack)<<" points of damage to the Esther"<<endl;
                        cout<<endl;
                        Esther_HP-=(accumulation*(attack));
                        accumulation=0;
                        if(monsterattack){
                            cout<<"You are attacked by the Esther"<<endl;
                            HP-=Esther_attack;
                            if(HP<=0){
                                HP=0;
                                cout<<"Your are dead"<<endl;
                                return;
                            }
                        }
                        if(Esther_HP<=0){
                            cout<<"The Esther has died"<<endl;
                            cout<<"You win!!!!!!"<<endl;
                            cout<<"You get 60$"<<endl;
                            money+=60;
                            battle=false;
                            return;
                        }
                    }
                }
                    else if(choice1=="2"||choice1=="B"||choice1=="b"){
                        if(monsterattack){
                        if(defence>=Esther_attack){
                            cout<<"You successfully defend its attack"<<endl;
                        }
                        else if(defence<Esther_attack){
                            cout<<"You defend "<<(defence-Esther_attack)<<" points"<<endl;
                            HP-=(defence-Esther_attack);
                        }
                    }
                        else if(monsterdefence){
                            cout<<"Both of you and Esther use defence"<<endl;
                        }
                    }
                    else if(choice1=="3"||choice1=="C"||choice1=="c"){
                        accumulation+=1;
                        if(monsterattack){
                            cout<<"You are attacked by Esther"<<endl;
                            HP-=Esther_attack;
                            if(HP<=0){
                                HP=0;
                                cout<<"Your are lose"<<endl;
                                return;
                            }
                        }
                        else if(monsterdefence){
                            cout<<"Esther use defence"<<endl;
                        }
                    }
                    else if(choice1=="4"||choice1=="D"||choice1=="d"){
                        cout<<"You have run away"<<endl;
                        battle=false;
                    }
                    else{
                        cout<<"Invalid input"<<endl<<endl;
                        }
                    }
                }
                else if(choice=="2"||choice=="B"||choice=="b"){
                    while(1){
                        battle=false;
                        cout<<"-----------------------------------------------------"<<endl;
                        cout<<"1.attack+30 (spend 10$)"<<endl;
                        cout<<"2.defence+40 (spend 15$)"<<endl;
                        cout<<"3.get 15$"<<endl;
                        string mychoice;
                        cout<<"My choice is:";
                        cin>>mychoice;
                        if(mychoice=="1"||mychoice=="A"||mychoice=="a"){
                            attack+=30;
                            money-=10;
                            return;
                        }
                        else if(mychoice=="2"||mychoice=="B"||mychoice=="b"){
                            defence+=40;
                            money-=15;
                            return;
                        }
                        else if(mychoice=="3"||mychoice=="C"||mychoice=="c"){
                            money+=15;
                            return;
                        }
                        else{
                            cout<<"Invalid input"<<endl;
                        }
                    }
                }
                else if(choice=="3"||choice=="C"||choice=="c"){
                    return;
                }
                else{
                    cout<<"Invalid input"<<endl<<endl;
                }
             }
        }
};

class Pokemon_helper:public NPC{
    public:
        void say_lines()override{
            cout<<"Hello, I am a Pokemon helper. I can give you a hand. What do you need?"<<endl;
        }
        void _do(int &money,int& food,int &water){
            while(1){
                string choice;
                cout<<"1.get 20 money"<<endl;
                cout<<"2.get 80 food"<<endl;
                cout<<"3.get 80 water"<<endl;
                cout<<"My choice is :";
                cin>>choice;
                if(choice=="1"||choice=="A"||choice=="a"){
                    money+=20;
                    return;
                }
                else if(choice=="2"||choice=="B"||choice=="b"){
                    food+=80;
                    return;
                }
                else if(choice=="3"||choice=="C"||choice=="c"){
                    water+=80;
                    return;
                }
                else{
                    cout<<"Invalid input"<<endl<<endl;
                }
            }
        }

};
class Nurse_Joey:public NPC{
    public:
        void say_lines() override{
            cout<<"I¡¦m Nurse Joey,do you need some help?(spend 10 dollars)"<<endl;
        }
        void _do(int &money,int &HP,int &HP_limit,int &poison){
            string choice;
            while(1){
                cout<<"1.get full HP"<<endl;
                cout<<"2.Detoxify(poison become 0)"<<endl;
                cout<<"3.No,I'm ok"<<endl<<endl;
                cout<<"My choice is :";
                cin>>choice;
                if(choice=="1"||choice=="A"||choice=="a"){
                    money-=10;
                    HP=HP_limit;
                    cout<<"You have been cured"<<endl;
                    return;
                }
                else if(choice=="2"||choice=="B"||choice=="b"){
                    money-=10;
                    poison=0;
                    cout<<"You have been detoxified"<<endl;
                }
                else if(choice=="3"||choice=="C"||choice=="c"){
                    cout<<"Nurse Joey: Bye bye"<<endl;
                    return;
                }
                else{
                    cout<<"Invalid input"<<endl<<endl;
                }
            }
        }
};

class Pokemon_hunter:public NPC{
    public:
    void say_lines() override{
        cout<<"I am a Pokemon hunter. You've just been poisoned by me."<<endl;
    }
    void _do(int &poison){
        cout<<"You are poisoned now"<<endl;
        poison+=10;
    }
};

class Boss{
    private:
        string name;
        int attack,defence,HP;
        int elemental_type;
    public:
        void setname(string name){
            this->name=name;
        }
        string showname(){
            return name+" Boss";
        }
        void setattack(int attack){
            this->attack=attack;
        }
        int showattack(){
            return attack;
        }
        void changeattack(int change){
            this->attack+=change;
        }
        void setdefence(int defence){
            this->defence=defence;
        }
        int showdefence(){
            return defence;
        }
        void changedefence(int change){
            this->defence+=change;
        }
        void setHP(int HP){
            this->HP=HP;
        }
        int showHP(){
            return HP;
        }
        void setelemental_type(int type){
            this->elemental_type=type;
        }
        string show_elemental_type(){
            if(this->elemental_type==1){
                return "water";
            }
            else if(this->elemental_type==2){
                return "fire";
            }
            else if(this->elemental_type==3){
                return "grass";
            }
        }
};
