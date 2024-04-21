#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include "character.h"
#include "1A1B.h"
using namespace std;

int what_to_do(){
    int check=1;
    string choice;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"What do you want to do?"<<endl;
    cout<<"A.Move"<<endl;
    cout<<"B.Check Status"<<endl;
    cout<<"C.Talk to Shop"<<endl;
    cout<<"D.Open Backpack"<<endl;
    cout<<"E.Show some game hints"<<endl;
    while(check){
        cin>>choice;
        if(choice=="A"||choice=="a"||choice=="1"){
            check=0;
            return 1;
        }
        else if(choice=="B"||choice=="b"||choice=="2"){
            check=0;
            return 2;
        }
        else if(choice=="C"||choice=="c"||choice=="3"){
            check=0;
            return 3;
        }
        else if(choice=="D"||choice=="d"||choice=="4"){
            check=0;
            return 4;
        }
        else if(choice=="E"||choice=="e"||choice=="5"){
            check=0;
            return 5;
        }
        else{
            cout<<"Invalid input,please input again."<<endl;
            check=1;
        }
    }
}

int _what_to_do(){
    int check=1;
    string choice;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"What do you want to do?"<<endl;
    cout<<"A.Move"<<endl;
    cout<<"B.Check Status"<<endl;
    cout<<"C.Talk to Shop"<<endl;
    cout<<"D.Open Backpack"<<endl;
    cout<<"E.Show some game hints"<<endl;
    cout<<"F.Challenge the Boss(you can't run away)"<<endl;
    while(check){
        cin>>choice;
        if(choice=="A"||choice=="a"||choice=="1"){
            check=0;
            return 1;
        }
        else if(choice=="B"||choice=="b"||choice=="2"){
            check=0;
            return 2;
        }
        else if(choice=="C"||choice=="c"||choice=="3"){
            check=0;
            return 3;
        }
        else if(choice=="D"||choice=="d"||choice=="4"){
            check=0;
            return 4;
        }
        else if(choice=="E"||choice=="e"||choice=="5"){
            check=0;
            return 5;
        }
        else if(choice=="F"||choice=="f"||choice=="6"){
            check=0;
            return 6;
        }
        else{
            cout<<"Invalid input,please input again."<<endl;
            check=1;
        }
    }
}


void where_to_go(int &position1,int &position2){
    int check=1;
    string choice;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"Where do you want to go?"<<endl;
    cout<<"A.Go up"<<endl;
    cout<<"B.Go down"<<endl;
    cout<<"C.Go left"<<endl;
    cout<<"D.Go right"<<endl;
    cout<<"E.Go back to pokemon center(0,0)"<<endl;
    while(check){
        cin>>choice;
        if(choice=="A"||choice=="a"||choice=="1"){
            check=0;
            position2+=1;
            return;
        }
        else if(choice=="B"||choice=="b"||choice=="2"){
            check=0;
            position2-=1;
            return;
        }
        else if(choice=="C"||choice=="c"||choice=="3"){
            check=0;
            position1-=1;
            return;
        }
        else if(choice=="D"||choice=="d"||choice=="4"){
            check=0;
            position1+=1;
            return;
        }
        else if(choice=="E"||choice=="e"||choice=="5"){
            check=0;
            position1=0;
            position2=0;
            return;
        }
        else{
            cout<<"Invalid input,please input again."<<endl;
            check=1;
        }
    }
}

