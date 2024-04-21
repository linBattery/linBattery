#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<vector>
#include "Room.h"
#include "NPC.h"
using namespace std;


class role{
    private:
        string name;
        int property,attack,HP;
        int HP_limit;
        int defence;
        int evolving_status;
        int food,water,money;
        int poison;
        int beaten_monster;
        int position[2];
        vector<item> items;
        vector<weapon> weapons;
    public:
        void setname(string name){
            this->name=name;
        }
        string showname(){
            return name;
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
        }
        void setattack(int attack){
            this->attack=attack;
        }
        int showattack(){
            return attack;
        }
        void change_attack(int change){
            this->attack+=change;
        }
        void setdefence(int defence){
            this->defence=defence;
        }
        int showdefence(){
            return defence;
        }
        void change_defence(int change){
            this->defence+=change;
        }
        void setHP(int HP){
            this->HP=HP;
        }
        int showHP(){
            return HP;
        }
        void setHP_limit(int HP_limit){
            this->HP_limit=HP_limit;
        }
        int showHP_limit(){
            return HP_limit;
        }
        void setevolving_status(int evolving_status){
            this->evolving_status=evolving_status;
        }
        int show_evolving_status(){
            return evolving_status;
        }
        void setfood(int food){
            this->food=food;
        }
        int showfood(){
            return food;
        }
        void setwater(int water){
            this->water=water;
        }
        int showwater(){
            return water;
        }
        void setmoney(int money){
            this->money=money;
        }
        int showmoney(){
            return money;
        }
        void spendmoney(int cost){
            this->money-=cost;
        }
        void setpoison(int poison){
            this->poison=poison;
        }
        int showpoison(){
            return poison;
        }
        void setposition(int &position1,int &position2){
            this->position[0]=position1;
            this->position[1]=position2;
        }
        int showposition1(){
            return this->position[0];
        }
        int showposition2(){
            return this->position[1];
        }
        void setbeat_monster(int monster){
            this->beaten_monster=monster;
        }
        void change_beat_monster(int change){
            this->beaten_monster+=change;
        }
        int showbeat_monster(){
            return this->beaten_monster;
        }
        role(int beaten_monster=0){
            setbeat_monster(beaten_monster);
        }
        void setitem(item a_item){
            bool hasitem=false;
            int i=0;
            for(auto a:items){
                if(a_item.showname()==a.showname()){
                    hasitem=true;
                    int item_sum=a.show_item_sum();
                    items[i].setitem_sum(item_sum+1);
                    return;
                }
                i++;
            }
            if(!hasitem){
                a_item.setitem_sum(1);
                items.push_back(a_item);
            }
        }
        void setweapon(weapon a_weapon){
            int have_weapon=0;
            for(auto a:weapons){
                if(a.showname()==a_weapon.showname()){
                    have_weapon=1;
                }
            }
            if(have_weapon){
                cout<<"You already have the weapon"<<endl;
                cout<<endl;
            }
            else{
                cout<<"You pick it up now, you have a "<<a_weapon.showname()<<endl;
                cout<<endl;
                weapons.push_back(a_weapon);
            }
        }
        void showweapon(int &use){
            int i=0;
            int j=0;
            for(auto a:weapons){
                i++;
            }
            if(i!=0){
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Which one do you want to equip(If you don't want to use any of them,please other positive numbers)"<<endl;
                for(auto a:weapons){
                    j++;
                    cout<<j<<"."<<a.showname()<<a._showadvantage()<<endl;
                }
                cout<<endl;
                cout<<"My choice is :";
                string weaponuse;
                int weapon_use;
                while(1){
                cin>>weaponuse;
                if(weaponuse=="1"||weaponuse=="A"||weaponuse=="a"){
                    weapon_use=1;
                    break;
                }
                else if(weaponuse=="2"||weaponuse=="B"||weaponuse=="b"){
                    weapon_use=2;
                    break;
                }
                else if(weaponuse=="3"||weaponuse=="C"||weaponuse=="c"){
                    weapon_use=3;
                    break;
                }
                else if(weaponuse=="4"||weaponuse=="D"||weaponuse=="d"){
                    weapon_use=4;
                    break;
                }
                else if(weaponuse=="5"||weaponuse=="E"||weaponuse=="e"){
                    weapon_use=5;
                    break;
                }
                else if(weaponuse=="6"||weaponuse=="F"||weaponuse=="f"){
                    weapon_use=6;
                    break;
                }
                else{
                    cout<<"Invalid input"<<endl;
                }
                }
                use=weapon_use;
                if(weapon_use<=i&&weapon_use>0){
                    if(weapons[weapon_use-1].showname()=="knife"){
                        setattack(showattack()+50);
                    }
                    if(weapons[weapon_use-1].showname()=="shield"){
                        setdefence(showdefence()+50);
                    }
                    if(weapons[weapon_use-1].showname()=="armor"){
                        setHP(showHP()+120);
                    }
                    if(weapons[weapon_use-1].showname()=="powerful_knife"){
                        setattack(showattack()+150);
                    }
                    if(weapons[weapon_use-1].showname()=="powerful_shield"){
                        setdefence(showdefence()+120);
                    }
                    if(weapons[weapon_use-1].showname()=="powerful_armor"){
                        setHP(showHP()+300);
                    }
                }
                else{
                    use=0;
                    cout<<"No this weapon"<<endl;
                }
            }
            else{
                cout<<"You don't have any weapon"<<endl;
            }
        }
        void remove_weapon(int &use){
                if(use<=0){
                    return;
                }
                else if(weapons[use-1].showname()=="knife"){
                    this->attack-=50;
                    return;
                }
                else if(weapons[use-1].showname()=="shield"){
                    setdefence(showdefence()-50);
                    return;
                }
                else if(weapons[use-1].showname()=="armor"){
                    setHP(showHP()-120);
                    return;
                }
                else if(weapons[use-1].showname()=="powerful_knife"){
                    setattack(showattack()-150);
                    return;
                }
                else if(weapons[use-1].showname()=="powerful_shield"){
                    setdefence(showdefence()-120);
                    return;
                }
                else if(weapons[use-1].showname()=="powerful_armor"){
                    setHP(showHP()-300);
                    return;
                }
        }
        void showitem(){
            int i=0;
            cout<<"-----------------------------------------------------"<<endl;
            for(auto a:items){
                i++;
                cout<<i<<"."<<a.showname()<<a.show_function()<<" x"<<a.show_item_sum()<<endl;
            }
            if(i>0){
                cout<<"Which one do you want to use?(If you don't want to use any of them,please press 0 or numbers.)"<<endl;
                int item_use;
                cout<<"My choice is :";
                cin>>item_use;
                if (item_use<=i&&item_use > 0) {
                        if(items[item_use-1].showname()=="evolving_stone"){
                            this->attack*=2;
                            this->defence*=2;
                            items[item_use-1].setitem_sum(items[item_use-1].show_item_sum()-1);
                            if(items[item_use-1].show_item_sum()==0){
                                items.erase(items.begin() + item_use - 1);
                            }
                        }
                        if(items[item_use-1].showname()=="training_book"){
                            this->attack+=10;
                            items[item_use-1].setitem_sum(items[item_use-1].show_item_sum()-1);
                            if(items[item_use-1].show_item_sum()==0){
                                items.erase(items.begin() + item_use - 1);
                            }
                        }
                        if(items[item_use-1].showname()=="dumbbell"){
                            this->attack+=10;
                            this->defence+=10;
                            items[item_use-1].setitem_sum(items[item_use-1].show_item_sum()-1);
                            if(items[item_use-1].show_item_sum()==0){
                                items.erase(items.begin() + item_use - 1);
                            }
                        }
                        if(items[item_use-1].showname()=="superbadge"){
                            this->HP_limit+=100;
                            items[item_use-1].setitem_sum(items[item_use-1].show_item_sum()-1);
                            if(items[item_use-1].show_item_sum()==0){
                                items.erase(items.begin() + item_use - 1);
                            }
                        }
                        if(items[item_use-1].showname()=="pokemon_protein"){
                            this->defence+=10;
                            this->HP_limit+=50;
                            items[item_use-1].setitem_sum(items[item_use-1].show_item_sum()-1);
                            if(items[item_use-1].show_item_sum()==0){
                                items.erase(items.begin() + item_use - 1);
                            }
                        }
                        if(items[item_use-1].showname()=="pokemon_fruit"){
                            this->poison=0;
                            items[item_use-1].setitem_sum(items[item_use-1].show_item_sum()-1);
                            if(items[item_use-1].show_item_sum()==0){
                                items.erase(items.begin() + item_use - 1);
                            }
                        }
                        if(items[item_use-1].showname()=="pork"){
                            this->food+=20;
                            items[item_use-1].setitem_sum(items[item_use-1].show_item_sum()-1);
                            if(items[item_use-1].show_item_sum()==0){
                                items.erase(items.begin() + item_use - 1);
                            }
                        }
                        if(items[item_use-1].showname()=="egg"){
                            this->food+=10;
                            this->water+=10;
                            items[item_use-1].setitem_sum(items[item_use-1].show_item_sum()-1);
                            if(items[item_use-1].show_item_sum()==0){
                                items.erase(items.begin() + item_use - 1);
                            }
                        }
                        if(items[item_use-1].showname()=="birthday_cake"){
                            this->food+=50;
                            this->water-=20;
                            items[item_use-1].setitem_sum(items[item_use-1].show_item_sum()-1);
                            if(items[item_use-1].show_item_sum()==0){
                                items.erase(items.begin() + item_use - 1);
                            }
                            if(showwater()<=0){
                                setwater(0);
                            }
                        }
                }
                else if(item_use<0){
                    cout<<"Invalid input"<<endl;
                }
            }
            else{
                cout<<"No item"<<endl;
            }
        }
        void meet_npc(int p1,int p2){
            smallmonster a_smallmonster;
            if(abs(p1)%2==1&&abs(p2)%3==1){
                if(p1<0&&p2>0){
                    Pokemon_hunter hunter;
                    hunter.say_lines();
                    int _poison=showpoison();
                    hunter._do(_poison);
                    setpoison(_poison);
                }
            }
            if((p1==5||p1==-5)&&(p2==5||p2==-5)){
                Brock brock;
                int money=showmoney();
                int attack=showattack();
                int defence=showdefence();
                brock.say_lines();
                brock._do(money,attack,defence);
                setmoney(money);
                setattack(attack);
                setdefence(defence);
            }
            if((p1==1||p1==-1||p1==7||p1==-7)&&(p2==5||p2==-5)){
                Team_Rocket_member member;
                int food=showfood();
                int water=showwater();
                member.say_lines();
                member._do(food,water);
                int T_HP;
                if(food<=0){
                    setHP((showHP()+food));
                    food=0;
                }
                if(water<=0){
                    setHP((showHP()+water));
                    water=0;
                }
                setfood(food);
                setwater(water);
            }
            if((p1==4||p1==-4)&&(p2==4||p2==-4)){
                Esther esther;
                int _attack=showattack();
                int _defence=showdefence();
                int _HP=showHP();
                int _money=showmoney();
                esther.say_lines();
                esther._do(_attack,_defence,_HP,_money);
                setmoney(_money);
                setattack(_attack);
                setdefence(_defence);
                setHP(_HP);
            }
            if(abs(p1)==0||abs(p2)==0){
                if((p1%3==2)||(p2%3==2)){
                    Nurse_Joey nurse;
                    int _money=showmoney();
                    int _HP=showHP();
                    int _HP_limit=showHP_limit();
                    int _poison=showpoison();
                    nurse.say_lines();
                    nurse._do(_money,_HP,_HP_limit,_poison);
                    setmoney(_money);
                    setHP(_HP);
                    setHP_limit(_HP_limit);
                    setpoison(_poison);
                }
            }
            if(p1!=0&&p2!=0){
                if(p1%4==0&&p2%2==0){
                    Pokemon_helper helper;
                    int _money=showmoney();
                    int _food=showfood();
                    int _water=showwater();
                    helper.say_lines();
                    helper._do(_money,_food,_water);
                    setmoney(_money);
                    setfood(_food);
                    setwater(_water);
                }
                if((p1>0&&p2>0)||(p1<0&&p2<0)){
                    if(p1%3==0&&p2%3==0){
                        int w_use=0;
                        while(1){
                        cout<<"Small monster appear"<<endl;
                        cout<<"Do you want to fight with it?"<<endl;
                        cout<<"1.Yes"<<endl;
                        cout<<"2.Run away"<<endl;
                        cout<<"My choice is: ";
                        string fighting;
                        cin>>fighting;
                        if(fighting=="1"||fighting=="A"||fighting=="a"){
                            showweapon(w_use);
                            int myattack=showattack();
                            int mydefence=showdefence();
                            int myHP=showHP();
                            int myHP_limit=showHP_limit();
                            int result=0;
                            a_smallmonster.fight(myattack,mydefence,myHP,result,showbeat_monster());
                            setHP(myHP);
                            if(w_use>=0){
                                remove_weapon(w_use);
                            }
                            if(result==1){
                                change_beat_monster(1);
                                setattack(showattack()+20);
                                setdefence(showdefence()+20);
                                setHP_limit(showHP_limit()+50);
                                setHP(showHP()+50);
                            }
                            return;
                        }
                        else if(fighting=="2"||fighting=="B"||fighting=="b"){
                            return;
                        }
                        else{
                            cout<<"invalid input"<<endl;
                        }
                        }
                    }
                }
                else if(p1>0&&p2<0||(p1<0&&p2>0)){
                    if(p1%1==0&&p2%3==0){
                        int w_use=0;
                        while(1){
                        cout<<"Small monster appear"<<endl;
                        cout<<"Do you want to fight with it?"<<endl;
                        cout<<"1.Yes"<<endl;
                        cout<<"2.Run away"<<endl;
                        cout<<"My choice is: ";
                        string fighting;
                        cin>>fighting;
                        if(fighting=="1"||fighting=="A"||fighting=="a"){
                            showweapon(w_use);
                            int myattack=showattack();
                            int mydefence=showdefence();
                            int myHP=showHP();
                            int myHP_limit=showHP_limit();
                            int result=0;
                            a_smallmonster.fight(myattack,mydefence,myHP,result,showbeat_monster());
                            setHP(myHP);
                            if(w_use>=0){
                                remove_weapon(w_use);
                            }
                            if(result==1){
                                change_beat_monster(1);
                                setattack(showattack()+20);
                                setdefence(showdefence()+20);
                                setHP_limit(showHP_limit()+50);
                                setHP(showHP()+50);
                            }
                            return;
                        }
                        else if(fighting=="2"||fighting=="B"||fighting=="b"){
                            return;
                        }
                        else{
                            cout<<"invalid input"<<endl;
                        }
                        }
                }
            }
        }
        }
        void show_all_status(){
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"name: "<<name<<endl;
            cout<<"elemental type: "<<showproperty()<<endl;
            cout<<"attack: "<<attack<<endl;
            cout<<"defence: "<<defence<<endl;
            cout<<"HP: "<<HP<<"/"<<HP_limit<<endl;
            cout<<"evolving status: "<<show_evolving_status()<<endl;
            cout<<"food,water: "<<food<<","<<water<<endl;
            cout<<"money: "<<money<<endl;
            cout<<"poison: "<<poison<<endl;
            cout<<"monster you have beaten: "<<beaten_monster<<endl<<endl;
            cout<<"**My weapon**"<<endl;
            int i=0;
            for(auto a:weapons){
                i++;
                cout<<i<<"."<<a.showname()<<a._showadvantage()<<endl;
            }
            if(i==0){
                cout<<"No weapon"<<endl;
            }
            cout<<endl;
            cout<<"My position: "<<"("<<position[0]<<","<<position[1]<<")"<<endl;
            cout<<"-----------------------------------------------------"<<endl;
            cout<<endl;
        }
};


class shop{
    public:
        vector<item> items;
        shop(){
            items.push_back(evolving_stone());
            items.push_back(training_book());
            items.push_back(dumbbell());
            items.push_back(superbadge());
            items.push_back(pokemon_protein());
            items.push_back(pokemon_fruit());
            items.push_back(pork());
            items.push_back(egg());
            items.push_back(birthday_cake());
        }
        void showitems(){
            cout<<"-----------------------------------------------------"<<endl;
            cout<<"What do you want to buy?"<<endl;
            int i=1;
            for(auto a:items){
                cout<<i<<"."<<a.showname()<<" "<<a.showcost()<<"$"<<a.show_function()<<endl;
                i++;
            }
        }
        item buyitem(int choice){
            choice-=1;
            return items[choice];
        }


};