bool knowmyphonenumber=false;
void showgame_hints(){
    cout<<"--------------------------------"<<endl;
    cout<<"What do you want to know"<<endl;
    cout<<"1.How to win"<<endl;
    cout<<"2.About battle"<<endl;
    cout<<"3.About food and water"<<endl;
    cout<<"4.About environment"<<endl;
    cout<<"5.About weapon"<<endl;
    cout<<"6.About elemental type"<<endl;
    cout<<"7.How to earn money"<<endl;
    cout<<"8.About NPC"<<endl;
    cout<<"9.My IG "<<endl;
    cout<<"10.My Phone number"<<endl<<endl;
    string choice;
    cout<<"I want to know :";
    cin>>choice;
    if(choice=="A"||choice=="a"||choice=="1"){
        cout<<"--------------------------------"<<endl;
        cout<<"In this game, you may encounter small monsters on the road"<<endl;
        cout<<"If you defeat a small monster, the count of 'monsters you have beaten' will increase by 1"<<endl;
        cout<<"If you have defeated more than five monsters, you will have the chance to fight the Boss"<<endl;
        cout<<"After you defeat the Boss, you will win the game"<<endl;
        cout<<endl;
    }
    else if(choice=="B"||choice=="b"||choice=="2"){
        cout<<"--------------------------------"<<endl;
        cout<<"During battle, you can choose from three actions:"<<endl;
        cout<<"1.attack / 2.defence /3.accumulate energy"<<endl;
        cout<<"Considering the count of your attack, you can cause damage to the monster by pausing (the energy you have accumulated)*attack"<<endl;
        cout<<"If you use defence, you can mitigate the damage from the monster's attack based on your count of defence"<<endl;
        cout<<endl;
        cout<<"small monster has three actions:"<<endl;
        cout<<"1.attack / 2.defence / 3.do nothing"<<endl;
        cout<<endl;
        cout<<"NPC has only two actions:"<<endl;
        cout<<"1.attack / 2.defence"<<endl;
        cout<<endl;
        cout<<"Boss has four actions:"<<endl;
        cout<<"1.attack / 2.defence /3.recover(depend on attack) /4.enhancement(attack+100,defence+50)"<<endl;
    }
    else if(choice=="C"||choice=="c"||choice=="3"){
        cout<<"--------------------------------"<<endl;
        cout<<"After you have no food or water,your HP will start to decrease"<<endl;
        cout<<"The reduction of HP depends on the amount of food or water you originally had to consume"<<endl;
        cout<<"You can obtain food by purchasing or meeting NPC"<<endl;
        cout<<"You can obtain water by purchasing, meeting NPCs, or finding it in the environment"<<endl;
        cout<<endl;
    }
    else if(choice=="D"||choice=="d"||choice=="4"){
        cout<<"--------------------------------"<<endl;
        cout<<"You need to consume varying amounts of food and water depending on the environment"<<endl<<endl;
        cout<<"**1.nullroom(food-4,water-4)**"<<endl;
        cout<<"Nurse Joey appears more frequently"<<endl;
        cout<<"No monster in the nullroom"<<endl<<endl;
        cout<<"**2.Volcano(food-6,water-6)**"<<endl;
        cout<<"weapon 'knife' and 'powerful shield' can be found in this area"<<endl<<endl;
        cout<<"**3.Forest(food-8,water-2)**"<<endl;
        cout<<"Monsters appear more frequently"<<endl;
        cout<<"weapon 'shield' and 'powerful knife' can be found in this area"<<endl;
        cout<<"Pokemon hunter may appear and poison you"<<endl<<endl;
        cout<<"**4.Desert(food-4,water-10)**"<<endl;
        cout<<"weapon 'armor' can be found in this area"<<endl<<endl;
        cout<<"**5.Swamp(food-2,water-2)**"<<endl;
        cout<<"Monsters appear more frequently"<<endl;
        cout<<"It is possible to be poisoned by environment"<<endl<<endl;
        cout<<endl;
    }
    else if(choice=="E"||choice=="e"||choice=="5"){
        cout<<"--------------------------------"<<endl;
        cout<<"All the weapons can be found on the ground.(you have to find them yourself.)"<<endl;
        cout<<"You can use a weapon when you encounter a small monster or a Boss (not useful when fighting with NPCs)"<<endl;
        cout<<"You can only use one weapon at a time"<<endl<<endl;
        cout<<"1.knife(attack+50)"<<endl;
        cout<<"2.shield(defence+50)"<<endl;
        cout<<"3.armor(HP+120)"<<endl;
        cout<<"4.powerful knife(attack+150)"<<endl;
        cout<<"5.powerful shield(defence+120)"<<endl;
        cout<<"6.super armor(HP+300)"<<endl;
    }
    else if(choice=="F"||choice=="f"||choice=="6"){
        cout<<"--------------------------------"<<endl;
        cout<<"water vs fire (attack*1.5)"<<endl;
        cout<<"fire vs grass (attack*1.5)"<<endl;
        cout<<"grass vs water (attack*1.5)"<<endl;
        cout<<"water vs water (attack*1)"<<endl;
        cout<<"fire vs fire (attack*1)"<<endl;
        cout<<"grass vs grass (attack*1)"<<endl;
        cout<<"fire vs water (attack*0.6)"<<endl;
        cout<<"water vs grass (attack*0.6)"<<endl;
        cout<<"grass vs fire (attack*0.6)"<<endl<<endl;
    }
    else if(choice=="G"||choice=="g"||choice=="7"){
        cout<<"Money will drop from the sky."<<endl;
        cout<<"You can get some money from NPC"<<endl;
    }
    else if(choice=="H"||choice=="h"||choice=="8"){
        cout<<"After you meet NPCs or small monsters, they will disappear and never appear in that room again."<<endl;
    }
    else if(choice=="I"||choice=="i"||choice=="9"){
        cout<<" yu_cheng931010 "<<endl;
    }
    else if(choice=="J"||choice=="j"||choice=="10"){
        knowmyphonenumber=true;
        cout<<" You will know my phone number if you win this game. "<<endl;
    }
    else{
        cout<<"Invalid input"<<endl;
    }
}


int main(){
    role pokemon;
    shop shopper;
    bool this_game=1;
    vector <int*> step[2];
    int position[2]={0};
    position[0]=0;/*set position up+ and down-*/
    position[1]=0;/*set position right+ and left-*/
    cout<<"Welcome to the Pokemon game! You now have a Pokemon, and your goal is to make it powerful."<<endl;
    cout<<"The introduction of this game is as follows."<<endl;
    cout<<"Each Pokemon has one elemental type (water, fire or grass), and you can choose your Pokemon's type yourself."<<endl;
    cout<<"(Water counters fire,fire counters grass,grass counters water.)"<<endl;
    cout<<"By evolving, your power will increase dramatically."<<endl;
    cout<<"If you died(HP=0),then you have to play a 1A1B game to revive"<<endl;
    cout<<"If you have no water or food, your HP will start to decrease (losing 5 points with each move)."<<endl;
    cout<<"After successfully defeating a powerful boss, you will emerge victorious"<<endl;
    cout<<"*****Game Start*****"<<endl;
    cout<<endl<<"Please enter your name: ";
    string name;
    cin>>name;
    pokemon.setname(name);
    pokemon.setattack(10);
    pokemon.setHP(300);
    pokemon.setHP_limit(300);
    pokemon.setdefence(10);
    pokemon.setevolving_status(0);
    pokemon.setwater(100);
    pokemon.setfood(100);
    pokemon.setpoison(0);
    pokemon.setbeat_monster(0);
    pokemon.setmoney(30);
    int p[2]={0,0};
    pokemon.setposition(p[0],p[1]);
    step->push_back(p);
    cout<<"Choose your elemental type: "<<endl;
    cout<<"1.Water"<<endl<<"2.Fire"<<endl<<"3.Grass"<<endl;
    string elemental_type;
    while(1){
        cin>>elemental_type;
        if(elemental_type=="1"||elemental_type=="2"||elemental_type=="3"){
            break;
        }
        else{
            cout<<"Invalid input,please input again."<<endl;
            continue;
        }
    }
    int elemental_type1=stoi(elemental_type);
    pokemon.setproperty(elemental_type1);
    cout<<"Start your travel,you are now at the starting point(0,0)."<<endl;
    cout<<"Hint:(x,y),if both x and y are larger than 0,means you are in the Volcano area"<<endl;
    cout<<"Hint:(x,y),if x smaller than 0 but y larger than 0,means you are in the Forest area"<<endl;
    cout<<"Hint:(x,y),if both x and y are smaller than 0,means you are in the Desert area"<<endl;
    cout<<"Hint:(x,y),if x larger than 0 but y smaller than 0,means you are in the Swamp area"<<endl;
    cout<<"Hint:(x,y),if x or y equal to 0,means you are in the Space area(Nothing in this room)"<<endl;
    bool enhancement=false;
    int chance=1;
    bool game_result=false;
    int money_drop;
    int p_money;
    while(this_game){
        bool pass=false;
        int a;
        if(pokemon.showbeat_monster()>=5){
            enhancement=true;
        }
        if(!enhancement){
            a=what_to_do();
        }
        else if(enhancement){
            a=_what_to_do();
        }
        if(a==1){
            if(pokemon.showpoison()){
                cout<<"You are poisoned now"<<endl;
                cout<<"Each poison point will reduce HP by 1 whenever you move."<<endl;
                cout<<"However, your poison will also decrease by 2 whenever you move."<<endl;
                int _HP=pokemon.showHP();
                int _poison=pokemon.showpoison();
                _HP-=pokemon.showpoison();
                pokemon.setHP(_HP);
                _poison-=2;
                pokemon.setpoison(_poison);
            }
            where_to_go(position[0],position[1]);
            pokemon.setposition(position[0],position[1]);
            room newroom;
            newroom=checkposition(pokemon.showposition1(),pokemon.showposition2());
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"You are now in the "<<newroom.showroomname()<<" Area"<<endl;
            cout<<"Your position is ("<<pokemon.showposition1()<<","<<pokemon.showposition2()<<")"<<endl;
            cout<<endl;
            bool check_sandstorm=false;/*sandstorm yes or no*/
            if(pokemon.showposition1()<0&&pokemon.showposition2()<0){
                int sandstorm;
                srand(time(NULL));
                sandstorm=(rand()%5+1);
                if(!check_sandstorm){
                    if(sandstorm==1){
                        check_sandstorm=true;
                        cout<<"A sandstorm appears, causing you to consume more water in the desert area"<<endl;
                        cout<<endl;
                    }
                }
            }
            else{
                check_sandstorm=false;
            }
            if(pokemon.showposition1()<0&&pokemon.showposition2()<0){
                int oasis;
                srand(time(NULL));
                oasis=(rand()%15+1);
                if(oasis==1){
                    cout<<"You find a oasis in the desert"<<endl;
                    cout<<"You get 150 water"<<endl;
                    cout<<endl;
                    pokemon.setwater(pokemon.showwater()+150);
                }
            }
            if(pokemon.showposition1()<0&&pokemon.showposition2()>0){
                int is_lake;
                srand(time(NULL));
                is_lake=(rand()%10+1);
                if(is_lake==1){
                    cout<<"Look! there is a lake in the forest"<<endl;
                    cout<<"You get 100 water."<<endl;
                    pokemon.setwater(pokemon.showwater()+100);
                }
            }
            srand(time(NULL));
            money_drop=(rand()%7+1);
            if(money_drop==1){
                cout<<"You are lucky,money drop from the sky"<<endl;
                cout<<"You get 15$"<<endl;
                p_money=pokemon.showmoney();
                p_money+=15;
                pokemon.setmoney(p_money);
            }
            if(pokemon.showposition1()==2&&pokemon.showposition2()==2){
                cout<<"There is a knife on the ground"<<endl;
                knife a_knife;
                pokemon.setweapon(a_knife);
            }
            if(pokemon.showposition1()==-3&&pokemon.showposition2()==1){
                cout<<"There is a shield on the ground"<<endl;
                shield a_shield;
                pokemon.setweapon(a_shield);
            }
            if(pokemon.showposition1()==-4&&pokemon.showposition2()==-2){
                cout<<"There is an armor on the ground"<<endl;
                armor a_armor;
                pokemon.setweapon(a_armor);
            }
            if(pokemon.showposition1()==-8&&pokemon.showposition2()==3){
                cout<<"There is a powerful knife on the ground"<<endl;
                powerful_knife p_knife;
                pokemon.setweapon(p_knife);
            }
            if(pokemon.showposition1()==9&&pokemon.showposition2()==7){
                cout<<"There is a powerful shield on the ground"<<endl;
                powerful_shield p_shield;
                pokemon.setweapon(p_shield);
            }
            if(pokemon.showposition1()==5&&pokemon.showposition2()==-1){
                cout<<"There is a super armor on the ground"<<endl;
                super_armor s_armor;
                pokemon.setweapon(s_armor);
            }
            int food=pokemon.showfood();
            int water=pokemon.showwater();
            if(pokemon.showfood()<=0){
                cout<<"Your stomach have no food,your HP starts to decrease"<<endl;
                int f_HP=pokemon.showHP();
                newroom.food_HP(f_HP);
                pokemon.setHP(f_HP);
            }
            else{
                newroom.eat(food);
                pokemon.setfood(food);
            }
            if(pokemon.showwater()<=0){
                cout<<"Your body have no water,your HP starts to decrease"<<endl;
                int w_HP=pokemon.showHP();
                newroom.water_HP(w_HP);
                pokemon.setHP(w_HP);
            }
            else{
                newroom.drink(water);
                if(check_sandstorm){
                    water-=10;
                }
                pokemon.setwater(water);
            }
            if(food<=0){
                food=0;
                pokemon.setfood(food);
                cout<<"Your stomach have no food,please eat something"<<endl;
                cout<<"Otherwise,your HP will start to decrease"<<endl;
                cout<<endl;
            }
            if(water<=0){
                water=0;
                pokemon.setwater(water);
                cout<<"Your body have no water,please eat or drink something"<<endl;
                cout<<"Otherwise,your HP will start to decrease"<<endl;
                cout<<endl;
            }
            for (auto a : *step) {
                if (a[0] == position[0] && a[1] == position[1]) {
                    pass = true;
                    break;
                }
            }
            if(!pass){
                pokemon.meet_npc(pokemon.showposition1(),pokemon.showposition2());
            }
            if(!pass){
                int* p1=new int[2];
                p1[0]=pokemon.showposition1();
                p1[1]=pokemon.showposition2();
                step->push_back(p1);
            }
        }
        if(a==2){
            cout<<endl;
            pokemon.show_all_status();
        }
        if(a==3){
            cout<<endl;
            shopper.showitems();
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"If you don't want to buy anything,please press 0"<<endl;
            cout<<"You have "<<pokemon.showmoney()<<" money"<<endl;
            string buyitem;
            int buy_item;
            while(1){
                cout<<"My choice is :";
                cin>>buyitem;
                if(buyitem=="0"){
                    buy_item=0;
                    break;
                }
                else if(buyitem=="1"||buyitem=="A"||buyitem=="a"){
                    buy_item=1;
                    break;
                }
                else if(buyitem=="2"||buyitem=="B"||buyitem=="b"){
                    buy_item=2;
                    break;
                }
                else if(buyitem=="3"||buyitem=="A"||buyitem=="a"){
                    buy_item=3;
                    break;
                }
                else if(buyitem=="4"||buyitem=="A"||buyitem=="a"){
                    buy_item=4;
                    break;
                }
                else if(buyitem=="5"||buyitem=="A"||buyitem=="a"){
                    buy_item=5;
                    break;
                }
                else if(buyitem=="6"||buyitem=="A"||buyitem=="a"){
                    buy_item=6;
                    break;
                }
                else if(buyitem=="7"||buyitem=="A"||buyitem=="a"){
                    buy_item=7;
                    break;
                }
                else if(buyitem=="8"||buyitem=="A"||buyitem=="a"){
                    buy_item=8;
                    break;
                }
                else if(buyitem=="9"||buyitem=="A"||buyitem=="a"){
                    buy_item=9;
                    break;
                }
                else{
                    cout<<"Invalid input,please input again"<<endl;
                }

            }
            if(buy_item<=9&&buy_item>0){
                if(pokemon.showmoney()>=shopper.buyitem(buy_item).showcost()){
                        pokemon.spendmoney(shopper.buyitem(buy_item).showcost());
                        pokemon.setitem(shopper.buyitem(buy_item));
                }
                else{
                    cout<<"Sorry, you don't have enough money."<<endl;
                }
            }
            else if(buy_item>9||buy_item<0){
                cout<<"Sorry, we don't have this product."<<endl;
            }
            else if(buy_item==0){
                cout<<"Bye~"<<endl;
            }
        }
        if(a==4){
            pokemon.showitem();
            cout<<endl;
        }
        if(a==5){
            showgame_hints();
        }
        if(a==6){
            Boss boss;
            boss.setattack(350);
            boss.setdefence(350);
            boss.setHP(1000);
            int elemental;
            int boss_do;
            srand(time(NULL));
            elemental=(rand()%3+1);
            boss.setelemental_type(elemental);
            boss.setname(boss.show_elemental_type());
            cout<<"-----------------------------------------------------"<<endl;
            cout<<boss.showname()<<" has appeared !"<<endl;
            cout<<"*****Battle start*****"<<endl;
            cout<<endl;
            int accumulation=0;
            srand(time(NULL));
            int get_integer;
            int b_HP;
            int m_HP;
            int b_attack;
            int b_defence;
            int w_use=0;
            pokemon.showweapon(w_use);
            while(1){
                boss_do=(rand()%4+1);
                cout<<"--------You---Boss---"<<endl;
                cout<<" Attack "<<pokemon.showattack()<<"     "<<boss.showattack()<<endl;
                cout<<"Defence "<<pokemon.showdefence()<<"     "<<boss.showdefence()<<endl;
                cout<<"   HP   "<<pokemon.showHP()<<"    "<<boss.showHP()<<endl;
                cout<<"I have "<<accumulation<<" energy (you can't attack your opponent if your energy is 0)"<<endl;
                cout<<"------------------------------"<<endl;
                cout<<"What do you want to do?"<<endl;
                cout<<"1.Attack"<<endl;
                cout<<"2.Defence"<<endl;
                cout<<"3.Accumulate energy"<<endl;
                string _choice;
                cin>>_choice;
                if(_choice=="1"||_choice=="A"||_choice=="a"){
                    if(accumulation>0){
                        if(boss_do==1){
                            get_integer=accumulation*pokemon.showattack()*compare_property(pokemon.showproperty(),boss.show_elemental_type());
                            cout<<"Your attack deals "<<get_integer<<" points of damage to the "<<boss.showname()<<endl;
                            b_HP=boss.showHP();
                            b_HP-=get_integer;
                            boss.setHP(b_HP);
                            accumulation=0;
                            cout<<"You were attacked by "<<boss.showname()<<endl;
                            get_integer=boss.showattack()*compare_property(boss.show_elemental_type(),pokemon.showproperty());
                            m_HP=pokemon.showHP();
                            m_HP-=get_integer;
                            pokemon.setHP(m_HP);
                        }
                        else if(boss_do==2){
                            get_integer=accumulation*pokemon.showattack()*compare_property(pokemon.showproperty(),boss.show_elemental_type());
                            cout<<"Boss uses defence"<<endl;
                            if(get_integer<=boss.showdefence()){
                                cout<<"Your attack has no effect on the "<<boss.showname()<<endl;
                            }
                            else{
                                get_integer-=boss.showdefence();
                                cout<<"Your attack deals "<<get_integer<<"points of damage to the "<<boss.showname()<<endl;
                                int b_HP=boss.showHP();
                                b_HP-=get_integer;
                                boss.setHP(b_HP);
                            }
                        }
                        else if(boss_do==3){
                            get_integer=accumulation*pokemon.showattack()*compare_property(pokemon.showproperty(),boss.show_elemental_type());
                            cout<<"Your attack deals "<<get_integer<<" points of damage to the "<<boss.showname()<<endl;
                            b_HP=boss.showHP();
                            b_HP-=get_integer;
                            boss.setHP(b_HP);
                            accumulation=0;
                            cout<<"Boss uses recover"<<endl;
                            b_HP=boss.showHP();
                            b_HP+=boss.showattack();
                            boss.setHP(b_HP);
                        }
                        else if(boss_do==4){
                            get_integer=accumulation*pokemon.showattack()*compare_property(pokemon.showproperty(),boss.show_elemental_type());
                            cout<<"Your attack deals "<<get_integer<<" points of damage to the "<<boss.showname()<<endl;
                            b_HP=boss.showHP();
                            b_HP-=get_integer;
                            boss.setHP(b_HP);
                            accumulation=0;
                            cout<<"Boss uses enhancement"<<endl;
                            b_attack=boss.showattack()+100;
                            b_defence=boss.showdefence()+100;
                            boss.setattack(b_attack);
                            boss.setdefence(b_defence);
                        }
                    }
                    else{
                        cout<<"You don't have any energy left"<<endl;
                    }
                }
                else if(_choice=="2"||_choice=="B"||_choice=="b"){
                        if(boss_do==1){
                            cout<<"You use defence"<<endl;
                            cout<<"You were attacked by "<<boss.showname()<<endl;
                            get_integer=boss.showattack()*compare_property(boss.show_elemental_type(),pokemon.showproperty());
                            if(pokemon.showdefence()>get_integer){
                                cout<<"You successfully defend against its attack"<<endl;
                            }
                            else{
                                cout<<"You still receive some damage"<<endl;
                                m_HP=pokemon.showHP();
                                m_HP-=(get_integer-pokemon.showdefence());
                                pokemon.setHP(m_HP);
                            }
                        }
                        else if(boss_do==2){
                            cout<<"Both of you use defence"<<endl;
                        }
                        else if(boss_do==3){
                            cout<<"You use defence"<<endl;
                            cout<<"Boss uses recover"<<endl;
                            b_HP=boss.showHP();
                            b_HP+=boss.showattack();
                            boss.setHP(b_HP);
                        }
                        else if(boss_do==4){
                            cout<<"You use defence"<<endl;
                            cout<<"Boss uses enhancement"<<endl;
                            b_attack=boss.showattack()+100;
                            b_defence=boss.showdefence()+100;
                            boss.setattack(b_attack);
                            boss.setdefence(b_defence);
                        }
                    }

                else if(_choice=="3"||_choice=="C"||_choice=="c"){
                        accumulation+=1;
                        if(boss_do==1){
                            cout<<"You were attacked by "<<boss.showname()<<endl;
                            get_integer=boss.showattack()*compare_property(boss.show_elemental_type(),pokemon.showproperty());
                            pokemon.setHP(pokemon.showHP()-get_integer);
                        }
                        else if(boss_do==2){
                            cout<<"Boss uses defence"<<endl;
                        }
                        else if(boss_do==3){
                            cout<<"Boss uses recover"<<endl;
                            b_HP=boss.showHP();
                            b_HP+=boss.showattack();
                            boss.setHP(b_HP);
                        }
                        else if(boss_do==4){
                            cout<<"Boss uses enhancement"<<endl;
                            b_attack=boss.showattack()+100;
                            b_defence=boss.showdefence()+100;
                            boss.setattack(b_attack);
                            boss.setdefence(b_defence);
                        }

                }
                else{
                    cout<<"Invalid input,please input again"<<endl;
                }
                if(pokemon.showHP()<=0){
                    pokemon.setHP(0);
                    cout<<"**Battle end**"<<endl;
                    cout<<"You have died"<<endl;
                    pokemon.remove_weapon(w_use);
                    break;
                }
                if(boss.showHP()<=0){
                    cout<<"**Battle end**"<<endl;
                    cout<<"You are winner"<<endl;
                    pokemon.remove_weapon(w_use);
                    cout<<endl;
                    game_result=true;
                    this_game=false;
                    break;
                }
            }
            pokemon.remove_weapon(w_use);
        }
        if(pokemon.showdefence()<=0){
            pokemon.setdefence(0);
        }
        if(pokemon.showattack()<=0){
            pokemon.setattack(0);
        }
        if(pokemon.showfood()>=150){
            pokemon.setfood(150);
        }
        if(pokemon.showwater()>=200){
            pokemon.setwater(200);
        }
        if(pokemon.showHP()<=0){
            pokemon.setHP(0);
            cout<<endl;
            if(pokemon.show_evolving_status()){
                cout<<"Your pokemon's evolving status -1"<<endl;
                cout<<"If your evolution status and HP are reduced to zero, you will die."<<endl;
                int now_evolving_status=pokemon.show_evolving_status();
                now_evolving_status-=1;
                pokemon.setevolving_status(now_evolving_status);
                pokemon.setHP(pokemon.showHP_limit());
            }
            else if(chance==1){
                chance-=1;
                cout<<"Now you have to play a '1A1B' game to revive(get full HP)"<<endl;
                cout<<"You have only one chance to revive"<<endl;
                if(game_1A1B()){
                    int full_HP=pokemon.showHP_limit();
                    pokemon.setHP(full_HP);
                }
            }
            else{
                game_result=false;
                this_game=false;
            }
        }
        if(pokemon.showHP()>=pokemon.showHP_limit()){
            pokemon.setHP(pokemon.showHP_limit());
        }
    }
    if(game_result){
        cout<<"***************"<<endl;
        cout<<"*  You win!!! *"<<endl;
        cout<<"***************"<<endl;
        if(knowmyphonenumber){
            cout<<endl;
            cout<<"My phone number: 0905860292"<<endl;
        }
        return 0;
    }
    else if(!game_result){
        cout<<"************"<<endl;
        cout<<"* You lose *"<<endl;
        cout<<"************"<<endl;
        return 0;
    }
}
